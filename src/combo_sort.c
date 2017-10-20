#include <wolf3d.h>

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

void	ft_combo_sort(int *order, double *dist, int size)
{
	int gap;
	int swapped;
	int i;
	int j;

	gap = size;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
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