/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:23:50 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:23:51 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_m m;

	UNUSED(ac);
	UNUSED(av);
	ft_main_init(&m);
	ft_main_loop(&m);
	ft_free_main(&m);
	ft_sdl_close(&m.sdl);
	return (0);
}
