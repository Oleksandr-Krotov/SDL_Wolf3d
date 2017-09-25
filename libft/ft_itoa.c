/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:39:24 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:40:51 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_num_len(int n)
{
	size_t			size;

	size = 0;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char		*ft_write_in(int n, char *number, int size, int flag)
{
	if (number != NULL)
	{
		number[size] = '\0';
		size--;
		while (size >= 0)
		{
			number[size] = (char)((n % 10) + '0');
			size--;
			n /= 10;
		}
		if (flag == 1)
			number[size + 1] = '-';
	}
	return (number);
}

char			*ft_itoa(int n)
{
	char			*number;
	int				size;
	int				flag;
	unsigned int	num;

	flag = 0;
	if (n < 0)
	{
		flag = 1;
		n *= -1;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = (unsigned int)n;
	if (n == 0)
		return (ft_strdup("0"));
	size = (int)ft_num_len(num);
	size += flag;
	number = malloc(sizeof(char) * (size + 1));
	number = ft_write_in(num, number, size, flag);
	return (number);
}
