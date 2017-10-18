#include <wolf3d.h>

SDL_Rect	ft_sdl_set_rect(int x, int y, int w, int h)
{
	SDL_Rect ret;

	ret.x = x;
	ret.y = y;
	ret.w = w;
	ret.h = h;
	return (ret);
}

