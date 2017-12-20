/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:03:13 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 14:03:14 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_main(t_m *m)
{
	TTF_CloseFont(m->font->type);
	free(m->font);
	m->font = NULL;
	ft_sdl_free_texture(m->bar, MUTUAL_IMG_NUM);
	free(m->bar);
	m->bar = NULL;
	free(m->zbuff);
	m->zbuff = NULL;
	ft_putstr("Good bye. Take care!\n");
	ft_putstr("You can buy full version on STEAM!\n");
}
