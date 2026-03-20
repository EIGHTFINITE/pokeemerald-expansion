#include "global.h"
#include "battle_main.h"
#include "decompress.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "malloc.h"
#include "move.h"
#include "sprite.h"
#include "constants/items.h"

// EWRAM vars
EWRAM_DATA u8 *gItemIconDecompressionBuffer = NULL;
EWRAM_DATA u8 *gItemIcon4x4Buffer = NULL;

// const rom data
#include "data/item_icon_table.h"

static const struct OamData sOamData_ItemIcon =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 2,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_ItemIcon[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sSpriteAnimTable_ItemIcon[] =
{
    sSpriteAnim_ItemIcon
};

const struct SpriteTemplate gItemIconSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_ItemIcon,
    .anims = sSpriteAnimTable_ItemIcon,
};

// code
bool8 AllocItemIconTemporaryBuffers(void)
{
    gItemIconDecompressionBuffer = Alloc(0x120);
    if (gItemIconDecompressionBuffer == NULL)
        return FALSE;

    gItemIcon4x4Buffer = AllocZeroed(0x200);
    if (gItemIcon4x4Buffer == NULL)
    {
        Free(gItemIconDecompressionBuffer);
        return FALSE;
    }

    return TRUE;
}

void FreeItemIconTemporaryBuffers(void)
{
    Free(gItemIconDecompressionBuffer);
    Free(gItemIcon4x4Buffer);
}

void CopyItemIconPicTo4x4Buffer(const void *src, void *dest)
{
    u8 i;

    for (i = 0; i < 3; i++)
        CpuCopy16(src + i * 96, dest + i * 128, 0x60);
}

u8 AddItemIconSprite(u16 tilesTag, u16 paletteTag, enum Item itemId)
{
    if (!AllocItemIconTemporaryBuffers())
    {
        return MAX_SPRITES;
    }
    else
    {
        u8 spriteId;
        struct SpriteSheet spriteSheet;
        struct SpritePalette spritePalette;
        struct SpriteTemplate *spriteTemplate;

        DecompressDataWithHeaderWram(GetItemIconPic(itemId), gItemIconDecompressionBuffer);
        CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer);
        spriteSheet.data = gItemIcon4x4Buffer;
        spriteSheet.size = 0x200;
        spriteSheet.tag = tilesTag;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetItemIconPalette(itemId);
        spritePalette.tag = paletteTag;
        LoadSpritePalette(&spritePalette);

        spriteTemplate = Alloc(sizeof(*spriteTemplate));
        CpuCopy16(&gItemIconSpriteTemplate, spriteTemplate, sizeof(*spriteTemplate));
        spriteTemplate->tileTag = tilesTag;
        spriteTemplate->paletteTag = paletteTag;
        spriteId = CreateSprite(spriteTemplate, 0, 0, 0);

        FreeItemIconTemporaryBuffers();
        Free(spriteTemplate);

        return spriteId;
    }
}

u8 AddCustomItemIconSprite(const struct SpriteTemplate *customSpriteTemplate, u16 tilesTag, u16 paletteTag, enum Item itemId)
{
    if (!AllocItemIconTemporaryBuffers())
    {
        return MAX_SPRITES;
    }
    else
    {
        u8 spriteId;
        struct SpriteSheet spriteSheet;
        struct SpritePalette spritePalette;
        struct SpriteTemplate *spriteTemplate;

        DecompressDataWithHeaderWram(GetItemIconPic(itemId), gItemIconDecompressionBuffer);
        CopyItemIconPicTo4x4Buffer(gItemIconDecompressionBuffer, gItemIcon4x4Buffer);
        spriteSheet.data = gItemIcon4x4Buffer;
        spriteSheet.size = 0x200;
        spriteSheet.tag = tilesTag;
        LoadSpriteSheet(&spriteSheet);

        spritePalette.data = GetItemIconPalette(itemId);
        spritePalette.tag = paletteTag;
        LoadSpritePalette(&spritePalette);

        spriteTemplate = Alloc(sizeof(*spriteTemplate));
        CpuCopy16(customSpriteTemplate, spriteTemplate, sizeof(*spriteTemplate));
        spriteTemplate->tileTag = tilesTag;
        spriteTemplate->paletteTag = paletteTag;
        spriteId = CreateSprite(spriteTemplate, 0, 0, 0);

        FreeItemIconTemporaryBuffers();
        Free(spriteTemplate);

        return spriteId;
    }
}

const void *GetItemIconPic(enum Item itemId)
{
    if (itemId == ITEM_LIST_END)
        return gItemIcon_ReturnToFieldArrow; // Use last icon, the "return to field" arrow
    if (itemId >= ITEMS_COUNT)
        return gItemsInfo[0].iconPic;
    if (gItemsInfo[itemId].pocket == POCKET_TM_HM)
    {
        if (GetItemTMHMIndex(itemId) > NUM_TECHNICAL_MACHINES)
            return gItemIcon_HM;
        return gItemIcon_TM;
    }

    return gItemsInfo[itemId].iconPic;
}

const u16 *GetItemIconPalette(enum Item itemId)
{
    if (itemId == ITEM_LIST_END)
        return gItemIconPalette_ReturnToFieldArrow;
    if (itemId >= ITEMS_COUNT)
        return gItemsInfo[0].iconPalette;
    if (gItemsInfo[itemId].pocket == POCKET_TM_HM)
    {
        enum Move move = GetItemTMHMMoveId(itemId);
        if (move == MOVE_CURSE)
            return gTypesInfo[TYPE_MYSTERY].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_FIGHTING)
            return gTypesInfo[TYPE_FIGHTING].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_FLYING)
            return gTypesInfo[TYPE_FLYING].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_POISON)
            return gTypesInfo[TYPE_POISON].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_GROUND)
            return gTypesInfo[TYPE_GROUND].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_ROCK)
            return gTypesInfo[TYPE_ROCK].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_BUG)
            return gTypesInfo[TYPE_BUG].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_GHOST)
            return gTypesInfo[TYPE_GHOST].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_STEEL)
            return gTypesInfo[TYPE_STEEL].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_FIRE)
            return gTypesInfo[TYPE_FIRE].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_WATER)
            return gTypesInfo[TYPE_WATER].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_GRASS)
            return gTypesInfo[TYPE_GRASS].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_ELECTRIC)
            return gTypesInfo[TYPE_ELECTRIC].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_PSYCHIC)
            return gTypesInfo[TYPE_PSYCHIC].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_ICE)
            return gTypesInfo[TYPE_ICE].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_DRAGON)
            return gTypesInfo[TYPE_DRAGON].paletteTMHM;
        else if (move == MOVE_HIDDEN_POWER_DARK)
            return gTypesInfo[TYPE_DARK].paletteTMHM;
        return gTypesInfo[GetMoveType(move)].paletteTMHM;
    }

    return gItemsInfo[itemId].iconPalette;
}
