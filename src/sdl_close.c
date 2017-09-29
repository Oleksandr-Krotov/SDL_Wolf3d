#include <wolf3d.h>

void	sdl_destroy_img(SDL_Surface *surface)
{
	SDL_FreeSurface(surface);
}

void	ft_sdl_close(t_m *m)
{
	TTF_CloseFont(m->font.type);
	sdl_destroy_img(m->wnd_img);
	SDL_DestroyWindow(m->wnd.p_wnd);
	TTF_Quit();
	SDL_Quit();
}

