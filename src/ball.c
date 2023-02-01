#include "include/ball.h"
#include "include/player.h"

void _moveBall(Ball *this) {
  // Position the ball
  this->_posX += this->_velX;
  this->_posY += this->_velY;

  // Check horizontal bounds
  if (this->_posX < LEFT_EDGE) {
    this->_posX = LEFT_EDGE;
    this->_velX = -this->_velX;
  } else if (this->_posX + this->_width > RIGHT_EDGE) {
    this->_posX = RIGHT_EDGE - this->_width;
    this->_velX = -this->_velX;
  }

  // Check vertical bounds
  if (this->_posY < TOP_EDGE) {
    this->_posY = TOP_EDGE;
    this->_velY = -this->_velY;
  } else if (this->_posY + this->_height > BOTTOM_EDGE) {
    game.endGame(&game);
  }

  /*Check for collisions with the player paddle*/
  if (this->_posX<player.getPosX(&player) + PLAYER_WIDTH &&this->_posX +
                  this->_width>
          player.getPosX(&player)) {
    if (this->_posY < PLAYER_POS_Y + PLAYER_HEIGHT &&
        this->_posY + this->_height >= PLAYER_POS_Y) {
      // On collision, invert the velocity
      this->_posY = PLAYER_POS_Y - this->_height - 1;
      this->_velY = -this->_velY;

      // Increase the score and update the HUD
      game.setScore(&game, game.getScore(&game) + 1);
      game.setFlashing(&game, TRUE);
      game.updateScoreDisplay(&game);

      // Make ball faster on every 10th hit
      if (game.getScore(&game) % 10 == 0) {
        this->_velX += sign(this->_velX);
        this->_velY += sign(this->_velY);
      }
    }
  }

  SPR_setPosition(this->sprite, this->_posX, this->_posY);
}

// Setters
void _setBallPosX(Ball *this, int posX) { this->_posX = posX; }
void _setBallPosY(Ball *this, int posY) { this->_posY = posY; }
void _setBallVelX(Ball *this, int velX) { this->_velX = velX; }
void _setBallVelY(Ball *this, int velY) { this->_velY = velY; }
void _setBallWidth(Ball *this, int width) { this->_width = width; }
void _setBallHeight(Ball *this, int height) { this->_height = height; }
void _setBallColor(Ball *this, int color) { this->_color = color; }

// Getters
int _getBallPosX(Ball *this) { return this->_posX; }
int _getBallPosY(Ball *this) { return this->_posY; }
int _getBallVelX(Ball *this) { return this->_velX; }
int _getBallVelY(Ball *this) { return this->_velY; }
int _getBallWidth(Ball *this) { return this->_width; }
int _getBallHeight(Ball *this) { return this->_height; }
int _getBallColor(Ball *this) { return this->_color; }

// Initialization
Ball ball = {._posX = 160 - 4,
             ._posY = 100,
             ._velX = 0,
             ._velY = 0,
             ._width = 8,
             ._height = 8,
             ._color = 0,

             .moveBall = _moveBall,

             .setPosX = _setBallPosX,
             .setPosY = _setBallPosY,
             .setVelX = _setBallVelX,
             .setVelY = _setBallVelY,
             .setWidth = _setBallWidth,
             .setHeight = _setBallHeight,
             .setColor = _setBallColor,

             .getPosX = _getBallPosX,
             .getPosY = _getBallPosY,
             .getVelX = _getBallVelX,
             .getVelY = _getBallVelY,
             .getWidth = _getBallWidth,
             .getHeight = _getBallHeight,
             .getColor = _getBallColor};
