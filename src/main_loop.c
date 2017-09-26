#include "wolf3d.h"

void	ft_main_loop(t_m *m)
{
	while (m->flags[CYCLE])
	{
		ft_sdl_event_hook(m);
		ft_draw_img(m);
		ft_sdl_update_window(m);
	}
};

