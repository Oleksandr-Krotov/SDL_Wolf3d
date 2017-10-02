#ifndef WOLDF3D_H
# define WOLDF3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <math.h>
#include <time.h>

#include "libft.h"
#include "define.h"
#include "arr_2d.h"

typedef struct s_wnd	t_wnd;
typedef struct s_font	t_font;
typedef struct s_rgba	t_rgba;
typedef struct s_txtrs	t_txtrs;
typedef struct s_v2f	t_v2f;
typedef struct s_v2d	t_v2d;
typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_flags	t_flags;
typedef struct s_cam	t_cam;
typedef struct s_dda	t_dda;
typedef struct s_time	t_time;
typedef struct s_rc		t_rc;
typedef struct s_draw	t_draw;
typedef struct s_m		t_m;

struct s_rgba
{
	Uint8		r;
	Uint8		g;
	Uint8		b;
	Uint8		a;
};

struct s_txtrs
{
	int w;
	int h;
	Uint32 *buf[8];
};

struct s_v2f
{
	double x;
	double y;
};

struct	s_v2d
{
	int	x;
	int	y;
};

struct s_map
{
	int		row;
	int		col;
	t_v2f	start;
	int		**arr;
};

struct s_texture
{
	int w;
	int h;
	Uint32 *buffer[TXTR_SIZE];
};
struct s_player
{
	t_v2f	pos;
	t_v2f	dir;
	double	old_x;
	double	ms;
	double	rs;
};

struct s_cam
{
	double plane_x;
	double old_x;
	double plane_y;
	double camera_x;
};

struct s_dda
{
	double side_dist_x;
	double side_dist_y;
	double dx;
	double dy;
};

struct s_rc
{
	t_v2f	pos;
	t_v2f	dir;
	double	old_x;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	double	wall_dist;
	double 	wall_x;
};

struct s_draw
{
	int		line_h;
	int		draw_s;
	int		draw_e;
	t_rgba	color;
	int		tex_num;
	int 	tex_x;
};


struct s_time
{
	double cur;
	double old;
	double fps;
};

struct s_font
{
	TTF_Font	*type;
	SDL_Color	color;
	char		*path;
};

struct s_wnd
{
	SDL_Window	*p_wnd;
};

struct s_m
{
	int				flags[FLAGS];
	int				w;
	int				h;
	t_wnd			wnd;
	t_font			font;
	SDL_Surface		*imgs;
	SDL_Surface		*wnd_img;
	t_map			map;
	t_txtrs			texturs;
	t_player		p;
	t_cam			cam;
	t_dda			dda;
	t_rc			rc;
	t_draw			line;
	t_time			time;
};

int			ft_read_map(t_m *m, char *f_name);

void		ft_main_loop(t_m *m);
void		ft_move_forward(t_m *m, int mult);
void		ft_move_back(t_m *m, int mult);
void		ft_turn_left(t_m *m, int mult);
void		ft_turn_right(t_m *m, int mult);
void		ft_calc_img(t_m *m);

void		ft_sdl_update_window(t_m *m);

SDL_Window	*ft_create_sdl_window(void);
SDL_Surface	*sdl_create_rgba_img(int width, int height);

void		ft_sdl_event_hook(t_m *m);
void		ft_sdl_put_pixel(SDL_Surface *img, int x, int y, t_rgba color);
void		ft_sdl_draw_text(SDL_Surface *img, t_font font, char *str, t_v2d xy);
void		ft_sdl_close(t_m *m);

void		ft_exit(t_m *m);
void		ft_error(int error);

char		*ft_load_file(const char *f_name);

void		ft_fps(t_m *m);
#endif
