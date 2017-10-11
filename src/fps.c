#include <wolf3d.h>

void	ft_fps(t_m *m)
{
	//FIXME "bad fps"
	m->time.old = m->time.cur;
	m->time.cur = SDL_GetTicks();
	m->time.fps = (m->time.cur - m->time.old) / 1000.0;
	printf("fps: %f\n",1 / m->time.fps);
//	ft_sdl_draw_text(m->imgs, m->font, ft_itoa((int)(1 /m->time.fps)), (t_v2d){10, 10});
	m->p.ms = m->time.fps * 3.0;
	m->p.rs = m->time.fps * 2.0;
}
