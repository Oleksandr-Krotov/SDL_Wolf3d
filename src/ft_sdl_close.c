/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:11:24 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:11:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

void	ft_sdl_close(t_sdl *sdl)
{
	Mix_CloseAudio();
	TTF_Quit();
	SDL_DestroyRenderer(sdl->rend);
	SDL_DestroyWindow(sdl->wnd);
	SDL_Quit();
}
