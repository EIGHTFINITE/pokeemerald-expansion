#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Protean changes the type of the user to the move used every time (Gen6-8)")
{
    GIVEN {
        WITH_CONFIG(GEN_PROTEAN_LIBERO, GEN_6);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Normal type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
    }
}

SINGLE_BATTLE_TEST("Protean changes the type of the user only once per switch in (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(GEN_PROTEAN_LIBERO, GEN_9);
        PLAYER(SPECIES_REGIROCK);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
        TURN { MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PROTEAN);
            MESSAGE("The opposing Kecleon transformed into the Normal type!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        ABILITY_POPUP(opponent, ABILITY_PROTEAN);
        MESSAGE("The opposing Kecleon transformed into the Water type!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
    }
}

SINGLE_BATTLE_TEST("Protean does not change the type of the user to Mystery type")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_WIDE_SLASH) == TYPE_MYSTERY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_KECLEON) { Ability(ABILITY_PROTEAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_WIDE_SLASH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_SLASH, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_PROTEAN);
            MESSAGE("The opposing Kecleon transformed into the ??? type!");
        }
    }
}
