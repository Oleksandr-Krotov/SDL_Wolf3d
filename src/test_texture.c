#include <SDL2/SDL_quit.h>

void	ft_load_texture_pack(void)
{
	int		x;
	int		y;
	int		xorcolor;
	int		ycolor;
	int		xycolor;
	Uint32	*buf[8];

	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			xorcolor = (x * 256 / 64) ^ (y * 256 / 64);
			ycolor = y * 256 / 64;
			xycolor = y * 128 / 64 + x * 128 / 64;
			buf[0][64 * y + x] = (Uint32)(65536 * 254 * (x != y && x != 64 - y));
			buf[1][64 * y + x] = (Uint32)(xycolor + 256 * xycolor + 65536 * xycolor);
			buf[2][64 * y + x] = (Uint32)(256 * xycolor + 65536 * xycolor);
			buf[3][64 * y + x] = (Uint32)(xorcolor + 256 * xorcolor + 65536 * xorcolor);
			buf[4][64 * y + x] = (Uint32)(256 * xorcolor);
			buf[5][64 * y + x] = (Uint32)(65536 * 192 * (x % 16 && y % 16));
			buf[6][64 * y + x] = (Uint32)(65536 * ycolor);
			buf[7][64 * y + x] = (128 + 256 + 65536 * 128);
			y++;
		}
		x++;
	}
}
