#include <wolf3d.h>

void	ft_sdl_draw_text(SDL_Surface *img, t_font font, char *str, t_v2d xy)
{
	SDL_Surface	*text_img;
	SDL_Rect	location;

	text_img = TTF_RenderText_Solid(font.type, str, font.color);
	location = (SDL_Rect){xy.x, xy.y, 0, 0};
	SDL_BlitSurface(text_img, NULL, img, &location);
	SDL_FreeSurface(text_img);
}
