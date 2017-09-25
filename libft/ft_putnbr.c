/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:43:32 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:43:36 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	num = (unsigned int)n;
	if (num >= 10)
	{
		ft_putnbr((int)(num / 10));
		ft_putchar((char)((num % 10) + '0'));
	}
	else
	{
		ft_putchar((char)(num + '0'));
	}
}
