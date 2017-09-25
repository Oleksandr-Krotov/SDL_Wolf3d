/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:16:07 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 14:16:43 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	const char *ptr2;
	const char *ptr1;
	const char *start;

	start = str1;
	ptr2 = str2;
	if (!*str2)
		return (char *)str1;
	while (*str1)
	{
		ptr1 = str1;
		while (*(str1++) == *(str2++))
		{
			if (!*str2)
				return (char *)ptr1;
			if (!*str1)
				return (NULL);
		}
		str1 = start++;
		str2 = ptr2;
	}
	return (NULL);
}
