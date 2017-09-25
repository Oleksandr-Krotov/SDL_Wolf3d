/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:49:04 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 13:50:58 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *vptr, int val, size_t n)
{
	unsigned char *ptr;

	ptr = vptr;
	while (n > 0)
	{
		*ptr = (unsigned char)val;
		ptr++;
		n--;
	}
	return (vptr);
}
