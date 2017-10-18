#include <wolf3d.h>

char	*ft_get_size(t_m *m, char *src)
{
	char *ptr;

	m->map.row = 0;
	m->map.col = 0;
	ptr = src;
	ptr = ft_strstr(ptr, "W:");
	if (ptr == NULL)
		ft_error(7);
	ptr += 2;
	if (ft_isdigit(*ptr))
		m->map.col = ft_atoi(ptr);
	else
		ft_error(7);
	if (m->map.col > 1000)
		ft_error(16);
	ptr = ft_strstr(ptr, "H:");
	if (ptr == NULL)
		ft_error(8);
	ptr += 2;
	if (ft_isdigit(*ptr))
		m->map.row = ft_atoi(ptr);
	else
		ft_error(8);
	if (m->map.row > 1000)
		ft_error(16);
	ptr = ft_strstr(ptr, "Map:");
	if (ptr == NULL)
		ft_error(9);
	ptr += 4;
	if (m->map.row == 0 || m->map.col == 0)
		ft_error(10);

	return (ptr);
}

void	ft_put_valid_num(t_m *m, char *src, int *i, int *j)
{
	m->map.arr[*i][*j] = ft_atoi(src);
	if ((*i == 0 || *i == m->map.row - 1) && m->map.arr[*i][*j] <= 0)
		ft_error(11);
	if ((*j == 0 || *j == m->map.col - 1) && m->map.arr[*i][*j] <= 0)
		ft_error(11);
	(*j)++;
	if (*j == m->map.col && *i < m->map.row - 1)
	{
		*j = 0;
		(*i)++;
	}
}

void	ft_fill_arr(t_m *m, char *src)
{
	int i;
	int j;


	i = 0;
	j = 0;
	while (*src != '\0')
	{
		if (!ft_isdigit(*src))
		{
			if (*src == 'S')
			{
				if (i == 0 && i == m->map.row - 1)
					ft_error(15);
				if (j == 0 || j == m->map.col - 1)
					ft_error(15);
				m->map.start.x = j;
				m->map.start.y = i;
				m->map.arr[i][j] = 0;
				j++;
			}
			src++;
		}
		else
		{
			ft_put_valid_num(m, src, &i, &j);
			while (ft_isdigit(*src))
				src++;
		}
	}
	if (i != m->map.row - 1 && j != m->map.row)
		ft_error(12);
	if (m->map.start.x == -1 || m->map.start.y == -1)
		ft_error(13);
}

int		ft_read_map(t_m *m, char *f_name)
{
	char *src;

	m->map.start.x = -1;
	m->map.start.y = -1;
	src = ft_load_file(f_name);
	src = ft_get_size(m, src);
	m->map.arr = ft_create_2d_int_arr(m->map.row, m->map.col);
	ft_bzero_2d_arr(m->map.row, m->map.col, m->map.arr);
	ft_fill_arr(m, src);
	printf("row: %d\ncol: %d\nstart: \n \tx: %.2f\n \ty: %.2f\n", m->map.row, m->map.row, m->map.start.x, m->map.start.y);
	print_int_2d_arr(m->map.row, m->map.col, m->map.arr);
	return (1);
}
