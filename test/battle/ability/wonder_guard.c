#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("TODO: Write Wonder Guard (Ability) test titles")

DOUBLE_BATTLE_TEST("Mystery type attacks bypass Wonder Guard")
{
    u32 move;
    PARAMETRIZE { move = MOVE_WIDE_SLASH; }
    PARAMETRIZE { move = MOVE_VACUUM_CUT; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_WIDE_SLASH) == TYPE_MYSTERY);
        ASSUME(GetMoveType(MOVE_VACUUM_CUT) == TYPE_MYSTERY);
        ASSUME(GetMoveTarget(MOVE_WIDE_SLASH) == MOVE_TARGET_BOTH);
        ASSUME(GetMoveTarget(MOVE_VACUUM_CUT) == MOVE_TARGET_BOTH);
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, move); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_WONDER_GUARD);
            ABILITY_POPUP(playerRight, ABILITY_WONDER_GUARD);
        }
        MESSAGE("Shedinja fainted!");
        MESSAGE("Shedinja fainted!");
    }
}
