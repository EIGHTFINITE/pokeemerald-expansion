#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Wonder Guard activates when targeted by moves not super effective against it")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_POUND; }
    PARAMETRIZE { move = MOVE_WATER_GUN; }
    PARAMETRIZE { move = MOVE_THUNDERSHOCK; }
    PARAMETRIZE { move = MOVE_LEAFAGE; }
    PARAMETRIZE { move = MOVE_POWDER_SNOW; }
    PARAMETRIZE { move = MOVE_KARATE_CHOP; }
    PARAMETRIZE { move = MOVE_SLUDGE; }
    PARAMETRIZE { move = MOVE_MUD_SLAP; }
    PARAMETRIZE { move = MOVE_CONFUSION; }
    PARAMETRIZE { move = MOVE_BUG_BITE; }
    PARAMETRIZE { move = MOVE_DRAGONBREATH; }
    PARAMETRIZE { move = MOVE_METAL_CLAW; }
    PARAMETRIZE { move = MOVE_FAIRY_WIND; }
    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_WONDER_GUARD);
        MESSAGE("It doesn't affect Shedinja…");
    }
}

SINGLE_BATTLE_TEST("Wonder Guard does not activate when targeted by moves super effective against it")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_EMBER; }
    PARAMETRIZE { move = MOVE_PECK; }
    PARAMETRIZE { move = MOVE_ROCK_THROW; }
    PARAMETRIZE { move = MOVE_ASTONISH; }
    PARAMETRIZE { move = MOVE_PURSUIT; }
    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        MESSAGE("It's super effective!");
        MESSAGE("Shedinja fainted!");
    }
}

DOUBLE_BATTLE_TEST("Mystery type attacks bypass Wonder Guard")
{
    u32 move;
    PARAMETRIZE { move = MOVE_VACUUM_CUT; }
    PARAMETRIZE { move = MOVE_WIDE_SLASH; }
    GIVEN {
        ASSUME(GetMoveType(MOVE_VACUUM_CUT) == TYPE_MYSTERY);
        ASSUME(GetMoveType(MOVE_WIDE_SLASH) == TYPE_MYSTERY);
        ASSUME(GetMoveTarget(MOVE_VACUUM_CUT) == TARGET_BOTH);
        ASSUME(GetMoveTarget(MOVE_WIDE_SLASH) == TARGET_BOTH);
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
