/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:21:03 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:21:04 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include "fps.h"

double	ft_smooth_delta(double old, double current)
{
	return (current * SMOOTH) + (old) * (1.0 - SMOOTH);
}

void	ft_fps(t_time *time)
{
	time->old = time->current;
	time->current = clock();
	time->current = ft_smooth_delta(time->old, time->current);
	time->delta = ((time->current - time->old) / CLOCKS_PER_SEC);
	time->fps = (int)(1 / time->delta);
}

int		ft_counter(int *storage, int fps, int limit)
{
	*storage += fps;
	if (*storage >= limit)
	{
		*storage = 0;
		return (1);
	}
	else
		return (0);
}
