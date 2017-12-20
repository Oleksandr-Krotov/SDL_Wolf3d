/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_garden.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:21:36 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:21:37 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_player_scene(t_player *pl, t_v2d start)
{
	pl->pos.x = start.y + 0.5;
	pl->pos.y = start.x + 0.5;
	pl->state.hp = 100;
	pl->timer = 0;
}

void	ft_init_torch(t_torch *torch)
{
	torch->hp = 100;
	torch->count = 0;
}

void	ft_create_sprite(t_scene *scene, size_t size)
{
	if ((scene->sprt.in = malloc(sizeof(t_sprite_in) * size)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	if ((scene->sprt.order = malloc(sizeof(int) * size)) == NULL)
		ft_error(ERR_MEM_ALLOC);
	if ((scene->sprt.dist = malloc(sizeof(double) * size)) == NULL)
		ft_error(ERR_MEM_ALLOC);
}

void	ft_init_sprite_garden(t_sprite_in *in)
{
	in[0] = (t_sprite_in){3.5, 8, COLONIT, 1, 1, 0, 1};
	in[1] = (t_sprite_in){7.5, 10, VANGUARD, 1, 1, 0, 1};
	in[2] = (t_sprite_in){1.5, 5, VANGUARD, 1, 1, 0, 1};
	in[3] = (t_sprite_in){1.5, 8.5, TORCH, 3, 3, 256, 1};
	in[4] = (t_sprite_in){8.5, 12.5, TORCH, 3, 3, 256, 1};
	in[5] = (t_sprite_in){11.5, 6.5, TORCH, 3, 3, 256, 1};
	in[6] = (t_sprite_in){16.5, 5.5, TORCH, 3, 3, 256, 1};
	in[7] = (t_sprite_in){5.5, 1.5, KEY, 3, 3, 256, 1};
	in[8] = (t_sprite_in){18.5, 12.5, COLONIT, 1, 1, 0, 1};
	in[9] = (t_sprite_in){13.5, 6.5, VANGUARD, 1, 1, 0, 1};
	in[10] = (t_sprite_in){8.5, 1.5, VANGUARD, 1, 1, 0, 1};
}

void	ft_init_garden(t_m *m, t_scene *scene)
{
	static int	alpha = 255;
	static int	count;

	count += m->time.fps;
	if (count > T_INTRO && alpha > 0)
	{
		SDL_SetTextureAlphaMod(m->bar[INTRO]->buf, (Uint8)alpha);
		alpha--;
	}
	SDL_RenderCopy(m->sdl.rend, m->bar[INTRO]->buf, NULL, NULL);
	if (alpha == 0)
	{
		ft_read_map(&scene->map, G_MAPNAME);
		ft_load_assets_garden(m, scene);
		ft_create_sprite(scene, G_SPRT_POINT);
		ft_init_player_scene(&m->player, scene->map.start);
		ft_init_torch(&scene->torch);
		ft_init_sprite_garden(scene->sprt.in);
		scene->flags[G_STAGE] = DESIGN;
		scene->flags[G_SPRITE] = G_SPRT_POINT;
		Mix_PlayMusic(scene->mus->buf, -1);
	}
}
