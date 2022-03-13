#pragma once

#ifndef __PLAYER__
#define __PLAYER__

#include <genesis.h>
#include "include/game.h"

// Player's attributes
#define PLAYER_POS_Y 200
#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 8

typedef struct{
  Sprite *sprite;

  int pos_x;
  int vel_x;
} Player; // player

extern Player player;
extern void positionPlayer(void);
extern void PlayerConstructor(int pos_x, int vel_x);

#endif // __PLAYER__
