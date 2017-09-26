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
		}
	}
}
