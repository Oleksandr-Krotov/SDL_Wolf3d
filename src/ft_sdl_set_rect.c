/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_set_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:12:14 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:12:15 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

SDL_Rect	ft_sdl_set_rect(int x, int y, int w, int h)
{
	SDL_Rect ret;

	ret.x = x;
	ret.y = y;
	ret.w = w;
	ret.h = h;
	return (ret);
}
