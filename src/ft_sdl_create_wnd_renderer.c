/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_create_wnd_renderer.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:11:39 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:11:41 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

void	ft_sdl_crete_wnd_and_rend(unsigned int width, unsigned int height,
									SDL_WindowFlags flag, t_sdl *sdl)
{
	if (SDL_CreateWindowAndRenderer(width, height, flag,
		&sdl->wnd, &sdl->rend) < 0)
	{
		SDL_Log("Can't create window or rend! SDL Err: %s\n", SDL_GetError());
		SDL_Quit();
	}
	sdl->w = width;
	sdl->h = height;
}
