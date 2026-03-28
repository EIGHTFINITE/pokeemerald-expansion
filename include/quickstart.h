#ifndef GUARD_QUICKSTART_H
#define GUARD_QUICKSTART_H

#include "config/quickstart.h"

#if RELEASE
    #define QUICKSTART FALSE
#else
    #define QUICKSTART ENABLE_QUICKSTART
#endif

void CreateQuickstartHud(s16 x, s16 y);
void Quickstart(void);

#endif // GUARD_QUICKSTART_H
