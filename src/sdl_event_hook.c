#include <wolf3d.h>

void	ft_sdl_event_hook(t_m *m)
{
	SDL_Event	wnd_event;
	int			mult;
	const Uint8 *state;

	state = SDL_GetKeyboardState(NULL);
	if (SDL_PollEvent(&wnd_event))
	{
		if (wnd_event.type == SDL_QUIT)
			m->flags[CYCLE] = 0;
	}
	mult = 1;
	if (state[SDL_SCANCODE_ESCAPE])
		m->flags[CYCLE] = 0;
	if (state[SDL_SCANCODE_LSHIFT])
		mult = 2;
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
		ft_move_forward(m, mult);
	if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
		ft_move_back(m, mult);
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
		ft_turn_left(m, mult);
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
		ft_turn_right(m, mult);
	if (state[SDL_SCANCODE_1])
		m->flags[FIRE] = 1;
	if (state[SDL_SCANCODE_2])
		m->flags[FIRE] = 0;
	printf("map[%f][%f]: %d\n", m->p.pos.x, m->p.pos.y, m->map.arr[(int)(m->p.pos.x)][(int)m->p.pos.y]);
	m->flags[REDRAW] = 1;
//		else if (wnd_event.type == SDL_KEYDOWN)
//		{
//			if (wnd_event.key.keysym.mod == KMOD_LSHIFT)
//				mult = 2;
//			if (wnd_event.key.keysym.sym == SDLK_ESCAPE)
//				m->flags[CYCLE] = 0;
//			if (wnd_event.key.keysym.sym == SDLK_w)
//				ft_move_forward(m, mult);
//			if (wnd_event.key.keysym.sym == SDLK_s)
//				ft_move_back(m, mult);
//			if (wnd_event.key.keysym.sym == SDLK_d)
//				ft_turn_right(m, mult);
//			if (wnd_event.key.keysym.sym == SDLK_a)
//				ft_turn_left(m, mult);
//		}
//	}
}
