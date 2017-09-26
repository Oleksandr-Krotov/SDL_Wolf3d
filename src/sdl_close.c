#include <wolf3d.h>

void	sdl_destroy_img(SDL_Surface *surface)
{
	SDL_FreeSurface(surface);
}

void	ft_sdl_close(t_m *m)
{
	sdl_destroy_img(m->imgs);
	sdl_destroy_img(m->wnd_img);
	SDL_DestroyWindow(m->wnd.p_wnd);
	SDL_Quit();
}

