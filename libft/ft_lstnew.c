/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:38:39 by akrotov           #+#    #+#             */
/*   Updated: 2016/12/08 19:38:55 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lstnew;

	lstnew = (t_list*)malloc(sizeof(t_list) + content_size);
	if (lstnew == NULL)
		return (NULL);
	if (content == NULL)
	{
		lstnew->content = NULL;
		lstnew->content_size = 0;
	}
	else
	{
		lstnew->content = malloc(sizeof(content) * content_size);
		if (lstnew->content == NULL)
			return (NULL);
		lstnew->content = ft_memcpy(lstnew->content, content, content_size);
		lstnew->content_size = content_size;
		lstnew->next = NULL;
	}
	lstnew->next = NULL;
	return (lstnew);
}
