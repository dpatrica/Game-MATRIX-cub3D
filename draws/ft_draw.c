//
// Created by Daisey Patrica on 16/12/2020.
//

#include "../includes/cub3d.h"

void	ft_draw_aim(t_all *xlm)
{
	int x;
	int y;
	int i;

	i = 10;
	x = (xlm->param.width / 2) - 5;
	y = (xlm->param.height / 2);
	while (i--)
		my_pixel_put(xlm, x++, y, 0xFF0000);
	i = 10;
	x = (xlm->param.width / 2);
	y -= 5;
	while (i--)
		my_pixel_put(xlm, x, y++, 0xFF0000);
}

void 	ft_draw_square(t_all *xlm, double x, double y, int color)
{
	double 	start_x;
	double 	start_y;

	start_x = x;
	start_y = y;
	while (y < (SQUARE_Y + start_y))
	{
		x = start_x;
		while (x < (SQUARE_X + start_x))
			my_pixel_put(xlm, x++, y, color);
//			mlx_pixel_put(xlm->image, xlm->win, x++, y, color);
		y++;
	}
}

void	ft_draw_map(t_all *xlm, double x_print, double y_print)
{
	int	x;
	int	y;
	double start_x;

	start_x = x_print;
	x = 0;
	y = 0;
	while (xlm->param.g_map[y] && xlm->param.g_map[y][x])
	{
		x_print = start_x;
		while (xlm->param.g_map[y][x])
		{
			if (xlm->param.g_map[y][x] == '1')
				ft_draw_square(xlm, x_print, y_print, 0xAA3AAA);
			else if (ft_rhr("0NSWE", xlm->param.g_map[y][x]))
				ft_draw_square(xlm, x_print, y_print, 0xFFFFFF);
			else if (xlm->param.g_map[y][x] == '2')
				ft_draw_square(xlm, x_print, y_print, 0x9400D3);
			x_print += SQUARE_X;
			x++;
		}
		y_print += SQUARE_Y;
		y++;
		x = 0;
	}
	ft_draw_square(xlm, START_X + (X * SQUARE_X) - (SQUARE_X / 2),\
	START_Y + (Y * SQUARE_Y) - (SQUARE_Y / 2), 0xFF0000);
}

void 	ft_draw_line(int x, int draw_s, int draw_e, int color, t_all *xlm)
{
	(void)color;
	int i;
	int old_draw_s;
//	if (draw_e < 0)
//		draw_e *= -1;
	old_draw_s = draw_s;
	i = -1;
	if (draw_s <= draw_e)
//	{
//		my_pixel_put(xlm, x, draw_s, color);
//		mlx_pixel_put(xlm->image, xlm->win, x, draw_s, color);
//		draw_s++;
		i = 0;
//	}
	if (!i)
	{
		while (i < old_draw_s)
			my_pixel_put(xlm, x, i++, xlm->param.c.rgb);
		while (++draw_e < (xlm->param.height - 1))
			my_pixel_put(xlm, x, draw_e, xlm->param.f.rgb);
	}
}

//		ft_draw_line(i, xlm->neo.draw_up, xlm->neo.draw_down, 0x800000, xlm); FIXME НЕ ЗАБУДЬ !

