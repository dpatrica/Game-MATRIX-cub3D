//
// Created by Daisey Patrica on 16/12/2020.
//

#include "./includes/cub3d.h"

void	ft_drow(t_all *xlm)
{
	int		x = 0;
	int 	y = 0;
	int		xx = 50;
	int		yy = 50;
	int		xxx = 50;
	int		yyy = 50;

	while (xlm->param.g_map[y] && xlm->param.g_map[y][x])
	{
		yyy += 15;
		while (xlm->param.g_map[y][x])
		{
			xxx += 15;
			if (xlm->param.g_map[y][x] == '1')
			{
				while (yy < yyy)
				{
					while (xx < xxx)
						mlx_pixel_put(xlm->mlx, xlm->win, xx++, yy, 0xAA3AAA);
					yy++;
					xx -= 15;
				}
			}
			else if (xlm->param.g_map[y][x] == '0')
			{
				while (yy < yyy)
				{
					while (xx < xxx)
						mlx_pixel_put(xlm->mlx, xlm->win, xx++, yy, 0xFFFFFF);
					yy++;
					xx -= 15;
				}
			}
			else if (ft_rhr("NSWE", xlm->param.g_map[y][x]))
			{
				xlm->player.x = x;
				xlm->player.y = y;
				while (yy < yyy)
				{
					while (xx < xxx)
						mlx_pixel_put(xlm->mlx, xlm->win, xx++, yy, 0xFF0000);
					yy++;
					xx -= 15;
				}
			}
			else if (xlm->param.g_map[y][x] == ' ')
				yy += 15;
			yy -= 15;
			xx += 15;
			x++;
		}
		y++;
		x = 0;
		xx = 50;
		xxx = 50;
		yy += 15;
	}
}