#pragma once

#ifndef __JOYSTICK__
#define __JOYSTICK__

#include <genesis.h>

#include "game.h"
#include "player.h"

extern void myJoyHandler(u16 joy, u16 changed, u16 state);

#endif // __JOYSTICK__
