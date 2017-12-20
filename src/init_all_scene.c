/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:23:14 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:23:15 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_set_start_stage(t_start *scene)
{
	scene->ft_stage[INIT] = (void *)ft_init_start;
	scene->ft_stage[DESIGN] = (void *)ft_design_start;
	scene->ft_stage[DESTRUCT] = (void *)ft_destruct_start;
}

void	ft_first_init_start(t_m *m)
{
	t_start *scene;

	if ((scene = malloc(sizeof(t_start))) == NULL)
		ft_error(ERR_MEM_ALLOC);
	ft_set_start_stage(scene);
	scene->flags[S_STAGE] = INIT;
	scene->flags[S_DES_TYPE] = ON;
	m->data = scene;
	m->m_flags[CUR_SCENE] = START;
}

void	ft_init_all_scene(t_m *m)
{
	m->ft_scene[START] = ft_start;
	m->ft_scene[GARDEN] = ft_garden;
	ft_first_init_start(m);
}
