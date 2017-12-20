/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:05:12 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:05:14 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_ray_cast(t_sdl *sdl, t_scene *scene, t_player player, double *z_buff)
{
	t_rc	rc;
	int		x;

	rc.pos = player.pos;
	x = 0;
	while (x < sdl->w)
	{
		rc.map.x = (int)rc.pos.x;
		rc.map.y = (int)rc.pos.y;
		rc.dir = ft_calc_ray_dir(sdl->w, player, x);
		rc.delta = ft_calc_delta(rc.dir);
		ft_init_dda(&rc);
		ft_dda(&rc, scene->map);
		z_buff[x] = ft_calc_wall_dist(&rc);
		ft_calc_line(&rc, sdl->h);
		ft_get_texture_num(&rc, &scene->map, scene->flags[G_TEX_SIZE]);
		ft_calc_walx(&rc);
		ft_calc_tex_x(&rc, scene->texture);
		ft_draw_line_wall(sdl->rend, &rc, scene, x);
		x++;
	}
	ft_sort_sprite(scene, &player, &rc, scene->flags[G_SPRITE]);
	ft_ray_cast_sprt(sdl, scene, &player, z_buff);
}
