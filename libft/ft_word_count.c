/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:33:31 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/08 19:33:33 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_word_count(const char *str, char c)
{
	size_t wc;

	wc = 0;
	if (str != NULL)
	{
		while (*str != '\0')
		{
			while (*str == c && *str != '\0')
				str++;
			if (*str != c && *str != '\0')
			{
				wc++;
				while (*str != c && *str != '\0')
					str++;
			}
		}
	}
	return (wc);
}
