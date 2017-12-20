/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_cast_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:05:34 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:05:35 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_sprite_check(t_scene *sc, t_ds *ds, int i)
{
	if (!sc->sprt.in[sc->sprt.order[i]].visible)
		return (1);
	if (sc->sprt.in[sc->sprt.order[i]].texture != TORCH &&
		sc->sprt.in[sc->sprt.order[i]].texture != KEY &&
		fabs(ds->trans.y) < 2 && sc->flags[G_TORCH])
		return (1);
	return (0);
}

void	ft_ray_cast_sprt(t_sdl *sdl, t_scene *sc, t_player *pl, double *zbuff)
{
	int		i;
	t_ds	ds;

	i = 0;
	ds.inv_det = 1.0 / (pl->cam.plane.x * pl->dir.y -
			pl->dir.x * pl->cam.plane.y);
	while (i < sc->flags[G_SPRITE])
	{
		ds.sprt_ptr = sc->sprt.buff[sc->sprt.in[sc->sprt.order[i]].texture];
		ft_get_sprite_pos(sc, pl, &ds, i);
		ft_get_sprite_transform(pl, &ds);
		if (ft_sprite_check(sc, &ds, i))
		{
			i++;
			continue ;
		}
		ds.scr_x = (int)((sdl->w / 2) * (1 + ds.trans.x / ds.trans.y));
		ds.v_mv_scr = (int)(sc->sprt.in[sc->sprt.order[i]].v_move / ds.trans.y);
		ft_get_sprite_w_end_h(sdl, &ds, &sc->sprt, i);
		ft_get_start_end_y(sdl, &ds);
		ft_get_start_end_x(sdl, &ds);
		ft_draw_sprite_stripe(sdl, sc, &ds, zbuff);
		i++;
	}
}
