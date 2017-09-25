/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:50:11 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/08 19:50:16 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *prev;

	if (alst != NULL)
	{
		while (*alst != NULL)
		{
			prev = (*alst);
			*alst = (*alst)->next;
			del((prev)->content, (prev)->content_size);
			free(prev);
		}
		free(*alst);
		*alst = NULL;
	}
}
