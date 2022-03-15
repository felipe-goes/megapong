#include "include/game.h"

u8 game_on = FALSE;
char msg_start[22] = "PRESS START TO BEGIN!\0";
char msg_reset[38] = "GAME OVER! PRESS START TO PLAY AGAIN.\0";

// Juice
int flashing = FALSE;
int frames = 0;
int ball_color = 0;

/*Score variables*/
int score = 0;
char label_score[6] = "SCORE\0";
char str_score[4] = "0";

void startGame(void) {
  score = 0;
  updateScoreDisplay();

  ball.setPosX(&ball, 0);
  ball.setPosY(&ball, 0);

  ball.setVelX(&ball, 1);
  ball.setVelY(&ball, 1);

  /*Clear the text from the screen*/
  VDP_clearTextArea(0, 10, 40, 10);

  game_on = TRUE;
}

void endGame(void) {
  showText(msg_reset);
  game_on = FALSE;
}

void updateScoreDisplay(void) {
  sprintf(str_score, "%d", score);
  VDP_clearText(1, 2, 3);
  VDP_drawText(str_score, 1, 2);
}
