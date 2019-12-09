# Snake

Implementing the classical snake game in C using the SDL2 library.
Just a prototype. I'm not even sure if I'll implement it completely.

## Current state:

![screenshot](./public/shot.png?raw=true "Screenshot of Snake game")

- The snake moves.
- User can change movement direction using the arrow keys.
- Game quits when the snake goes out of screen boundaries.

## How to build and run game on Ubuntu

	# apt install gcc git make libsdl2-dev
	$ git clone https://github.com/sandov/snake
	$ cd snake/
	$ make
	$ bin/snake
