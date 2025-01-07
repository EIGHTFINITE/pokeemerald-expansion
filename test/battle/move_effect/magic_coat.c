#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_MAGIC_COAT) == EFFECT_MAGIC_COAT);
}

SINGLE_BATTLE_TEST("Magic Coat prints the correct message when bouncing back a move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        PLAYER(SPECIES_ZIGZAGOON);
        #if B_SLEEP_CLAUSE == FALSE
        PLAYER(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_ZIGZAGOON);
        #endif
        OPPONENT(SPECIES_ZIGZAGOON);
    } WHEN {
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPORE); }
        #if B_SLEEP_CLAUSE == FALSE
        TURN { SWITCH(opponent, 1); }
        TURN { MOVE(player, MOVE_MAGIC_COAT); MOVE(opponent, MOVE_SPORE); }
        #endif
    } SCENE {
        #if B_SLEEP_CLAUSE == FALSE
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("Zigzagoon bounced the Spore back!");
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
        #endif
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAGIC_COAT, player);
        MESSAGE("Zigzagoon bounced the Spore back!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("The opposing Zigzagoon fell asleep!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}
