/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:48:31 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 11:48:32 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPS_H
# define FPS_H

# include <time.h>

# define SMOOTH 0.1

typedef struct s_time	t_time;

struct	s_time
{
	double	current;
	double	old;
	double	delta;
	int		fps;
};

void	ft_fps(t_time *time);
int		ft_counter(int *storage, int fps, int limit);

#endif
