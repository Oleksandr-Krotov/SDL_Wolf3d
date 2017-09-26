#ifndef WOLDF3D_H
# define WOLDF3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <SDL2/SDL.h>
#include <libxml2/libxml/parser.h>

#include "libft.h"
#include "define.h"

typedef struct s_wnd	t_wnd;
typedef struct s_rgba	t_rgba;
typedef struct s_v2f	t_v2f;
typedef struct s_map	t_map;
typedef struct s_player t_player;
typedef struct s_flags	t_flags;
typedef struct s_cam	t_cam;
typedef struct s_m		t_m;

struct s_rgba{
	Uint8		r;
	Uint8		g;
	Uint8		b;
	Uint8		a;
};

struct s_v2f
{
	double x;
	double y;
};

struct s_map
{
	int w;
	int h;
	int *map;
};

struct s_player
{
	t_v2f pos;
	t_v2f dir;
};

struct s_cam
{
	double plane_x;
	double plane_y;
	double camera_x;
};

struct s_wnd
{
	SDL_Window	*p_wnd;
};

struct s_m
{
	t_wnd			wnd;
	int				flags[FLAGS];
	SDL_Surface		*imgs;
	SDL_Surface		*wnd_img;
	t_map			map;
};

void		ft_main_loop(t_m *m);
void		ft_draw_img(t_m *m);

void		ft_sdl_update_window(t_m *m);

SDL_Window	*ft_create_sdl_window(void);
SDL_Surface	*sdl_create_rgba_img(int width, int height);

void		ft_sdl_event_hook(t_m *m);
void		ft_sdl_put_pixel(SDL_Surface *img, int x, int y, t_rgba color);
void		ft_sdl_close(t_m *m);

void		ft_exit(t_m *m);
void		ft_error(int error);
#endif
