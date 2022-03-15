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
    SPR_init(0, 0, 0);

    VDP_loadTileSet(bgtile.tileset, 1, DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);

    /*Draw the texts*/
    VDP_setTextPlane(BG_A);
    VDP_drawText(label_score, 1, 1);
    showText(msg_start);
    updateScoreDisplay();

    VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL1, 0, FALSE, FALSE, 1), 0, 0,
                        40, 30);

    // Create sprite variables
    ball.sprite =
        SPR_addSprite(&imgball, ball.getPosX(&ball), ball.getPosY(&ball),
                      TILE_ATTR(PAL1, 0, FALSE, FALSE));
    ball_color = VDP_getPaletteColor(22);

    player.sprite =
        SPR_addSprite(&paddle, player.getPosX(&player), PLAYER_POS_Y,
                      TILE_ATTR(PAL1, 0, FALSE, FALSE));

    // Game loop
    while (1) {
        if (game_on == TRUE) {
            ball.moveBall(&ball);
            player.positionPlayer(&player);

            // Handle the flashing of the ball
            if (flashing == TRUE) {
                frames++;

                if (frames % 4 == 0) {
                    VDP_setPaletteColor(22, ball_color);
                } else if (frames % 2 == 0) {
                    VDP_setPaletteColor(22, RGB24_TO_VDPCOLOR(0xffffff));
                }

                // Stop flashing
                if (frames > 16) {
                    flashing = FALSE;
                    frames = 0;
                }
            }
        }

        SPR_update();
        SYS_doVBlankProcess();
    }

    return 0;
}
