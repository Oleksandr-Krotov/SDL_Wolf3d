#include "wolf3d.h"

void	ft_calc_ray_posdir(t_m *m, int x)
{
	m->cam.camera_x = 2 * x / (double)m->imgs->w - 1;
	m->rc.pos = m->p.pos;
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

void	ft_calc_wall_dist(t_m *m)
{
	if (m->rc.side == 0)
		m->rc.wall_dist = (m->rc.map_x - m->rc.pos.x + (1 - m->rc.step_x) / 2) / m->rc.dir.x;
	else
		m->rc.wall_dist = (m->rc.map_y - m->rc.pos.y + (1 - m->rc.step_y) / 2) / m->rc.dir.y;
}

void	ft_calc_line_h(t_m *m)
{
	m->line.line_h = (int)(m->h / m->rc.wall_dist);
}

void 	ft_calc_line_start(t_m *m)
{
	m->line.draw_s = -(m->line.line_h) / 2 + m->h / 2;
	if (m->line.draw_s < 0)
		m->line.draw_s = 0;
}

void	ft_calc_line_end(t_m *m)
{
	m->line.draw_e = m->line.line_h / 2 + m->h / 2;
	if (m->line.draw_e >= m->h)
		m->line.draw_e = m->h - 1;
}

void	ft_get_texture_num(t_m *m)
{
		if((m->line.tex_num = m->map.arr[m->rc.map_x][m->rc.map_y] - 1) >= TXTR_SIZE)
			m->line.tex_num = 8;
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
	m->line.tex_x = (int)(m->rc.wall_x * (double)(m->texturs.w));
	if (m->rc.side == 0 && m->rc.dir.x > 0)
		m->line.tex_x = m->texturs.w - m->line.tex_x - 1;
	if (m->rc.side == 1 && m->rc.dir.y < 0)
		m->line.tex_x = m->texturs.w - m->line.tex_x - 1;
}

void	sdl_get_texture_pixel(t_m *m, int y)
{
	int			d;
	int			tex_y;
	Uint8		*pixel;
	Uint32		pix32;

	d = y * 256 - m->h * 128 + m->line.line_h * 128;
	tex_y = ((d * m->texturs.h) / m->line.line_h) / 256;
	pixel = m->texturs.buf[m->line.tex_num]->pixels;
	d = (tex_y * (m->texturs.buf[m->line.tex_num]->pitch) + m->line.tex_x * m->texturs.buf[m->line.tex_num]->format->BytesPerPixel);
	pix32 = *(Uint32 *)&pixel[d];
	SDL_GetRGBA(pix32, m->texturs.buf[m->line.tex_num]->format, &m->line.color.r, &m->line.color.g, &m->line.color.b, &m->line.color.a);
	if (m->rc.wall_dist >= 1)
	{
		m->line.color.r /= (m->rc.wall_dist );
		m->line.color.g /= (m->rc.wall_dist );
		m->line.color.b /= (m->rc.wall_dist );
	}
	if (m->flags[FIRE])
	{
		m->line.color.r = (Uint8)((m->line.color.r * 0.7) + (200 / (m->rc.wall_dist) * 0.3));
		m->line.color.g = (Uint8)((m->line.color.g * 0.7) + (120 / (m->rc.wall_dist) * 0.3));
	}
}

void	ft_draw_line(t_m *m, int x)
{
	int	y;

	y = 0;
	while (y < m->h)
	{
		if (y > m->line.draw_s && y < m->line.draw_e)
		{
			sdl_get_texture_pixel(m, y);
			ft_sdl_put_pixel(m->imgs, x, y, m->line.color);
		}
		else if (y < m->line.draw_s)
			ft_sdl_put_pixel(m->imgs, x, y, (SDL_Color){45 , 45 , 45, 255});
		else
			ft_sdl_put_pixel(m->imgs, x, y, (SDL_Color){45, 45, 45, 255});
		y++;
	}
}

void	ft_calc_img(t_m *m)
{
	int		x;

	x = 0;
	while (x < m->imgs->w)
	{
		m->rc.hit = 0;
		ft_calc_ray_posdir(m, x);
		ft_init_map_pos(m);
		ft_calc_delta(m);
		ft_init_dda(m);
		ft_dda(m);
		ft_get_texture_num(m);
		ft_calc_wall_dist(m);
		ft_calc_line_h(m);
		ft_calc_line_start(m);
		ft_calc_line_end(m);
		ft_calc_walx(m);
		ft_calc_tex_x(m);
		ft_draw_line(m, x);
		x++;
	}
}