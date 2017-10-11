#include "wolf3d.h"

SDL_Window	*ft_create_sdl_window(void)
{
	SDL_Window *window;
	window = SDL_CreateWindow(D_NAME,
							  0,
							  0,
							  DISP_W,
							  DISP_H,
							  SDL_WINDOW_SHOWN);
	if (window == NULL)
		ft_error(3);
	return (window);
}


