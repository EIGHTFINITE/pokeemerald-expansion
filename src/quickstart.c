#include "global.h"
#include "config/general.h"
#include "constants/global.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "graphics.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "config/quickstart.h"
#include "quickstart.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"


enum { TAG_SKIP_INTRO = 2000 };

static const u32 gQuickstartHudGfx[] = INCBIN_U32("graphics/quickstart/quickstart_hud.4bpp.smol");
#if FIRERED
static const u16 gQuickstartHudPal[] = INCBIN_U16("graphics/quickstart/firered.gbapal");
#elif LEAFGREEN
static const u16 gQuickstartHudPal[] = INCBIN_U16("graphics/quickstart/leafgreen.gbapal");
#else
static const u16 gQuickstartHudPal[] = INCBIN_U16("graphics/quickstart/emerald.gbapal");
#endif

static const struct OamData sQuickstartHudOam = {
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .priority = 0,
    .paletteNum = 0,
};

static const union AnimCmd sSkipAnim_0[] = {ANIMCMD_FRAME(0, 0), ANIMCMD_END};
static const union AnimCmd sSkipAnim_1[] = {ANIMCMD_FRAME(4, 0), ANIMCMD_END};
static const union AnimCmd sSkipAnim_2[] = {ANIMCMD_FRAME(8, 0), ANIMCMD_END};
static const union AnimCmd sSkipAnim_3[] = {ANIMCMD_FRAME(12, 0), ANIMCMD_END};

static const union AnimCmd* const sSkipAnimTable[] = {
    sSkipAnim_0,
    sSkipAnim_1,
    sSkipAnim_2,
    sSkipAnim_3,
};

static const struct SpriteTemplate sQuickstartHudTemplate  = {
    .tileTag = TAG_SKIP_INTRO,
    .paletteTag = TAG_SKIP_INTRO,
    .oam = &sQuickstartHudOam,
    .anims = sSkipAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sSpriteSheet_QuickstartHud = {
    .data = gQuickstartHudGfx, .size = 0x200, .tag = TAG_SKIP_INTRO};

static const struct SpritePalette sSpritePalette_QuickstartHud = {
    .data = gQuickstartHudPal, .tag = TAG_SKIP_INTRO};

static inline enum Gender SetQuickstartPlayerGender()
{
    switch (QUICKSTART_GENDER)
    {
        case GENDER_MALE:
            return MALE;
        case GENDER_FEMALE:
            return FEMALE;
        case GENDER_RANDOM:
        default:
            return RandomPercentage(RNG_NONE, 50) ? FEMALE : MALE;
    }
}

static void CB2_SkipToNewGameEmerald(void)
{
    static const u8 sText_Brendan[] = _("BRENDAN");
    static const u8 sText_May[] = _("MAY");
    if (!UpdatePaletteFade())
    {
        gSaveBlock2Ptr->playerGender = SetQuickstartPlayerGender();
        const u8* textPtr = gSaveBlock2Ptr->playerGender ? sText_May : sText_Brendan;
        StringCopy_PlayerName(gSaveBlock2Ptr->playerName, textPtr);
        SetMainCallback2(CB2_NewGame);
    }
}

static void CB2_SkipToNewGameFrlg(void)
{
    #if IS_FRLG
    static const u8 sText_Red[] = _("RED");
    static const u8 sText_Leaf[] = _("LEAF");
    static const u8 sText_Blue[] = _("BLUE");
    if (!UpdatePaletteFade())
    {
        gSaveBlock2Ptr->playerGender = RandomPercentage(RNG_NONE, 50) ? FEMALE : MALE;
        const u8* textPtr = gSaveBlock2Ptr->playerGender ? sText_Leaf : sText_Red;
        StringCopy_PlayerName(gSaveBlock2Ptr->playerName, textPtr);
        StringCopy_PlayerName(gSaveBlock1Ptr->rivalName, sText_Blue);
        SetMainCallback2(CB2_NewGame);
    }
    #endif /* if IS_FRLG */
}

static void LoadQuickstartSpritsheetAndPal(void)
{
    if (!QUICKSTART)
        return;
    LoadCompressedSpriteSheet(&sSpriteSheet_QuickstartHud);
    LoadSpritePalette(&sSpritePalette_QuickstartHud);
}

void CreateQuickstartHud(s16 x, s16 y)
{
    if (!QUICKSTART || !QUICKSTART_HUD)
        return;

    LoadQuickstartSpritsheetAndPal();
    u8 i, spriteId;

    x-=16;
    y+=8;

    for (i = 0; i < 4; i++)
    {
        s16 dx = (i & 1) * 32;
        s16 dy = 4 * (2*(!!(i>>1)) - 1);

        spriteId = CreateSprite(&sQuickstartHudTemplate, x + dx, y + dy, 0);
        StartSpriteAnim(&gSprites[spriteId], i);
    }
}

void QuickstartFrlg()
{
    if (!QUICKSTART)
        return;

    if (!gPaletteFade.active)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        FadeOutBGM(4);
        FreeAllSpritePalettes();
        ResetTasks();
        SetMainCallback2(CB2_SkipToNewGameFrlg);
    }
}

void QuickstartEmerald(void)
{
    if (!QUICKSTART)
        return;

    FadeOutBGM(4);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    SetMainCallback2(CB2_SkipToNewGameEmerald);
    return;
}
