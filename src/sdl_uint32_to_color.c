#include <wolf3d.h>

SDL_Color	translate_color(Uint32 int_color)
{
	SDL_Color color;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	color={(int_color & 0x00ff0000)/0x10000,
	(int_color &0x0000ff00)/0x100,
	(int_color & 0x000000ff),0};
#else
	color = (SDL_Color){(Uint8)(int_color & 0x000000ff),
						(Uint8)((int_color & 0x0000ff00) / 0x100),
						(Uint8)((int_color & 0x00ff0000) / 0x10000), 0};
#endif
	return color;
}