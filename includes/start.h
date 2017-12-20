/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:06:56 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 12:06:57 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_H
# define START_H

/*
** SCREEN SCENE START
*/

# define START_TEX_SIZE 	3
# define P_S_BG 			P_START"start_bg.png"
# define P_S_LIGHT 			P_START"start_light.png"
# define P_S_PRESS 			P_START"start_press.png"
# define P_S_MUS_BG			P_SOUNDS"start_BG.mp3"
# define P_S_CHUNK_LIGHT	P_SOUNDS"light.wav"

# define S_STAGE			0
# define S_FRAME			1
# define S_EVENT			2
# define S_DES_TYPE			3
# define S_FLAG_SIZE		4

enum	e_start
{
	S_BG,
	S_LIGHT,
	S_PRESS
};

#endif
