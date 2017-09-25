#include "wolf3d.h"

void	ft_error(int error)
{
	if (error == -1)
		ft_putstr("Failed initialisation SDL\n");
	else if (error == -2)
		ft_putstr("Failed init SDL_Window\n");
	else if (error == -3)
		ft_putstr("Failed init SDL_surface\n");
	exit(error);
}