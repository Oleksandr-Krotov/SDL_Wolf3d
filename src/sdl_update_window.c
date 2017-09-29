#include "wolf3d.h"

void	ft_sdl_update_window(t_m *m)
{
	SDL_BlitSurface(m->imgs, NULL, m->wnd_img, NULL);
	SDL_UpdateWindowSurface(m->wnd.p_wnd);
	SDL_FreeSurface(m->imgs);
}
