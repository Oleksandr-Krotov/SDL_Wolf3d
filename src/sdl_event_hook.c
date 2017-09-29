#include <wolf3d.h>

void	ft_sdl_event_hook(t_m *m)
{
	SDL_Event	wnd_event;
	int			mult;

	mult = 1;
	if (SDL_PollEvent(&wnd_event))
	{
		if (wnd_event.type == SDL_QUIT)
			m->flags[CYCLE] = 0;
		else if (wnd_event.type == SDL_KEYDOWN)
		{
			if (wnd_event.key.keysym.mod == KMOD_LSHIFT)
				mult = 2;
			if (wnd_event.key.keysym.sym == SDLK_ESCAPE)
				m->flags[CYCLE] = 0;
			if (wnd_event.key.keysym.sym == SDLK_w)
				ft_move_forward(m, mult);
			if (wnd_event.key.keysym.sym == SDLK_s)
				ft_move_back(m, mult);
			if (wnd_event.key.keysym.sym == SDLK_d)
				ft_turn_right(m, mult);
			if (wnd_event.key.keysym.sym == SDLK_a)
				ft_turn_left(m, mult);
			m->flags[REDRAW] = 1;
		}
	}
}
