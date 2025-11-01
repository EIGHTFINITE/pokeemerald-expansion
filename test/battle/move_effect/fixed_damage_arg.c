#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_SONIC_BOOM) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveEffect(MOVE_VACUUM_CUT) == EFFECT_FIXED_HP_DAMAGE);
    ASSUME(GetMoveType(MOVE_VACUUM_CUT) == TYPE_MYSTERY);
    ASSUME(GetMoveTarget(MOVE_VACUUM_CUT) == MOVE_TARGET_BOTH);
}

SINGLE_BATTLE_TEST("Sonic Boom deals fixed damage", s16 damage)
{
    u16 mon;
    PARAMETRIZE { mon = SPECIES_RATTATA; }
    PARAMETRIZE { mon = SPECIES_ARON; }

    GIVEN {
        ASSUME(GetMoveFixedHPDamage(MOVE_SONIC_BOOM) == 20);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(mon);
    } WHEN {
        TURN { MOVE(player, MOVE_SONIC_BOOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT(results[0].damage == 20);
        EXPECT(results[1].damage == 20);
    }
}

TO_DO_BATTLE_TEST("Sonic Boom affects ghost types (Gen1)")

SINGLE_BATTLE_TEST("Sonic Boom doesn't affect ghost types (Gen2+)")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GASTLY);
    } WHEN {
        TURN { MOVE(player, MOVE_SONIC_BOOM); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, player);
        MESSAGE("It doesn't affect the opposing Gastly…");
    }
}

DOUBLE_BATTLE_TEST("Vacuum-Cut bypasses Wonder Guard")
{
    GIVEN {
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        PLAYER(SPECIES_SHEDINJA) { Ability(ABILITY_WONDER_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_VACUUM_CUT); }
    } SCENE {
        NONE_OF {
            ABILITY_POPUP(playerLeft, ABILITY_WONDER_GUARD);
            ABILITY_POPUP(playerRight, ABILITY_WONDER_GUARD);
        }
        MESSAGE("Shedinja fainted!");
        MESSAGE("Shedinja fainted!");
    }
}
