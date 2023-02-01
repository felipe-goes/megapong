#include "include/player.h"

void _positionPlayer(Player *this) {
  /*Add the player's velocity to its position*/
  this->_posX += this->_velX;

  /*Keep the player within the bounds of the screen*/
  if (this->_posX < LEFT_EDGE)
    this->_posX = LEFT_EDGE;
  if (this->_posX + PLAYER_WIDTH > RIGHT_EDGE)
    this->_posX = RIGHT_EDGE - PLAYER_WIDTH;

  /*Let the Sprite engine position the sprite*/
  SPR_setPosition(this->sprite, this->_posX, PLAYER_POS_Y);
}

void _setPlayerPosX(Player *this, int pos_x) { this->_posX = pos_x; }
int _getPlayerPosX(Player *this) { return this->_posX; }

void _setPlayerVelX(Player *this, int vel_x) { this->_velX = vel_x; }
int _getPlayerVelX(Player *this) { return this->_velX; }

// Created just to illustrate how it would be if player did not had to be global
Player *PlayerConstructor(Player *this, int pos_x, int vel_x) {
  this->_posX = pos_x;
  this->_velX = vel_x;

  this->setPosX = _setPlayerPosX;
  this->getPosX = _getPlayerPosX;

  this->setVelX = _setPlayerVelX;
  this->getVelX = _getPlayerVelX;

  this->positionPlayer = _positionPlayer;

  return this;
}

// Initialization
Player player = {._posX = 144,
                 ._velX = 0,

                 .setPosX = _setPlayerPosX,
                 .getPosX = _getPlayerPosX,
                 .setVelX = _setPlayerVelX,
                 .getVelX = _getPlayerVelX,

                 .positionPlayer = _positionPlayer};
