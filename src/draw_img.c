#include "wolf3d.h"

#define UDIV m->sprite.in[m->sprite.order[i]].u_div
#define VDIV m->sprite.in[m->sprite.order[i]].v_div
#define VMOVE m->sprite.in[m->sprite.order[i]].v_move

void	ft_calc_ray_posdir(t_m *m, int x)
{
	m->cam.camera_x = (2 * x / (double)m->wnd.w - 1);
	m->rc.dir.x = m->p.dir.x + m->cam.plane_x * m->cam.camera_x;
	m->rc.dir.y = m->p.dir.y + m->cam.plane_y * m->cam.camera_x;
}

void 	ft_init_map_pos(t_m *m)
{
	m->rc.map_x = (int)(m->rc.pos.x);
	m->rc.map_y = (int)(m->rc.pos.y);
}

void	ft_calc_delta(t_m *m)
{
	m->dda.dx = sqrt(1 + pow(m->rc.dir.y, 2) / pow(m->rc.dir.x, 2));
	m->dda.dy = sqrt(1 + pow(m->rc.dir.x, 2) / pow(m->rc.dir.y, 2));
}

void	ft_init_dda(t_m *m)
{
	if (m->rc.dir.x < 0)
	{
		m->rc.step_x = -1;
		m->dda.side_dist_x = (m->rc.pos.x - m->rc.map_x) * m->dda.dx;
	}
	else
	{
		m->rc.step_x = 1;
		m->dda.side_dist_x = (m->rc.map_x + 1.0 - m->rc.pos.x) * m->dda.dx;
	}
	if (m->rc.dir.y < 0)
	{
		m->rc.step_y = -1;
		m->dda.side_dist_y = (m->rc.pos.y - m->rc.map_y) * m->dda.dy;
	}
	else
	{
		m->rc.step_y = 1;
		m->dda.side_dist_y = (m->rc.map_y + 1.0 - m->rc.pos.y) * m->dda.dy;
	}
}

void	ft_dda(t_m *m)
{
	while (m->rc.hit == 0)
	{
		if (m->dda.side_dist_x < m->dda.side_dist_y)
		{
			m->dda.side_dist_x += m->dda.dx;
			m->rc.map_x += m->rc.step_x;
			m->rc.side = 0;
		}
		else
		{
			m->dda.side_dist_y += m->dda.dy;
			m->rc.map_y += m->rc.step_y;
			m->rc.side = 1;
		}
		if (m->map.arr[m->rc.map_x][m->rc.map_y] > 0)
			m->rc.hit = 1;
	}
}

int		ft_calc_wall_dist(t_m *m)
{
	if (m->rc.side == 0)
		m->rc.wall_dist = (m->rc.map_x - m->rc.pos.x + (1 - m->rc.step_x) / 2) / m->rc.dir.x;
	else
		m->rc.wall_dist = (m->rc.map_y - m->rc.pos.y + (1 - m->rc.step_y) / 2) / m->rc.dir.y;
	if (m->rc.wall_dist >= 3 && !m->torch.status)
		return (0);
	return (1);
}

void	ft_calc_line_h(t_m *m)
{
	m->main_draw.h = (int)(m->wnd.h / m->rc.wall_dist) + 100;
}

void 	ft_calc_line_start(t_m *m)
{
	m->main_draw.start_y = -(m->main_draw.h) / 2 + m->wnd.h / 2;
	if (m->main_draw.start_y < 0)
		m->main_draw.start_y = 0;
}

void	ft_calc_line_end(t_m *m)
{
	m->main_draw.end_y = m->main_draw.h / 2 + m->wnd.h / 2;
	if (m->main_draw.end_y >= m->wnd.h)
		m->main_draw.end_y = m->wnd.h - 1;
}

void	ft_get_texture_num(t_m *m)
{
		if((m->main_draw.tex_num = m->map.arr[m->rc.map_x][m->rc.map_y] - 1) >= TXTR_SIZE)
			m->main_draw.tex_num = 0;
}

void	ft_calc_walx(t_m *m)
{
	if ( m->rc.side == 0)
		m->rc.wall_x = m->rc.pos.y + m->rc.wall_dist * m->rc.dir.y;
	else
		m->rc.wall_x = m->rc.pos.x + m->rc.wall_dist * m->rc.dir.x;
	m->rc.wall_x -= floor(m->rc.wall_x);
}

