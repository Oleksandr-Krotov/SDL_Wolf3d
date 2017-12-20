/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:47:58 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 11:47:59 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
** DISPLAY
*/

# define DISP_W 1200
# define DISP_H 900

# define MS 2;
# define RS 3;

# define T_MSG 300000
# define T_HP 3000000
# define T_TORCH 200000
# define T_ANIM 100000
# define T_INTRO 10000000

/*
**	SCENE_SIZE
*/

# define SCENE_SIZE			5
# define SCENE_STAGE		3

/*
** AUDIO CHANEL
*/

# define C_BG		1
# define C_EVENT	2
# define C_EFFECT	3

/*
** PATH
*/

# define P_MAP		"maps/"
# define P_ASSETS	"assets/"
# define P_TEXTURE	P_ASSETS"texture/"
# define P_SOUNDS	P_ASSETS"sounds/"
# define P_FONT		P_ASSETS"font/"
# define P_START	P_TEXTURE"start_screen/"
# define P_GARDEN	P_TEXTURE"garden/"

/*
** FLAGS
*/

# define LOOP		0
# define CUR_SCENE	1
# define FLAG_SIZE	2

/*
**  MUTUAL TEXTURE
*/

# define P_HP			P_TEXTURE"hp.png"
# define P_CLOSE_MSG	P_TEXTURE"CloseMsg.png"
# define P_DIE			P_TEXTURE"Die.png"
# define P_ROPE			P_TEXTURE"Rope.png"
# define P_SPARK		P_TEXTURE"Spark.png"
# define P_SCREAM		P_TEXTURE"Scream.png"
# define P_WOUND		P_TEXTURE"Wound.png"
# define P_TORCH_SPRITE	P_TEXTURE"TorchSprite.png"
# define P_OPEN_GARDEN	P_TEXTURE"OpenGarden.png"
# define P_INTRO		P_TEXTURE"Intro.png"

/*
**FONT
*/
# define P_F_METAL		P_FONT"MetalMacabre.ttf"

#endif
