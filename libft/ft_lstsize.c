/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:44:29 by akrotov           #+#    #+#             */
/*   Updated: 2017/03/14 17:44:30 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *lst)
{
	t_list *lst_ptr;
	size_t ret_size;

	lst_ptr = lst;
	ret_size = 0;
	while (lst_ptr != NULL)
	{
		ret_size++;
		lst_ptr = lst_ptr->next;
	}
	return (ret_size);
}
