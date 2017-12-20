/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scream_event_garden.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:21:49 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:21:50 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_scream_smile_garden(t_m *m, t_scene *scene)
{
	if (scene->flags[G_SCREAM] == 1 && (int)m->player.pos.x == 8 &&
		(int)m->player.pos.y == 11)
	{
		Mix_PauseMusic();
		SDL_Delay(300);
		SDL_RenderCopy(m->sdl.rend, m->bar[SCREAM]->buf, NULL, NULL);
		scene->flags[G_SCREAM] = 2;
	}
	else if (scene->flags[G_SCREAM] == 2 && (int)m->player.pos.x == 8 &&
			(int)m->player.pos.y == 11)
	{
		Mix_PlayChannel(3, scene->chunk[CHUNK_SCREAM]->buf, 0);
		SDL_Delay(2000);
		m->player.state.hp = (int)fmax(0, m->player.state.hp - 10);
		Mix_PlayChannel(3, scene->chunk[CHUNK_WOUND]->buf, 0);
		Mix_ResumeMusic();
		scene->flags[G_SCREAM] = 0;
	}
}
