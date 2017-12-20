/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:40:56 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/29 14:40:57 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->arr[i]);
		map->arr[i] = NULL;
		i++;
	}
	free(map->arr);
	map->arr = NULL;
}
