/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disign_garden.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:20:45 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:20:46 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_sound_event(t_v2f pos, t_chunk **chunk, int *flags)
{
	if (flags[G_CROW] == ON && (int)pos.x == 13 && (int)pos.y == 5)
	{
		Mix_VolumeChunk(chunk[CHUNK_CROW]->buf, MIX_MAX_VOLUME);
		Mix_PlayChannel(3, chunk[CHUNK_CROW]->buf, 0);
		flags[G_CROW] = OFF;
	}
	if (flags[G_KEY] == OFF && (int)pos.x == 4 && (int)pos.y == 1)
		Mix_PlayChannel(3, chunk[CHUNK_KEY]->buf, 0);
	if (flags[G_WALK] == ON && (int)pos.x == 18 && (int)pos.y == 7)
	{
		Mix_PlayChannel(3, chunk[CHUNK_GRAVE_W]->buf, 0);
		flags[G_WALK] = OFF;
	}
	if (flags[G_MOO] == ON && flags[G_KEY] == TRUE &&
			(int)pos.x == 11 && (int)pos.y == 1)
	{
		Mix_PlayChannel(3, chunk[CHUNK_MOO]->buf, 0);
		flags[G_MOO] = OFF;
	}
}

void	ft_event_manager(t_m *m, t_scene *scene)
{
	ft_sound_event(m->player.pos, scene->chunk, scene->flags);
	ft_scream_smile_garden(m, scene);
	if (scene->flags[G_TORCH] == OFF)
	{
		m->player.timer += m->time.fps;
		if (m->player.timer > T_HP)
		{
			m->player.state.hp -= 5;
			m->player.timer = 0;
			Mix_PlayChannel(4, scene->chunk[CHUNK_WOUND]->buf, 0);
		}
		if (m->player.state.hp <= 0)
		{
			scene->flags[G_GAME] = OVER;
			scene->flags[G_STAGE] = DESTRUCT;
		}
	}
	SDL_SetTextureAlphaMod(m->bar[WOUND]->buf,
							(Uint8)(255 * (100 - m->player.state.hp) / 100.0));
	SDL_RenderCopy(m->sdl.rend, m->bar[WOUND]->buf, NULL, NULL);
}

void	ft_garden_event(t_m *m, t_scene *sc)
{
	ft_get_drop(m, sc->sprt.in, sc, sc->flags);
	ft_torch_event(m, sc);
	ft_event_manager(m, sc);
}

void	ft_design_garden(t_m *m, t_scene *scene)
{
	ft_event_hook_garden(m, scene);
	ft_ray_cast(&m->sdl, scene, m->player, m->zbuff);
	ft_garden_event(m, scene);
	ft_draw_bar(m, scene);
	ft_put_msg_to_screen(m, scene);
}
