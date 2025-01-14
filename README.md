Fish Fillets - Next Generation
http://fillets.sf.net


Compile requirements
====================

** WARNING ** 
This source has been modified from the original in order to port to SDL2 and fix things up for running on a Mac. While the souce
should still compile in general for other platforms, the automake stuff here will have to be modified to search for the SDL2
libraries, etc.

The requirements below are now out of date - the equiavalent SDL 2 libraries should be used instead.

** END WARNING **

Library SDL = Simple DirectMedia Layer (video, input, sound)
- libSDL >= 1.2, www.libsdl.org

Library SDL_mixer (multiple sounds)
- libSDL_mixer >= 1.2.5, http://www.libsdl.org/projects/SDL_mixer/

Library SDL_image (PNG support)
- libSDL_image, http://www.libsdl.org/projects/SDL_image/

Library SDL_ttf (TrueType UTF-8 fonts)
- libSDL_ttf, http://www.libsdl.org/projects/SDL_ttf/

Library LUA (script language, used for debug console, configuration, levels,...)
- liblua50, www.lua.org
- liblualib50

Mac Details
===========

This is intended to build on a mac, and has some scripts to help make everything. Get the original Fillets-NG
distribution from http://fillets.sf.net

Run:

bash$ make -f ./macfiles/makefile
bash$ ./macfiles/make-bundle <version> /path/to/fillets-ng-data

You should end up with a Fillets.app in the top level directory. You may have to modify some paths in the 
macfiles/makefile to correspond with where your copies of the SDL2 frameworks are.


Cmake details
=============

on Ubuntu the required packages can be installed with:

    sudo apt install libsdl2-dev libsdl2-mixer-dev libsdl2-image-dev libsdl2-gfx-dev libsdl2-ttf-dev liblua5.4-dev
  
On Fedora the required packages can be installed with:

    sudo dnf install SDL2-devel SDL2_mixer-devel SDL2_image-devel SDL2_gfx-devel SDL2_ttf-devel lua-devel

on Windows the required libraries can be installed with:
  
    vcpkg install sdl2 sdl2-mixer sdl2-image sdl2-gfx sdl2-ttf lua

How to run
==========

I. Compile
----------

- Compile the game:
$ tar xzf fillets-ng.tar.gz
$ cd fillets-ng
$ ./configure
$ make
$ make install


II. Install data
----------------

- Download fillets-ng-data from http://fillets.sourceforge.net/download.php
- Extract fillets-ng-data.tar.gz to a $datadir.
  default: /usr/local/share/games/fillets-ng/

III. Run it
-----------
$ ./src/game/fillets systemdir=$datadir

Controls
========

Up, down, left and right arrow keys control the current fish.
Use space bar to switch between the fish.

See also "How to Play" $datadir/doc/html/manual.html

restart level - Backspace
undo - -/+
help - F1
save game - F2
load game - F3
show/hide move counter - F5
show/hide subtitles - F6
game menu - F10
fullscreen - F11
faster game - Shift

