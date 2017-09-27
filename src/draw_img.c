#include "wolf3d.h"

void	ft_calc_img(t_m *m)
{
	int		x;
	int		y;
	t_rgba	color;

	color = (t_rgba){0, 200, 0, 0};
	x = 0;
	while (x < m->imgs->w)
	{
		m->cam.camera_x = 2 * x / m->imgs->w - 1;
		m->p.dir.x = m->p.dir.x + m->cam.plane_x * m->cam.camera_x;
		m->p.dir.x = m->p.pos.y + m->cam.plane_x * m->cam.camera_x;
		m->dda.delta_dist_x = sqrt((1 + pow(m->p.dir.y, 2) / pow(m->p.dir.x, 2)));
		m->dda.delta_dist_y = sqrt((1 + pow(m->p.dir.y, 2) / pow(m->p.dir.x, 2)));
		if (m->p.dir.x < 0)
		{
			m->rc.step_x = -1;
			m->dda.side_dist_x =
		}
//		y = 0;
//		while (y < m->imgs->h)
//		{
//			ft_sdl_put_pixel(m->imgs, x, y, color);
//			y++;
//		}
		x++;
	}
}
