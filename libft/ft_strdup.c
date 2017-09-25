/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:55:56 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/07 13:56:10 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	sum;

	ptr = (char *)str;
	sum = ft_strlen(ptr);
	ptr = (char *)malloc(sizeof(char) * sum + 1);
	if (ptr != NULL)
		ft_strcpy(ptr, str);
	else
		return (NULL);
	return (ptr);
}
