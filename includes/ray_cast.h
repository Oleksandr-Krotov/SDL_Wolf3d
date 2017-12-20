/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:51:25 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 11:51:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# include "type.h"

typedef struct s_rc	t_rc;

struct	s_rc
{
	t_v2f	pos;
	t_v2f	dir;
	t_v2f	delta;
	t_v2f	side_dist;
	t_v2d	step;
	t_v2d	map;
	double	dist;
	double	wall_x;
	int		side;
	int		line_h;
	int		start_y;
	int		end_y;
	int		tex_num;
	int		tex_x;
};

typedef struct s_ds	t_ds;

struct	s_ds
{
	t_v2f	sprite;
	double	inv_det;
	t_v2f	trans;
	int		scr_x;
	int		height;
	int		width;
	t_v2d	start;
	t_v2d	end;
	t_v2d	tex;
	int		tex_2;
	int		v_mv_scr;
	t_tex	*sprt_ptr;
};

#endif
