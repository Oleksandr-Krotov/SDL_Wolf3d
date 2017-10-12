#include "wolf3d.h"

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not init. SDL Err: %s\n", SDL_GetError());
		ft_error(2);
	}
}

void	ft_ttf_init(t_m *m)
{
	TTF_Init();
	m->font.path = "assets/fonts/OpenSans-SemiBold.ttf";
	m->font.type = TTF_OpenFont(m->font.path, 16);
	m->font.color = (SDL_Color){255, 255, 255, 0};
}

void	ft_init_player(t_m *m)
{
	m->p.pos.y = m->map.start.x;
	m->p.pos.x = m->map.start.y;
	m->p.dir.x = -1;
	m->p.dir.y = 0;
	if((m->p.arm[TORCH].texture = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/torch.png")) == NULL)
		ft_error(5);
	m->p.arm[TORCH].status = 0;
}

void	ft_init_cam(t_m *m)
{
	m->cam.plane_x = 0;
	m->cam.plane_y = 0.66;
	m->cam.camera_x = 0;
}

void	ft_load_texture_pack_img(t_m *m)
{
	if((m->textures.buf[0] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/eagle.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[1] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/redbrick.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[2] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/purplestone.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[3] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/greystone.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[4] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/bluestone.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[5] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/mossy.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[6] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/wood.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[7] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/colorstone.png")) == NULL)
		ft_error(5);
	if((m->textures.buf[8] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/crash.png")) == NULL)
		ft_error(5);
	if((m->scream = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/scream.png")) == NULL)
		ft_error(5);
}

void	ft_init_textures(t_m *m)
{
	m->textures.w = TXTR_W;
	m->textures.h = TXTR_H;
	ft_load_texture_pack_img(m);
}

void	ft_init(t_m *m)
{
	ft_init_sdl();
	ft_ttf_init(m);
	if (SDL_CreateWindowAndRenderer(DISP_W, DISP_H, SDL_WINDOW_RESIZABLE, &m->wnd.p_wnd, &m->wnd.p_rend))
		ft_error(3);
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
		SDL_Log("Culd't init Mixer!\n");
	m->flags[CYCLE] = 1;
	m->flags[REDRAW] = 1;
	m->flags[FIRE] = 1;
	m->flags[SCREAM] = 1;
	m->w = DISP_W;
	m->h = DISP_H;
	ft_init_textures(m);
	ft_init_player(m);
	ft_init_cam(m);
	m->time.cur = 0;
	m->time.old = 0;
	m->music.bg = Mix_LoadWAV("assets/h3f.wav");
	SDL_PauseAudio(0);
}

int		main(int argc, char **argv)
{
	t_m	m;

	if (argc != 2)
		ft_error(1);
	m.map.start.x = -1;
	m.map.start.y = -1;
	ft_read_map(&m, argv[1]);
	ft_init(&m);
	ft_main_loop(&m);
	ft_sdl_close(&m);
	return (0);
}
