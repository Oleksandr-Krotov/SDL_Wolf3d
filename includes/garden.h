/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garden.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrotov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:49:09 by akrotov           #+#    #+#             */
/*   Updated: 2017/10/28 11:49:10 by akrotov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARDEN_H
# define GARDEN_H

# define G_MAPNAME P_MAP"garden.w3d"

/*
** FLAGS
*/
# define G_STAGE			0
# define G_DES_TYPE			1
# define G_TEX_SIZE			2
# define G_TORCH			3
# define G_SPRITE			4
# define G_GAME				5
# define G_SCREAM			6
# define G_KEY				7
# define G_MSG				8
# define G_CROW				9
# define G_WALK				10
# define G_MOO				11
# define G_FLAG_SIZE		12

/*
** TEXTURE
*/
# define P_G_CRASH			P_GARDEN"Crash.png"
# define P_G_DARK_MOSS		P_GARDEN"DarkMoss.png"
# define P_G_FEN_STONE		P_GARDEN"FenStone.png"
# define P_G_GREEN_BRK		P_GARDEN"GreenBrk.png"
# define P_G_GREEN_BRK2		P_GARDEN"GreenBrk2.png"
# define P_G_HEDGE			P_GARDEN"Hedge.png"
# define P_G_IVY_WALL		P_GARDEN"IvyWall.png"
# define P_G_MOSSY_ROCK		P_GARDEN"MossyRock.png"
# define P_G_GATE			P_GARDEN"Gate.png"

/*
** SPRITE
*/
# define P_G_COLONIT		P_GARDEN"Colonit.png"
# define P_G_VANGUARD		P_GARDEN"Vanguard.png"
# define P_G_KEY			P_GARDEN"Key.png"
# define P_G_TORCH			P_GARDEN"Torch.png"
# define G_SPRT_POINT		11

/*
** AUDIO
*/
# define P_G_MUS_BG			P_SOUNDS"SwampBG.mp3"

# define P_G_CHUNK_WOUND	P_SOUNDS"Wound.wav"
# define P_G_CHUNK_SCREAM	P_SOUNDS"Scream.wav"
# define P_G_CHUNK_LOCK		P_SOUNDS"Lock.wav"
# define P_G_CHUNK_GATE		P_SOUNDS"CemeteryGate.wav"
# define P_G_CHUNK_CROW		P_SOUNDS"Crow.wav"
# define P_G_CHUNK_KEY		P_SOUNDS"Key.wav"
# define P_G_CHUNK_GRAVE_W	P_SOUNDS"GravelWalk.wav"
# define P_G_CHUNK_MOO		P_SOUNDS"SonoMoo.mp3"

enum	e_garden_tex
{
	CRASH,
	DARK_MOSS,
	FEN_STONE,
	GREEN_BRK,
	GREEN_BRK2,
	HEDGE,
	IVY_WALL,
	MOSSY_ROCK,
	GATE,
	G_TEX_NUM
};

enum	e_garden_sprt
{
	COLONIT,
	VANGUARD,
	KEY,
	TORCH,
	G_SPTR_NUM
};

enum	e_garden_chunk
{
	CHUNK_WOUND,
	CHUNK_SCREAM,
	CHUNK_LOCK,
	CHUNK_GATE,
	CHUNK_CROW,
	CHUNK_KEY,
	CHUNK_GRAVE_W,
	CHUNK_MOO,
	G_CHUNK_NUM
};

#endif
