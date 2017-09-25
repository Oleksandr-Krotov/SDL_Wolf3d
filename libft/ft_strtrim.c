/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:36:02 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:36:35 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*buff;
	size_t	s_len;

	buff = NULL;
	if (s != NULL)
	{
		s = ft_skip_whitespace((char *)s);
		s_len = ft_strlen((char *)s);
		while (s_len && (s[s_len - 1] == '\n' ||
				s[s_len - 1] == '\t' ||
				s[s_len - 1] == ' '))
			s_len--;
		buff = (char *)malloc(sizeof(char) * (s_len + 1));
		if (buff != NULL)
		{
			buff[s_len] = '\0';
			ft_memcpy(buff, s, s_len);
		}
	}
	return (buff);
}
