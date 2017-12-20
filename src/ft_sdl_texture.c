/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:12:22 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:12:24 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

t_tex	*ft_sdl_load_texture(SDL_Renderer *rend, char *path)
{
	t_tex *ret;

	if ((ret = malloc(sizeof(t_tex))) == NULL)
		ft_error(ERR_MEM_ALLOC);
	if ((ret->buf = IMG_LoadTexture(rend, path)) == NULL)
	{
		SDL_Log("Couldn't load texture! SDL Err: %s\n", SDL_GetError());
		SDL_Quit();
	}
	SDL_QueryTexture(ret->buf, NULL, NULL, &ret->w, &ret->h);
	return (ret);
}

void	ft_sdl_free_texture(t_tex **tex, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		SDL_DestroyTexture(tex[i]->buf);
		free(tex[i]);
		tex[i] = NULL;
		i++;
	}
}
