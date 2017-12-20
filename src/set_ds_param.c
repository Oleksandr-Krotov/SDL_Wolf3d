/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ds_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:10:15 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:10:16 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_get_sprite_pos(t_scene *sc, t_player *pl, t_ds *ds, int i)
{
	ds->sprite.x = sc->sprt.in[sc->sprt.order[i]].x - pl->pos.x;
	ds->sprite.y = sc->sprt.in[sc->sprt.order[i]].y - pl->pos.y;
}

void	ft_get_sprite_transform(t_player *pl, t_ds *ds)
{
	ds->trans.x = ds->inv_det *
			(pl->dir.y * ds->sprite.x - pl->dir.x * ds->sprite.y);
	ds->trans.y = ds->inv_det *
			(-pl->cam.plane.y * ds->sprite.x + pl->cam.plane.x * ds->sprite.y);
}

void	ft_get_sprite_w_end_h(t_sdl *sdl, t_ds *ds, t_sprite *sprite, int i)
{
	ds->height = (int)(abs((int)(sdl->h / ds->trans.y)) /
			sprite->in[sprite->order[i]].v_div);
	ds->width = (int)(abs((int)(sdl->h / ds->trans.y)) /
			sprite->in[sprite->order[i]].u_div);
}

void	ft_get_start_end_y(t_sdl *sdl, t_ds *ds)
{
	ds->start.y = -ds->height / 2 + sdl->h / 2 + ds->v_mv_scr;
	if (ds->start.y < 0)
		ds->start.y = 0;
	ds->end.y = ds->height / 2 + sdl->h / 2 + ds->v_mv_scr;
	if (ds->end.y >= sdl->h)
		ds->end.y = sdl->h - 1;
}

void	ft_get_start_end_x(t_sdl *sdl, t_ds *ds)
{
	ds->start.x = (-ds->width / 2 + ds->scr_x);
	if (ds->start.x < 0)
		ds->start.x = 0;
	ds->end.x = ds->width / 2 + ds->scr_x;
	if (ds->end.x >= sdl->w)
		ds->end.x = sdl->w - 1;
}
