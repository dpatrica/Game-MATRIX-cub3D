//
// Created by Daisey Patrica on 16/12/2020.
//

#include "./includes/cub3d.h"

void 	ft_drow_square(t_all xlm, float x, float y, unsigned int color)
{
	int start_x;
	int start_y;

	start_x = x;
	start_y = y;
	while (y < (xlm.width_square + start_y))
	{
		x = start_x;
		while (x < (xlm.width_square + start_x))
			mlx_pixel_put(xlm.mlx, xlm.win, x++, y, color);
		y++;
	}
}

void	ft_drow_map(t_all *xlm, int x_print, int y_print)
{
	int	x;
	int	y;
	int start_x;

	start_x = x_print;
	x = 0;
	y = 0;
	while (xlm->param.g_map[y] && xlm->param.g_map[y][x])
	{
		x_print = start_x;
		while (xlm->param.g_map[y][x])
		{
			if (xlm->param.g_map[y][x] == '1')
				ft_drow_square(*xlm, x_print, y_print, 0xAA3AAA);
			else if (ft_rhr("NSWE0", xlm->param.g_map[y][x]))
				ft_drow_square(*xlm, x_print, y_print, 0xFFFFFF);
			x_print += SQUARE;
			x++;
		}
		y_print += SQUARE;
		y++;
		x = 0;
	}
	ft_drow_square(*xlm, START_POS + (X * SQUARE) - (SQUARE / 2),\
	START_POS + (Y * SQUARE) - (SQUARE / 2), 0xFF0000);
}

//void	ft_drow(t_all *xlm)
//{
//	int		x = 0;
//	int 	y = 0;
//	int		xx = 50;
//	int		yy = 50;
//	int		xxx = 50;
//	int		yyy = 50;
//
//	while (xlm->param.g_map[y] && xlm->param.g_map[y][x])
//	{
//		yyy += 15;
//		while (xlm->param.g_map[y][x])
//		{
//			xxx += 15;
//			if (xlm->param.g_map[y][x] == '1')
//			{
//				while (yy < yyy)
//				{
//					while (xx < xxx)
//						mlx_pixel_put(xlm->mlx, xlm->win, xx++, yy, 0xAA3AAA);
//					yy++;
//					xx -= 15;
//				}
//			}
//			else if (xlm->param.g_map[y][x] == '0')
//			{
//				while (yy < yyy)
//				{
//					while (xx < xxx)
//						mlx_pixel_put(xlm->mlx, xlm->win, xx++, yy, 0xFFFFFF);
//					yy++;
//					xx -= 15;
//				}
//			}
//			else if (ft_rhr("NSWE", xlm->param.g_map[y][x]))
//			{
//				xlm->player.x = x;
//				xlm->player.y = y;
//				while (yy < yyy)
//				{
//					while (xx < xxx)
//						mlx_pixel_put(xlm->mlx, xlm->win, xx++, yy, 0xFF0000);
//					yy++;
//					xx -= 15;
//				}
//			}
//			else if (xlm->param.g_map[y][x] == ' ')
//				yy += 15;
//			yy -= 15;
//			xx += 15;
//			x++;
//		}
//		y++;
//		x = 0;
//		xx = 50;
//		xxx = 50;
//		yy += 15;
//	}
//}