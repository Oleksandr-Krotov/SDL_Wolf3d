#include "wolf3d.h"

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not init. SDL Err: %s\n", SDL_GetError());
		ft_error(2);
	}
}

void	ft_ttf_init(t_m *m)
{
	TTF_Init();
	m->font.path = "assets/fonts/OpenSans-SemiBold.ttf";
	m->font.type = TTF_OpenFont(m->font.path, 15);
	m->font.color = (SDL_Color){255, 255, 255, 0};
}

void	ft_init_player(t_m *m)
{
	m->p.pos.y = m->map.start.x;
	m->p.pos.x = m->map.start.y;
	m->p.dir.x = -1;
	m->p.dir.y = 0;
	if ((m->p.arm[TORCH].texture = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/torch.png")) == NULL)
		ft_error(5);
	m->p.hp = 100;
}

void	ft_init_torch(t_m *m)
{
	m->torch.status = TRUE;
	m->torch.hp = 100;
	m->torch.count = 0;
}

void	ft_init_cam(t_m *m)
{
	m->cam.plane_x = 0;
	m->cam.plane_y = 0.66;
	m->cam.camera_x = 0;
}

void	ft_load_texture_pack_img(t_m *m)
{
	if ((m->tex.buf[0] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/DarkMoss256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[1] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/FenStone_256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[2] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/green_brk256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[3] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/green_brk2_256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[4] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/gate.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[5] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/Hedge256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[6] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/IvyWall256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[7] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/MossyRock256.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[8] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/colonit.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[9] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/Vanguard.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[10] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/drop.png")) == NULL)
		ft_error(5);
	if ((m->tex.buf[11] = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/key2.png")) == NULL)
		ft_error(5);
	if ((m->scream = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/scream.png")) == NULL)
		ft_error(5);
	if ((m->msg = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/close_msg.png")) == NULL)
		ft_error(5);
	if ((m->torch.rope = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/rope2.png")) == NULL)
		ft_error(5);
	if ((m->torch.spark = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/spark.png")) == NULL)
		ft_error(5);
	if ((m->p.heart = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/hp.png")) == NULL)
		ft_error(5);
	if ((m->p.wound = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/wound.png")) == NULL)
		ft_error(5);
	if ((m->p.die = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/die.png")) == NULL)
		ft_error(5);
	if ((m->open = IMG_LoadTexture(m->wnd.p_rend, "assets/textures/open_swamp.png")) == NULL)
		ft_error(5);
}

void	ft_init_textures(t_m *m)
{
	m->tex.w = TXTR_W;
	m->tex.h = TXTR_H;
	m->tex.half = m->tex.w / 2;
	ft_load_texture_pack_img(m);
}

void	ft_init_sprite(t_m *m)
{
	m->sprite.in[0] = (t_sprite_in){3.5, 8, 8, 0.5, 0.5, 128, 1};
	m->sprite.in[1] = (t_sprite_in){7.5, 10, 9, 0.5, 0.5, 128, 1};
	m->sprite.in[3] = (t_sprite_in){1.5, 5, 9, 0.5, 0.5, 128, 1};
	m->sprite.in[4] = (t_sprite_in){1.5, 8.5, 10, 3, 3, 256, 1};
	m->sprite.in[5] = (t_sprite_in){8.5, 12.5, 10, 3, 3, 256, 1};
	m->sprite.in[6] = (t_sprite_in){11.5, 6.5, 10, 3, 3, 256, 1};
	m->sprite.in[7] = (t_sprite_in){16.5, 5.5, 10, 3, 3, 256, 1};
	m->sprite.in[8] = (t_sprite_in){5.5, 1.5, 11, 3, 3, 256, 1};
}

void	ft_init_sound(t_m *m)
{
	if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_MOD | MIX_INIT_OGG) == NULL)
		SDL_Log("Couldn't init Mixer");
	if (Mix_OpenAudio(44100, AUDIO_S16, 2, 4096 ) < 0)
		SDL_Log("Couldn't init Mixer!\n");
	m->music.audio = Mix_LoadMUS("assets/sounds/SwampBG.mp3");
	m->music.screamer = Mix_LoadWAV("assets/sounds/scream.wav");
	m->music.wound = Mix_LoadWAV("assets/sounds/wound.wav");
	m->music.lock = Mix_LoadWAV("assets/sounds/lock.wav");
	m->music.open = Mix_LoadWAV("assets/sounds/cemetery_gate.wav");
	m->music.crow = Mix_LoadWAV("assets/sounds/crow.wav");
	m->music.event = Mix_LoadWAV("assets/sounds/event.wav");
	m->music.walk = Mix_LoadWAV("assets/sounds/gravelwalk.wav");
	if (m->music.audio == NULL)
	{
		SDL_Log( "Couldn't load 1.mp3: %s\n",
				SDL_GetError());
		ft_exit(m);
	}
	m->music.volume = MIX_MAX_VOLUME / 4;
	m->music.status = 0;
	Mix_VolumeMusic(m->music.volume);
}

void	ft_init(t_m *m)
{
	ft_init_sdl();
	ft_init_sound(m);
	ft_ttf_init(m);
	if (SDL_CreateWindowAndRenderer(DISP_W, DISP_H, SDL_WINDOW_RESIZABLE , &m->wnd.p_wnd, &m->wnd.p_rend) < 0)
		ft_error(3);
	m->flags[GAME] = START;
	m->flags[REDRAW] = TRUE;
	m->flags[SCREAM] = TRUE;
	m->flags[KEY] = FALSE;
	m->flags[CROW] = TRUE;
	m->flags[WALK] = TRUE;
	m->wnd.w = DISP_W;
	m->wnd.h = DISP_H;
	m->wnd.old_w = m->wnd.w;
	m->sprite.zbuff = malloc(sizeof(double) * m->wnd.w);
	ft_init_textures(m);
	ft_init_sprite(m);
	ft_init_player(m);
	ft_init_torch(m);
	ft_init_cam(m);
	m->time.cur = 0;
	m->time.old = 0;
	SDL_PauseAudio(0);
}

int		main(int argc, char *argv[])
{
	t_m	m;
	if (argc == 1)
		ft_error(1);
	ft_read_map(&m, argv[1]);
	ft_init(&m);
	ft_main_loop(&m);
	ft_sdl_close(&m);
	return (0);
}
