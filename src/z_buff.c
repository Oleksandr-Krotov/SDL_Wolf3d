/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:02:22 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:02:29 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_z_buff(t_m *m)
{
	if ((m->zbuff = malloc(sizeof(double) * DISP_W)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	m->old_w = DISP_W;
}

void	ft_recreate_z_buff(t_m *m)
{
	if (m->old_w != m->sdl.w)
	{
		free(m->zbuff);
		m->zbuff = malloc(sizeof(double) * m->sdl.w);
		m->old_w = m->sdl.w;
	}
}
