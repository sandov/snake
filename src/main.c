#include <stdbool.h>
#include <SDL2/SDL.h>

#define SQSIZE 32
#define WINWIDTH 512
#define WINHEIGHT 512
#define GRIDSIZE 16
#define MARGIN 1

struct game{
	SDL_Window *window;
	SDL_Renderer *rend;
	bool running;
};

struct snake{
	int headx;
	int heady;
};

void init(struct game *game){
	game->window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED,
	                                SDL_WINDOWPOS_UNDEFINED, WINWIDTH,
	                                512, SDL_WINDOW_SHOWN);

	game->rend = SDL_CreateRenderer(game->window, -1, 0);

	game->running = true;
}

void render(struct game *game, bool grid[GRIDSIZE][GRIDSIZE]){
	SDL_SetRenderDrawColor(game->rend, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(game->rend);
	SDL_SetRenderDrawColor(game->rend, 0x4f, 0x5f, 0x7f, 0xff);
	SDL_Rect r = {0, 0, SQSIZE-2*MARGIN, SQSIZE-2*MARGIN};

	for (int i = 0; i < GRIDSIZE; i++){
		for (int j = 0; j < GRIDSIZE; j++){
			if (grid[i][j]){
				r.y = i * SQSIZE + MARGIN;
				r.x = j * SQSIZE + MARGIN;
				SDL_RenderFillRect(game->rend, &r);
			}
		}
	}

	SDL_RenderPresent(game->rend);
}

void process_input(struct game *game){
	SDL_Event ev;
	while (SDL_PollEvent(&ev)){
		if (ev.type == SDL_QUIT){
			game->running = false;
		}
	}
}

void quit(struct game *game){
	SDL_DestroyRenderer(game->rend);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}

int main(void){
	struct game game;
	init(&game);

	struct snake snake;
	snake.headx = GRIDSIZE / 2;
	snake.heady = GRIDSIZE / 2;

	bool grid[GRIDSIZE][GRIDSIZE] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	}; 

	while (game.running){
		process_input(&game);
		render(&game, grid);
		SDL_Delay(20);
	}

	quit(&game);
	
	return 0;
}
