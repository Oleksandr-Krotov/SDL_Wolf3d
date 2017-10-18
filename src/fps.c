#include <wolf3d.h>

double	ft_get_fps(t_m *m)
{
	m->time.old = m->time.cur;
	m->time.cur = SDL_GetTicks();
	return ((m->time.cur - m->time.old) / 1000.0);
}

void	ft_fps_to_screen(t_m *m)
{
	static int		i;
	static double	mid = 25;
	static double	sum;

	sum += m->time.fps;
	i++;
	if (i >= 25)
	{
		mid = sum / i;
		i = 0;
		sum = 0;
	}
	ft_sdl_draw_text(&m->wnd, m->font, ft_itoa((int)(1 / mid)), (t_v2d){5, 5});
	printf("fps: %d\n", (int)(1 / mid));
}

void	ft_fps(t_m *m)
{
	m->time.fps = ft_get_fps(m);
	if (m->time.fps < 0.015)
		m->time.fps = 0.015;
	ft_fps_to_screen(m);
	m->p.ms = m->time.fps;
	m->p.rs = m->time.fps;
}
