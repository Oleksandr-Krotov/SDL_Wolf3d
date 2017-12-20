/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:24:04 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:24:05 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_flags(int *flags)
{
	flags[LOOP] = ON;
}

void	ft_init_player(t_player *pl)
{
	pl->pos.x = -1;
	pl->pos.y = -1;
	pl->dir.x = -1;
	pl->dir.y = 0;
	pl->cam.plane.x = 0.0;
	pl->cam.plane.y = 0.66;
}

void	ft_init_bar(t_m *m)
{
	if ((m->bar = malloc(sizeof(t_tex *) * MUTUAL_IMG_NUM)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	m->bar[HP] = ft_sdl_load_texture(m->sdl.rend, P_HP);
	m->bar[CLOSE_MSG] = ft_sdl_load_texture(m->sdl.rend, P_CLOSE_MSG);
	m->bar[DIE] = ft_sdl_load_texture(m->sdl.rend, P_DIE);
	m->bar[ROPE] = ft_sdl_load_texture(m->sdl.rend, P_ROPE);
	m->bar[SPARK] = ft_sdl_load_texture(m->sdl.rend, P_SPARK);
	m->bar[SCREAM] = ft_sdl_load_texture(m->sdl.rend, P_SCREAM);
	m->bar[WOUND] = ft_sdl_load_texture(m->sdl.rend, P_WOUND);
	m->bar[TORCH_SPRITE] = ft_sdl_load_texture(m->sdl.rend, P_TORCH_SPRITE);
	m->bar[OPEN_GARDEN] = ft_sdl_load_texture(m->sdl.rend, P_OPEN_GARDEN);
	m->bar[INTRO] = ft_sdl_load_texture(m->sdl.rend, P_INTRO);
}

void	ft_init_font(t_m *m)
{
	m->font = ft_sdl_set_font(P_F_METAL, 72);
	ft_sdl_font_color(m->font, (SDL_Colour){255, 255, 255, 255});
}

void	ft_main_init(t_m *m)
{
	ft_sdl_all(&m->sdl);
	ft_init_font(m);
	ft_init_flags(m->m_flags);
	ft_init_bar(m);
	ft_init_all_scene(m);
	ft_init_player(&m->player);
	ft_init_z_buff(m);
}
