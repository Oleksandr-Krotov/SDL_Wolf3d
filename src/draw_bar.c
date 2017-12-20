/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:19:04 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:19:41 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_bar(t_m *m, t_scene *sc)
{
	SDL_Rect	dst;
	char		str[4];

	sprintf(str, "%d", m->player.state.hp);
	dst = ft_sdl_set_rect(m->sdl.w - (int)(m->sdl.w * 0.1),
		m->sdl.h - (int)(m->sdl.h * 0.12),
		(int)(m->sdl.w * 0.09), (int)(m->sdl.h * 0.11));
	SDL_RenderCopy(m->sdl.rend, m->bar[HP]->buf, NULL, &dst);
	ft_sdl_draw_text(&m->sdl, *m->font, str,
					(t_v2d){(int)(m->sdl.w - (m->sdl.w * 0.15)),
						(int)(m->sdl.h - (m->sdl.h * 0.1))});
	if (sc->flags[G_KEY] == TRUE)
	{
		SDL_SetTextureColorMod(sc->sprt.buff[KEY]->buf, 255, 255, 255);
		dst = ft_sdl_set_rect((int)(m->sdl.w * 0.01), m->sdl.h / 2,
								(int)(m->sdl.w * 0.1), (int)(m->sdl.h * 0.1));
		SDL_RenderCopy(m->sdl.rend, sc->sprt.buff[KEY]->buf, NULL, &dst);
	}
}
