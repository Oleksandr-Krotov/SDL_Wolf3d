/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:13:23 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:13:24 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
** STD LIBS
*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <math.h>
# include <time.h>

/*
** CUSTOM LIBS
*/

# include "libft.h"
# include "arr_2d.h"
# include "error.h"
# include "type.h"
# include "mysdl.h"
# include "fps.h"
# include "define.h"
# include "ray_cast.h"

/*
** SCENE_HEADERS
*/

# include "start.h"
# include "garden.h"

enum	e_scene_type
{
	START,
	GARDEN,
	HOUSE,
	DUNGEON,
	DEAD,
	SCENE_NUM
};

enum	e_game
{
	CREATE,
	OVER,
	EXIT,
	OPEN
};

enum	e_scene_state
{
	INIT,
	DESIGN,
	DESTRUCT
};

enum	e_mutual_img
{
	HP,
	CLOSE_MSG,
	DIE,
	ROPE,
	SPARK,
	SCREAM,
	WOUND,
	TORCH_SPRITE,
	OPEN_GARDEN,
	INTRO,
	MUTUAL_IMG_NUM
};

typedef struct s_state		t_state;

struct	s_state
{
	int		hp;
	double	ms;
	double	rs;
};

typedef struct s_torch		t_torch;

struct	s_torch
{
	int		hp;
	int		count;
};

typedef struct s_camera	t_camera;

struct	s_camera
{
	t_v2f	plane;
};

typedef struct s_player	t_player;

struct	s_player
{
	t_v2f		pos;
	t_v2f		dir;
	t_camera	cam;
	t_state		state;
	int			timer;
};

typedef struct s_map		t_map;

struct	s_map
{
	int		width;
	int		height;
	t_v2d	start;
	int		**arr;
};

typedef struct s_sprite_in	t_sprite_in;

struct	s_sprite_in
{
	double		x;
	double		y;
	int			texture;
	double		u_div;
	double		v_div;
	double		v_move;
	int			visible;
};

typedef struct s_sprite	t_sprite;

struct	s_sprite
{
	int			*order;
	double		*dist;
	t_sprite_in	*in;
	t_tex		**buff;
};

typedef struct s_scene		t_scene;

struct	s_scene
{
	void		(*ft_stage[SCENE_STAGE])(void*, void*);
	t_tex		**texture;
	t_sprite	sprt;
	t_music		*mus;
	t_chunk		**chunk;
	int			*flags;
	t_map		map;
	t_torch		torch;
};

typedef struct s_start		t_start;

struct	s_start
{
	void		(*ft_stage[SCENE_STAGE])(void*, void*);
	t_tex		*texture[START_TEX_SIZE];
	t_music		*mus;
	t_chunk		*chunk;
	int			flags[S_FLAG_SIZE];
};

typedef struct s_m			t_m;

struct	s_m
{
	t_sdl		sdl;
	t_time		time;
	t_event		event;
	t_player	player;
	t_tex		**bar;
	t_font		*font;
	double		*zbuff;
	int			old_w;
	void		*data;
	void		(*ft_scene[SCENE_SIZE])(t_m *m);
	int			m_flags[FLAG_SIZE];
};

/*
** MAIN
*/
void	ft_main_init(t_m *m);
void	ft_main_loop(t_m *m);
void	ft_free_main(t_m *m);

/*
** MAIN INIT
*/
void	ft_sdl_all(t_sdl *sdl);
void	ft_init_all_scene(t_m *m);
void	ft_init_z_buff(t_m *m);
void	ft_recreate_z_buff(t_m *m);

/*
** START SCENE
*/
void	ft_start(t_m *m);
void	ft_first_init_start(t_m *m);
void	ft_init_start(t_m *m, t_start *scene);
void	ft_design_start(t_m *m, t_start *scene);
void	ft_destruct_start(t_m *m, t_start *scene);

/*
** EVENTS
*/
void	ft_torch_event(t_m *m, t_scene *sc);
void	ft_draw_bar(t_m *m, t_scene *sc);
void	ft_put_msg_to_screen(t_m *m, t_scene *sc);
void	ft_get_drop(t_m *m, t_sprite_in *lst, t_scene *sc, int *flags);

/*
** GARDEN SCENE
*/
void	ft_garden(t_m *m);
void	ft_first_init_garden(t_m *m);
void	ft_init_flags_garden(t_scene *scene);
void	ft_init_garden(t_m *m, t_scene *scene);
void	ft_load_assets_garden(t_m *m, t_scene *scene);
void	ft_design_garden(t_m *m, t_scene *scene);
void	ft_event_hook_garden(t_m *m, t_scene *sc);
void	ft_scream_smile_garden(t_m *m, t_scene *scene);
void	ft_destruct_garden(t_m *m, t_scene *sc);

/*
** READ MAP
*/
void	ft_read_map(t_map *map, char *f_name);
char	*ft_get_map_size(t_map *map, char *src);
void	ft_free_map(t_map *map);

/*
** RAY CAST
*/
void	ft_ray_cast(t_sdl *sdl, t_scene *sc, t_player player, double *z_buff);
t_v2f	ft_calc_delta(t_v2f dir);
void	ft_init_dda(t_rc *rc);
void	ft_dda(t_rc *rc, t_map map);
t_v2f	ft_calc_ray_dir(int wnd_w, t_player pl, int x);
double	ft_calc_wall_dist(t_rc *rc);
void	ft_calc_line(t_rc *rc, int wnd_h);
void	ft_calc_walx(t_rc *rc);
void	ft_calc_tex_x(t_rc *rc, t_tex **tex);
void	ft_get_texture_num(t_rc *rc, t_map *map, int tex_size);
void	ft_draw_line_wall(SDL_Renderer *rend, t_rc *rc, t_scene *sc, int x);
void	ft_sort_sprite(t_scene *scene, t_player *p, t_rc *rc, int size);
void	ft_ray_cast_sprt(t_sdl *sdl, t_scene *sc, t_player *pl, double *zbuff);
void	ft_calc_light_pow(SDL_Texture *texture, double dist, int flag);
void	ft_get_sprite_pos(t_scene *sc, t_player *pl, t_ds *ds, int i);
void	ft_get_sprite_transform(t_player *pl, t_ds *ds);
void	ft_get_start_end_y(t_sdl *sdl, t_ds *ds);
void	ft_get_start_end_x(t_sdl *sdl, t_ds *ds);
void	ft_get_sprite_w_end_h(t_sdl *sdl, t_ds *ds, t_sprite *sprite, int i);
void	ft_draw_sprite_stripe(t_sdl *sdl, t_scene *sc, t_ds *ds, double *zbuff);

/*
** CONTROL
*/
void	ft_move_forward(t_map *map, t_player *p, double mult);
void	ft_move_back(t_map *map, t_player *p, double mult);
void	ft_turn_left(t_player *p, double mult);
void	ft_turn_right(t_player *p, double mult);
void	ft_do_action(t_scene *sc, t_player *p);

/*
** USEFUL FEATURES
*/
char	*ft_load_file(const char *f_name);
void	ft_combo_sort(int *order, double *dist, int size);

#endif
