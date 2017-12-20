/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:18:30 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:18:31 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move_forward(t_map *map, t_player *p, double mult)
{
	double check_x;
	double check_y;

	check_x = p->pos.x + p->dir.x * p->state.ms * mult;
	check_y = p->pos.y + p->dir.y * p->state.ms * mult;
	if (map->arr[(int)(check_x + 0.2)][(int)(p->pos.y + 0.2)] == 0 &&
		map->arr[(int)(check_x - 0.2)][(int)(p->pos.y + 0.2)] == 0 &&
		map->arr[(int)(check_x + 0.2)][(int)(p->pos.y - 0.2)] == 0 &&
		map->arr[(int)(check_x - 0.2)][(int)(p->pos.y - 0.2)] == 0)
		p->pos.x += p->dir.x * p->state.ms * mult;
	if (map->arr[(int)(p->pos.x + 0.2)][(int)(check_y + 0.2)] == 0 &&
		map->arr[(int)(p->pos.x - 0.2)][(int)(check_y + 0.2)] == 0 &&
		map->arr[(int)(p->pos.x + 0.2)][(int)(check_y - 0.2)] == 0 &&
		map->arr[(int)(p->pos.x - 0.2)][(int)(check_y - 0.2)] == 0)
		p->pos.y += p->dir.y * p->state.ms * mult;
}

void	ft_move_back(t_map *map, t_player *p, double mult)
{
	double check_x;
	double check_y;

	check_x = p->pos.x - p->dir.x * p->state.ms * mult;
	check_y = p->pos.y - p->dir.y * p->state.ms * mult;
	if (map->arr[(int)(check_x + 0.2)][(int)(p->pos.y + 0.2)] == 0 &&
		map->arr[(int)(check_x - 0.2)][(int)(p->pos.y + 0.2)] == 0 &&
		map->arr[(int)(check_x + 0.2)][(int)(p->pos.y - 0.2)] == 0 &&
		map->arr[(int)(check_x - 0.2)][(int)(p->pos.y - 0.2)] == 0)
		p->pos.x -= p->dir.x * p->state.ms * mult;
	if (map->arr[(int)(p->pos.x + 0.2)][(int)(check_y + 0.2)] == 0 &&
		map->arr[(int)(p->pos.x - 0.2)][(int)(check_y + 0.2)] == 0 &&
		map->arr[(int)(p->pos.x + 0.2)][(int)(check_y - 0.2)] == 0 &&
		map->arr[(int)(p->pos.x - 0.2)][(int)(check_y - 0.2)] == 0)
		p->pos.y -= p->dir.y * p->state.ms * mult;
}

void	ft_turn_left(t_player *p, double mult)
{
	double old;

	old = p->dir.x;
	p->dir.x = (p->dir.x * cos(p->state.rs * mult) -
			p->dir.y * sin(p->state.rs * mult));
	p->dir.y = (old * sin(p->state.rs * mult) +
			p->dir.y * cos(p->state.rs * mult));
	old = p->cam.plane.x;
	p->cam.plane.x = (p->cam.plane.x * cos(p->state.rs * mult) -
			p->cam.plane.y * sin(p->state.rs * mult));
	p->cam.plane.y = (old * sin(p->state.rs * mult) +
			p->cam.plane.y * cos(p->state.rs * mult));
}

void	ft_turn_right(t_player *p, double mult)
{
	double old;

	old = p->dir.x;
	p->dir.x = (p->dir.x * cos(-p->state.rs * mult) -
			p->dir.y * sin(-p->state.rs * mult));
	p->dir.y = (old * sin(-p->state.rs * mult) +
			p->dir.y * cos(-p->state.rs * mult));
	old = p->cam.plane.x;
	p->cam.plane.x = (p->cam.plane.x * cos(-p->state.rs * mult) -
			p->cam.plane.y * sin(-p->state.rs * mult));
	p->cam.plane.y = (old * sin(-p->state.rs * mult) +
			p->cam.plane.y * cos(-p->state.rs * mult));
}

void	ft_do_action(t_scene *sc, t_player *p)
{
	if (sc->map.arr[(int)(p->pos.x + p->dir.x + 0.3)][(int)p->pos.y] == 8
		|| sc->map.arr[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y + 0.3)] == 8
		|| sc->map.arr[(int)(p->pos.x + p->dir.x - 0.3)][(int)p->pos.y] == 8
		|| sc->map.arr[(int)(p->pos.x)][(int)(p->pos.y + p->dir.y - 0.3)] == 8)
	{
		if (!sc->flags[G_KEY])
		{
			Mix_PlayChannel(3, sc->chunk[CHUNK_LOCK]->buf, 0);
			sc->flags[G_MSG] = TRUE;
		}
		else
		{
			sc->flags[G_GAME] = OPEN;
			sc->flags[G_STAGE] = DESTRUCT;
		}
	}
}
