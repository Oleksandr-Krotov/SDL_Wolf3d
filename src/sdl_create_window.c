#include "wolf3d.h"

SDL_Window	*ft_create_sdl_window(void)
{
	SDL_Window *window;
	window = SDL_CreateWindow(D_NAME,
							  0,
							  0,
							  D_WIDTH,
							  D_HEIGHT,
							  SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not create. SDL Err: %s\n", SDL_GetError());
		ft_error(-2);
	}
	return (window);
}


