/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:10:35 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 15:10:55 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	const unsigned char *ptr1;
	const unsigned char *ptr2;

	ptr1 = (const unsigned char *)str1;
	ptr2 = (const unsigned char *)str2;
	while (*ptr1 == *ptr2)
	{
		if (*ptr1 == '\0')
		{
			return (0);
		}
		ptr1++;
		ptr2++;
	}
	return (*ptr1 - *ptr2);
}
