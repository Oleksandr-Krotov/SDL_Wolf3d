#include <wolf3d.h>

void	ft_move_forward(t_m *m, double mult)
{
	if (m->map.arr[(int)(m->p.pos.x + m->p.dir.x * m->p.ms * mult + 0.2)][(int)m->p.pos.y] == 0 && m->map.arr[(int)(m->p.pos.x + m->p.dir.x * m->p.ms * mult - 0.2)][(int)m->p.pos.y] == 0)
		m->p.pos.x += m->p.dir.x * m->p.ms * mult;
	if (m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y + m->p.dir.y * m->p.ms * mult + 0.2)] == 0 && m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y + m->p.dir.y * m->p.ms * mult - 0.2)] == 0)
		m->p.pos.y += m->p.dir.y * m->p.ms * mult;
}

void	ft_move_back(t_m *m, double mult)
{
	if (m->map.arr[(int)(m->p.pos.x - m->p.dir.x * m->p.ms * mult + 0.2)][(int)m->p.pos.y] == 0 && m->map.arr[(int)(m->p.pos.x - m->p.dir.x * m->p.ms * mult - 0.2)][(int)m->p.pos.y] == 0)
		m->p.pos.x -= m->p.dir.x * m->p.ms * mult;
	if (m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y - m->p.dir.y * m->p.ms * mult + 0.2)] == 0 && m->map.arr[(int)m->p.pos.x][(int)(m->p.pos.y - m->p.dir.y * m->p.ms * mult - 0.2)] == 0)
		m->p.pos.y -= m->p.dir.y * m->p.ms * mult;
}

void	ft_turn_left(t_m *m, double mult)
{
	m->p.old_x = m->p.dir.x;
	m->p.dir.x = (m->p.dir.x * cos(m->p.rs * mult) - m->p.dir.y * sin(m->p.rs * mult));
	m->p.dir.y = (m->p.old_x * sin(m->p.rs * mult) + m->p.dir.y * cos(m->p.rs * mult));
	m->cam.old_x = m->cam.plane_x;
	m->cam.plane_x = (m->cam.plane_x * cos(m->p.rs * mult) - m->cam.plane_y * sin(m->p.rs * mult));
	m->cam.plane_y = (m->cam.old_x * sin(m->p.rs * mult) + m->cam.plane_y * cos(m->p.rs * mult));
}

void	ft_turn_right(t_m *m, double mult)
{
	m->p.old_x = m->p.dir.x;
	m->p.dir.x = (m->p.dir.x * cos(-m->p.rs * mult) - m->p.dir.y * sin(-m->p.rs * mult));
	m->p.dir.y = (m->p.old_x * sin(-m->p.rs * mult) + m->p.dir.y * cos(-m->p.rs * mult));
	m->cam.old_x = m->cam.plane_x;
	m->cam.plane_x = (m->cam.plane_x * cos(-m->p.rs * mult) - m->cam.plane_y * sin(-m->p.rs * mult));
	m->cam.plane_y = (m->cam.old_x * sin(-m->p.rs * mult) + m->cam.plane_y * cos(-m->p.rs * mult));
}

void 	ft_do_action(t_m *m)
{
	if (m->map.arr[(int)(m->p.pos.x + m->p.dir.x + 0.5)][(int)m->p.pos.y] == 5
		|| m->map.arr[(int)(m->p.pos.x)][(int)(m->p.pos.y + m->p.dir.y + 0.5)] == 5
		|| m->map.arr[(int)(m->p.pos.x + m->p.dir.x - 0.5)][(int)m->p.pos.y] == 5
		|| m->map.arr[(int)(m->p.pos.x)][(int)(m->p.pos.y + m->p.dir.y - 0.5)] == 5)
	{
		if (!m->flags[KEY])
		{
			Mix_PlayChannel(3, m->music.lock, 0);
			m->flags[MSG] = TRUE;
		}
		else
		{
			m->flags[GAME] = OPEN;
		}
	}
	printf("Ex+1: [%d][%d]--->%d\n", (int)(m->p.pos.x + m->p.dir.x + 1), (int)m->p.pos.y, m->map.arr[(int)(m->p.pos.x + m->p.dir.x + 1)][(int)m->p.pos.y]);
}