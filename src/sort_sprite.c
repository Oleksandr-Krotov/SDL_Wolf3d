/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:10:42 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:10:46 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_sort_sprite(t_scene *scene, t_player *p, t_rc *rc, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		scene->sprt.order[i] = i;
		scene->sprt.dist[i] = (p->pos.x - scene->sprt.in[i].x) *
								(p->pos.x - scene->sprt.in[i].x) +
								(p->pos.y - scene->sprt.in[i].y) *
								(rc->pos.y - scene->sprt.in[i].y);
		i++;
	}
	ft_combo_sort(scene->sprt.order, scene->sprt.dist, size);
}
