/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:22:25 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:22:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_get_map_with(t_map *map, char *src)
{
	src = ft_strstr(src, "W:");
	if (src == NULL)
		ft_error(7);
	src += 2;
	if (ft_isdigit(*src))
	{
		if ((map->width = ft_atoi(src)) > 1000)
			ft_error(8);
	}
	else
		ft_error(7);
	return (src);
}

char	*ft_get_map_height(t_map *map, char *src)
{
	src = ft_strstr(src, "H:");
	if (src == NULL)
		ft_error(8);
	src += 2;
	if (ft_isdigit(*src))
	{
		if ((map->height = ft_atoi(src)) > 1000)
			ft_error(8);
	}
	else
		ft_error(8);
	return (src);
}

char	*ft_get_map_size(t_map *map, char *src)
{
	src = ft_get_map_with(map, src);
	src = ft_get_map_height(map, src);
	src = ft_strstr(src, "Map:");
	if (src == NULL)
		ft_error(12);
	src += 4;
	if (map->width < 3 || map->height < 3)
		ft_error(11);
	return (src);
}
