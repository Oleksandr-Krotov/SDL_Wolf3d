/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl_insomnia.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:31:25 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 14:31:26 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_sdl_all(t_sdl *sdl)
{
	ft_sdl_init();
	ft_sdl_ttf_init();
	ft_sdl_init_sound(MIX_INIT_MP3 | MIX_INIT_MOD | MIX_INIT_OGG);
	ft_sdl_crete_wnd_and_rend(DISP_W, DISP_H, SDL_WINDOW_RESIZABLE, sdl);
	SDL_SetWindowTitle(sdl->wnd, "INSOMNIA");
	SDL_SetWindowMinimumSize(sdl->wnd, 320, 240);
	SDL_RenderClear(sdl->rend);
}
