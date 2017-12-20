/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:04:22 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:04:24 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_v2f	ft_calc_delta(t_v2f dir)
{
	t_v2f delta;

	delta.x = (sqrt(1 + pow(dir.y, 2) / pow(dir.x, 2)));
	delta.y = (sqrt(1 + pow(dir.x, 2) / pow(dir.y, 2)));
	return (delta);
}

void	ft_init_dda(t_rc *rc)
{
	if (rc->dir.x < 0)
	{
		rc->step.x = -1;
		rc->side_dist.x = (rc->pos.x - rc->map.x) * rc->delta.x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist.x = (rc->map.x + 1.0 - rc->pos.x) * rc->delta.x;
	}
	if (rc->dir.y < 0)
	{
		rc->step.y = -1;
		rc->side_dist.y = (rc->pos.y - rc->map.y) * rc->delta.y;
	}
	else
	{
		rc->step.y = 1;
		rc->side_dist.y = (rc->map.y + 1.0 - rc->pos.y) * rc->delta.y;
	}
}

void	ft_dda(t_rc *rc, t_map map)
{
	while (map.arr[rc->map.x][rc->map.y] == 0)
	{
		if (rc->side_dist.x < rc->side_dist.y)
		{
			rc->side_dist.x += rc->delta.x;
			rc->map.x += rc->step.x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist.y += rc->delta.y;
			rc->map.y += rc->step.y;
			rc->side = 1;
		}
	}
}
