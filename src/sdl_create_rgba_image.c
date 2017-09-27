#include "wolf3d.h"

SDL_Surface	*sdl_create_rgba_img(int width, int height)
{
	SDL_Surface *surface_ptr;

	if ((surface_ptr = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0)) == NULL)
	{
		SDL_Log("SDL_CreateRGBSurfaceWithFormat() failed: %s", SDL_GetError());
		exit(1);
	}
	return (surface_ptr);
}
