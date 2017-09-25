/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:09:40 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/09 19:09:41 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char *ptr1;
	const unsigned char *ptr2;
	size_t				i;

	if (n == 0)
		return (0);
	ptr1 = (const unsigned char *)str1;
	ptr2 = (const unsigned char *)str2;
	while (*ptr1 == *ptr2 && n > 1)
	{
		if (*ptr1 == '\0')
			return (0);
		ptr1++;
		ptr2++;
		n--;
	}
	return (*ptr1 - *ptr2);
}
