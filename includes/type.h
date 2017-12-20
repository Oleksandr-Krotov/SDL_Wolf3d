/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:07:44 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:07:45 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define TRUE 1
# define FALSE 0

# define UNUSED(x) (void)(x)

typedef enum e_switch	t_switch;

enum	e_switch
{
	OFF,
	ON
};

typedef struct s_v2d	t_v2d;

struct	s_v2d
{
	int	x;
	int	y;
};

typedef struct s_v3d	t_v3d;

struct	s_v3d
{
	int	x;
	int	y;
	int	z;
};

typedef struct s_v2f	t_v2f;

struct	s_v2f
{
	double	x;
	double	y;
};

typedef struct s_v3f	t_v3f;

struct	s_v3f
{
	double	x;
	double	y;
	double	z;
};

#endif
