#include "include/player.h"

void _positionPlayer(Player *this) {
  /*Add the player's velocity to its position*/
  this->_pos_x += this->_vel_x;

  /*Keep the player within the bounds of the screen*/
  if (this->_pos_x < LEFT_EDGE)
    this->_pos_x = LEFT_EDGE;
  if (this->_pos_x + PLAYER_WIDTH > RIGHT_EDGE)
    this->_pos_x = RIGHT_EDGE - PLAYER_WIDTH;

  /*Let the Sprite engine position the sprite*/
  SPR_setPosition(this->sprite, this->_pos_x, PLAYER_POS_Y);
}

void _setPosX(Player *this, int pos_x){
  this->_pos_x = pos_x;
}
int _getPosX(Player *this){
  return this->_pos_x;
}

void _setVelX(Player *this, int vel_x){
  this->_vel_x = vel_x;
}
int _getVelX(Player *this){
  return this->_vel_x;
}

// Created just to illustrate how it would be if player did not had to be global
Player* PlayerConstructor(Player *this, int pos_x, int vel_x){
  this->_pos_x = pos_x;
  this->_vel_x = vel_x;

  this->setPosX = _setPosX;
  this->getPosX = _getPosX;

  this->setVelX = _setVelX;
  this->getVelX = _getVelX;

  this->positionPlayer = _positionPlayer;

  return this;
}

Player player = {
  ._pos_x = 144,
  ._vel_x = 0,

  .setPosX = _setPosX,
  .getPosX = _getPosX,
  .setVelX = _setVelX,
  .getVelX = _getVelX,

  .positionPlayer = _positionPlayer
};

