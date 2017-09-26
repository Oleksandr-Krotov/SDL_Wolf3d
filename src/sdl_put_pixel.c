#include "wolf3d.h"

void	ft_sdl_put_pixel(SDL_Surface *img, int x, int y, t_rgba color)
{
	int	a;
	Uint8 *ptr;

	ptr = img->pixels;
	a = y * img->pitch + x * 4;
	ptr[a] = color.b;
	ptr[a + 1] = color.g;
	ptr[a + 2] = color.r;
	ptr[a + 3] = 0;
}
