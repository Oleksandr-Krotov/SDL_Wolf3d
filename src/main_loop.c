#include "wolf3d.h"

void	ft_torch(t_m * m)
{
	SDL_Rect	src;
	SDL_Rect	dst;
	int			step_x;
	int			step_y;
	static int	num_x;
	static int	num_y;
	static int	i;

	if (m->torch.status)
	{
		i += 1 / m->time.fps;
		step_x = 183;
		step_y = 191;
		if (i >= 200)
		{
			num_x = rand() % 4;
			num_y = rand() % 2;
			i = 0;
		}
		src = ft_sdl_set_rect(step_x * num_x, step_y * num_y, step_x, 200);
		dst = ft_sdl_set_rect((int)(m->wnd.w * 0.2) , (int)(m->wnd.h * 0.53), m->wnd.w / 4, m->wnd.h / 2);
		SDL_RenderCopy(m->wnd.p_rend, m->p.arm[TORCH].texture, &src, &dst);
	}
}

void	ft_get_drop(t_sprite_in *lst, t_v2f pos, t_torch_time *torch, int *flags)
{
	int i;

	i = 0;
	while (i < SPRITE_SIZE)
	{
		if (lst[i].texture == 10 && lst[i].visible == TRUE &&((int)lst[i].x == (int)pos.x && (int)lst[i].y == (int)pos.y))
		{
			torch->status = TRUE;
			lst[i].visible = FALSE;
			torch->hp = (int)fmin(100, torch->hp + 25);
			break ;
		}
		else if (lst[i].texture == 11 && lst[i].visible == TRUE &&((int)lst[i].x == (int)pos.x && (int)lst[i].y == (int)pos.y))
		{
			flags[KEY]= TRUE;
			lst[i].visible = FALSE;
			break ;
		}
		i++;
	}
}

void	ft_torch_time(t_wnd wnd, t_torch_time *torch, double fps)
{
	SDL_Rect	dst;
	SDL_Rect	src;
	double		step;

	step = (wnd.w - (wnd.w * 0.25)) / 100;
	if (torch->status == TRUE)
	{
		src = ft_sdl_set_rect(0 , 0, 1024 * torch->hp / 100, 256);
		dst = ft_sdl_set_rect(wnd.w / 8, 0, (int)(step * torch->hp), (int)(wnd.h * 0.1));
		SDL_RenderCopy(wnd.p_rend, torch->rope, &src, &dst);
		dst = ft_sdl_set_rect((int)(wnd.w / 8 + step * torch->hp) - (int)(wnd.w * 0.025), 0, (int)(wnd.w * 0.05), (int)(wnd.h * 0.1));
		SDL_RenderCopy(wnd.p_rend, torch->spark, NULL, &dst);
	}
	torch->count += 1 / fps;
	if (torch->count >= 400 && torch->hp > 0)
	{
		torch->hp--;
		torch->count = 0;
		if (torch->hp == 0)
			torch->status = FALSE;
	}
}

void	ft_sound_event(t_v2f pos, t_audio audio, int *flags)
{
	if (flags[CROW] == TRUE && (int)pos.x == 13 && (int)pos.y == 5)
	{
		Mix_VolumeChunk(audio.crow, MIX_MAX_VOLUME / 2);
		Mix_PlayChannel(3, audio.crow, 0);
		flags[CROW] = FALSE;
	}
	if (flags[KEY] == FALSE && (int)pos.x == 4 && (int)pos.y == 1)
		Mix_PlayChannel(3, audio.event, 0);
	if (flags[WALK] == TRUE && (int)pos.x == 18 && (int)pos.y == 7)
	{
		Mix_PlayChannel(3, audio.walk, 0);
		flags[WALK] = FALSE;
	}
}

