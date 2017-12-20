/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_init_sound.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:12:05 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 13:12:06 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysdl.h"

void	ft_sdl_init_sound(MIX_InitFlags flags)
{
	if (Mix_Init(flags) == 0)
		SDL_Log("Couldn't init Mixer! SDL Err: %s\n", SDL_GetError());
	if (Mix_OpenAudio(44100, AUDIO_S16, 2, 4096) < 0)
		SDL_Log("Couldn't init Mixer! SDL Err: %s\n", SDL_GetError());
}

t_music	*ft_sdl_load_music(char *path, int volume)
{
	t_music *ret;

	if ((ret = malloc(sizeof(t_music))) == NULL)
		ft_error(ERR_MEM_ALLOC);
	if ((ret->buf = Mix_LoadMUS(path)) == NULL)
		SDL_Log("%s\n", SDL_GetError());
	ret->volume = volume;
	Mix_VolumeMusic(volume);
	return (ret);
}

t_chunk	*ft_sdl_load_chunk(char *path, int chanel, int volume)
{
	t_chunk *ret;

	if ((ret = malloc(sizeof(t_chunk))) == NULL)
		ft_error(ERR_MEM_ALLOC);
	if ((ret->buf = Mix_LoadWAV(path)) == NULL)
		SDL_Log("%s\n", SDL_GetError());
	ret->chanel = chanel;
	ret->volume = volume;
	Mix_VolumeChunk(ret->buf, volume);
	return (ret);
}

void	ft_sdl_free_chunk(t_chunk **chunk, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		Mix_FreeChunk(chunk[i]->buf);
		free(chunk[i]);
		chunk[i] = NULL;
		i++;
	}
}
