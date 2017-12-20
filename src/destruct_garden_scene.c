/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct_garden_scene.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:20:20 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:20:23 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_sprite(t_scene *scene)
{
	free(scene->sprt.in);
	scene->sprt.in = NULL;
	free(scene->sprt.order);
	scene->sprt.order = NULL;
	free(scene->sprt.dist);
	scene->sprt.dist = NULL;
}

void	ft_free_sprite_garden(t_scene *scene)
{
	ft_sdl_free_texture(scene->sprt.buff, G_SPTR_NUM);
	free(scene->sprt.buff);
	ft_free_sprite(scene);
}

void	ft_free_assets_garden(t_scene *scene)
{
	ft_sdl_free_texture(scene->texture, G_TEX_NUM);
	free(scene->texture);
	ft_sdl_free_chunk(scene->chunk, G_CHUNK_NUM);
	free(scene->chunk);
	Mix_FreeMusic(scene->mus->buf);
	free(scene->mus);
	scene->mus = NULL;
	ft_free_sprite_garden(scene);
}

void	ft_garden_end(t_m *m, t_scene *sc)
{
	if (sc->flags[G_GAME] == OVER)
	{
		SDL_RenderCopy(m->sdl.rend, m->bar[DIE]->buf, NULL, NULL);
		SDL_RenderCopy(m->sdl.rend, m->bar[WOUND]->buf, NULL, NULL);
		SDL_Delay(3000);
		m->m_flags[LOOP] = OFF;
	}
	else if (sc->flags[G_GAME] == OPEN)
	{
		Mix_PauseMusic();
		Mix_PlayChannel(3, sc->chunk[CHUNK_GATE]->buf, 0);
		SDL_RenderCopy(m->sdl.rend, m->bar[OPEN_GARDEN]->buf, NULL, NULL);
	}
	if (sc->flags[G_GAME] == OVER || sc->flags[G_GAME] == OPEN)
	{
		SDL_RenderPresent(m->sdl.rend);
		SDL_Delay(6000);
		m->m_flags[LOOP] = OFF;
	}
	if (sc->flags[G_DES_TYPE] == OFF)
		m->m_flags[LOOP] = OFF;
}

void	ft_destruct_garden(t_m *m, t_scene *sc)
{
	ft_garden_end(m, sc);
	ft_free_map(&sc->map);
	ft_free_assets_garden(sc);
	free(sc->flags);
	free(m->data);
}