void	ft_calc_tex_x(t_m *m)
{
	m->main_draw.tex_x = (int)(m->rc.wall_x * (double)(m->tex.w));
	if (m->rc.side == 0 && m->rc.dir.x > 0)
		m->main_draw.tex_x = m->tex.w - m->main_draw.tex_x - 1;
	if (m->rc.side == 1 && m->rc.dir.y < 0)
		m->main_draw.tex_x = m->tex.w - m->main_draw.tex_x - 1;
}

void	ft_calc_light_power(SDL_Texture *texture, double dist, int fire)
{
	double dev;

	dev = dist > 0.5 ? dist : 0.5;
	if (!fire)
		SDL_SetTextureColorMod(texture,
						   (Uint8)(30 / dev),
						   (Uint8)(30 / dev),
						   (Uint8)(30 / dev));
	else
		SDL_SetTextureColorMod(texture,
						   (Uint8)(100 / dev),
						   (Uint8)(65 / dev),
						   (Uint8)(55 / dev));
}

void	ft_draw_line(t_m *m, int x)
{
	SDL_Rect	tex_rect;
	SDL_Rect	wnd_rect;
	int			d;
	int			tex_y;
	int			tex_y2;
	int 		l_mult_th;

	l_mult_th = m->main_draw.h * m->tex.half;
	d = m->main_draw.start_y * m->tex.h - m->h_m_thh + l_mult_th;
	tex_y = ((d * m->tex.h) / m->main_draw.h) / m->tex.h;
	d = (m->main_draw.end_y - 1) * m->tex.h - m->h_m_thh + l_mult_th;
	tex_y2 = ((d * m->tex.h) / m->main_draw.h) / m->tex.h;
	ft_calc_light_power(m->tex.buf[m->main_draw.tex_num], m->rc.wall_dist, m->torch.status);
	tex_rect = ft_sdl_set_rect(m->main_draw.tex_x, tex_y, 1, tex_y2 - tex_y);
	wnd_rect = ft_sdl_set_rect(x, m->main_draw.start_y, 1, m->main_draw.end_y - m->main_draw.start_y);
	SDL_RenderCopy(m->wnd.p_rend, m->tex.buf[m->main_draw.tex_num], &tex_rect, &wnd_rect);
}

void	ft_calc_z_buffer(t_m *m, int x)
{
	m->sprite.zbuff[x] = m->rc.wall_dist;
}

void	ft_sort_sprite(t_m *m)
{
	int		i;

	i = 0;
	while (i < SPRITE_SIZE)
	{
		m->sprite.order[i] = i;
		m->sprite.dist[i] = (m->p.pos.x - m->sprite.in[i].x) * (m->p.pos.x - m->sprite.in[i].x) + (m->p.pos.y - m->sprite.in[i].y) * (m->rc.pos.y - m->sprite.in[i].y);
		i++;
	}
	ft_combo_sort(m->sprite.order, m->sprite.dist, SPRITE_SIZE);
}

