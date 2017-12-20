/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rc_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:10:29 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:10:30 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_v2f	ft_calc_ray_dir(int wnd_w, t_player pl, int x)
{
	double	camera_x;
	t_v2f	dir;

	camera_x = (2 * x / (double)wnd_w - 1);
	dir.x = pl.dir.x + pl.cam.plane.x * camera_x;
	dir.y = pl.dir.y + pl.cam.plane.y * camera_x;
	return (dir);
}

double	ft_calc_wall_dist(t_rc *rc)
{
	if (rc->side == 0)
		rc->dist = (rc->map.x - rc->pos.x + (1 - rc->step.x) / 2) / rc->dir.x;
	else
		rc->dist = (rc->map.y - rc->pos.y + (1 - rc->step.y) / 2) / rc->dir.y;
	return (rc->dist);
}

void	ft_calc_line(t_rc *rc, int wnd_h)
{
	rc->line_h = (int)(wnd_h / rc->dist);
	rc->start_y = -(rc->line_h) / 2 + wnd_h / 2;
	rc->end_y = rc->line_h / 2 + wnd_h / 2;
}

void	ft_calc_walx(t_rc *rc)
{
	if (rc->side == 0)
		rc->wall_x = rc->pos.y + rc->dist * rc->dir.y;
	else
		rc->wall_x = rc->pos.x + rc->dist * rc->dir.x;
	rc->wall_x -= floor(rc->wall_x);
}

void	ft_calc_tex_x(t_rc *rc, t_tex **tex)
{
	rc->tex_x = (int)(rc->wall_x * (double)(tex[rc->tex_num]->w));
}
