/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readonedig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 12:34:17 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/10 12:34:19 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_readonedig(void)
{
	char	tmp;
	int		n;

	n = 0;
	while (read(0, &tmp, 1) > 0)
	{
		if (ft_isdigit(tmp) == 1)
			n = (n * 10) + (tmp - '0');
		else if (tmp == ' ' || tmp == '\n')
			break ;
	}
	return (n);
}
