/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:28:05 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 16:28:28 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *ptr;
	char *p;

	ptr = NULL;
	if (s)
	{
		ptr = ft_strdup(s);
		if (ptr != NULL)
		{
			p = ptr;
			while (*p != '\0')
			{
				*p = f(*p);
				p++;
			}
		}
	}
	if (ptr != NULL)
		return (ptr);
	else
		return (NULL);
}
