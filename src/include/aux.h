#pragma once

#ifndef _AUX_
#define _AUX_

#include <genesis.h>

inline int sign(int x) { return (x > 0) - (x < 0); }

/*Draws text in the center of the screen*/
extern void showText(char s[]);

#endif // __AUX__
