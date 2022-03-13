# MegaPong 7 - Collisions

It’s physics time! We got two moving parts, now it’s time to smash them together.
SGDK has built-in collision stuff, but we won’t need that for this simple
project. The method we’re using to handle collisions is called AABB collision
detection. It uses axis-aligned bounding boxes, which sounds really fancy,
doesn’t it? Basically that just means we’ll be using rectangles to check for
collisions, instead of the actual sprite graphics. It’s a very simple and
efficient method of handling collisions. You can check out an interactive demo
[here](https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection).

## Collision

We will stick our collision code in `moveBall()`, as it makes the most sense
there. Put it after checking for the screen bounds, but before applying the
ball’s velocity. Let’s start by checking the x positions:

```
if(ball_pos_x < player_pos_x + player_width && ball_pos_x + ball_width > player_pos_x){
	// do things
}
```

It might seem a bit tricky at first glance, but it’s actually very simple once
you get it. What we’re doing here is:

1. checking whether the left edge of the ball is to the left of the right edge
   of the paddle.
2. checking whether the right edge of the ball is to the right of the left edge
   of the paddle.

There can only be a collision if those two conditions are true! Otherwise the
ball wouldn’t be in range of the paddle, but would fly past it left or right.

That takes care of the horizontal check. Now we need to check the vertical
coordinates. We’ll end up with the following:

```
if(ball_pos_x < player_pos_x + player_width && ball_pos_x + ball_width > player_pos_x){
  if(ball_pos_y < player_pos_y + player_height && ball_pos_y + ball_height >= player_pos_y){
    // do things
  }
}
```

The logic is the same as with the horizontal check.

If both of these if-statements are true, then we definitely have a collision on
our hands! Now we just need to code what should happen in that case, which is
the same as when the ball hits the bounds of the screen. The entire collision
code now looks like this:

```
/_Check for collisions with the player paddle_/
if(ball_pos_x < player_pos_x + player_width && ball_pos_x + ball_width > player_pos_x){
  if(ball_pos_y < player_pos_y + player_height && ball_pos_y + ball_height >= player_pos_y){
    //On collision, invert the velocity
    ball_pos_y = player_pos_y - ball_height - 1;
    ball_vel_y = -ball_vel_y;
  }
}
```

If there is a collision (that is, when the collision rectangles of both sprites
overlap), we want the ball to bounce off. To do this, we simply invert the
vertical velocity of the ball. But: Just to be safe we first place the ball one
pixel above the paddle to prevent issues, such as the ball getting stuck inside
of the paddle.

And that’s pretty much it! Collision handling is a rather complex and tricky
subject, but for a simple game like this it’s not much more than basic geometry.
compile the game and rejoice in the fact that our game now has some actual
gameplay!

## Wraping Up

Join the [official SGDK Discord](https://discord.gg/xmnBWQS)

[Page 1](./MegaPongTutorial1.md)

[Page 2](./MegaPongTutorial2.md)

[Page 3](./MegaPongTutorial3.md)

[Page 4](./MegaPongTutorial4.md)

[Page 5](./MegaPongTutorial5.md)

[Page 6](./MegaPongTutorial6.md)

[Page 8](./MegaPongTutorial8.md)

[Page 9](./MegaPongTutorial9.md)

[BONUS](./MegaPongTutorialBONUS.md)
