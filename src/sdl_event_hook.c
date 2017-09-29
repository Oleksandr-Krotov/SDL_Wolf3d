#include <wolf3d.h>

void	ft_sdl_event_hook(t_m *m)
{
	SDL_Event wnd_event;

	if (SDL_PollEvent(&wnd_event))
	{
		if (wnd_event.type == SDL_QUIT)
			m->flags[CYCLE] = 0;
		else if (wnd_event.type == SDL_KEYDOWN)
		{
			if (wnd_event.key.keysym.sym == SDLK_ESCAPE)
				m->flags[CYCLE] = 0;
			if (wnd_event.key.keysym.sym == SDLK_w)
			{
				printf("map[%d][%d]: %d\n", (int)(m->p.pos.x + m->p.dir.x * m->p.ms), (int)m->p.pos.y, m->map.arr[(int)(m->p.pos.x + m->p.dir.x * m->p.ms)][(int)m->p.pos.y]);
				if (m->map.arr[(int)(m->p.pos.x + m->p.dir.x * m->p.ms)][(int)m->p.pos.y] == 0)
					m->p.pos.x += m->p.dir.x * m->p.ms;
				if (m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y + m->p.dir.y * m->p.ms)] == 0)
					m->p.pos.y += m->p.dir.y * m->p.ms;
			}
			if (wnd_event.key.keysym.sym == SDLK_s)
			{
				printf("map[%d][%d]: %d\n", (int)(m->p.pos.x - m->p.dir.x * m->p.ms), (int)m->p.pos.y, m->map.arr[(int)(m->p.pos.x - m->p.dir.x * m->p.ms)][(int)m->p.pos.y]);
				if (m->map.arr[(int)(m->p.pos.x - m->p.dir.x * m->p.ms)][(int)m->p.pos.y] == 0)
					m->p.pos.x -= m->p.dir.x * m->p.ms;
				if (m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y - m->p.dir.y * m->p.ms)] == 0)
					m->p.pos.y -= m->p.dir.y * m->p.ms;
			}
			if (wnd_event.key.keysym.sym == SDLK_d)
			{
				m->p.old_x = m->p.dir.x;
				m->p.dir.x = m->p.dir.x * cos(-m->p.rs) - m->p.dir.y * sin(-m->p.rs);
				m->p.dir.y = m->p.old_x * sin(-m->p.rs) + m->p.dir.y * cos(-m->p.rs);
				m->cam.old_x = m->cam.plane_x;
				m->cam.plane_x = m->cam.plane_x * cos(-m->p.rs) - m->cam.plane_y * sin(-m->p.rs);
				m->cam.plane_y = m->cam.old_x * sin(-m->p.rs) + m->cam.plane_y * cos(-m->p.rs);
			}
			if (wnd_event.key.keysym.sym == SDLK_a)
			{
				m->p.old_x = m->p.dir.x;
				m->p.dir.x = m->p.dir.x * cos(m->p.rs) - m->p.dir.y * sin(m->p.rs);
				m->p.dir.y = m->p.old_x * sin(m->p.rs) + m->p.dir.y * cos(m->p.rs);
				m->cam.old_x = m->cam.plane_x;
				m->cam.plane_x = m->cam.plane_x * cos(m->p.rs) - m->cam.plane_y * sin(m->p.rs);
				m->cam.plane_y = m->cam.old_x * sin(m->p.rs) + m->cam.plane_y * cos(m->p.rs);
			}
			m->flags[REDRAW] = 1;
		}
	}
}
