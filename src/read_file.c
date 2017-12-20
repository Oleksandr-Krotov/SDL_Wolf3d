/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:50:59 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:51:02 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char	*ft_load_file(const char *f_name)
{
	FILE		*file;
	struct stat f_stat;
	char		*source;

	file = fopen(f_name, "r");
	if (file <= 0)
		ft_error(ERR_OPEN_FILE);
	stat(f_name, &f_stat);
	source = (char *)malloc((size_t)(f_stat.st_size + 1));
	fread(source, (size_t)f_stat.st_size, 1, file);
	source[f_stat.st_size] = '\0';
	fclose(file);
	return (source);
}
