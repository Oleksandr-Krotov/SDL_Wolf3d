/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_stripe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:04:49 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:04:52 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_rect(t_sdl *sdl, t_ds *ds, int stripe, int flag)
{
	SDL_Rect	dst;
	SDL_Rect	src;

	ft_calc_light_pow(ds->sprt_ptr->buf, ds->trans.y, flag);
	src = ft_sdl_set_rect(ds->tex.x, ds->tex.y, 1, ds->tex_2 - ds->tex.y);
	dst = ft_sdl_set_rect(stripe, ds->start.y, 1, ds->end.y - ds->start.y);
	SDL_RenderCopy(sdl->rend, ds->sprt_ptr->buf, &src, &dst);
}

void	ft_draw_sprite_stripe(t_sdl *sdl, t_scene *sc, t_ds *ds, double *zbuff)
{
	int			d;
	int			tx_s;
	int			stripe;

	tx_s = ds->sprt_ptr->h;
	stripe = ds->start.x;
	while (stripe < ds->end.x)
	{
		ds->tex.x = ((tx_s * (stripe - (-ds->width / 2 + ds->scr_x)) *
				tx_s / ds->width) / tx_s);
		if (ds->trans.y > 0 && ds->trans.y < zbuff[stripe])
		{
			d = (ds->start.y - ds->v_mv_scr) * tx_s - sdl->h * (tx_s / 2) +
					ds->height * (tx_s / 2);
			ds->tex.y = ((d * tx_s) / ds->height) / tx_s;
			d = (ds->end.y - 1 - ds->v_mv_scr) * tx_s - sdl->h * (tx_s / 2) +
					ds->height * (tx_s / 2);
			ds->tex_2 = ((d * tx_s) / ds->height) / tx_s;
			ft_put_rect(sdl, ds, stripe, sc->flags[G_TORCH]);
		}
		stripe++;
	}
}
