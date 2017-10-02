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

void	ft_load_texture_pack(t_txtrs *tex)
{
	int x;
	int y;
	int xorcolor;
	int ycolor;
	int xycolor;

	x = 0;
	while (x < tex->w)
	{
		y = 0;
		while (y < tex->h)
		{
			xorcolor = (x * 256/ tex->w) ^ (y * 256 / tex->h);
			ycolor = y * 256 / tex->w;
			xycolor = y * 128 / tex->h + x * 128 / tex->w;
			tex->buf[0][tex->w * y + x] = (Uint32)(655336 * 254 * (x != y && x != tex->w - y));
			tex->buf[1][tex->w * y + x] = (Uint32)(xycolor + 256 * xycolor + 65536 * xycolor);
			tex->buf[2][tex->w * y + x] = (Uint32)(256 * xycolor + 65536 * xycolor);
			tex->buf[3][tex->w * y + x] = (Uint32)(xorcolor + 256 * xorcolor + 65536 * xorcolor);
			tex->buf[4][tex->w * y + x] = (Uint32)(256 * xorcolor);
			tex->buf[5][tex->w * y + x] = (Uint32)(65536 * 192 * (x % 16 && y % 16));
			tex->buf[6][tex->w * y + x] = (Uint32)(65536 * ycolor);
			tex->buf[7][tex->w * y + x] = (Uint32)(128 + 256 + 65536 * 128);
			y++;
		}
		x++;
	}
}

void	ft_init_textures(t_m *m)
{
	int i;

	m->texturs.w = TXTR_W;
	m->texturs.h = TXTR_H;
	i = 0;
	while (i < TXTR_SIZE)
	{

		m->texturs.buf[i] = malloc(sizeof(Uint32) * TXTR_W * TXTR_H);
		i++;
	}
	ft_load_texture_pack(&(m->texturs));
}

void	ft_init(t_m *m)
{
	ft_init_sdl();
	ft_ttf_init(m);
	m->wnd.p_wnd = ft_create_sdl_window();
	m->wnd_img = SDL_GetWindowSurface(m->wnd.p_wnd);
	m->flags[CYCLE] = 1;
	m->flags[REDRAW] = 1;
	m->w = DISP_W;
	m->h = DISP_H;
	ft_init_textures(m);
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
