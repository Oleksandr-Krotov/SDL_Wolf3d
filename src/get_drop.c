/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_drop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:21:18 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:21:19 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_check_enemy(t_m *m, t_sprite_in *lst, t_scene *sc, int *flags)
{
	if ((flags[G_TORCH] == OFF && lst->texture == COLONIT &&
			lst->visible == ON && ((int)lst->x == (int)m->player.pos.x &&
			(int)lst->y == (int)m->player.pos.y)))
	{
		m->player.state.hp -= 10;
		Mix_PlayChannel(4, sc->chunk[CHUNK_WOUND]->buf, 0);
		lst->visible = OFF;
		return (1);
	}
	if ((flags[G_TORCH] == OFF && lst->texture == VANGUARD &&
			lst->visible == ON && ((int)lst->x == (int)m->player.pos.x &&
				(int)lst->y == (int)m->player.pos.y)))
	{
		m->player.state.hp -= 10;
		Mix_PlayChannel(4, sc->chunk[CHUNK_WOUND]->buf, 0);
		lst->visible = OFF;
		return (1);
	}
	return (0);
}

int		ft_check_torch(t_sprite_in lst, t_v2f pos)
{
	if (lst.texture == TORCH && lst.visible == ON &&
			((int)lst.x == (int)pos.x &&
					(int)lst.y == (int)pos.y))
		return (1);
	return (0);
}

void	ft_get_drop(t_m *m, t_sprite_in *lst, t_scene *sc, int *flags)
{
	int i;

	i = 0;
	while (i < G_SPRT_POINT)
	{
		if (ft_check_torch(lst[i], m->player.pos))
		{
			sc->flags[G_TORCH] = ON;
			lst[i].visible = OFF;
			sc->torch.hp = (int)fmin(100, sc->torch.hp + 25);
			break ;
		}
		else if (lst[i].texture == KEY && lst[i].visible == ON &&
				((int)lst[i].x == (int)m->player.pos.x &&
				(int)lst[i].y == (int)m->player.pos.y))
		{
			flags[G_KEY] = ON;
			lst[i].visible = OFF;
			break ;
		}
		else if (ft_check_enemy(m, &lst[i], sc, flags))
			break ;
		i++;
	}
}
