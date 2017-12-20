/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook_garden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:21:07 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:21:08 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_poll_event_garden(t_m *m, t_scene *sc)
{
	if (m->event.poll.type == SDL_KEYDOWN)
	{
		if (m->event.poll.key.keysym.sym == SDLK_ESCAPE)
		{
			sc->flags[G_STAGE] = DESTRUCT;
			sc->flags[G_DES_TYPE] = OFF;
		}
		else if (m->event.poll.key.keysym.sym == SDLK_e)
			ft_do_action(sc, &m->player);
	}
}

void	ft_move_control(t_m *m, t_scene *sc)
{
	double		mult;

	mult = 1;
	if (m->event.s_buf[SDL_SCANCODE_LSHIFT])
		mult = 1.2;
	if (m->event.s_buf[SDL_SCANCODE_UP] || m->event.s_buf[SDL_SCANCODE_W])
		ft_move_forward(&sc->map, &m->player, mult);
	if (m->event.s_buf[SDL_SCANCODE_DOWN] || m->event.s_buf[SDL_SCANCODE_S])
		ft_move_back(&sc->map, &m->player, mult);
	if (m->event.s_buf[SDL_SCANCODE_LEFT] || m->event.s_buf[SDL_SCANCODE_A])
		ft_turn_left(&m->player, mult);
	if (m->event.s_buf[SDL_SCANCODE_RIGHT] || m->event.s_buf[SDL_SCANCODE_D])
		ft_turn_right(&m->player, mult);
}

void	ft_event_hook_garden(t_m *m, t_scene *sc)
{
	ft_poll_event_garden(m, sc);
	ft_move_control(m, sc);
	if (m->event.s_buf[SDL_SCANCODE_KP_PLUS])
	{
		sc->mus->volume = sc->mus->volume >= 128 ? 128 : sc->mus->volume + 1;
		Mix_VolumeMusic(sc->mus->volume);
	}
	if (m->event.s_buf[SDL_SCANCODE_KP_MINUS])
	{
		sc->mus->volume = sc->mus->volume <= 0 ? 0 : sc->mus->volume - 1;
		Mix_VolumeMusic(sc->mus->volume);
	}
}
