#include "wolf3d.h"

void	ft_sdl_put_pixel(SDL_Surface *img, int x, int y, SDL_Color color)
{
	int		a;
	Uint32	*ptr;

	SDL_LockSurface(img);
	ptr = img->pixels;
	a = y * (img->pitch / img->format->BytesPerPixel) + x ;
	ptr[a] = SDL_MapRGBA(img->format, color.r, color.g, color.b, color.a);
	SDL_UnlockSurface(img);
}