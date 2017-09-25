#include "wolf3d.h"

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		printf("SDL could not init. SDL Err: %s\n", SDL_GetError());
	ft_error(-1);
}

void	ft_init_prm(t_id *id)
{
	;
}

void	ft_set_window_prm(t_wnd *wnd, int wid, int hei, const char *name)
{
	wnd->wid = wid;
	wnd->hei = hei;
	wnd->name = name;
}

SDL_Window *ft_create_sdl_window(t_wnd *wnd)
{
	SDL_Window *p_wnd;
	p_wnd = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, wnd->wid, wnd->hei, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	if (p_wnd == NULL)
	{
		printf("Window could not create. SDL Err: %s\n", SDL_GetError());
		ft_error(-2);
	}
	return (p_wnd);
}

void	ft_sdl_loop(t_id *id)
{
	SDL_Event wnd_event;

	ft_ray_cast(id->imgs[0]);
	while (1)
	{
		if (SDL_PollEvent(&wnd_event))
			if (wnd_event.type == SDL_QUIT)
				break;
		SDL_BlitSurface(id->imgs[0], NULL, id->wnd_img, NULL);
		SDL_UpdateWindowSurface(id->wnd.p_wnd);
	}
}

int main(int argc, char *argv[])
{
	t_id	id;

	ft_init_sdl();
	ft_init_prm(&id);
	ft_set_window_prm(&id.wnd, 1900, 1100, "TEST");
	id.wnd.p_wnd = ft_create_sdl_window(&id.wnd);
	id.wnd_img = SDL_GetWindowSurface(id.wnd.p_wnd);
	if ((id.imgs[0] = SDL_CreateRGBSurface(0, 500, 500, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff)) == NULL)
	{
		SDL_Log("SDL_CreateRGBSurfaceWithFormat() failed: %s", SDL_GetError());
		exit(1);
	}
	SDL_FillRect(id.imgs[0], NULL, SDL_MapRGB(id.imgs[0]->format, 255, 0, 0));
	ft_sdl_loop(&id);

	SDL_FreeSurface(id.imgs[0]);
	SDL_FreeSurface(id.wnd_img);
	id.imgs[0] = NULL;
	id.wnd_img = NULL;
	SDL_DestroyWindow(id.wnd.p_wnd);
	SDL_Quit();

	return (0);
}
