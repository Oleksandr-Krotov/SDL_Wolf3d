#include "wolf3d.h"


SDL_Surface	*sdl_create_img(int width, int height)
{
	SDL_Surface *surface_ptr;

	if ((surface_ptr = SDL_CreateRGBSurface(0, width, height, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff)) == NULL)
	{
		SDL_Log("SDL_CreateRGBSurfaceWithFormat() failed: %s", SDL_GetError());
		exit(1);
	}
	return (surface_ptr);
}

void	sdl_destroy_img(SDL_Surface *surface)
{
	SDL_FreeSurface(surface);
	surface = NULL;
}

void	sdl_close(t_id *id)
{
	SDL_DestroyWindow(id->wnd.p_wnd);
	sdl_destroy_img(id->imgs);
	sdl_destroy_img(id->wnd_img);
	SDL_Quit();
}

void	ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not init. SDL Err: %s\n", SDL_GetError());
		ft_error(-1);
	}
}

void	ft_create_sdl_window(SDL_Window *window)
{
	 window = SDL_CreateWindow(D_NAME,
							 SDL_WINDOWPOS_CENTERED,
							 SDL_WINDOWPOS_CENTERED,
							 D_WIDTH,
							 D_HEIGHT,
							 SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not create. SDL Err: %s\n", SDL_GetError());
		ft_error(-2);
	}
}

void	ft_sdl_loop(t_id *id)
{
	SDL_Event wnd_event;
	Uint8 red = (Uint8)(rand() % 255);
	Uint8 green = (Uint8)(rand() % 255);
	Uint8 blue = (Uint8)(rand() % 255);

	while (1)
	{
		if (SDL_PollEvent(&wnd_event))
			if (wnd_event.type == SDL_QUIT)
				break;
		id->imgs = sdl_create_img(D_WIDTH, D_HEIGHT);
		SDL_FillRect(id->imgs, NULL, SDL_MapRGB(id->imgs->format, red, green, blue));
		SDL_BlitSurface(id->imgs, NULL, id->wnd_img, NULL);
		SDL_UpdateWindowSurface(id->wnd.p_wnd);
		sdl_destroy_img(id->imgs);
	}
}

int		main(int argc, char **argv)
{
	t_id	id;

	ft_init_sdl();
	ft_create_sdl_window(id.wnd.p_wnd);
	id.wnd_img = SDL_GetWindowSurface(id.wnd.p_wnd);
	ft_sdl_loop(&id);
	id.imgs = sdl_create_img(800, 600);
	sdl_close(&id);
	return (0);
}
