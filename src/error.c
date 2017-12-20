/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:20:50 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:20:51 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error(int err)
{
	if (err == ERR_MEM_ALLOC)
		perror("Couldn't allocate memory!\n");
	else if (err == ERR_OPEN_FILE)
		perror("Couldn't open file!\n");
	else if (err == 7)
		perror("Bad map width! Example: \"W:10\"\n");
	else if (err == 8)
		perror("Bad map height! Example: \"H:10\"\n");
	else if (err == 10)
		perror("Map size more than 1000\n");
	else if (err == 11)
		perror("To much small map! Min size: 3x3\n");
	else if (err == 12)
		perror("Cant't find map start! Example: \"Map: \"\n");
	else if (err == 13)
		perror("Start position at the edges of map!\n");
	exit(err);
}
