#include <wolf3d.h>

SDL_Rect	ft_sdl_set_rect(int w, int h, int x, int y)
{
	SDL_Rect ret;

	ret.w = w;
	ret.h = h;
	ret.x = x;
	ret.y = y;
	return (ret);
}