void	ft_event_manager(t_m *m)
{
	ft_sound_event(m->p.pos, m->music, m->flags);
	if (m->flags[SCREAM] == 1 && (int)m->p.pos.x == 8 && (int)m->p.pos.y == 11)
	{
		Mix_PauseMusic();
		SDL_Delay(300);
		SDL_RenderCopy(m->wnd.p_rend, m->scream, NULL, NULL);
		m->flags[SCREAM] = 2;
	}
	else if (m->flags[SCREAM] == 2 && (int)m->p.pos.x == 8 && (int)m->p.pos.y == 11)
	{
		Mix_PlayChannel(3, m->music.screamer, 0);
		SDL_Delay(2000);
		m->p.hp = (int)fmax(0, m->p.hp - 10);
		Mix_PlayChannel(3, m->music.wound, 0);
		Mix_ResumeMusic();
		m->flags[SCREAM] = 0;
	}
	if (m->torch.hp == 0)
	{
		m->p.count += (1 / m->time.fps);
		if (m->p.count > 4000)
		{
			m->p.hp -= 5;
			m->p.count = 0;
			Mix_PlayChannel(4, m->music.wound, 0);
		}
		if (m->p.hp <= 0)
			m->flags[GAME] = OVER;
	}
	SDL_SetTextureAlphaMod(m->p.wound, (Uint8)(255 * (100 - m->p.hp) / 100.0));
	SDL_RenderCopy(m->wnd.p_rend, m->p.wound, NULL, NULL);
}


double	*ft_recalc_disp_size(t_wnd *wnd, double *zbuf)
{
	SDL_GetWindowSize(wnd->p_wnd, &wnd->w, &wnd->h);
	if (wnd->w <= 0)
		wnd->w = 1;
	if (wnd->h <= 0)
		wnd->h = 1;
	if (wnd->old_w != wnd->w)
	{
		free(zbuf);
		zbuf = malloc(sizeof(double) * wnd->w);
		wnd->old_w = wnd->w;
	}
	return (zbuf);
}

void	ft_draw_bar(t_m *m)
{
	SDL_Rect dst;
	dst = ft_sdl_set_rect(m->wnd.w - (int)(m->wnd.w * 0.07), m->wnd.h - (int)(m->wnd.h * 0.07), (int)(m->wnd.w * 0.05), (int)(m->wnd.h * 0.05));
	SDL_RenderCopy(m->wnd.p_rend, m->p.heart, NULL, &dst);
	ft_sdl_draw_text(&m->wnd, m->font, ft_itoa(m->p.hp), (t_v2d){(int)(m->wnd.w - (m->wnd.w * 0.05)), (int)(m->wnd.h - (m->wnd.h * 0.05))});
	if (m->flags[KEY])
	{
		dst = ft_sdl_set_rect((int)(m->wnd.w * 0.01), m->wnd.h /2 , (int)(m->wnd.w * 0.1), (int)(m->wnd.h * 0.1));
		SDL_RenderCopy(m->wnd.p_rend, m->tex.buf[11], NULL, &dst);
	}
}

void	ft_torch_event(t_m *m)
{
	ft_torch(m);
	ft_torch_time(m->wnd, &m->torch, m->time.fps);
	ft_get_drop(m->sprite.in, m->p.pos, &m->torch, m->flags);
}

void	ft_end_game(t_m *m)
{
	if (m->flags[GAME] == OVER)
	{
		SDL_RenderCopy(m->wnd.p_rend, m->p.die, NULL, NULL);
		SDL_RenderCopy(m->wnd.p_rend, m->p.wound, NULL, NULL);
	}
	else if (m->flags[GAME] == OPEN)
	{
		Mix_PlayChannel(3, m->music.open, 0);
		SDL_RenderCopy(m->wnd.p_rend, m->open, NULL, NULL);
	}
	if (m->flags[GAME] == OVER || m->flags[GAME] == OPEN)
	{
		SDL_RenderPresent(m->wnd.p_rend);
		SDL_Delay(5000);
	}
}

void	ft_put_msg_to_screen(t_m *m)
{
	static int count = 0;

	if (m->flags[MSG] == TRUE && count < 500)
	{
		SDL_RenderCopy(m->wnd.p_rend, m->msg, NULL, NULL);
		count += (int)(1 / m->time.fps);
	}
	else if (count > 500)
	{
		m->flags[MSG] = FALSE;
		count = 0;
	}
}

void	ft_main_loop(t_m *m)
{
	Mix_PlayMusic(m->music.audio, -1);
	while (m->flags[GAME] == START)
	{
		m->sprite.zbuff = ft_recalc_disp_size(&m->wnd, m->sprite.zbuff);
		SDL_SetRenderDrawColor(m->wnd.p_rend, 0, 0, 0, 0);
		SDL_RenderClear(m->wnd.p_rend);
		ft_calc_img(m);
		ft_fps(m);
		ft_torch_event(m);
		ft_event_manager(m);
		ft_put_msg_to_screen(m);
		ft_draw_bar(m);
		SDL_RenderPresent(m->wnd.p_rend);
		ft_event_manager(m);
		ft_sdl_event_hook(m);
	}
	ft_end_game(m);
}
