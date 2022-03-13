# MegaPong 5 - Sprites

## Importing Sprites

Open the `res` folder of your project, then create a folder called `sprites`
within it. Put the ball sprite in that new folder. Then open `resources.res` and
add the following line below `bgtile`:

```
IMAGE   bgtile    "tiles/bgtile.png"  0
SPRITE  imgball    "sprites/ball.png"  1   1   NONE
```

This will compile our image as a SPRITE resource. Let's break it down:

`SPRITE`: This tells SGDK that we want to create a resource of type SPRITE.
`imgball`: This is the name we will use to refer to our resource inside the
code. It doesn’t have to match the file name, but I’d recommend it since things
could get confusing otherwise.
`sprites/ball.png`: This is the resource we want to import.
`1`: This is the width of the sprite in tiles. The sprite is 8 pixels wide,
which equals one tile.
`1`: This is the height of the sprite in tiles. The sprite is 8 pixels high,
which equals one tile.
`NONE`: This tells the resource compiler what compression to use. As with the
tile, we won’t be using any in this project.

So far so good. If we compile the game now, the ball image should be processed
as a SPRITE file. Go ahead, open up `resources.h` in the `res` folder and take
a peek. Our `imgball` definition should be in there! Now we just need to get the
ball into our game.

## Adding the Sprite

First of all we’ll create a variable in which to store our ball sprite, so we’ll
have access to it from throughout the game. At the very top of `main.c`, below
the includes, add the line:

```
Sprite* ball;
```

This will point to our ball sprite once it’s loaded. But before we load it, we
have to lay the groundwork. SGDK uses a sprite engine to handle sprites, and we
have to start it first. In the `main` function, add this line after the code that
loads our tiles:

```
SPR_init(0,0,0);
```

This will initialize the sprite engine. The parameters specify the maximum number
of sprites, the VRAM size and the unpack buffer size, respectively. `0` tells
SGDK to use the defaults, which is fine for now. Initializing the sprite engine
is absolutely necessary if we want to handle sprites, which will be the case for
pretty much any game!

With the sprite engine fired up, we can now add the sprite to our game. Add this
line after the previous one:

```
ball = SPR_addSprite(&imgball,100,100,TILE_ATTR(PAL1,0, FALSE, FALSE));
```

This is a bit of a mouthful, so let’s break it down. The signature of the 
function is:

```
Sprite* SPR_addSprite(const SpriteDefinition * 	spriteDef, s16 x, s16 y, u16 attribute)
```

`spriteDef`: The address in memory of our compiled sprite resource. This is the
name we gave our asset in the resource file. Don’t forget the `&` operator!
`x`: The x-coordinate (in pixels!) of our sprite
`y`: The y-coordinate (in pixels!) of our sprite
`attribute`: These are the same as the attributes for tiles. Counterintuitively
we even use `TILE_ATTR` to set these. Remember: If we don’t set the palette here,
the sprite won’t look right!

*Note: We’re using the same palette as the background tile we’re using, but as
you might have noticed, the ball is actually of a color not used in the tile.
I’ve already added the additional colors we need to the tile image, so that’s
why this works. Otherwise the sprite in the game wouldn’t look like the .png
file.*

And another note: *As you can see, the coordinates for sprites are given in
**pixels**, not tiles. Don’t forget this!*

Okay, now our ball is in the game! …or is it? If you compile now you won’t see
it. This is because we forgot an important step. Remember that sprite engine
SGDK uses? We have to tell it to update, which is the step that actually displays
the sprites at their current positions. Put this in the `while(1)` loop, right
before the call to `SYS_doVBlankProcess();`:

```
SPR_update();
```

## Moving the Ball

We will create a function called `moveBall()` that will move the ball every
frame. Define this function before the main function (but after defining
`Sprite* ball`):

```
void moveBall(){
  //Ball movement goes here
}
```

We’ll also need some variables to store the position and velocity for the ball.
At the top of `main.c`, below our ball sprite definition, add:

```
int ball_pos_x = 100;
int ball_pos_y = 100;
int ball_vel_x = 1;
int ball_vel_y = 1;
int ball_width = 8;
int ball_height = 8;
```

These variables will store the position of our ball, its velocity and its size.
We’ll need all of this stuff in a second.

Now in `moveBall()` we can apply the ball’s velocity to its current position,
which will move it. Well it won’t actually move it, because `ball_pos_x` and
`ball_pos_y` are just some variables we created. In order to actually move the
ball sprite, we have to tell the sprite engine to put the ball at this new
position. This is what all that looks like:

```
ball_pos_x += ball_vel_x;
ball_pos_y += ball_vel_y;

SPR_setPosition(ball,ball_pos_x,ball_pos_y);
```

`SPR_setPosition` is simple: it takes a sprite, as well as the desired x- and
y-coordinates. It will then draw the sprite at these coordinates, which in our
case will move our ball around the game field.

Now we just need to call our `moveBall()` function. In the `while(1)` loop,
before `SPR_update();`, add:

```
moveBall();
```

## Making the Ball Bounce

Jumping the logic explanation... we will end up with the `moveBall()` function
looking like this.

```
void moveBall(){
	//Position the ball
	ball_pos_x += ball_vel_x;
	ball_pos_y += ball_vel_y;

	//Check horizontal bounds
	if(ball_pos_x < LEFT_EDGE){
		ball_pos_x = LEFT_EDGE;
		ball_vel_x = -ball_vel_x;
	} else if(ball_pos_x + ball_width > RIGHT_EDGE){
		ball_pos_x = RIGHT_EDGE - ball_width;
		ball_vel_x = -ball_vel_x;
	}

	//Check vertical bounds
	if(ball_pos_y < TOP_EDGE){
		ball_pos_y = TOP_EDGE;
		ball_vel_y = -ball_vel_y;
	} else if(ball_pos_y + ball_height > BOTTOM_EDGE){
		ball_pos_y = BOTTOM_EDGE - ball_height;
		ball_vel_y = -ball_vel_y;
	}

	SPR_setPosition(ball,ball_pos_x,ball_pos_y);
}
```

## Wraping Up

Join the [official SGDK Discord](https://discord.gg/xmnBWQS)

[Page 1](./MegaPongTutorial1.md)

[Page 2](./MegaPongTutorial2.md)

[Page 3](./MegaPongTutorial3.md)

[Page 4](./MegaPongTutorial4.md)

[Page 6](./MegaPongTutorial6.md)

[Page 7](./MegaPongTutorial7.md)

[Page 8](./MegaPongTutorial8.md)

[Page 9](./MegaPongTutorial9.md)

[BONUS](./MegaPongTutorialBONUS.md)
