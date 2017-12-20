/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:52:47 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:52:48 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_num(int *num_x, int *num_y)
{
	if (*num_y == 1 && *num_x > 3)
	{
		*num_x = 0;
		*num_y = 0;
	}
	else if (*num_x > 3)
	{
		*num_x = 0;
		*num_y = 1;
	}
}

void	ft_torch(t_m *m, t_scene *sc)
{
	t_sd_rects	rect;
	t_v2d		step;
	static int	num_x;
	static int	num_y;
	static int	i;

	if (sc->flags[G_TORCH])
	{
		i += m->time.fps;
		step.x = 183;
		step.y = 191;
		if (i >= T_ANIM)
		{
			num_x++;
			check_num(&num_x, &num_y);
			i = 0;
		}
		rect.src = ft_sdl_set_rect(step.x * num_x, step.y * num_y, step.x, 200);
		rect.dst = ft_sdl_set_rect((int)(m->sdl.w * 0.2),
					(int)(m->sdl.h * 0.53), m->sdl.w / 4, m->sdl.h / 2);
		SDL_RenderCopy(m->sdl.rend,
					m->bar[TORCH_SPRITE]->buf,
						&rect.src, &rect.dst);
	}
}

void	ft_torch_time(t_m *m, t_scene *sc, double fps)
{
	SDL_Rect	dst;
	SDL_Rect	src;
	double		step;

	step = (m->sdl.w - (m->sdl.w * 0.25)) / 100;
	if (sc->flags[G_TORCH] == TRUE)
	{
		src = ft_sdl_set_rect(0, 0, 1024 * sc->torch.hp / 100, 256);
		dst = ft_sdl_set_rect(m->sdl.w / 8, 0, (int)(step * sc->torch.hp),
							(int)(m->sdl.h * 0.1));
		SDL_RenderCopy(m->sdl.rend, m->bar[ROPE]->buf, &src, &dst);
		dst = ft_sdl_set_rect((int)(m->sdl.w / 8 + step * sc->torch.hp) -
							(int)(m->sdl.w * 0.025), 0, (int)(m->sdl.w * 0.05),
							(int)(m->sdl.h * 0.1));
		SDL_RenderCopy(m->sdl.rend, m->bar[SPARK]->buf, NULL, &dst);
	}
	sc->torch.count += fps;
	if (sc->torch.count >= T_TORCH && sc->torch.hp >= 0)
	{
		sc->torch.hp--;
		sc->torch.count = 0;
		if (sc->torch.hp == 0)
			sc->flags[G_TORCH] = FALSE;
	}
}

void	ft_torch_event(t_m *m, t_scene *sc)
{
	ft_torch(m, sc);
	ft_torch_time(m, sc, m->time.fps);
}
