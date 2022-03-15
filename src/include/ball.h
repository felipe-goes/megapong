#pragma once

#ifndef __BALL__
#define __BALL__

#include <genesis.h>

#include "game.h"
#include "player.h"
#include "aux.h"

extern Sprite *ball;

// Ball's attributes
extern int ball_pos_x;
extern int ball_pos_y;
extern int ball_vel_x;
extern int ball_vel_y;
extern int ball_width;
extern int ball_height;

extern void moveBall();

#endif // __BALL__
