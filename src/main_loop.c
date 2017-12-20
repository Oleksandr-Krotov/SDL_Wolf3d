/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:50:38 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:50:39 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_const_action(t_m *m)
{
	ft_fps(&m->time);
	m->player.state.ms = m->time.delta * MS;
	m->player.state.rs = m->time.delta * RS;
	ft_sdl_get_wnd_size(&m->sdl);
	ft_recreate_z_buff(m);
	ft_sdl_event_hook(&m->event);
	ft_sdl_quit_event(&m->event, &m->m_flags[LOOP]);
}

void	ft_main_loop(t_m *m)
{
	while (m->m_flags[LOOP] == ON)
	{
		ft_const_action(m);
		m->ft_scene[m->m_flags[CUR_SCENE]](m);
		ft_sdl_update_window(m->sdl.rend);
	}
}
