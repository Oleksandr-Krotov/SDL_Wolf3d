#include "wolf3d.h"

void	ft_sdl_put_pixel(SDL_Surface *img, int x, int y, t_rgba color)
{
	int	a;
	Uint32 *ptr;

	SDL_LockSurface(img);
	ptr = img->pixels;
	a = y * (img->pitch / 4) + x ;
	ptr[a] = SDL_MapRGB(img->format, color.r, color.g, color.b);
//	ptr[a] = color.b;
//	ptr[a + 1] = color.g;
//	ptr[a + 2] = color.r;
//	ptr[a + 3] = 0;
	SDL_UnlockSurface(img);
}

SDL_Color translate_color(Uint32 int_color)

//Change from an "int color" to an SDL_Color
{
	SDL_Color color={(int_color & 0x000000ff),
					 (int_color & 0x0000ff00)/0x100,
					 (int_color & 0x00ff0000)/0x10000,0};
	return color;
}

void	ft_sdl_put_uint32(SDL_Surface *img, int x, int y, Uint32 color)
{
	int	a;
	Uint32	*ptr;
	SDL_Color color_ptr;

	color_ptr = translate_color(color);
	SDL_LockSurface(img);
	ptr = img->pixels;
	a = y * (img->pitch / 4) + x ;
	ptr[a] = SDL_MapRGB(img->format, color_ptr.b, color_ptr.g, color_ptr.r);
	SDL_UnlockSurface(img);
}
