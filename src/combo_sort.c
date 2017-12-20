/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:18:49 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:18:50 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_fswap(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		ft_calc_gap(int gap)
{
	gap = (gap * 10) / 13;
	if (gap == 9 || gap == 10)
		gap = 11;
	if (gap < 1)
		gap = 1;
	return (gap);
}

void	ft_combo_sort(int *order, double *dist, int size)
{
	int gap;
	int swapped;
	int i;
	int j;

	gap = (int)size;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = ft_calc_gap(gap);
		swapped = 0;
		i = 0;
		while (i < size - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_fswap(&dist[i], &dist[j]);
				ft_swap(&order[i], &order[j]);
				swapped = 1;
			}
			i++;
		}
	}
}
