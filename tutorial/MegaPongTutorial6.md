# MegaPong 6 - Input and Paddles

## Creating a Paddle

Put the file you downloaded in `res/sprites`. Then add it to the `resources.res`
file like this:

```
SPRITE  paddle  "sprites/paddle.png" 4 1 NONE
```

Remember that the size parameters are given in tiles! Our paddle is 32px wide,
which equals 4 tiles at 8 pixels each.

Now we need a variable to store the paddle sprite. Below all the ball-related
variables at the top of `main.c`, add this:

```
Sprite* player;
```

And while we’re up here, let’s add the variables we’ll need to handle the
paddle’s position and movement directly below:

```
int player_pos_x = 144;
const int player_pos_y = 200;
int player_vel_x = 0;
const int player_width = 32;
const int player_height = 8;
```

Since the paddle will only move left and right, its height is set as `const` and
we’re only tracking the x velocity.

Now with all of that taken care of we can add the sprite to the game. After
`SPR_init(0,0,0)` in `main()`, add this (before or after adding the ball, it
doesn’t matter):

```
player = SPR_addSprite(&paddle, player_pos_x, player_pos_y, TILE_ATTR(PAL1, 0, FALSE, FALSE));
```

## Handling Input

Now it’s time to get interactive. Input in SGDK is handled via a callback
function. What that means is that basically SGDK constantly keeps an eye on the
connected controllers. If a button is pressed, it will automatically call a
function you specify. This function then needs to check which button was pressed
and tell the game what to do. It’s a pretty simple setup, so let’s write one of
those callback functions! Here is the chunk of code that will make our paddle
move according to our inputs:

```
void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		/*Set player velocity if left or right are pressed;
		 *set velocity to 0 if no direction is pressed */
		if (state & BUTTON_RIGHT)
		{
			player_vel_x = 3;
		}
		else if (state & BUTTON_LEFT)
		{
			player_vel_x = -3;
		} else{
			if( (changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT) ){
				player_vel_x = 0;
			}
		}
	}
}
```

Put this function somewhere at the top of `main.c`. I’d suggest putting it after
the variables, before or after `moveBall()`.

There’s quite a lot to unpack here, so let’s do it! First, let’s look at the
parameters of our callback.

`joy`: This tells us which joypad was used. It will usually be `JOY_1` or
`JOY_2`, but SGDK actually supports up to 8 joypads.
`changed`: This tells us whether the state of a button has changed over the last
frame. If the current state is different from the state in the previous frame,
this will be `1` (otherwise `0`).
`state`: This will be `1` if the button is currently pressed and `0` if it isn’t.

So after making sure that the input came from joypad 1 (the only one we’ll be
using here), we check whether the D-Pad was pressed left or right. If so, we
set the player velocity accordingly. However, if any of the directions has been
released, we set the velocity to 0 so that the player stops moving.

Now that we have defined our callback function, we have to pass it to SGDK. At
the beginning of `main`, before loading any of our tiles or sprites, add these
two lines:

```
JOY_init();
JOY_setEventHandler( &myJoyHandler );
```

The first line initializes the joypad controls in SGDK. Without this step we
wouldn’t be able to receive any input at all. The second line sets our defined
function as the callback for joypad input. And that’s all we need to have
working controls in our game! Since our function works as a callback, we don’t
have to manually check for joypad input every frame. SGDK does that for us and
invokes our function whenever it’s needed! Just remember to actually set that
callback.

## Moving the Player

But our input won’t do anything right now, because we’re not actually moving
the player paddle. Just like with the ball, we’ll create a function to do that:

```
void positionPlayer(){
	/*Add the player's velocity to its position*/
	player_pos_x += player_vel_x;

	/*Keep the player within the bounds of the screen*/
	if(player_pos_x < LEFT_EDGE) player_pos_x = LEFT_EDGE;
	if(player_pos_x + player_width > RIGHT_EDGE) player_pos_x = RIGHT_EDGE - player_width;

	/*Let the Sprite engine position the sprite*/
	SPR_setPosition(player,player_pos_x,player_pos_y);
}
```

This is stuff we’ve done before, so I won’t dwell on it. Put the function near
`moveBall()`. Finally call the function by adding `positionPlayer();` in the
game loop, right after `moveBall()`. For reference, the loop should now look like
this:

```
while(1)
{
	moveBall();
	positionPlayer();
	
	SPR_update();
	SYS_doVBlankProcess();
}
```

## Wraping Up

Join the [official SGDK Discord](https://discord.gg/xmnBWQS)

[Page 1](./MegaPongTutorial1.md)

[Page 2](./MegaPongTutorial2.md)

[Page 3](./MegaPongTutorial3.md)

[Page 4](./MegaPongTutorial4.md)

[Page 5](./MegaPongTutorial5.md)

[Page 7](./MegaPongTutorial7.md)

[Page 8](./MegaPongTutorial8.md)

[Page 9](./MegaPongTutorial9.md)

[BONUS](./MegaPongTutorialBONUS.md)

