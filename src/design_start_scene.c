/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disign_start_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:18:45 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:18:46 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_sdl_draw_start(SDL_Renderer *rend, t_tex **texture, int *flags)
{
	static int i;

	SDL_RenderCopy(rend, texture[flags[S_FRAME]]->buf, NULL, NULL);
	if (flags[S_FRAME] == S_BG)
	{
		SDL_RenderCopy(rend, texture[S_PRESS]->buf, NULL, NULL);
		SDL_SetTextureAlphaMod(texture[S_PRESS]->buf, (Uint8)i);
		i++;
	}
}

void	ft_event_hook_start(t_m *m, t_start *scene)
{
	if (m->event.poll.type == SDL_KEYDOWN)
	{
		if (m->event.poll.key.keysym.sym == SDLK_RETURN)
			scene->flags[S_FRAME] = S_LIGHT;
		else if (m->event.poll.key.keysym.sym == SDLK_ESCAPE)
		{
			scene->flags[S_DES_TYPE] = OFF;
			scene->flags[S_STAGE] = DESTRUCT;
		}
	}
}

void	ft_event_start(t_chunk *chunk, int *flags)
{
	if (flags[S_FRAME] == S_LIGHT && flags[S_EVENT] == ON)
	{
		Mix_PlayChannel(chunk->chanel, chunk->buf, 0);
		flags[S_EVENT] = OFF;
		flags[S_STAGE] = DESTRUCT;
		SDL_Delay(4000);
	}
}

void	ft_design_start(t_m *m, t_start *scene)
{
	ft_event_start(scene->chunk, scene->flags);
	ft_event_hook_start(m, scene);
	ft_sdl_draw_start(m->sdl.rend, scene->texture, scene->flags);
}
