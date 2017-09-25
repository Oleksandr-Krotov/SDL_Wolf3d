/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:16:03 by akrotov           #+#    #+#             */
/*   Updated: 2017/03/14 19:16:32 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list *lst)
{
	void	*tmp;
	int		flag;
	t_list	*lst_ptr;

	flag = 0;
	while (flag != 1 || lst_ptr->next != NULL)
	{
		flag = 1;
		lst_ptr = lst;
		while (lst_ptr->next != NULL)
		{
			if (ft_strcmp(lst_ptr->content, lst_ptr->next->content) > 0)
			{
				flag = 0;
				tmp = lst_ptr->next->content;
				lst_ptr->next->content = lst_ptr->content;
				lst_ptr->content = tmp;
			}
			lst_ptr = lst_ptr->next;
		}
	}
}
