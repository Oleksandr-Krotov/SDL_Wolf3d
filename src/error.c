#include "wolf3d.h"

void	ft_error(int error)
{
	if (error == 1)
		perror("Bad number of arguments!\nWolf3d work only with one!");
	else if (error == 2)
		perror("Failed initialisation SDL\n");
	else if (error == 3)
		perror("Failed create SDL_Window\n");
	else if (error == 4)
		perror("Failed init SDL_surface\n");
	else if (error == 5)
		perror("Failed load texture\n");
	else if (error == 6)
		perror("Can't read this map!\n");
	else if (error == 7)
		perror("Can't find map width! Example: \"W: n\"\n");
	else if (error == 8)
		perror("Can't find map height! Example: \"H: n\"\n");
	else if (error == 9)
		perror("Cant't find map start! Example: \"Map: \"\n");
	else if (error == 10)
		perror("Empty map!\n");
	else if (error == 11)
		perror("Map size not equal to a given value or empty place at the edges of map!\n");
	else if (error == 12)
		perror("Map size not equal to a given value!\n");
	else if (error == 13)
		perror("Can't searched starting position!\n");
	else if (error == 14)
		perror("SDL can't update window!!!\n");
	else if (error == 15)
		perror("Start position at the edges of map!\n");
	exit(error);
}