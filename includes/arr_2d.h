#ifndef ARR_2D_H
#define ARR_2D_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int		**ft_create_2d_int_arr(int row, int col);
void	ft_bzero_2d_arr(int row, int col, int **arr);
void	print_int_2d_arr(int row, int col, int **arr);

#endif
