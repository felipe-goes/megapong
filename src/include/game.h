#pragma once

#ifndef _GAME_CONST_
#define _GAME_CONST_

#include <genesis.h>
#include <string.h>

#include "ball.h"
#include "aux.h"

// The edges of the play field
#define LEFT_EDGE 0
#define RIGHT_EDGE 320
#define TOP_EDGE 0
#define BOTTOM_EDGE 224

typedef struct GAME_STRUCT Game;
typedef struct GAME_STRUCT {
  // public
  void (*startGame)(Game *this);
  void (*endGame)(Game *this);
  void (*updateScoreDisplay)(Game *this);

  void (*setOn)(Game *this, u8 on);
  void (*setMsgStart)(Game *this, char *msgStart);
  void (*setMsgReset)(Game *this, char *msgReset);
  void (*setFlashing)(Game *this, int flashing);
  void (*setFrames)(Game *this, int frames);
  void (*setScore)(Game *this, int score);
  void (*setLabelScore)(Game *this, char *labelScore);
  void (*setStrScore)(Game *this, char *strScore);

  u8 (*getOn)(Game *this);
  char *(*getMsgStart)(Game *this);
  char *(*getMsgReset)(Game *this);
  int (*getFlashing)(Game *this);
  int (*getFrames)(Game *this);
  int (*getScore)(Game *this);
  char *(*getLabelScore)(Game *this);
  char *(*getStrScore)(Game *this);

  // private
  u8 _on;
  char _msgStart[22];
  char _msgReset[38];

  int _flashing;
  int _frames;

  // Score variables
  int _score;
  char _labelScore[6];
  char _strScore[4];

} Game;

extern void _startGame(Game *this);
extern void _endGame(Game *this);
extern void _updateScoreDisplay(Game *this);

extern void _setGameOn(Game *this, u8 on);
extern void _setGameMsgStart(Game *this, char *msgStart);
extern void _setGameMsgReset(Game *this, char *msgReset);
extern void _setGameFlashing(Game *this, int flashing);
extern void _setGameFrames(Game *this, int frames);
extern void _setGameScore(Game *this, int score);
extern void _setGameLabelScore(Game *this, char *labelScore);
extern void _setGameStrScore(Game *this, char *strScore);

extern u8 _getGameOn(Game *this);
extern char *_getGameMsgStart(Game *this);
extern char *_getGameMsgReset(Game *this);
extern int _getGameFlashing(Game *this);
extern int _getGameFrames(Game *this);
extern int _getGameScore(Game *this);
extern char *_getGameLabelScore(Game *this);
extern char *_getGameStrScore(Game *this);

extern Game game;

#endif // _GAME_CONST_
