/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_event_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:11:46 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:11:47 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_sdl_event_hook(t_event *event)
{
	event->s_buf = SDL_GetKeyboardState(NULL);
	event->state = SDL_PollEvent(&event->poll);
}

void	ft_sdl_quit_event(t_event *event, int *flags)
{
	if (event->state == 1)
	{
		if (event->poll.type == SDL_QUIT)
			*flags = OFF;
	}
}
