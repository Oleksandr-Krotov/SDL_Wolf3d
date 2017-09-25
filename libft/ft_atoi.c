/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:53:42 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/09 18:56:11 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		num;
	int		flag;

	num = 0;
	flag = 1;
	str = ft_skip_whitespace((char *)str);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	while (ft_isdigit(*str) != 0)
	{
		num = (num * 10) + *str - '0';
		str++;
	}
	return (flag == -1 ? -num : num);
}
