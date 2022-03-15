#include "include/joystick.h"

void myJoyHandler(u16 joy, u16 changed, u16 state) {
  if (joy == JOY_1) {
    if (state & BUTTON_START) {
      if (!game_on) {
        startGame();
      }
    }

    /*Set player velocity if left or right are pressed;
     *set velocity to 0 if no direction is pressed */
    if (state & BUTTON_RIGHT) {
      player.setVelX(&player, 3);
    } else if (state & BUTTON_LEFT) {
      player.setVelX(&player, -3);
    } else {
      if ((changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT)) {
        player.setVelX(&player, 0);
      }
    }
  }
}
