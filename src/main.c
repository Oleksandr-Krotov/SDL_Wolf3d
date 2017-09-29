#include "wolf3d.h"

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not init. SDL Err: %s\n", SDL_GetError());
		ft_error(-1);
	}
}

void	ft_ttf_init(t_m *m)
{
	TTF_Init();
	m->font.path = "/usr/share/fonts/truetype/freefont/FreeSansBold.ttf";
	m->font.type = TTF_OpenFont(m->font.path, 16);
	m->font.color = (SDL_Color){255, 255, 255, 0};
}

void	ft_init_player(t_m *m)
{
	m->p.pos.x = m->map.start.x;
	m->p.pos.y = m->map.start.y;
	m->p.dir.x = -1;
	m->p.dir.y = 0;
}

void	ft_init_cam(t_m *m)
{
	m->cam.plane_x = 0;
	m->cam.plane_y = 0.66;
	m->cam.camera_x = 0;
}

void	ft_init(t_m *m)
{
	ft_init_sdl();
	ft_ttf_init(m);
	m->wnd.p_wnd = ft_create_sdl_window();
	m->wnd_img = SDL_GetWindowSurface(m->wnd.p_wnd);
	m->flags[CYCLE] = 1;
	m->flags[REDRAW] = 1;
	m->w = D_WIDTH;
	m->h = D_HEIGHT;
	ft_init_player(m);
	ft_init_cam(m);
	m->time.cur = 0;
	m->time.old = 0;
}

int		main(int argc, char **argv)
{
	t_m	m;

	m.map.start.x = -1;
	m.map.start.y = -1;
	ft_read_map(&m, argv[1]);
	ft_init(&m);
	ft_main_loop(&m);
	ft_sdl_close(&m);
	return (0);
}
