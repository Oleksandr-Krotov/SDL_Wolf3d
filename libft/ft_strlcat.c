/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:59:06 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 13:59:27 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t d;
	size_t s;

	d = ft_strlen(dst);
	s = ft_strlen((char *)src);
	if (n > (d + 1))
		ft_strncat(dst, (char *)src, n - (d + 1));
	if (n > d)
		return (d + s);
	else
		return (n + s);
}
