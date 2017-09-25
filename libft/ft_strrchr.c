/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:08:35 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 14:09:08 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (*ptr == c)
		{
			str = ptr;
		}
		ptr++;
	}
	if (c == '\0' && *ptr == '\0')
	{
		return (ptr);
	}
	else if (*str != c)
	{
		return (NULL);
	}
	else
		return ((char *)(str));
}
