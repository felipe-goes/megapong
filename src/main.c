#include <genesis.h>
#include <resources.h>

#include "include/player.h"
#include "include/game.h"
#include "include/aux.h"
#include "include/ball.h"
#include "include/joystick.h"

int main() {
  // Init system
  JOY_init();
  JOY_setEventHandler(&myJoyHandler);
  // I think this got deprecated and now you should not pass any argument
  // SPR_init(0, 0, 0);
  SPR_init();

  VDP_loadTileSet(bgtile.tileset, 1, DMA);
  VDP_setPalette(PAL1, bgtile.palette->data);

  /*Draw the texts*/
  VDP_setTextPlane(BG_A);
  VDP_drawText(game.getLabelScore(&game), 1, 1);
  showText(game.getMsgStart(&game));
  game.updateScoreDisplay(&game);

  VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, 1), 0, 0, 40,
                      30);

  // Create sprite variables
  ball.sprite =
    SPR_addSprite(&imgball, ball.getPosX(&ball), ball.getPosY(&ball),
                  TILE_ATTR(PAL1, 0, FALSE, FALSE));
  ball.setColor(&ball, VDP_getPaletteColor(22));

  player.sprite = SPR_addSprite(&paddle, player.getPosX(&player), PLAYER_POS_Y,
                                TILE_ATTR(PAL1, 0, FALSE, FALSE));

  // Game loop
  int newFrame; // variable for the game loop

  while (1) {
    if (game.getOn(&game)) {
      ball.moveBall(&ball);
      player.positionPlayer(&player);

      // Handle the flashing of the ball
      if (game.getFlashing(&game)) {
        newFrame = game.getFrames(&game) + 1;
        game.setFrames(&game, newFrame);

        if (game.getFrames(&game) % 4 == 0) {
          VDP_setPaletteColor(22, ball.getColor(&ball));
        } else if (game.getFrames(&game) % 2 == 0) {
          VDP_setPaletteColor(22, RGB24_TO_VDPCOLOR(0xffffff));
        }

        // Stop flashing
        if (game.getFrames(&game) > 16) {
          game.setFlashing(&game, FALSE);
          game.setFrames(&game, 0);
        }
      }
    }

    SPR_update();
    SYS_doVBlankProcess();
  }

  return 0;
}
