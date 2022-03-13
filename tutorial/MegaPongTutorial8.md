# MegaPong 8 - Score and HUD

## Score and HUD

First we’re going to define the variables that we’ll need. At the beginning of
the file, next to all our other variables, add this:

```
/*Score variables*/
int score = 0;
char label_score[6] = "SCORE\0";
char str_score[4] = "0";
```

`int score` will store our current score value. `char label_score[6]` will be
the label of our score HUD element. `char str_score[4]` will store our current
score value as a string.

Now we have everything we need. In `main()`, add this after loading the tiles:

```
/*Draw the texts*/
VDP_setTextPlane(BG_A);
VDP_drawText(label_score,1,1);
```

_(Note: In versions of SGDK before 1.5, the function is called `VDP_setTextPlan()`
without the final ‘e’.)_

Remember `VDP_drawText` from the very first installment of this tutorial? It’s
back! But before we use it, we first tell SGDK to draw all texts on plane A,
because drawing them on the same plane you have tiles on can lead to issues.
There is actually a more sophisticated way to draw HUD elements, but this way
will suffice for now. Then we draw our score label at position (1,1). Keep in
mind that `VDP_drawText` uses tiles as the unit!

That draws our label to the screen. Now we need to put our score in there. For
that we’ll need some tools, so add the following line to very beginning of
`main.c`:

```
#include <string.h>
```

This gives us access to some code that makes dealing with strings easier. And
we’ll need a small helper function soon, so let’s just define it right now:

```
int sign(int x) {
    return (x > 0) - (x < 0);
}
```

This function returns the sign of `int x`. I’d recommend putting this definition
above all the other functions, so that there won’t be any issues later (remember:
In C you can only call functions that have already been defined further up in
the code).

Now we’ll create a function that will display our actual score value in the HUD.
Add it before `main()`:

```
void updateScoreDisplay(){
	sprintf(str_score,"%d",score);
	VDP_clearText(1,2,3);
	VDP_drawText(str_score,1,2);
}
```

The function `sprintf` might look a bit confusing, but it’s doing something rather
simple. Basically, it takes the `int` value of `score` and puts it into the
variable `str_score`. In very crude terms, it converts an `int` into a `char[]`
so that we can use it for our HUD. It’s a general C function and not unique to
SGDK, so you can find more info [elsewhere](https://www.geeksforgeeks.org/sprintf-in-c/).

Once `str_score` has our current score value, we first clear any text that might
have been there before. We do this by calling `VDP_clearText(1,2,3);`. This
function takes 3 parameters: The x-coordinate (in tiles), the y-coordinate (in
tiles) and the length (also in tiles) we want to clear out. If we didn’t clear
the text, all characters would remain on screen until they are replaced - if
they are ever replaced.

Finally, we draw our current score at position (1,2). This is one tile below our
score label.

We’ll want to call this function once at the beginning, so that the HUD displays
a score of `0` when we start the game. Add a call after we’re drawing
`label_score` in `main()`. For reference, this is all the code we’re using to
display the HUD at the start of the game:

```
VDP_setTextPlane(BG_A);
VDP_drawText(label_score,1,1);
updateScoreDisplay();
```

Now there are only two more things to do: We need to increase the score when the
player hits the ball, then we have to update the HUD by calling
`updateScoreDisplay()`. We’ll do both of these things in `moveBall()`. Navigate
to the if-statements checking for collisions with the player paddle, and put the
following two lines in the inner if-statement:

```
score++;
updateScoreDisplay();
```

This way, every time the paddle hits the ball, the score gets increased by 1 and
the HUD is automatically updated. Neat!

But while we’re here, let’s add a little spice to the game. Put the following
right after the previous code:

```
if( score % 10 == 0){
ball_vel_x += sign(ball_vel_x);
ball_vel_y += sign(ball_vel_y);
}
```

As you can see, this will increase the velocity of the ball by 1 on every 10th
hit (using the `sign` function we had defined previously). It would be pretty
boring if the ball kept its speed all the time! For reference, this is what the
whole `moveBall()` function now looks like:

```
void moveBall(){
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

    //Check for collision with paddle
    if(ball_pos_x < player_pos_x + player_width && ball_pos_x + ball_width > player_pos_x){
    	if(ball_pos_y < player_pos_y + player_height && ball_pos_y + ball_height >= player_pos_y){
    		//On collision, invert the velocity
    		ball_pos_y = player_pos_y - ball_height - 1;
    		ball_vel_y = -ball_vel_y;

    		//Increase the score and update the HUD
    		score++;
    		updateScoreDisplay();

    		//Make ball faster on every 10th hit
    		if( score % 10 == 0){
    			ball_vel_x += sign(ball_vel_x);
    			ball_vel_y += sign(ball_vel_y);
    		}
    	}
    }

    //Position the ball
    ball_pos_x += ball_vel_x;
    ball_pos_y += ball_vel_y;

    SPR_setPosition(ball,ball_pos_x,ball_pos_y);

}
```

Alright, that was a lot! Now compile the game and give it a spin. Each hit
should net you one point, and the difficulty should increase on every 10th hit.

## Wraping Up

Join the [official SGDK Discord](https://discord.gg/xmnBWQS)

[Page 1](./MegaPongTutorial1.md)

[Page 2](./MegaPongTutorial2.md)

[Page 3](./MegaPongTutorial3.md)

[Page 4](./MegaPongTutorial4.md)

[Page 5](./MegaPongTutorial5.md)

[Page 6](./MegaPongTutorial6.md)

[Page 7](./MegaPongTutorial7.md)

[Page 9](./MegaPongTutorial9.md)

[BONUS](./MegaPongTutorialBONUS.md)
