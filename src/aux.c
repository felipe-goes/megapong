#include "include/aux.h"

/*Draws text in the center of the screen*/
void showText(char s[]) { VDP_drawText(s, 20 - strlen(s) / 2, 15); }
