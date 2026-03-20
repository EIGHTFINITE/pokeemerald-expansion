#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gTypesInfo[TYPE_NONE].isHiddenPowerType == FALSE);
    ASSUME(gTypesInfo[TYPE_NORMAL].isHiddenPowerType == FALSE);
    ASSUME(gTypesInfo[TYPE_FIGHTING].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_FLYING].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_POISON].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_GROUND].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_ROCK].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_BUG].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_GHOST].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_STEEL].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_MYSTERY].isHiddenPowerType == FALSE);
    ASSUME(gTypesInfo[TYPE_FIRE].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_WATER].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_GRASS].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_ELECTRIC].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_PSYCHIC].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_ICE].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_DRAGON].isHiddenPowerType == TRUE);
    ASSUME(gTypesInfo[TYPE_DARK].isHiddenPowerType == TRUE);
    // Any type after Dark shouldn't be part of Hidden Power officially.
    for (u32 j = TYPE_DARK + 1; j < NUMBER_OF_MON_TYPES; j++) {
        ASSUME(gTypesInfo[j].isHiddenPowerType == FALSE);
    }
}

// IV combinations sourced from https://www.smogon.com/forums/threads/hidden-power-iv-combinations.78083/
SINGLE_BATTLE_TEST("Hidden Power's type is determined by IVs")
{
    enum Type type, foeType, j;
    u32 foeSpecies, foeItem;
    u32 hp, atk, def, spAtk, spDef, speed;
    bool32 hidden;

    PARAMETRIZE { type = TYPE_NONE;     hidden = FALSE; }
    PARAMETRIZE { type = TYPE_NORMAL;   hidden = FALSE; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_CHOPLE_BERRY; hp = 30; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_CHOPLE_BERRY; hp = 31; atk = 15; def = 30; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_CHOPLE_BERRY; hp = 30; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FIGHTING; hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_CHOPLE_BERRY; hp = 31; atk = 31; def = 30; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_COBA_BERRY;   hp = 31; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_COBA_BERRY;   hp = 31; atk = 15; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_COBA_BERRY;   hp = 31; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_FLYING;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_COBA_BERRY;   hp = 31; atk = 31; def = 31; spAtk = 30; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_KEBIA_BERRY;  hp = 30; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_KEBIA_BERRY;  hp = 31; atk = 15; def = 30; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_KEBIA_BERRY;  hp = 30; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_POISON;   hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_KEBIA_BERRY;  hp = 31; atk = 31; def = 30; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_STEEL;   foeSpecies = SPECIES_KLINK;     foeItem = ITEM_SHUCA_BERRY;  hp = 31; atk =  2; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_STEEL;   foeSpecies = SPECIES_KLINK;     foeItem = ITEM_SHUCA_BERRY;  hp = 31; atk = 15; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_STEEL;   foeSpecies = SPECIES_KLINK;     foeItem = ITEM_SHUCA_BERRY;  hp = 31; atk = 22; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GROUND;   hidden = TRUE;  foeType = TYPE_STEEL;   foeSpecies = SPECIES_KLINK;     foeItem = ITEM_SHUCA_BERRY;  hp = 31; atk = 31; def = 31; spAtk = 30; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_FIRE;    foeSpecies = SPECIES_VULPIX;    foeItem = ITEM_CHARTI_BERRY; hp = 31; atk =  2; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_FIRE;    foeSpecies = SPECIES_VULPIX;    foeItem = ITEM_CHARTI_BERRY; hp = 31; atk = 15; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_FIRE;    foeSpecies = SPECIES_VULPIX;    foeItem = ITEM_CHARTI_BERRY; hp = 31; atk = 22; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_ROCK;     hidden = TRUE;  foeType = TYPE_FIRE;    foeSpecies = SPECIES_VULPIX;    foeItem = ITEM_CHARTI_BERRY; hp = 31; atk = 31; def = 30; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_TANGA_BERRY;  hp = 31; atk =  2; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_TANGA_BERRY;  hp = 31; atk = 15; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_TANGA_BERRY;  hp = 31; atk = 22; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_BUG;      hidden = TRUE;  foeType = TYPE_DARK;    foeSpecies = SPECIES_UMBREON;   foeItem = ITEM_TANGA_BERRY;  hp = 31; atk = 31; def = 31; spAtk = 31; spDef = 30; speed = 30; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_KASIB_BERRY;  hp = 31; atk =  2; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_KASIB_BERRY;  hp = 31; atk = 15; def = 30; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_KASIB_BERRY;  hp = 31; atk = 22; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_GHOST;    hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_KASIB_BERRY;  hp = 31; atk = 31; def = 30; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_BABIRI_BERRY; hp = 31; atk =  2; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_BABIRI_BERRY; hp = 31; atk = 15; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_BABIRI_BERRY; hp = 31; atk = 22; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_STEEL;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_BABIRI_BERRY; hp = 31; atk = 31; def = 31; spAtk = 31; spDef = 30; speed = 31; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_OCCA_BERRY;   hp = 31; atk =  2; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_OCCA_BERRY;   hp = 31; atk = 15; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_OCCA_BERRY;   hp = 31; atk = 22; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_FIRE;     hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_OCCA_BERRY;   hp = 31; atk = 31; def = 30; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_PASSHO_BERRY; hp = 31; atk =  2; def = 30; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_PASSHO_BERRY; hp = 31; atk = 15; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_PASSHO_BERRY; hp = 31; atk = 22; def = 30; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_WATER;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_PASSHO_BERRY; hp = 31; atk = 31; def = 31; spAtk = 30; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_RINDO_BERRY;  hp = 30; atk =  2; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_RINDO_BERRY;  hp = 30; atk = 15; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_RINDO_BERRY;  hp = 30; atk = 22; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_GRASS;    hidden = TRUE;  foeType = TYPE_ROCK;    foeSpecies = SPECIES_NOSEPASS;  foeItem = ITEM_RINDO_BERRY;  hp = 30; atk = 31; def = 31; spAtk = 30; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_WATER;   foeSpecies = SPECIES_SQUIRTLE;  foeItem = ITEM_WACAN_BERRY;  hp = 31; atk =  2; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_WATER;   foeSpecies = SPECIES_SQUIRTLE;  foeItem = ITEM_WACAN_BERRY;  hp = 30; atk = 15; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_WATER;   foeSpecies = SPECIES_SQUIRTLE;  foeItem = ITEM_WACAN_BERRY;  hp = 31; atk = 22; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ELECTRIC; hidden = TRUE;  foeType = TYPE_WATER;   foeSpecies = SPECIES_SQUIRTLE;  foeItem = ITEM_WACAN_BERRY;  hp = 30; atk = 31; def = 30; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_POISON;  foeSpecies = SPECIES_KOFFING;   foeItem = ITEM_PAYAPA_BERRY; hp = 31; atk =  2; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_POISON;  foeSpecies = SPECIES_KOFFING;   foeItem = ITEM_PAYAPA_BERRY; hp = 30; atk = 15; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_POISON;  foeSpecies = SPECIES_KOFFING;   foeItem = ITEM_PAYAPA_BERRY; hp = 31; atk = 22; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_PSYCHIC;  hidden = TRUE;  foeType = TYPE_POISON;  foeSpecies = SPECIES_KOFFING;   foeItem = ITEM_PAYAPA_BERRY; hp = 30; atk = 31; def = 31; spAtk = 31; spDef = 31; speed = 30; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_YACHE_BERRY;  hp = 30; atk =  2; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_YACHE_BERRY;  hp = 30; atk = 15; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_YACHE_BERRY;  hp = 30; atk = 22; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_ICE;      hidden = TRUE;  foeType = TYPE_GRASS;   foeSpecies = SPECIES_TANGELA;   foeItem = ITEM_YACHE_BERRY;  hp = 30; atk = 31; def = 30; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_MYSTERY;  hidden = FALSE; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_DRAGON;  foeSpecies = SPECIES_DRATINI;   foeItem = ITEM_HABAN_BERRY;  hp = 30; atk =  2; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_DRAGON;  foeSpecies = SPECIES_DRATINI;   foeItem = ITEM_HABAN_BERRY;  hp = 30; atk = 15; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_DRAGON;  foeSpecies = SPECIES_DRATINI;   foeItem = ITEM_HABAN_BERRY;  hp = 30; atk = 22; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DRAGON;   hidden = TRUE;  foeType = TYPE_DRAGON;  foeSpecies = SPECIES_DRATINI;   foeItem = ITEM_HABAN_BERRY;  hp = 30; atk = 31; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_COLBUR_BERRY; hp = 31; atk =  3; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_COLBUR_BERRY; hp = 31; atk = 15; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_COLBUR_BERRY; hp = 31; atk = 23; def = 31; spAtk = 31; spDef = 31; speed = 31; }
    PARAMETRIZE { type = TYPE_DARK;     hidden = TRUE;  foeType = TYPE_PSYCHIC; foeSpecies = SPECIES_WOBBUFFET; foeItem = ITEM_COLBUR_BERRY; hp = 31; atk = 31; def = 31; spAtk = 31; spDef = 31; speed = 31; }

    // Any type after Dark shouldn't be part of Hidden Power officially.
    for (j = TYPE_DARK + 1; j < NUMBER_OF_MON_TYPES; j++) {
        PARAMETRIZE { type = j; hidden = FALSE; }
    }

    GIVEN {
        if (hidden) {
            ASSUME(gTypeEffectivenessTable[type][foeType] == UQ_4_12(2.0));                 // Foe's Type resists
            ASSUME(GetSpeciesType(foeSpecies, 0) == GetSpeciesType(foeSpecies, 1)); // Foe's pure type
            ASSUME(GetSpeciesType(foeSpecies, 0) == foeType);                           // Foe is the super-effective type
            ASSUME(GetItemHoldEffect(foeItem) == HOLD_EFFECT_RESIST_BERRY);              // Item is resist berry
            ASSUME(GetItemHoldEffectParam(foeItem) == type);                             // Resist berry of type
            PLAYER(SPECIES_DUNSPARCE) { HPIV(hp); AttackIV(atk); DefenseIV(def); SpAttackIV(spAtk); SpDefenseIV(spDef); SpeedIV(speed); }
        } else {
            PLAYER(SPECIES_DUNSPARCE);
        }
        OPPONENT(foeSpecies) { Item(foeItem); }
    } WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER); }
    } SCENE {
        // Only test valid Hidden Power types
        if (hidden) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponent); // Check that the item is triggered
            ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player);
            HP_BAR(opponent);
            MESSAGE("It's super effective!");
        }
    }
}

