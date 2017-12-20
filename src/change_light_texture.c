/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_light_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:03:57 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:03:58 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_calc_light_pow(SDL_Texture *texture, double dist, int flag)
{
	double dev;

	dev = dist > 0.5 ? dist : 0.5;
	if (!flag)
		SDL_SetTextureColorMod(texture,
			(Uint8)(35 / dev),
				(Uint8)(35 / dev),
					(Uint8)(35 / dev));
	else
		SDL_SetTextureColorMod(texture,
			(Uint8)(100 / dev),
				(Uint8)(65 / dev),
					(Uint8)(55 / dev));
}
