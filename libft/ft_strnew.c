/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:22:21 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:24:49 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	unsigned char *ptr;

	ptr = ft_memalloc(size + 1);
	if (ptr != NULL)
	{
		ft_bzero(ptr, size);
		return ((char *)(ptr));
	}
	return (NULL);
}
