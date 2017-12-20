/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:18:52 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:18:53 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_load_tex_start(SDL_Renderer *rend, t_tex **tex)
{
	tex[S_BG] = ft_sdl_load_texture(rend, P_S_BG);
	tex[S_LIGHT] = ft_sdl_load_texture(rend, P_S_LIGHT);
	tex[S_PRESS] = ft_sdl_load_texture(rend, P_S_PRESS);
}

void	ft_load_sound_start(t_start *scene)
{
	scene->mus = ft_sdl_load_music(P_S_MUS_BG, MIX_MAX_VOLUME / 2);
	scene->chunk = ft_sdl_load_chunk(P_S_CHUNK_LIGHT, C_EVENT, 100);
}

void	ft_load_assets_start(t_m *m, t_start *scene)
{
	ft_load_tex_start(m->sdl.rend, scene->texture);
	ft_load_sound_start(scene);
}

void	ft_init_start(t_m *m, t_start *scene)
{
	ft_load_assets_start(m, scene);
	scene->flags[S_STAGE] = DESIGN;
	scene->flags[S_FRAME] = S_BG;
	scene->flags[S_EVENT] = ON;
	Mix_PlayMusic(scene->mus->buf, -1);
}
