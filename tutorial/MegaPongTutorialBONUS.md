# MegaPong BONUS - Flashing

Alright, we have a complete and working game now. We have graphics, gameplay,
scores, game overs…sound is still missing, true, but that’s a topic for another
tutorial. However, we can still add something to make our game a bit better: The
almighty [Juice](https://www.youtube.com/watch?v=Fy0aCDmgnxg).

## Setting Things Up

First off we’ll add some variables that we need. Put them somewhere at the top
of `main.c`, maybe after the `msg_` variables:

```
int flashing = FALSE;
int frames = 0;
int ball_color = 0;
```

The variable `flashing` will track whether the ball is currently flashing or
not. `frames` will help us count the elapsed frames, so that we can control how
rapidly and for how long the ball will flash. And finally, `ball_color` will
store the main color of the ball. I’ll explain why we have to do that in a second.

Next up we’ll tell the game when the ball is supposed to flash. Since we want
it to happen when the ball is hit by the paddle, we’ll stick that code in
`moveBall()`. In the part where we handle the ball’s collision (where we do
`score++` and the like), add the following line:

```
flashing = TRUE;
```

And that’s all we need to do here!

## The Flase Effect

That’s the easy part over with, now to implement the actual flashing. Most of it
will take place within the main game loop, but there is one thing that we have
to do beforehand. After we add the ball sprite using `SPR_addSprite` and before
the `while(1)` loop starts, add the following line:

```
ball_color = VDP_getPaletteColor(22);
```

As you might be able to guess, `VDP_getPaletteColor(u16 index)` gets the palette
color from a specific index. We’re grabbing index `22` here, which just so
happens to be the orange color used for the ball. I’ll explain this in a bit
more detail in another post, but for now, you only need to know that we’re
storing the default color of the ball in `ball_color`.

Alright, let’s dive into that loop! First, add an if-statement checking whether
`flashing` equals `TRUE`, so that your loop looks something like this:

```
while(1)
{
	if(game_on == TRUE){
		moveBall();
		positionPlayer();

		//Handle the flashing of the ball
		if( flashing == TRUE ){
			//Cool flashing code goes here!	
		}
	}
	SPR_update();
	SYS_doVBlankProcess();
}
```

All our code will go within that new if-statement. First of all we’ll want to
start counting frames, so we can control the timing of the flashing. So add this
line, which will increment the variable `frames` by 1 every frame:

```
frames++;
```

So far so good. Now before we dive into the juicy part, let me explain what we
actually want to achieve!

There are a few ways to create a flashing effect on the Mega Drive. The most
common one (and the one that we’ll use) is to temporarily replace a color in the
palette with white. That way, all the parts of all the sprites that use that
color will turn white for a brief instant. The downside to this is that all
sprites that use that color will be affected, so you have to plan in advance
which of the colors you’ll use for the effect. And of course you’ll have to
draw the sprites with the effect in mind, so that the flashing will look good.
A lot of the time, games will replace the color black with white to simulate
flashing, but we’ll simply use the orange of the ball.

And yes, that’s why we’re storing the ball color in `ball_color`. That way we
can simply switch between white and the original color!

As for the speed of the flashing effect: That’s up to taste, but we will flip
the colors on every third frame. This means the color will remain white for two
frames, then it’ll switch back to orange for two frames, then back to white and
so on. We’re gonna use our `frames` variable to keep track of this.

Now with the theory out of the way, let’s do it! Add the following code block
after `frames++;`:

```
if( frames % 4 == 0 ){
	VDP_setPaletteColor(22,ball_color);
} else if( frames % 2 == 0){
	VDP_setPaletteColor(22,RGB24_TO_VDPCOLOR(0xffffff));
}
```

Let’s break it down. `VDP_setPaletteColor` is obviously the counterpart to
`VDP_getPaletteColor` and sets the color at a certain index. We’re using this
function twice: To set the color at `22` to `ball_color`, and to set it to white.
`RGB24_TO_VDPCOLOR` is simply a helper function that converts a hex value to the
format that the VDP uses. This makes it more convenient for us.

We’re using the modulo operator and our `frames` variable to control when the
change should occur. Every 2nd frame the color is set to white and every 4th
frame it switches back to the original orange. It’s important to check for
`frames % 4` first because it would never trigger if you checked for
`frames % 2` first (since every number divisible by 4 is also divisible by 2).

Alright, if you try the game now you’ll see that the ball starts flashing when
you hit it! And you’ll see that it never stops flashing. Let’s put a limit on that.

Add the following code block right after the previous one:

```
//Stop flashing
if(frames > 30){
	flashing = FALSE;
	frames = 0;
	VDP_setPaletteColor(22,ball_color);
}
```

This should be rather simple. Once the frame counter exceeds `30` (which means
that half a second has passed, as we’re running at 60fps) we set flashing to
`FALSE` which stops all our flashing code from happening. Then we reset the
`frames` counter to prepare it for the next time we need flashing. Finally,
we make sure that the original ball color is restored by calling
`VDP_setPaletteColor(22,ball_color);` one last time.

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

[Page 9](./MegaPongTutorial9.md)

