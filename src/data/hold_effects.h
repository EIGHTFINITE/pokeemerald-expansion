const struct HoldEffectInfo gHoldEffectsInfo[HOLD_EFFECT_COUNT] =
{
    [HOLD_EFFECT_NONE] =
    {
    },

    [HOLD_EFFECT_RESTORE_HP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CURE_PAR] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_CURE_SLP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_CURE_PSN] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_CURE_BRN] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_CURE_FRZ] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_RESTORE_PP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onAttackerAfterHit = TRUE,
    },

    [HOLD_EFFECT_CURE_CONFUSION] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_CURE_STATUS] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onStatusChange = TRUE,
    },

    [HOLD_EFFECT_CONFUSE_SPICY] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CONFUSE_DRY] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CONFUSE_SWEET] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CONFUSE_BITTER] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CONFUSE_SOUR] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_ATTACK_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_DEFENSE_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_SPEED_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_SP_ATTACK_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_SP_DEFENSE_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CRITICAL_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_RANDOM_STAT_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_EVASION_UP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_WHITE_HERB] =
    {
        .whiteHerb = TRUE,
        .whiteHerbFirstTurn = TRUE,
        .whiteHerbEndTurn = TRUE,
        .onFling = TRUE,
    },

    [HOLD_EFFECT_MACHO_BRACE] =
    {
    },

    [HOLD_EFFECT_EXP_SHARE] =
    {
    },

    [HOLD_EFFECT_QUICK_CLAW] =
    {
    },

    [HOLD_EFFECT_FRIENDSHIP_UP] =
    {
    },

    [HOLD_EFFECT_MENTAL_HERB] =
    {
        .onTargetAfterHit = TRUE,
        .onAttackerAfterHit = TRUE,
        .onFling = TRUE,
    },

    [HOLD_EFFECT_CHOICE_BAND] =
    {
    },

    [HOLD_EFFECT_FLINCH] =
    {
        .onAttackerAfterHit = TRUE,
    },

    [HOLD_EFFECT_DOUBLE_PRIZE] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
    },

    [HOLD_EFFECT_REPEL] =
    {
    },

    [HOLD_EFFECT_SOUL_DEW] =
    {
    },

    [HOLD_EFFECT_DEEP_SEA_TOOTH] =
    {
    },

    [HOLD_EFFECT_DEEP_SEA_SCALE] =
    {
    },

    [HOLD_EFFECT_CAN_ALWAYS_RUN] =
    {
    },

    [HOLD_EFFECT_PREVENT_EVOLVE] =
    {
    },

    [HOLD_EFFECT_FOCUS_BAND] =
    {
    },

    [HOLD_EFFECT_LUCKY_EGG] =
    {
    },

    [HOLD_EFFECT_SCOPE_LENS] =
    {
    },

    [HOLD_EFFECT_LEFTOVERS] =
    {
        .leftovers = TRUE,
    },

    [HOLD_EFFECT_DRAGON_SCALE] =
    {
    },

    [HOLD_EFFECT_LIGHT_BALL] =
    {
    },

    [HOLD_EFFECT_TYPE_POWER] =
    {
    },

    [HOLD_EFFECT_UPGRADE] =
    {
    },

    [HOLD_EFFECT_SHELL_BELL] =
    {
        .lifeOrbShellBell = TRUE,
    },

    [HOLD_EFFECT_LUCKY_PUNCH] =
    {
    },

    [HOLD_EFFECT_METAL_POWDER] =
    {
    },

    [HOLD_EFFECT_THICK_CLUB] =
    {
    },

    [HOLD_EFFECT_LEEK] =
    {
    },

    [HOLD_EFFECT_CHOICE_SCARF] =
    {
    },

    [HOLD_EFFECT_CHOICE_SPECS] =
    {
    },

    [HOLD_EFFECT_DAMP_ROCK] =
    {
    },

    [HOLD_EFFECT_GRIP_CLAW] =
    {
    },

    [HOLD_EFFECT_HEAT_ROCK] =
    {
    },

    [HOLD_EFFECT_ICY_ROCK] =
    {
    },

    [HOLD_EFFECT_LIGHT_CLAY] =
    {
    },

    [HOLD_EFFECT_SMOOTH_ROCK] =
    {
    },

    [HOLD_EFFECT_POWER_HERB] =
    {
    },

    [HOLD_EFFECT_BIG_ROOT] =
    {
    },

    [HOLD_EFFECT_EXPERT_BELT] =
    {
    },

    [HOLD_EFFECT_LIFE_ORB] =
    {
        .lifeOrbShellBell = TRUE,
    },

    [HOLD_EFFECT_METRONOME] =
    {
    },

    [HOLD_EFFECT_MUSCLE_BAND] =
    {
    },

    [HOLD_EFFECT_WIDE_LENS] =
    {
    },

    [HOLD_EFFECT_WISE_GLASSES] =
    {
    },

    [HOLD_EFFECT_ZOOM_LENS] =
    {
    },

    [HOLD_EFFECT_LAGGING_TAIL] =
    {
    },

    [HOLD_EFFECT_FOCUS_SASH] =
    {
    },

    [HOLD_EFFECT_FLAME_ORB] =
    {
        .orbs = TRUE,
    },

    [HOLD_EFFECT_TOXIC_ORB] =
    {
        .orbs = TRUE,
    },

    [HOLD_EFFECT_STICKY_BARB] =
    {
        .onTargetAfterHit = TRUE,
        .orbs = TRUE,
    },

    [HOLD_EFFECT_IRON_BALL] =
    {
    },

    [HOLD_EFFECT_BLACK_SLUDGE] =
    {
        .leftovers = TRUE,
    },

    [HOLD_EFFECT_DESTINY_KNOT] =
    {
    },

    [HOLD_EFFECT_SHED_SHELL] =
    {
    },

    [HOLD_EFFECT_QUICK_POWDER] =
    {
    },

    [HOLD_EFFECT_ADAMANT_ORB] =
    {
    },

    [HOLD_EFFECT_LUSTROUS_ORB] =
    {
    },

    [HOLD_EFFECT_GRISEOUS_ORB] =
    {
    },

    [HOLD_EFFECT_ENIGMA_BERRY] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_RESIST_BERRY] =
    {
    },

    [HOLD_EFFECT_POWER_ITEM] =
    {
    },

    [HOLD_EFFECT_RESTORE_PCT_HP] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_MICLE_BERRY] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onHpThreshold = TRUE,
    },

    [HOLD_EFFECT_CUSTAP_BERRY] =
    {
    },

    [HOLD_EFFECT_JABOCA_BERRY] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_ROWAP_BERRY] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_KEE_BERRY] =
    {
        .keeMarangaBerry = TRUE,
    },

    [HOLD_EFFECT_MARANGA_BERRY] =
    {
        .keeMarangaBerry = TRUE,
    },

    [HOLD_EFFECT_PLATE] =
    {
    },

    [HOLD_EFFECT_FLOAT_STONE] =
    {
    },

    [HOLD_EFFECT_EVIOLITE] =
    {
    },

    [HOLD_EFFECT_ASSAULT_VEST] =
    {
    },

    [HOLD_EFFECT_DRIVE] =
    {
    },

    [HOLD_EFFECT_GEMS] =
    {
    },

    [HOLD_EFFECT_ROCKY_HELMET] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_AIR_BALLOON] =
    {
        .onTargetAfterHit = TRUE,
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
    },

    [HOLD_EFFECT_RED_CARD] =
    {
    },

    [HOLD_EFFECT_RING_TARGET] =
    {
    },

    [HOLD_EFFECT_BINDING_BAND] =
    {
    },

    [HOLD_EFFECT_EJECT_BUTTON] =
    {
    },

    [HOLD_EFFECT_ABSORB_BULB] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_CELL_BATTERY] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_MEGA_STONE] =
    {
    },

    [HOLD_EFFECT_SAFETY_GOGGLES] =
    {
    },

    [HOLD_EFFECT_LUMINOUS_MOSS] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_SNOWBALL] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_WEAKNESS_POLICY] =
    {
        .onTargetAfterHit = TRUE,
    },

    [HOLD_EFFECT_PRIMAL_ORB] =
    {
    },

    [HOLD_EFFECT_PROTECTIVE_PADS] =
    {
    },

    [HOLD_EFFECT_TERRAIN_EXTENDER] =
    {
    },

    [HOLD_EFFECT_TERRAIN_SEED] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onEffect = TRUE,
    },

    [HOLD_EFFECT_ADRENALINE_ORB] =
    {
    },

    [HOLD_EFFECT_MEMORY] =
    {
    },

    [HOLD_EFFECT_Z_CRYSTAL] =
    {
    },

    [HOLD_EFFECT_UTILITY_UMBRELLA] =
    {
    },

    [HOLD_EFFECT_EJECT_PACK] =
    {
    },

    [HOLD_EFFECT_ROOM_SERVICE] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onEffect = TRUE,
    },

    [HOLD_EFFECT_BLUNDER_POLICY] =
    {
        .onAttackerAfterHit = TRUE,
    },

    [HOLD_EFFECT_HEAVY_DUTY_BOOTS] =
    {
    },

    [HOLD_EFFECT_THROAT_SPRAY] =
    {
        .onAttackerAfterHit = TRUE,
    },

    [HOLD_EFFECT_ABILITY_SHIELD] =
    {
    },

    [HOLD_EFFECT_CLEAR_AMULET] =
    {
    },

    [HOLD_EFFECT_MIRROR_HERB] =
    {
        .mirrorHerb = TRUE,
        .mirrorHerbFirstTurn = TRUE,
    },

    [HOLD_EFFECT_PUNCHING_GLOVE] =
    {
    },

    [HOLD_EFFECT_COVERT_CLOAK] =
    {
    },

    [HOLD_EFFECT_LOADED_DICE] =
    {
    },

    [HOLD_EFFECT_BOOSTER_ENERGY] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
        .onEffect = TRUE,
    },

    [HOLD_EFFECT_OGERPON_MASK] =
    {
    },

    [HOLD_EFFECT_BERSERK_GENE] =
    {
        .onSwitchIn = TRUE,
        .onSwitchInFirstTurn = TRUE,
    },
};
