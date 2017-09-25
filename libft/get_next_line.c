/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:44:18 by akrotov           #+#    #+#             */
/*   Updated: 2017/03/14 19:18:45 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd_and_rest	*ft_search_fd(int fd, t_fd_and_rest **gnl)
{
	t_fd_and_rest *ptr;

	ptr = *gnl;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	ptr = malloc(sizeof(t_fd_and_rest));
	ptr->fd = fd;
	ptr->next = *gnl;
	*gnl = ptr;
	ft_bzero(ptr->temp, BUFF_SIZE + 1);
	return (ptr);
}

size_t			ft_clear_buff(char *buff, t_fd_and_rest *ptr)
{
	t_ret	ret;
	char	*tmp;

	ret.ret_r = 0;
	tmp = ptr->temp;
	while (buff[ret.ret_r] != '\0' && ret.ret_r < BUFF_SIZE)
	{
		if (buff[ret.ret_r] != '\n')
			ret.ret_r++;
		else
		{
			ret.ret_c = 1;
			buff[ret.ret_r] = '\0';
			ret.ret_r++;
			while (buff[ret.ret_r] != '\0' && ret.ret_r < BUFF_SIZE)
			{
				*tmp = buff[ret.ret_r];
				buff[ret.ret_r] = '\0';
				ret.ret_r++;
				tmp++;
			}
		}
	}
	return (ret.ret_c);
}

char			*ft_add_str(char **str, char *buff)
{
	char *p;

	p = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(p, buff);
	ft_bzero(buff, BUFF_SIZE + 1);
	free(p);
	return (*str);
}

size_t			ft_add_temp(char *buff, char **str, t_fd_and_rest *ptr)
{
	size_t	ret;
	char	*p;

	ft_strcpy(buff, ptr->temp);
	ft_bzero(ptr->temp, BUFF_SIZE + 1);
	ret = ft_clear_buff(buff, ptr);
	p = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(p, buff);
	ft_bzero(buff, BUFF_SIZE + 1);
	free(p);
	return (ret);
}

int				get_next_line(int fd, char **str)
{
	static t_fd_and_rest	*gnl;
	char					buff[BUFF_SIZE + 1];
	t_fd_and_rest			*ptr;
	t_ret					ret;

	if (fd < 0 || str == NULL || (read(fd, NULL, 0)) == -1)
		return (-1);
	*str = ft_strnew(0);
	ret.ret_c = 0;
	ret.ret_r = 1;
	ft_bzero(buff, BUFF_SIZE + 1);
	ptr = ft_search_fd(fd, &gnl);
	if (ft_strlen(ptr->temp) > 0)
		ret.ret_c = (size_t)ft_add_temp(buff, str, ptr);
	while (ret.ret_c != 1 && ret.ret_r > 0)
		if ((ret.ret_r = (int)read(fd, &buff, BUFF_SIZE)) > 0)
		{
			ret.ret_c = ft_clear_buff(buff, ptr);
			*str = ft_add_str(str, buff);
		}
	if (*str == NULL || (ret.ret_r == 0 && ft_strlen(*str) == 0))
		return (0);
	if (ret.ret_r == -1)
		return (-1);
	return (1);
}
