/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:33:47 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:35:14 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*p;

	p = NULL;
	if (s != NULL)
	{
		ptr = (char *)malloc(sizeof(char) * len + 1);
		if (ptr != NULL)
		{
			p = ptr;
			while (len > 0)
			{
				*ptr = s[start];
				len--;
				start++;
				ptr++;
			}
			*ptr = '\0';
		}
	}
	return (p);
}
