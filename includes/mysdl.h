/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:52:19 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 11:52:20 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSDL_H
# define MYSDL_H
# include <SDL2/SDL.h>
# if __APPLE__
#  include <SDL2_ttf/SDL_ttf.h>
#  include <SDL2_image/SDL_image.h>
#  include <SDL2_mixer/SDL_mixer.h>
# elif __linux__
#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_image.h>
#  include <SDL2/SDL_mixer.h>
# endif

# include "error.h"
# include "type.h"

typedef struct s_event	t_event;

struct		s_event
{
	SDL_Event	poll;
	int			state;
	const Uint8	*s_buf;
};

typedef struct s_sd_rects	t_sd_rects;

struct		s_sd_rects
{
	SDL_Rect	src;
	SDL_Rect	dst;
};

typedef struct s_font	t_font;

struct		s_font
{
	TTF_Font	*type;
	SDL_Color	color;
};

typedef struct s_music	t_music;

struct		s_music
{
	Mix_Music	*buf;
	int			volume;
};

typedef struct s_chunk	t_chunk;

struct		s_chunk
{
	Mix_Chunk	*buf;
	int			chanel;
	int			volume;
};

typedef struct s_tex	t_tex;

struct		s_tex
{
	SDL_Texture	*buf;
	int			w;
	int			h;
};

typedef struct s_sdl	t_sdl;

struct		s_sdl
{
	SDL_Window		*wnd;
	SDL_Renderer	*rend;
	int				w;
	int				h;
};

/*
** INIT
*/
void		ft_sdl_init(void);
void		ft_sdl_ttf_init(void);
void		ft_sdl_init_sound(MIX_InitFlags flags);

/*
** WINDOW
*/

/*
** \brief Create window and linked Renderer size of window.
** \param width of the window being created
** \param height of the window being created
** \param flag The m_flags on a window
** \param sdl window and renderer structure
*/
void		ft_sdl_crete_wnd_and_rend(unsigned int width, unsigned int height,
									SDL_WindowFlags flag, t_sdl *sdl);
void		ft_sdl_get_wnd_size(t_sdl *sdl);
void		ft_sdl_update_window(SDL_Renderer *rend);

/*
** TEXTURES
*/
t_tex		*ft_sdl_load_texture(SDL_Renderer *rend, char *path);
void		ft_sdl_free_texture(t_tex **tex, int size);

/*
** RECT
*/
SDL_Rect	ft_sdl_set_rect(int x, int y, int w, int h);

/*
** FONT
*/
t_font		*ft_sdl_set_font(char *path, int size);
void		ft_sdl_font_color(t_font *font, SDL_Color color);
void		ft_sdl_draw_text(t_sdl *sdl, t_font font, char *str, t_v2d xy);

/*
** AUDIO
*/
t_music		*ft_sdl_load_music(char *path, int volume);
t_chunk		*ft_sdl_load_chunk(char *path, int chanel, int volume);
void		ft_sdl_free_chunk(t_chunk **chunk, int size);

/*
** EVENT
*/
void		ft_sdl_event_hook(t_event *event);
void		ft_sdl_quit_event(t_event *event, int *flags);
void		ft_sdl_close(t_sdl *sdl);

#endif
