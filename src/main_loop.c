#include "wolf3d.h"

void	ft_main_loop(t_m *m)
{
	while (m->flags[CYCLE])
	{
		SDL_GetWindowSize(m->wnd.p_wnd, &m->w, &m->h);
		ft_sdl_event_hook(m);
//		SDL_SetRenderDrawColor(m->wnd.p_rend, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(m->wnd.p_rend);
		ft_calc_img(m);
		ft_fps(m);
		SDL_RenderPresent(m->wnd.p_rend);
//		ft_sdl_update_window(m);
	}
};

