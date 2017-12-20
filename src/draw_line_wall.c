/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:04:35 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:04:36 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_get_texture_num(t_rc *rc, t_map *map, int tex_size)
{
	if ((rc->tex_num = map->arr[rc->map.x][rc->map.y]) >= tex_size)
		rc->tex_num = CRASH;
}

void	ft_draw_line_wall(SDL_Renderer *rend, t_rc *rc, t_scene *sc, int x)
{
	SDL_Rect	tex_rect;
	SDL_Rect	wnd_rect;
	int			dev;
	t_tex		*ptr;

	ptr = sc->texture[rc->tex_num];
	dev = sc->flags[G_TORCH] == ON ? 0 : (int)(90 * rc->dist);
	ft_calc_light_pow(ptr->buf, rc->dist, sc->flags[G_TORCH]);
	tex_rect = ft_sdl_set_rect(rc->tex_x, dev, 1, sc->texture[rc->tex_num]->w);
	wnd_rect = ft_sdl_set_rect(x, rc->start_y, 1, rc->end_y - rc->start_y);
	SDL_RenderCopy(rend, sc->texture[rc->tex_num]->buf, &tex_rect, &wnd_rect);
}
