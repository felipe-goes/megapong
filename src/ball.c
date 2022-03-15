#include "include/ball.h"
#include "include/player.h"

Sprite *ball;

// Ball's attributes
int ball_pos_x = 100;
int ball_pos_y = 100;
int ball_vel_x = 1;
int ball_vel_y = 1;
int ball_width = 8;
int ball_height = 8;

void moveBall() {
  // Position the ball
  ball_pos_x += ball_vel_x;
  ball_pos_y += ball_vel_y;

  // Check horizontal bounds
  if (ball_pos_x < LEFT_EDGE) {
    ball_pos_x = LEFT_EDGE;
    ball_vel_x = -ball_vel_x;
  } else if (ball_pos_x + ball_width > RIGHT_EDGE) {
    ball_pos_x = RIGHT_EDGE - ball_width;
    ball_vel_x = -ball_vel_x;
  }

  // Check vertical bounds
  if (ball_pos_y < TOP_EDGE) {
    ball_pos_y = TOP_EDGE;
    ball_vel_y = -ball_vel_y;
  } else if (ball_pos_y + ball_height > BOTTOM_EDGE) {
    endGame();
  }

  /*Check for collisions with the player paddle*/
  if (ball_pos_x < player.getPosX(&player) + PLAYER_WIDTH &&
      ball_pos_x + ball_width > player.getPosX(&player)) {
    if (ball_pos_y < PLAYER_POS_Y + PLAYER_HEIGHT &&
        ball_pos_y + ball_height >= PLAYER_POS_Y) {
      // On collision, invert the velocity
      ball_pos_y = PLAYER_POS_Y - ball_height - 1;
      ball_vel_y = -ball_vel_y;

      // Increase the score and update the HUD
      score++;
      flashing = TRUE;
      updateScoreDisplay();

      // Make ball faster on every 10th hit
      if (score % 10 == 0) {
        ball_vel_x += sign(ball_vel_x);
        ball_vel_y += sign(ball_vel_y);
      }
    }
  }

  SPR_setPosition(ball, ball_pos_x, ball_pos_y);
}
