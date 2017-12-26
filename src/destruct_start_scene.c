/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_start_scene.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:18:39 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:18:40 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_sound_start(t_start *scene)
{
	Mix_FreeMusic(scene->mus->buf);
	free(scene->mus);
	scene->mus = NULL;
	Mix_FreeChunk(scene->chunk->buf);
	free(scene->chunk);
	scene->chunk = NULL;
}

void	ft_destruct_start(t_m *m, t_start *scene)
{
	ft_sdl_free_texture(scene->texture, START_TEX_SIZE);
	ft_free_sound_start(scene);
	if (scene->flags[S_DES_TYPE] == OFF)
	{
		m->m_flags[LOOP] = OFF;
		free(scene);
		m->data = NULL;
	}
	else
	{
		free(scene);
		m->data = NULL;
		ft_first_init_garden(m);
	}
}
