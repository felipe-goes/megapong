#include "include/player.h"

Player player;

void PlayerConstructor(int pos_x, int vel_x){
  player.pos_x = pos_x;
  player.vel_x = vel_x;
}

void positionPlayer(void) {
  /*Add the player's velocity to its position*/
  player.pos_x += player.vel_x;

  /*Keep the player within the bounds of the screen*/
  if (player.pos_x < LEFT_EDGE)
    player.pos_x = LEFT_EDGE;
  if (player.pos_x + PLAYER_WIDTH > RIGHT_EDGE)
    player.pos_x = RIGHT_EDGE - PLAYER_WIDTH;

  /*Let the Sprite engine position the sprite*/
  SPR_setPosition(player.sprite, player.pos_x, PLAYER_POS_Y);
}
