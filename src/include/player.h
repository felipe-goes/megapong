#pragma once

#ifndef PLAYER
#define PLAYER

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
  int _pos_x;
  int _vel_x;
} Player;

extern Player* PlayerConstructor(Player *this, int pos_x, int vel_x);
extern Player player;

extern void _setPosX(Player *this, int pos_x);
extern int _getPosX(Player *this);

extern void _setVelX(Player *this, int vel_x);
extern int _getVelX(Player *this);

extern void _positionPlayer(Player *this);

#endif // PLAYER
