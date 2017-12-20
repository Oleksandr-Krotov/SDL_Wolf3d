/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_init_garden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:21:14 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:21:15 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_garden_stage(t_scene *scene)
{
	scene->ft_stage[INIT] = (void*)ft_init_garden;
	scene->ft_stage[DESIGN] = (void*)ft_design_garden;
	scene->ft_stage[DESTRUCT] = (void*)ft_destruct_garden;
}

void	ft_init_flags_garden(t_scene *scene)
{
	if ((scene->flags = malloc(sizeof(int) * G_FLAG_SIZE)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	scene->flags[G_STAGE] = INIT;
	scene->flags[G_DES_TYPE] = ON;
	scene->flags[G_TEX_SIZE] = G_TEX_NUM;
	scene->flags[G_TORCH] = ON;
	scene->flags[G_SPRITE] = ON;
	scene->flags[G_GAME] = CREATE;
	scene->flags[G_SCREAM] = ON;
	scene->flags[G_KEY] = FALSE;
	scene->flags[G_MSG] = FALSE;
	scene->flags[G_CROW] = ON;
	scene->flags[G_WALK] = ON;
	scene->flags[G_MOO] = ON;
}

void	ft_first_init_garden(t_m *m)
{
	t_scene *scene;

	if ((scene = malloc(sizeof(t_scene))) == NULL)
		ft_error(ERR_MEM_ALLOC);
	ft_set_garden_stage(scene);
	ft_init_flags_garden(scene);
	m->data = scene;
	m->m_flags[CUR_SCENE] = GARDEN;
}
