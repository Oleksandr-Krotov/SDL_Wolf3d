#include "wolf3d.h"

void	ft_main_loop(t_m *m)
{
	while (m->flags[CYCLE])
	{
		m->imgs = sdl_create_rgba_img(DISP_W, DISP_H);
		ft_sdl_event_hook(m);
		ft_calc_img(m);
		ft_fps(m);
		ft_sdl_update_window(m);
	}
};

