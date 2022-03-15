#pragma once

#ifndef __GAME_CONST__
#define __GAME_CONST__

#include <genesis.h>
#include <string.h>

#include "ball.h"
#include "aux.h"

extern u8 game_on;
extern char msg_start[22];
extern char msg_reset[38];

// Juice
extern int flashing;
extern int frames;
extern int ball_color;

/*Score variables*/
extern int score;
extern char label_score[6];
extern char str_score[4];

// The edges of the play field
#define LEFT_EDGE 0
#define RIGHT_EDGE 320
#define TOP_EDGE 0
#define BOTTOM_EDGE 224

extern void startGame(void);
extern void endGame(void);
extern void updateScoreDisplay(void);

#endif // __GAME_CONST__
