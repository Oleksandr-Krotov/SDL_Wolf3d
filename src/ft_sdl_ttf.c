/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_ttf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:12:28 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:12:30 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

void	ft_sdl_ttf_init(void)
{
	if (TTF_Init() < 0)
	{
		SDL_Log("Couldn't init TTF! SDL Err: %s\n", SDL_GetError());
		SDL_Quit();
	}
}

t_font	*ft_sdl_set_font(char *path, int size)
{
	t_font *ret;

	if ((ret = malloc(sizeof(t_font))) == NULL)
		ft_error(ERR_MEM_ALLOC);
	if ((ret->type = TTF_OpenFont(path, size)) == NULL)
		SDL_Log("Couldn't open font! SDL Err: %s\n", SDL_GetError());
	return (ret);
}

void	ft_sdl_font_color(t_font *font, SDL_Color color)
{
	font->color = color;
}

void	ft_sdl_draw_text(t_sdl *sdl, t_font font, char *str, t_v2d xy)
{
	SDL_Surface	*surface;
	SDL_Texture *texture;
	SDL_Rect	dst;

	surface = TTF_RenderText_Solid(font.type, str, font.color);
	dst = ft_sdl_set_rect(xy.x, xy.y,
							(int)(sdl->w * 0.1),
								(int)(sdl->h * 0.15));
	texture = SDL_CreateTextureFromSurface(sdl->rend, surface);
	SDL_RenderCopy(sdl->rend, texture, NULL, &dst);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}
