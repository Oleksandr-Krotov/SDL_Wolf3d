/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:33:50 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/09 14:33:52 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	const char	*ptr1;
	size_t		i;

	i = ft_strlen((char *)str2);
	if (!*str2)
		return ((char *)str1);
	while (*str1 != '\0' && len >= i)
	{
		ptr1 = str1;
		if (ft_strncmp(str1, str2, i) == 0)
			return (char *)(ptr1);
		str1++;
		len--;
	}
	return (NULL);
}
