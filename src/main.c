#include "wolf3d.h"

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not init. SDL Err: %s\n", SDL_GetError());
		ft_error(-1);
	}
}

void	ft_init(t_m *m)
{
	ft_init_sdl();
	m->wnd.p_wnd = ft_create_sdl_window();
	m->wnd_img = SDL_GetWindowSurface(m->wnd.p_wnd);
	m->imgs = sdl_create_rgba_img(D_WIDTH, D_HEIGHT);
	m->flags[CYCLE] = 1;
}

void	ft_read_map(t_m *m)
{

}

int		main(int argc, char **argv)
{
	t_m	m;

	ft_read_map(m);
	ft_init(&m);
	ft_main_loop(&m);
	ft_sdl_close(&m);
	return (0);
}
