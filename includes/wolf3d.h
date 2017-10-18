#ifndef WOLF3D_H
# define WOLF3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <SDL2/SDL.h>
#if __APPLE__
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#endif
#include <math.h>
#include <time.h>

#include "libft.h"
#include "define.h"
#include "arr_2d.h"


enum e_game
{
	START,
	OVER,
	EXIT
};
typedef struct s_wnd	t_wnd;
typedef struct s_disp	t_disp;
typedef struct s_font	t_font;
typedef struct s_rgb	t_rgb;
typedef struct s_txtrs	t_txtrs;
typedef struct s_sprite_in	t_sprite_in;
typedef struct s_sprite		t_sprite;
typedef struct s_torch_time t_torch_time;
typedef struct s_v2f	t_v2f;
typedef struct s_v2d	t_v2d;
typedef struct s_map	t_map;
typedef struct s_arm	t_arm;
typedef struct s_player	t_player;
typedef struct s_flags	t_flags;
typedef struct s_cam	t_cam;
typedef struct s_dda	t_dda;
typedef struct s_time	t_time;
typedef struct s_rc		t_rc;
typedef struct s_draw	t_draw;
typedef struct s_draw_sprite t_draw_sprite;
typedef struct s_audio	t_audio;
typedef struct s_m		t_m;

struct s_rgb
{
	Uint8		r;
	Uint8		g;
	Uint8		b;
};

struct s_txtrs
{
	int w;
	int h;
	int half;
	SDL_Texture *buf[TXTR_SIZE];
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

struct s_arm
{
	int			status;
	SDL_Texture	*texture;
};

struct s_sprite_in
{
	double		x;
	double		y;
	int			texture;
	double		u_div;
	double		v_div;
	double		v_move;
	int			visible;
};

struct s_sprite
{
	int			order[SPRITE_SIZE];
	double		dist[SPRITE_SIZE];
	double		*zbuff;
	t_sprite_in	in[SPRITE_SIZE];
};

struct s_torch_time
{
	int 		status;
	int 		hp;
	int 		count;
	SDL_Texture *rope;
	SDL_Texture *spark;
};

struct s_player
{
	t_v2f		pos;
	t_v2f		dir;
	t_arm		arm[OUTFIT];
	double		old_x;
	double		ms;
	double		rs;
	int			hp;
	int			count;
	SDL_Texture *heart;
	SDL_Texture *wound;
	SDL_Texture *die;
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
	int			h;
	int			start_y;
	int			end_y;
	int			tex_num;
	int 		tex_x;
};

struct s_draw_sprite
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	trans_x;
	double	trans_y;
	int		screen_x;
	int		height;
	int		width;
	int 	start_x;
	int 	start_y;
	int 	end_x;
	int 	end_y;
	int		tex_x;
	int		tex_y;
	int		tex_y2;
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

struct	s_wnd
{
	SDL_Window		*p_wnd;
	SDL_Renderer	*p_rend;
	int w;
	int h;
	int old_w;
};

struct s_audio
{
	int			volume;
	int			status;
	Mix_Music	*audio;
	Mix_Chunk	*screamer;
	Mix_Chunk	*wound;
};

struct s_m
{
	int				flags[FLAGS];
	t_wnd			wnd;
	t_font			font;
	t_map			map;
	t_txtrs			tex;
	t_sprite		sprite;
	t_player		p;
	t_cam			cam;
	t_dda			dda;
	t_rc			rc;
	t_draw			main_draw;
	t_draw_sprite	sprite_draw;
	t_torch_time	torch;
	t_time			time;
	SDL_Texture     *scream;
	SDL_Texture     *crash;
	t_audio			music;
	int 			h_m_thh;
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
void		ft_sdl_draw_text(t_wnd *wnd, t_font font, char *str, t_v2d xy);
void		ft_sdl_close(t_m *m);
void		ft_sdl_put_uint32(SDL_Surface *img, int x, int y, Uint32 color);
void		ft_sdl_put_pixel(SDL_Surface *img, int x, int y, SDL_Color color);
SDL_Rect	ft_sdl_set_rect(int x, int y, int w, int h);
char		*ft_load_file(const char *f_name);
void		ft_combo_sort(int *order, double *dist, int amount);

void		ft_exit(t_m *m);
void		ft_error(int error);

void		ft_fps(t_m *m);
#endif