TO_DO_BATTLE_TEST("Hidden Power's power is determined by IVs before Gen6");

SINGLE_BATTLE_TEST("Hidden Power always triggers Counter instead of Mirror Coat (Gen 1-3)")
{
    u8 hp, atk, def, spa, spd, spe;

    PARAMETRIZE { hp = 31; atk = 30; def = 30; spa = 30; spd = 30; spe = 30; } // TYPE_FIGHTING
    PARAMETRIZE { hp = 31; atk = 30; def = 31; spa = 30; spd = 30; spe = 30; } // TYPE_FLYING
    PARAMETRIZE { hp = 31; atk = 30; def = 30; spa = 30; spd = 30; spe = 31; } // TYPE_POISON
    PARAMETRIZE { hp = 31; atk = 30; def = 31; spa = 30; spd = 30; spe = 31; } // TYPE_GROUND
    PARAMETRIZE { hp = 31; atk = 30; def = 30; spa = 31; spd = 30; spe = 30; } // TYPE_ROCK
    PARAMETRIZE { hp = 31; atk = 30; def = 31; spa = 31; spd = 30; spe = 30; } // TYPE_BUG
    PARAMETRIZE { hp = 31; atk = 31; def = 30; spa = 31; spd = 30; spe = 31; } // TYPE_GHOST
    PARAMETRIZE { hp = 31; atk = 31; def = 31; spa = 31; spd = 30; spe = 31; } // TYPE_STEEL
    PARAMETRIZE { hp = 31; atk = 31; def = 30; spa = 30; spd = 31; spe = 30; } // TYPE_FIRE
    PARAMETRIZE { hp = 31; atk = 31; def = 31; spa = 30; spd = 31; spe = 30; } // TYPE_WATER
    PARAMETRIZE { hp = 31; atk = 31; def = 30; spa = 30; spd = 31; spe = 31; } // TYPE_GRASS
    PARAMETRIZE { hp = 31; atk = 31; def = 31; spa = 30; spd = 31; spe = 31; } // TYPE_ELECTRIC
    PARAMETRIZE { hp = 31; atk = 31; def = 30; spa = 31; spd = 31; spe = 30; } // TYPE_PSYCHIC
    PARAMETRIZE { hp = 31; atk = 31; def = 31; spa = 31; spd = 31; spe = 30; } // TYPE_ICE
    PARAMETRIZE { hp = 31; atk = 31; def = 30; spa = 31; spd = 31; spe = 31; } // TYPE_DRAGON
    PARAMETRIZE { hp = 31; atk = 31; def = 31; spa = 31; spd = 31; spe = 31; } // TYPE_DARK
 
    GIVEN {
        WITH_CONFIG(B_HIDDEN_POWER_COUNTER, GEN_3);
        ASSUME(GetMoveEffect(MOVE_COUNTER) == EFFECT_REFLECT_DAMAGE );
        ASSUME(GetMoveEffect(MOVE_MIRROR_COAT) == EFFECT_REFLECT_DAMAGE);
        ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_COUNTER) == 1u << DAMAGE_CATEGORY_PHYSICAL );
        ASSUME(GetMoveReflectDamage_DamageCategories(MOVE_MIRROR_COAT) == 1u << DAMAGE_CATEGORY_SPECIAL );
        PLAYER(SPECIES_WOBBUFFET) { HPIV(hp); AttackIV(atk); DefenseIV(def); SpAttackIV(spa); SpDefenseIV(spd); SpeedIV(spe); }
        OPPONENT(SPECIES_WOBBUFFET);
    }
    WHEN {
        TURN { MOVE(player, MOVE_HIDDEN_POWER); MOVE(opponent, MOVE_MIRROR_COAT); }
        TURN { MOVE(player, MOVE_HIDDEN_POWER); MOVE(opponent, MOVE_COUNTER); }
    }
    SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player);
        MESSAGE("The opposing Wobbuffet used Mirror Coat!");
        MESSAGE("But it failed!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_COUNTER, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Fighting is a Normal-type move that always changes to a Fighting-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_FIGHTING && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_FIGHTING);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_FIGHTING) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_FIGHTING) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_FIGHTING); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Fighting type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_FIGHTING, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Flying is a Normal-type move that always changes to a Flying-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_FLYING && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_FLYING);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_FLYING) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_FLYING) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_FLYING); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Flying type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_FLYING, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Poison is a Normal-type move that always changes to a Poison-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_POISON && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_POISON);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_POISON) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_POISON) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_POISON); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Poison type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_POISON, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Ground is a Normal-type move that always changes to a Ground-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_GROUND && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_GROUND);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_GROUND) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_GROUND) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_GROUND); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Ground type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_GROUND, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Rock is a Normal-type move that always changes to a Rock-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_ROCK && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_ROCK);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_ROCK) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_ROCK) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_ROCK); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Rock type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_ROCK, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Bug is a Normal-type move that always changes to a Bug-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_BUG && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_BUG);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_BUG) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_BUG) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_BUG); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Bug type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_BUG, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Ghost is a Normal-type move that always changes to a Ghost-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_GHOST && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_GHOST);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_GHOST) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_GHOST) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_GHOST); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Ghost type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_GHOST, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Steel is a Normal-type move that always changes to a Steel-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_STEEL && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_STEEL);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_STEEL) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_STEEL) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_STEEL); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Steel type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_STEEL, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Fire is a Normal-type move that always changes to a Fire-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_FIRE && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_FIRE);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_FIRE) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_FIRE) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_FIRE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Fire type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_FIRE, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Water is a Normal-type move that always changes to a Water-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_WATER && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_WATER);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_WATER) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_WATER) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_WATER); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_WATER, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Grass is a Normal-type move that always changes to a Grass-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_GRASS && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_GRASS);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_GRASS) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_GRASS) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_GRASS); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Grass type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_GRASS, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Electric is a Normal-type move that always changes to a Electric-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_ELECTRIC && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_ELECTRIC);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_ELECTRIC) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_ELECTRIC) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_ELECTRIC); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Electric type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_ELECTRIC, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Psychic is a Normal-type move that always changes to a Psychic-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_PSYCHIC && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_PSYCHIC);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_PSYCHIC) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_PSYCHIC) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_PSYCHIC); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Psychic type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_PSYCHIC, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Ice is a Normal-type move that always changes to a Ice-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_ICE && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_ICE);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_ICE) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_ICE) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_ICE); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Ice type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_ICE, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Dragon is a Normal-type move that always changes to a Dragon-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_DRAGON && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_DRAGON);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_DRAGON) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_DRAGON) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_DRAGON); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Dragon type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_DRAGON, opponent);
    }
}

SINGLE_BATTLE_TEST("Hidden Power Dark is a Normal-type move that always changes to a Dark-type move")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_KECLEON, 0) != TYPE_DARK && GetSpeciesType(SPECIES_KECLEON, 1) != TYPE_DARK);
        ASSUME(GetMoveType(MOVE_HIDDEN_POWER_DARK) == TYPE_NORMAL);
        ASSUME(GetMoveEffect(MOVE_HIDDEN_POWER_DARK) == EFFECT_HIDDEN_POWER);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_HIDDEN_POWER_DARK); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Dark type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HIDDEN_POWER_DARK, opponent);
    }
}
