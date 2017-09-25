/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:50:39 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/08 19:50:41 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*curr;

	new_list = NULL;
	if (lst != NULL)
	{
		if ((new_list = f(lst)) == NULL)
			return (NULL);
		curr = new_list;
		while (lst->next != NULL)
		{
			if ((curr->next = f(lst->next)) == NULL)
				return (NULL);
			curr = curr->next;
			lst = lst->next;
		}
	}
	return (new_list);
}
