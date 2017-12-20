/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_garden.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:17:34 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 14:17:35 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_load_tex_garden(SDL_Renderer *rend, t_scene *scene)
{
	if ((scene->texture = malloc(sizeof(t_tex *) * G_TEX_NUM)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	scene->texture[CRASH] = ft_sdl_load_texture(rend, P_G_CRASH);
	scene->texture[DARK_MOSS] = ft_sdl_load_texture(rend, P_G_DARK_MOSS);
	scene->texture[FEN_STONE] = ft_sdl_load_texture(rend, P_G_FEN_STONE);
	scene->texture[GREEN_BRK] = ft_sdl_load_texture(rend, P_G_GREEN_BRK);
	scene->texture[GREEN_BRK2] = ft_sdl_load_texture(rend, P_G_GREEN_BRK2);
	scene->texture[HEDGE] = ft_sdl_load_texture(rend, P_G_HEDGE);
	scene->texture[IVY_WALL] = ft_sdl_load_texture(rend, P_G_IVY_WALL);
	scene->texture[MOSSY_ROCK] = ft_sdl_load_texture(rend, P_G_MOSSY_ROCK);
	scene->texture[GATE] = ft_sdl_load_texture(rend, P_G_GATE);
}

void	ft_load_sprite_garden(SDL_Renderer *rend, t_sprite *sprite)
{
	if ((sprite->buff = malloc(sizeof(t_tex *) * G_SPTR_NUM)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	sprite->buff[COLONIT] = ft_sdl_load_texture(rend, P_G_COLONIT);
	sprite->buff[VANGUARD] = ft_sdl_load_texture(rend, P_G_VANGUARD);
	sprite->buff[KEY] = ft_sdl_load_texture(rend, P_G_KEY);
	sprite->buff[TORCH] = ft_sdl_load_texture(rend, P_G_TORCH);
}

void	ft_load_sound_garden(t_scene *scene)
{
	scene->mus = ft_sdl_load_music(P_G_MUS_BG, MIX_MAX_VOLUME / 2);
	if ((scene->chunk = malloc(sizeof(t_chunk *) * G_CHUNK_NUM)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	scene->chunk[CHUNK_WOUND] =
			ft_sdl_load_chunk(P_G_CHUNK_WOUND, C_EFFECT, MIX_MAX_VOLUME / 3);
	scene->chunk[CHUNK_SCREAM] =
			ft_sdl_load_chunk(P_G_CHUNK_SCREAM, C_EVENT, MIX_MAX_VOLUME);
	scene->chunk[CHUNK_LOCK] =
			ft_sdl_load_chunk(P_G_CHUNK_LOCK, C_EVENT, MIX_MAX_VOLUME / 2);
	scene->chunk[CHUNK_GATE] =
			ft_sdl_load_chunk(P_G_CHUNK_GATE, C_EVENT, MIX_MAX_VOLUME / 2);
	scene->chunk[CHUNK_CROW] =
			ft_sdl_load_chunk(P_G_CHUNK_CROW, C_EVENT, MIX_MAX_VOLUME / 2);
	scene->chunk[CHUNK_KEY] =
			ft_sdl_load_chunk(P_G_CHUNK_KEY, C_EVENT, MIX_MAX_VOLUME / 2);
	scene->chunk[CHUNK_GRAVE_W] =
			ft_sdl_load_chunk(P_G_CHUNK_GRAVE_W, C_EVENT, MIX_MAX_VOLUME / 2);
	scene->chunk[CHUNK_MOO] =
			ft_sdl_load_chunk(P_G_CHUNK_MOO, C_EVENT, MIX_MAX_VOLUME);
}

void	ft_load_assets_garden(t_m *m, t_scene *scene)
{
	ft_load_tex_garden(m->sdl.rend, scene);
	ft_load_sprite_garden(m->sdl.rend, &scene->sprt);
	ft_load_sound_garden(scene);
}
