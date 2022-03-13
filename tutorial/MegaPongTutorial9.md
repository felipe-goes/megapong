# MegaPong 9 - Game Over

## Making Things Easier for Us

First, let’s make things a bit easier for ourselves. We’ll have to show some
messages on screen soon and we can create the following helper function to help
us out:

````
/*Draws text in the center of the screen*/
void showText(char s[]){
	VDP_drawText(s, 20 - strlen(s)/2 ,15);
}
```

As you can see, this function takes a string (that is, a `char[]`) and then
draws this string in the center of the screen using `VDP_drawText` and the power
of math. This spares us from always having to specify the x- and y-positions of
the text we want to draw.

## Game Over

Now to implement a fail state. We’ll need a global variable to track the current
game state, so let’s define one (outside of `main()`). We’ll also take this
opportunity to write and store the messages we want displayed when the game
starts/ends. Put these lines somehwere at the top of `main.c` near your other
variable definitions:

```
game_on = FALSE;
char msg_start[22] = "PRESS START TO BEGIN!\0";
char msg_reset[37] = "GAME OVER! PRESS START TO PLAY AGAIN.";
```

Now to define what should happen when the game ends, that is when the ball is
lost. We’ll do that in a function:

```
void endGame(){
	showText(msg_reset);
	game_on = FALSE;
}
```

Define this function after `showText()` since we’re using it in this one! The
function should be pretty self-explanatory: We display our reset message, then
set `game_on` to `FALSE`. So when does the game end? When the ball hits the lower
bound of the screen, so we’ll call this function in `moveBall()`. Replace the
following lines…

```
} else if(ball_pos_y + ball_height > BOTTOM_EDGE){
	ball_pos_y = BOTTOM_EDGE - ball_height;
	ball_vel_y = -ball_vel_y;
}
```

…with this one:

```
else if(ball_pos_y + ball_height > BOTTOM_EDGE){
	endGame();
}
```

Now the ball won’t bounce off the bottom edge anymore, meaning players can
actually lose!

## Starting

That’s the ending taken care of, but a game also needs a proper beginning. Right
now the game starts the moment you open it, which isn’t ideal. But that's where
our `game_on` variable will come in handy once again! Let’s define a counterpart
function to `endGame()`:

```
void startGame(){
	score = 0;
	updateScoreDisplay();

	ball_pos_x = 0;
	ball_pos_y = 0;

	ball_vel_x = 1;
	ball_vel_y = 1;

	/*Clear the text from the screen*/
	VDP_clearTextArea(0,10,40,10);

	game_on = TRUE;
}
```

This function resets our score and HUD, positions the ball at (0,0) and then
launches it by setting its velocity. It then calls `VDP_clearTextArea` which, as
the name implies, clears an area of the screen of text. To be more specific, it
clears a rectangle starting at tile coordinates (0,10) with a width of 40 tiles
and a height of 10 tiles. We call this so any messages on the screen - `msg_start`
or `msg_reset` - are cleared before the game begins. And finally, the function
sets `game_on` to `TRUE`.

Okay, so where do we call this function? Well, remember our joypad callback
function? Let’s put it in there, so it gets called whenever players press the
Start button! In `void myJoyHandler`, add the following before checking for
`BUTTON_RIGHT` and `BUTTON_LEFT`:

```
if(state & BUTTON_START){
	if(!game_on){
		startGame();
	}
}
```

Pressing the Start button will now start our game, but only if it’s not running
already. However: If you compile the game and try it out now, you’ll notice that
the ball starts moving immediately, whether you’ve pressed Start or not. This is
because we’re missing one step: We have to tell the game to only move our
entities when the game is actually running, meaning if `game_on == TRUE`. Modify
your `while(1)` loop in `main()` so it looks like this:

```
while(1)
{
	if(game_on == TRUE){
		moveBall();
		positionPlayer();
	}

	SPR_update();
	SYS_doVBlankProcess();
}

return(0);
```

That way the ball and paddle will only be moved when the game has really begun,
and stop moving once it’s over.

We’re almost done! Let’s just add some icing to the cake by welcoming the player
to our game. In `main()`, after drawing the score label and updating the score,
add this:

```
showText(msg_start);
```

This shows our previously defined start message on the screen.

Since we’re already calling `VDP_clearTextArea(0,10,40,10);` in `startGame()`
that’s all we need to do, as the message will be deleted once the game starts.

## Done

I’d like to thank you very much for reading. I hope you’ve found this tutorial
helpful! If you want to see more tutorials like this one, consider becoming a
patron on [Patreon](https://www.patreon.com/ohsat)! You will get project files
for each step of a tutorial and more.

## Wraping Up

Join the [official SGDK Discord](https://discord.gg/xmnBWQS)

[Page 1](./MegaPongTutorial1.md)

[Page 2](./MegaPongTutorial2.md)

[Page 3](./MegaPongTutorial3.md)

[Page 4](./MegaPongTutorial4.md)

[Page 5](./MegaPongTutorial5.md)

[Page 6](./MegaPongTutorial6.md)

[Page 7](./MegaPongTutorial7.md)

[Page 8](./MegaPongTutorial8.md)

[BONUS](./MegaPongTutorialBONUS.md)