/*void	ft_draw_beam(t_all *xlm)
{
	double	xx;
	double	yy;
	int		i = -1;
	int		j;
	int 	x;
	int 	y;
	int		hit;
	int		side;
	int		step_x;
	int		step_y;
	int		line_len;
	int		draw_s;
	int		draw_e;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	raydir_x;
	double	raydir_y;
	double	camera_x;
	double	wall_dist;

	while (++i < (xlm->param.width - 1))
	{
		hit = 0;
//		printf("%d\n", i);
		camera_x = 2 * i / (double)xlm->param.width - 1;
//		printf("camera_x:%12f\n", camera_x);
//		sleep(1);
		raydir_x = xlm->player.dir_x + xlm->player.plan_x * camera_x;
		raydir_y = xlm->player.dir_y + xlm->player.plan_y * camera_x;
//		printf("rdyr_x:%12f\nrdyr_y:%12f\n", raydir_x, raydir_y);
		x = (int)X;
		y = (int)Y;
//		printf("OLDx:%d\nOLDy:%d\n", x, y);
		delta_x = fabs(1 / raydir_x);
		delta_y = fabs(1 / raydir_y);
//		printf("delta_x:%12f\ndelta_y:%12f\n", delta_x, delta_y);
		if (raydir_x < 0)
		{
			step_x = -1;
			side_x = (X - x) * delta_x;
		}
		else
		{
			step_x = 1;
			side_x = (x + 1.0 - X) * delta_x;
		}
		if (raydir_y < 0)
		{
			step_y = -1;
			side_y = (Y - y) * delta_y;
		}
		else
		{
			step_y = 1;
			side_y = (y + 1.0 - Y) * delta_y;
		}
//		printf("side_x:%12f\nside_y:%12f\nstep_x:%12d\nstep_y:%12d\n", side_x, side_y, step_x, step_y);
		while (hit == 0)
		{
			if (side_x < side_y)
			{
				side_x += delta_x;
				x += step_x;
				side = 0;
			}
			else
			{
				side_y += delta_y;
				y += step_y;
				side = 1;
			}
			if (xlm->param.g_map[y][x] == '1')
			{
//				xlm->param.g_map[y][x] = '2';
				hit = 1;
			}
		}
//		printf("x:%d\ny:%d\nNEWside_x:%12f\nNEWside_y:%12f\n", x, y, side_x, side_y);
//		printf("side:%d\n", side);
		if (side == 0)
			wall_dist = (x - X + (1 - step_x) / 2) / raydir_x;
		else
			wall_dist = (y - Y + (1 - step_y) / 2) / raydir_y;
//		printf("i:%d\n", i);
		xx = (START_X + (X * SQUARE));
		yy = (START_Y + (Y * SQUARE));
		j = 0;
//		if (wall_dist < 0)
//			wall_dist *= -1;
//		printf("wall_d:%12f\n", wall_dist);
//		sleep(1);
		while (j < (int)(wall_dist * SQUARE))
		{
			mlx_pixel_put(xlm->mlx, xlm->win, xx, yy, 0xDAF87D);
			xx += 1 * xlm->player.dir_x + xlm->player.plan_x * camera_x;
			yy += 1 * xlm->player.dir_y + xlm->player.plan_y * camera_x;
			j++;
		}
		line_len = (int)(xlm->param.height / wall_dist);
		draw_s = -line_len / 2 + xlm->param.height / 2;
		if (draw_s < 0)
			draw_s = 0;
		draw_e = line_len / 2 + xlm->param.height / 2;
		if (draw_e >= xlm->param.height)
			draw_e = xlm->param.height - 1;
//		printf("S:%d\nE:%d\nI:%d\n", draw_s, draw_e, i);
		ft_draw_line(i, draw_s, draw_e, 0xFF0000, xlm);
	}
*//*	xx = (START_X + (X * SQUARE));
	yy = (START_Y + (Y * SQUARE));
//	printf("wall_d:%f\n", wall_dist);
	i = 0;
	while (i < (int)(wall_dist * SQUARE))
	{
//		int m = 0;
//		printf("I:%d\n", i);
		//while (m++ < 20)
		mlx_pixel_put(xlm->mlx, xlm->win, xx, yy, 0x0000FF);
		xx += 1 * xlm->player.dir_x;
		yy += 1 * xlm->player.dir_y;
		i++;
	}*//*
//	side_x = X;
//	side_y = Y;
//	while (xlm->param.g_map[(int)yy][(int)xx] != '1')
//	{
//		mlx_pixel_put(xlm->mlx, xlm->win, x, y, 0x0000FF);
//		y -= ;
//		yy -= 0.05;
//	}
//	else if (xlm->player.dir == 'S')
//	{
//		while (xlm->param.g_map[(int)yy][(int)xx] != '1')
//		{
//			mlx_pixel_put(xlm->mlx, xlm->win, x, y, 0x0000FF);
//			y++;
//			yy += 0.05;
//		}
//	}
//	else if (xlm->player.dir == 'W')
//	{
//		while (xlm->param.g_map[(int)yy][(int)xx] != '1')
//		{
//			mlx_pixel_put(xlm->mlx, xlm->win, x, y, 0x0000FF);
//			x--;
//			xx -= 0.05;
//		}
//	}
//	else if (xlm->player.dir == 'E')
//	{
//		while (xlm->param.g_map[(int)yy][(int)xx] != '1')
//		{
//			mlx_pixel_put(xlm->mlx, xlm->win, x, y, 0x0000FF);
//			x++;
//			xx += 0.05;
//		}
//	}
}*/

