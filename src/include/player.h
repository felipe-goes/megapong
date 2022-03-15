#pragma once

#ifndef _PLAYER_
#define _PLAYER_

#include <genesis.h>
#include "game.h"

// Player's attributes
#define PLAYER_POS_Y 200
#define PLAYER_WIDTH 32
#define PLAYER_HEIGHT 8

typedef struct PLAYER_STRUCT Player;
typedef struct PLAYER_STRUCT{
  // public
  Sprite *sprite;
  void (*positionPlayer)(Player *this);

  void (*setPosX)(Player *this, int pos_x);
  int (*getPosX)(Player *this);

  void (*setVelX)(Player *this, int vel_x);
  int (*getVelX)(Player *this);

  // private
  int _posX;
  int _velX;
} Player;

extern Player* PlayerConstructor(Player *this, int pos_x, int vel_x);
extern Player player;

extern void _setPlayerPosX(Player *this, int pos_x);
extern int _getPlayerPosX(Player *this);

extern void _setPlayerVelX(Player *this, int vel_x);
extern int _getPlayerVelX(Player *this);

extern void _positionPlayer(Player *this);

#endif // _PLAYER_
