/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_update_window_size.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:12:36 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:12:55 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

void	ft_sdl_get_wnd_size(t_sdl *sdl)
{
	SDL_GetWindowSize(sdl->wnd, &sdl->w, &sdl->h);
}

void	ft_sdl_update_window(SDL_Renderer *rend)
{
	SDL_RenderPresent(rend);
	SDL_RenderClear(rend);
}