//void	ft_draw(t_all *xlm)
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
//	i = xlm->param.height / xlm->move.mouse_cam - 1;
//i = 0;
//while (i < (xlm->param.height / xlm->move.mouse_cam - 1))
//{
//xlm->neo.rdir_x = xlm->player.dir_x - xlm->player.plan_x;
//xlm->neo.rdir_y = xlm->player.dir_y - xlm->player.plan_y;
//xlm->neo.rdir2_x = xlm->player.dir_x + xlm->player.plan_x;
//xlm->neo.rdir2_y = xlm->player.dir_y + xlm->player.plan_y;
//hit = i - xlm->param.height;
//xlm->neo.z_pos = xlm->param.height / xlm->move.mouse_cam;
//xlm->neo.dist_row = xlm->neo.z_pos / xlm->move.mouse_cam;
//xlm->neo.f_step_x = xlm->neo.dist_row * (xlm->neo.rdir2_x - xlm->neo.rdir_x) / xlm->param.width;
//xlm->neo.f_step_y = xlm->neo.dist_row * (xlm->neo.rdir2_y - xlm->neo.rdir_y) / xlm->param.width;
//xlm->neo.floor_x = Y + xlm->neo.dist_row * xlm->neo.rdir_x;
//xlm->neo.floor_y = X + xlm->neo.dist_row * xlm->neo.rdir_y;
//j = 0;
//while (j < (xlm->param.width - 1))
//{
//xlm->neo.celling_x = (int)xlm->neo.floor_x;
//xlm->neo.celling_y = (int)xlm->neo.floor_y;
//n = (int)(xlm->tex.skybox.width * (xlm->neo.floor_x - xlm->neo.celling_x)) & (xlm->tex.skybox.width - 1);
//d = (int)(xlm->tex.skybox.height * (xlm->neo.floor_y - xlm->neo.celling_y)) & (xlm->tex.skybox.height - 1);
//xlm->neo.floor_x += xlm->neo.f_step_x;
//xlm->neo.floor_y += xlm->neo.f_step_y;
//clr = (unsigned int*)(xlm->tex.skybox.adr + xlm->tex.skybox.line_len * d + n * (xlm->tex.skybox.bpp / 8));
//my_pixel_put(xlm, j, i, (int)*clr);
//j++;
//}
//i++;
//}
//	i = xlm->param.height / xlm->move.mouse_cam - 1;
//i = 0;
//while (i < (xlm->param.height / xlm->move.mouse_cam - 1))
//{
//xlm->neo.rdir_x = xlm->player.dir_x - xlm->player.plan_x;
//xlm->neo.rdir_y = xlm->player.dir_y - xlm->player.plan_y;
//xlm->neo.rdir2_x = xlm->player.dir_x + xlm->player.plan_x;
//xlm->neo.rdir2_y = xlm->player.dir_y + xlm->player.plan_y;
//hit = i - xlm->param.height / 50;
//xlm->neo.z_pos = xlm->param.height / xlm->move.mouse_cam;
//xlm->neo.dist_row = xlm->neo.z_pos / hit;
//xlm->neo.f_step_x = xlm->neo.dist_row * (xlm->neo.rdir2_x - xlm->neo.rdir_x) / xlm->param.width;
//xlm->neo.f_step_y = xlm->neo.dist_row * (xlm->neo.rdir2_y - xlm->neo.rdir_y) / xlm->param.width;
//xlm->neo.floor_x = Y + xlm->neo.dist_row * xlm->neo.rdir_x;
//xlm->neo.floor_y = X + xlm->neo.dist_row * xlm->neo.rdir_y;
//j = 0;
//while (j < (xlm->param.width - 1))
//{
//xlm->neo.celling_x = (int)xlm->neo.floor_x;
//xlm->neo.celling_y = (int)xlm->neo.floor_y;
//n = (int)(xlm->tex.skybox.width * (xlm->neo.floor_x - xlm->neo.celling_x)) & (xlm->tex.skybox.width - 1);
//d = (int)(xlm->tex.skybox.height * (xlm->neo.floor_y - xlm->neo.celling_y)) & (xlm->tex.skybox.height - 1);
//xlm->neo.floor_x += xlm->neo.f_step_x;
//xlm->neo.floor_y += xlm->neo.f_step_y;
//clr = (unsigned int*)(xlm->tex.skybox.adr + xlm->tex.skybox.line_len * d + n * (xlm->tex.skybox.bpp / 8));
//my_pixel_put(xlm, j, i, (int)*clr);
//j++;
//}
//i++;
//}

//		xlm->neo.l_x = (START_X + (X * SQUARE));
//		xlm->neo.l_y = (START_Y + (Y * SQUARE));
//		j = 0;
//		while (j < (int)(xlm->neo.dist * SQUARE)) FIXME ОТРИСОВКА ЛУЧЕЙ ! ! !
//		{
//			my_pixel_put(xlm, xlm->neo.l_x, xlm->neo.l_y, 0xDAF87D);
//			mlx_pixel_put(xlm->image, xlm->win, xlm->neo.l_x, xlm->neo.l_y, 0xDAF87D);
//			xlm->neo.l_x += 1 * xlm->player.dir_x + xlm->player.plan_x * xlm->neo.cam;
//			xlm->neo.l_y += 1 * xlm->player.dir_y + xlm->player.plan_y * xlm->neo.cam;
//			j++;
//		}