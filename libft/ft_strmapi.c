/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:28:33 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:29:16 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	char			*ptr;
	unsigned int	i;

	ptr = NULL;
	s_len = 0;
	i = 0;
	if (s)
		s_len = ft_strlen((char *)s);
	if (s_len > 0)
	{
		ptr = ft_strdup(s);
		if (ptr != NULL)
		{
			while (i < s_len)
			{
				ptr[i] = f(i, ptr[i]);
				i++;
			}
		}
	}
	return (ptr);
}
