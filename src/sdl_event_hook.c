#include <wolf3d.h>

void	ft_sdl_event_hook(t_m *m)
{
	SDL_Event	wnd_event;
	const Uint8	*state;
	double		mult;

	state = SDL_GetKeyboardState(NULL);
	if (SDL_PollEvent(&wnd_event))
	{
		if (wnd_event.type == SDL_QUIT)
			m->flags[GAME] = EXIT;
	}
	mult = 1;
	if (state[SDL_SCANCODE_ESCAPE])
		m->flags[GAME] = EXIT;
	if (state[SDL_SCANCODE_LSHIFT])
		mult = 1.2;
	if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
		ft_move_forward(m, mult);
	if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
		ft_move_back(m, mult);
	if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
		ft_turn_left(m, mult);
	if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
		ft_turn_right(m, mult);
	if (state[SDL_SCANCODE_1])
		m->torch.status = TRUE;
	if (state[SDL_SCANCODE_2])
		m->torch.status = FALSE;
	if (state[SDL_SCANCODE_E])
		ft_do_action(m);
	if (state[SDL_SCANCODE_KP_PLUS])
	{
		m->music.volume = m->music.volume >= 128 ? 128 : m->music.volume + 1;
		Mix_VolumeMusic(m->music.volume);
	}
	if (state[SDL_SCANCODE_KP_MINUS])
	{
		m->music.volume = m->music.volume <= 0 ? 0 : m->music.volume - 1;
		Mix_VolumeMusic(m->music.volume);
	}
	printf("map[%d][%d]: %d\n", (int)m->p.pos.x, (int)m->p.pos.y, m->map.arr[(int)(m->p.pos.x)][(int)m->p.pos.y]);
//	printf("dirX: %f\ndirY: %f\n", m->p.dir.x, m->p.dir.y);
//	printf("Volume lvl: [%d]\n", m->music.volume);
	m->flags[REDRAW] = 1;
}
