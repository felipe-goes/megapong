#pragma once

#ifndef _BALL_
#define _BALL_

#include <genesis.h>

#include "game.h"
#include "player.h"
#include "aux.h"

typedef struct BALL_STRUCT Ball;
typedef struct BALL_STRUCT
{
  // public
  Sprite *sprite;
  void (*moveBall)(Ball *this);

  void (*setPosX)(Ball *this, int posX);
  void (*setPosY)(Ball *this, int posY);
  void (*setVelX)(Ball *this, int velX);
  void (*setVelY)(Ball *this, int velY);
  void (*setWidth)(Ball *this, int width);
  void (*setHeight)(Ball *this, int height);

  int (*getPosX)(Ball *this);
  int (*getPosY)(Ball *this);
  int (*getVelX)(Ball *this);
  int (*getVelY)(Ball *this);
  int (*getWidth)(Ball *this);
  int (*getHeight)(Ball *this);

  // private
  int _posX;
  int _posY;
  int _velX;
  int _velY;
  int _width;
  int _height;
} Ball;

extern Ball ball;

extern void _moveBall(Ball *this);

extern void _setBallPosX(Ball *this, int posX);
extern void _setBallPosY(Ball *this, int posY);
extern void _setBallVelX(Ball *this, int velX);
extern void _setBallVelY(Ball *this, int velY);
extern void _setBallWidth(Ball *this, int width);
extern void _setBallHeight(Ball *this, int height);

extern int _getBallPosX(Ball *this);
extern int _getBallPosY(Ball *this);
extern int _getBallVelX(Ball *this);
extern int _getBallVelY(Ball *this);
extern int _getBallWidth(Ball *this);
extern int _getBallHeight(Ball *this);

#endif // _BALL_
