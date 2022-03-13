# MegaPong 1 - Hello Mega Drive World!

## Setting Up SGDK

- You need to install Java
- SGDK GitHub: https://github.com/Stephane-D/SGDK
- Linux:
    - SGDK Docker: https://gitlab.com/doragasu/docker-sgdk/-/tree/v1.70 [Works Great]
    - Genesis development environment for Linux: https://github.com/kubilus1/gendev/

## Emulators

- [Gens KMod](https://segaretro.org/Gens_KMod): Emulator with a number of debugging features, such as real-time viewing of VRAM, palettes, registers and more.
- [BlastEm](https://www.retrodev.com/blastem/): Open source, higly accurate emulator for the Genesis/Megadrive that runs on modest hardware.
- [BizHawk](https://tasvideos.org/BizHawk/ReleaseHistory): Other option instead of Gens KMod. Working well on my Linux distro.

## Setting Up a Project

[Download Project Template.](https://www.ohsat.com/tutorial/megapong/megapong-1/emptyproject.zip)

[My Template for using NeoVim with ccls LSP and CMake.](./template.zip)

In the root of the folder you should now find the following things:

~~~
out
res
src
~~~

This is the structure of a basic SGDK project. The `out` folder will contain our
rom file once we have compiled one. `res` will hold the resources (graphics, audio...)
for our project. The `src` folder contains our source code files. Inside you will
find the `main.c` file, which is where we will add all of our code.

So let's do just that!

## Compiling and Running Hello World

Run the docker command on your project root folder. I mapped a keybind for it
in the `init.vim`. Replace `v1.70` for any wanted tag.

~~~
docker run --rm -v $PWD:/m68k -t registry.gitlab.com/doragasu/docker-sgdk:v1.70
~~~

## But Wait, What did I Just Write?

Let's take a look in the following code.

~~~
VDP_drawText("Hello Mega Drive World!", 8, 12);
~~~

As you can probably tell, this function draws text on the screen. To be more
precise, in this case, it draws the text “Hello Mega Drive World!” on the screen,
at the coordinates (8,12).

By the way: This function uses the VDP of the Mega Drive, or the **V**ideo **D**isplay
**P**rocessor, which explains the `VDP_` prefix. Basically every function starting
with `VDP_` in SGDK does something visual, in this case drawing text on the screen.

The next interesting line also has something to do with visuals:

~~~
SYS_doVBlankProcess();
~~~

This is a very important function. Basically, everything you put into the
`while(1){ ... }` loop is executed as quickly as possible, which might or might
not sync up with your display. In order to avoid display issues, you have to
tell your Mega Drive to wait until the screen display has been fully updated
before it starts processing more stuff. And that’s what `SYS_doVBlankProcess()`
does! Remember to always put `SYS_doVBlankProcess();` at the end of your game loop
and things should be fine.

## Wraping Up

Join the [official SGDK Discord](https://discord.gg/xmnBWQS)

[Page 2](./MegaPongTutorial2.md)

[Page 3](./MegaPongTutorial3.md)

[Page 4](./MegaPongTutorial4.md)

[Page 5](./MegaPongTutorial5.md)

[Page 6](./MegaPongTutorial6.md)

[Page 7](./MegaPongTutorial7.md)

[Page 8](./MegaPongTutorial8.md)

[Page 9](./MegaPongTutorial9.md)

[BONUS](./MegaPongTutorialBONUS.md)

