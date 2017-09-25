/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:53:56 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 13:54:41 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memptr, int val, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)memptr;
	while (n > 0)
	{
		if (*ptr == (unsigned char)val)
			return (ptr);
		n--;
		ptr++;
	}
	return (NULL);
}
