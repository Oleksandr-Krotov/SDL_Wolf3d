/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_lock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:13:12 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:13:15 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_msg_to_screen(t_m *m, t_scene *sc)
{
	static int count;

	if (sc->flags[G_MSG] == TRUE && count < T_MSG)
	{
		count += m->time.fps;
		SDL_RenderCopy(m->sdl.rend, m->bar[CLOSE_MSG]->buf, NULL, NULL);
	}
	else if (count >= T_MSG)
	{
		sc->flags[G_MSG] = FALSE;
		count = 0;
	}
}
