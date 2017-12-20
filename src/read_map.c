/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:51:15 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:51:18 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_map_seach_start(t_map *map, char *src, t_v2d *cord)
{
	if (*src == 'S')
	{
		if (cord->y == 0 || cord->y == map->height - 1
			|| cord->x == 0 || cord->x == map->width - 1)
			ft_error(13);
		map->start.x = cord->x;
		map->start.y = cord->y;
		map->arr[cord->y][cord->x] = 0;
		cord->x++;
	}
	return (src + 1);
}

void	ft_valid_num(t_map *map, char *src, t_v2d *cord)
{
	map->arr[cord->y][cord->x] = ft_atoi(src);
	if ((cord->y == 0 || cord->y == map->height - 1) &&
		map->arr[cord->y][cord->x] <= 0)
		ft_error(11);
	if ((cord->x == 0 || cord->x == map->width - 1) &&
		map->arr[cord->y][cord->x] <= 0)
		ft_error(11);
	cord->x++;
	if (cord->x == map->width && cord->y < map->height - 1)
	{
		cord->x = 0;
		cord->y++;
	}
}

void	ft_fill_map(t_map *map, char *src)
{
	t_v2d cord;

	cord = (t_v2d){0, 0};
	while (*src != '\0')
	{
		if (!ft_isdigit(*src))
			src = ft_map_seach_start(map, src, &cord);
		else
		{
			ft_valid_num(map, src, &cord);
			while (ft_isdigit(*src))
				src++;
		}
	}
}

void	ft_read_map(t_map *map, char *f_name)
{
	char *src;
	char *ptr;

	map->start = (t_v2d){-1, -1};
	src = ft_load_file(f_name);
	ptr = src;
	ptr = ft_get_map_size(map, ptr);
	map->arr = ft_create_2d_int_arr(map->height, map->width);
	ft_bzero_2d_arr(map->height, map->width, map->arr);
	ft_fill_map(map, ptr);
	free(src);
}
