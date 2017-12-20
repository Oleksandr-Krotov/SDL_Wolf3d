/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:18:37 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:18:39 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr_2d.h"

void	ft_bzero_2d_arr(int row, int col, int **arr)
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int		**ft_create_2d_int_arr(int row, int col)
{
	int **arr;
	int i;

	arr = malloc(sizeof(int *) * row);
	i = 0;
	while (i < row)
	{
		arr[i] = malloc(sizeof(int) * col);
		if (arr[i] == NULL)
			perror("Failed allocate memory 2d array\n");
		i++;
	}
	return (arr);
}

void	print_int_2d_arr(int row, int col, int **arr)
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			printf("%d ", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
