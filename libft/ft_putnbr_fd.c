/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:44:26 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:44:59 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (fd >= 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		num = (unsigned int)n;
		if (num >= 10)
		{
			ft_putnbr_fd((int)(num / 10), fd);
			ft_putchar_fd((char)((num % 10) + '0'), fd);
		}
		else
			ft_putchar_fd((char)(num + '0'), fd);
	}
}
