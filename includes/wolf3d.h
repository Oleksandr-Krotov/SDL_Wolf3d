#ifndef WOLDF3D_H
# define WOLDF3D_H

/*
**	GRAPHICS
*/

#include <SDL2/SDL.h>
/*
** STD_LIB
*/
#include <stdio.h>
#include <stdlib.h>
/*
** CUSTOM_LIB
*/
#include "libft.h"

#define D_WIDTH 800
#define D_HEIGHT 600
#define D_NAME "Wolf3d"

typedef struct s_wnd	t_wnd;
typedef struct s_id		t_id;

struct s_wnd
{
	SDL_Window	*p_wnd;
	const char	*name;
	int			wid;
	int			hei;
};

struct s_id
{
	t_wnd		wnd;
	SDL_Surface	*imgs;
	SDL_Surface	*wnd_img;
};

void	ft_error(int error);
#endif
