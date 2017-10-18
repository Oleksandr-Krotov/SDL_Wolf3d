#include <wolf3d.h>

void	ft_sdl_draw_text(t_wnd *wnd, t_font font, char *str, t_v2d xy)
{
	SDL_Surface	*surface;
	SDL_Texture *texture;
	SDL_Rect	src;
	SDL_Rect	dst;

	surface = TTF_RenderText_Solid(font.type, str, font.color);
	src = ft_sdl_set_rect(0, 0, 100, 100);
	dst = ft_sdl_set_rect(xy.x, xy.y, (int)(wnd->w * 0.05), (int)(wnd->h * 0.05));
	texture = SDL_CreateTextureFromSurface(wnd->p_rend, surface);
	SDL_RenderCopy(wnd->p_rend, texture, &src, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
