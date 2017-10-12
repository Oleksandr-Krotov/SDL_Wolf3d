#include "wolf3d.h"

void	ft_torch(t_m * m)
{
	SDL_Rect src;
	SDL_Rect dst;
	int step_x;
	int step_y;
	static int num_x;
	static int num_y;
	static int i;

	if (m->flags[FIRE])
	{
		i += 1 / m->time.fps;
		step_x = 183;
		step_y = 191;
		if (i >= 500)
		{
			num_x = rand() % 4;
			num_y = rand() % 2;
			i = 0;
		}
		src = ft_sdl_set_rect(step_x, 200, step_x * num_x, step_y * num_y);
		dst = ft_sdl_set_rect(300, 300, 100, m->h - 280);
		SDL_RenderCopy(m->wnd.p_rend, m->p.arm[TORCH].texture, &src, &dst);
	}
}

void	ft_main_loop(t_m *m)
{
	while (m->flags[CYCLE])
	{
		SDL_GetWindowSize(m->wnd.p_wnd, &m->w, &m->h);
		ft_sdl_event_hook(m);
		SDL_SetRenderDrawColor(m->wnd.p_rend, 25, 25, 25, 255);
		SDL_RenderClear(m->wnd.p_rend);
			ft_calc_img(m);
		ft_fps(m);
		ft_torch(m);
		if (m->flags[SCREAM] == 1 && (int)m->p.pos.x == 8 && (int)m->p.pos.y == 11)
		{
			SDL_Delay(1000);
			m->flags[FIRE] = 0;
			SDL_RenderCopy(m->wnd.p_rend, m->scream, NULL, NULL);
		}
		if ((int)(1 / m->time.fps) % 53 == 0)
			SDL_RenderCopy(m->wnd.p_rend, m->scream, NULL, NULL);
		SDL_SetRenderDrawColor(m->wnd.p_rend, 0, 255, 0, 255);
		SDL_RenderDrawLine(m->wnd.p_rend, m->w / 2 - 10, m->h / 2, m->w / 2 + 10, m->h / 2);
		SDL_RenderDrawLine(m->wnd.p_rend, m->w / 2, m->h / 2 - 10, m->w / 2, m->h / 2 + 10);
		SDL_RenderPresent(m->wnd.p_rend);
		if (m->flags[SCREAM] == 1 && (int)m->p.pos.x == 8 && (int)m->p.pos.y == 11)
		{
			SDL_Delay(2000);
			m->flags[SCREAM] = 0;
		}
	}
}