void	ft_calc_sprite(t_m *m)
{
	int i;
	int d;
	int vMoveScreen;
	SDL_Rect	tex_rect;
	SDL_Rect	wnd_rect;

	i = 0;
	while (i < SPRITE_SIZE)
	{
		if (!m->sprite.in[m->sprite.order[i]].visible)
		{
			i++;
			continue ;
		}
		m->sprite_draw.sprite_x = m->sprite.in[m->sprite.order[i]].x - m->p.pos.x;
		m->sprite_draw.sprite_y = m->sprite.in[m->sprite.order[i]].y - m->p.pos.y;
		//FIXME can calculate it before
 		m->sprite_draw.inv_det = 1.0 / (m->cam.plane_x * m->p.dir.y - m->p.dir.x * m->cam.plane_y);

		m->sprite_draw.trans_x = m->sprite_draw.inv_det * (m->p.dir.y * m->sprite_draw.sprite_x - m->p.dir.x * m->sprite_draw.sprite_y);
		m->sprite_draw.trans_y = m->sprite_draw.inv_det * (-m->cam.plane_y * m->sprite_draw.sprite_x + m->cam.plane_x * m->sprite_draw.sprite_y);

		if (m->sprite.in[m->sprite.order[i]].texture != 10 && m->sprite.in[m->sprite.order[i]].texture != 11 && fabs(m->sprite_draw.trans_y) < 3 && m->torch.status)
		{
			i++;
			continue ;
		}
		if (m->sprite.in[m->sprite.order[i]].texture != 10 && m->sprite.in[m->sprite.order[i]].texture != 11 && fabs(m->sprite_draw.trans_y) < 1.5)
		{
			i++;
			continue ;
		}
		//FIXME can (m->w / 2) calculate before
		m->sprite_draw.screen_x = (int)((m->wnd.w / 2) * (1 + m->sprite_draw.trans_x / m->sprite_draw.trans_y));

		vMoveScreen = (int)(VMOVE / m->sprite_draw.trans_y);

		m->sprite_draw.height = (int)(abs((int)(m->wnd.h / m->sprite_draw.trans_y)) / VDIV);

		m->sprite_draw.start_y = -m->sprite_draw.height / 2 + m->wnd.h / 2 + vMoveScreen;
		if (m->sprite_draw.start_y < 0)
			m->sprite_draw.start_y = 0;
		//FIXME can (m->h / 2) calculate before
		m->sprite_draw.end_y = m->sprite_draw.height / 2 + m->wnd.h / 2 + vMoveScreen;
		if (m->sprite_draw.end_y >= m->wnd.h)
			m->sprite_draw.end_y = m->wnd.h - 1;

		m->sprite_draw.width = (int)(abs((int)(m->wnd.h / m->sprite_draw.trans_y)) / UDIV);
		m->sprite_draw.start_x = -m->sprite_draw.width / 2 + m->sprite_draw.screen_x;
		if (m->sprite_draw.start_x < 0)
			m->sprite_draw.start_x = 0;
		m->sprite_draw.end_x = m->sprite_draw.width / 2 + m->sprite_draw.screen_x;
		if (m->sprite_draw.end_x >= m->wnd.w)
			m->sprite_draw.end_x = m->wnd.w - 1;
		//FIXME replace 256 to size texture;
		for (int stripe = m->sprite_draw.start_x; stripe < m->sprite_draw.end_x; stripe++)
		{
			m->sprite_draw.tex_x = ((256 * (stripe - (-m->sprite_draw.width / 2 + m->sprite_draw.screen_x)) * 256 / m->sprite_draw.width) / 256);
			if (m->sprite_draw.trans_y > 0 && m->sprite_draw.end_x < m->wnd.w && m->sprite_draw.trans_y < m->sprite.zbuff[stripe])
			{
				d = (m->sprite_draw.start_y - vMoveScreen) * m->tex.h - m->wnd.h * m->tex.half + m->sprite_draw.height * m->tex.half;
				m->sprite_draw.tex_y = ((d * m->tex.h) / m->sprite_draw.height) / m->tex.h;
				d = (m->sprite_draw.end_y - 1  - vMoveScreen) * m->tex.h - m->wnd.h * m->tex.half + m->sprite_draw.height * m->tex.half;
				m->sprite_draw.tex_y2 = ((d * m->tex.h) / m->sprite_draw.height) / m->tex.h;
				ft_calc_light_power(m->tex.buf[m->sprite.in[m->sprite.order[i]].texture], m->sprite_draw.trans_y, m->torch.status);
				tex_rect = ft_sdl_set_rect(m->sprite_draw.tex_x, m->sprite_draw.tex_y, 1,m->sprite_draw.tex_y2 - m->sprite_draw.tex_y);
				wnd_rect = ft_sdl_set_rect(stripe, m->sprite_draw.start_y, 1, m->sprite_draw.end_y - m->sprite_draw.start_y);
				SDL_RenderCopy(m->wnd.p_rend, m->tex.buf[m->sprite.in[m->sprite.order[i]].texture], &tex_rect, &wnd_rect);
			}
		}
		i++;
	}
}

void	ft_calc_img(t_m *m)
{
	int		x;

	m->rc.pos = m->p.pos;
	x = 0;
	while (x < m->wnd.w)
	{
		m->rc.hit = 0;
		m->h_m_thh = !m->torch.status ? (m->wnd.h - 200) * m->tex.half : m->wnd.h * m->tex.half;
		ft_calc_ray_posdir(m, x);
		ft_init_map_pos(m);
		ft_calc_delta(m);
		ft_init_dda(m);
		ft_dda(m);
		ft_get_texture_num(m);
		ft_calc_wall_dist(m);
		ft_calc_z_buffer(m, x);
		ft_calc_line_h(m);
		ft_calc_line_start(m);
		ft_calc_line_end(m);
		ft_calc_walx(m);
		ft_calc_tex_x(m);
		ft_draw_line(m, x);
		x += 2;
	}
	ft_sort_sprite(m);
	ft_calc_sprite(m);
}