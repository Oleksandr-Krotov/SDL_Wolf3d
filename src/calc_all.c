#include <wolf3d.h>

void	ft_move_forward(t_m *m, int mult)
{
	printf("map[%d][%d]: %d\n", (int)(m->p.pos.x + m->p.dir.x * m->p.ms), (int)m->p.pos.y, m->map.arr[(int)(m->p.pos.x + m->p.dir.x * m->p.ms)][(int)m->p.pos.y]);
	if (m->map.arr[(int)(m->p.pos.x + m->p.dir.x * m->p.ms * mult)][(int)m->p.pos.y] == 0)
		m->p.pos.x += m->p.dir.x * m->p.ms * mult;
	if ((m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y + m->p.dir.y * m->p.ms * mult)] == 0))
		m->p.pos.y += m->p.dir.y * m->p.ms * mult;
}

void	ft_move_back(t_m *m, int mult)
{
	printf("map[%d][%d]: %d\n", (int)(m->p.pos.x - m->p.dir.x * m->p.ms), (int)m->p.pos.y, m->map.arr[(int)(m->p.pos.x - m->p.dir.x * m->p.ms)][(int)m->p.pos.y]);
	if (m->map.arr[(int)(m->p.pos.x - m->p.dir.x * m->p.ms * mult)][(int)m->p.pos.y] == 0)
		m->p.pos.x -= m->p.dir.x * m->p.ms * mult;
	if (m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y - m->p.dir.y * m->p.ms * mult)] == 0)
		m->p.pos.y -= m->p.dir.y * m->p.ms * mult;
}

void	ft_turn_left(t_m *m, int mult)
{
	m->p.old_x = m->p.dir.x;
	m->p.dir.x = (m->p.dir.x * cos(m->p.rs * mult) - m->p.dir.y * sin(m->p.rs * mult));
	m->p.dir.y = (m->p.old_x * sin(m->p.rs * mult) + m->p.dir.y * cos(m->p.rs * mult));
	m->cam.old_x = m->cam.plane_x;
	m->cam.plane_x = (m->cam.plane_x * cos(m->p.rs * mult) - m->cam.plane_y * sin(m->p.rs * mult));
	m->cam.plane_y = (m->cam.old_x * sin(m->p.rs * mult) + m->cam.plane_y * cos(m->p.rs * mult));
}

void	ft_turn_right(t_m *m, int mult)
{
	m->p.old_x = m->p.dir.x;
	m->p.dir.x = (m->p.dir.x * cos(-m->p.rs * mult) - m->p.dir.y * sin(-m->p.rs * mult));
	m->p.dir.y = (m->p.old_x * sin(-m->p.rs * mult) + m->p.dir.y * cos(-m->p.rs * mult));
	m->cam.old_x = m->cam.plane_x;
	m->cam.plane_x = (m->cam.plane_x * cos(-m->p.rs * mult) - m->cam.plane_y * sin(-m->p.rs * mult));
	m->cam.plane_y = (m->cam.old_x * sin(-m->p.rs * mult) + m->cam.plane_y * cos(-m->p.rs * mult));
}
