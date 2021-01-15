//
// Created by Daisey Patrica on 16/12/2020.
//

#include "../includes/cub3d.h"

void	my_pixel_put(t_all *xlm, int x, int y, int color)
{
	char *dst;

	dst = xlm->img.adr + (y * xlm->img.line_len + x * (xlm->img.bpp / 8));
	*(unsigned int*)dst = color;
}

/*static void	ma_pixel_put(t_all *xlm, int x, int y, int color)
{
	char *dst;

	dst = xlm->tex.no.adr + (y * xlm->img.line_len + x * (xlm->tex.no.bpp / 8));
	*(unsigned int*)dst = color;
}*/

void 	ft_draw_square(t_all *xlm, int x, int y, int color)
{
	int	start_x;
	int	start_y;

	start_x = x;
	start_y = y;
	while (y < (SQUARE + start_y))
	{
		x = start_x;
		while (x < (SQUARE + start_x))
			my_pixel_put(xlm, x++, y, color);
//			mlx_pixel_put(xlm->image, xlm->win, x++, y, color);
		y++;
	}
}

void	ft_draw_map(t_all *xlm, int x_print, int y_print)
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
				ft_draw_square(xlm, x_print, y_print, 0xAA3AAA);
			else if (ft_rhr("0NSWE", xlm->param.g_map[y][x]))
				ft_draw_square(xlm, x_print, y_print, 0xFFFFFF);
			else if (xlm->param.g_map[y][x] == '2')
				ft_draw_square(xlm, x_print, y_print, 0x9400D3);
			x_print += SQUARE;
			x++;
		}
		y_print += SQUARE;
		y++;
		x = 0;
	}
	ft_draw_square(xlm, START_X + (X * SQUARE) - (SQUARE / 2),\
	START_Y + (Y * SQUARE) - (SQUARE / 2), 0xFF0000);
}

void 	ft_draw_line(int x, int draw_s, int draw_e, int color, t_all *xlm)
{
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

void	ft_draw_beam(t_all *xlm)
{
	int		i = -1;
	int		j;
	int		hit;

	while (++i < (xlm->param.width - 1))
	{
		hit = 0;
		xlm->neo.cam = 2 * i / (double)xlm->param.width - 1;
		xlm->neo.rdir_x = xlm->player.dir_x + xlm->player.plan_x * xlm->neo.cam;
		xlm->neo.rdir_y = xlm->player.dir_y + xlm->player.plan_y * xlm->neo.cam;
		xlm->neo.x = (int)X;
		xlm->neo.y = (int)Y;
		xlm->neo.del_x = fabs(1 / xlm->neo.rdir_x);
		xlm->neo.del_y = fabs(1 / xlm->neo.rdir_y);
		if (xlm->neo.rdir_x < 0)
		{
			xlm->neo.step_x = -1;
			xlm->neo.side_x = (X - xlm->neo.x) * xlm->neo.del_x;
		}
		else
		{
			xlm->neo.step_x = 1;
			xlm->neo.side_x = (xlm->neo.x + 1.0 - X) * xlm->neo.del_x;
		}
		if (xlm->neo.rdir_y < 0)
		{
			xlm->neo.step_y = -1;
			xlm->neo.side_y = (Y - xlm->neo.y) * xlm->neo.del_y;
		}
		else
		{
			xlm->neo.step_y = 1;
			xlm->neo.side_y = (xlm->neo.y + 1.0 - Y) * xlm->neo.del_y;
		}
		while (hit == 0)
		{
			if (xlm->neo.side_x < xlm->neo.side_y)
			{
				xlm->neo.side_x += xlm->neo.del_x;
				xlm->neo.x += xlm->neo.step_x;
				xlm->neo.side = 0;
			}
			else
			{
				xlm->neo.side_y += xlm->neo.del_y;
				xlm->neo.y += xlm->neo.step_y;
				xlm->neo.side = 1;
			}
			if (xlm->param.g_map[xlm->neo.y][xlm->neo.x] == '1')
				hit = 1;
		}
		if (xlm->neo.side == 0)
			xlm->neo.dist = (xlm->neo.x - X + (1 - xlm->neo.step_x) / 2) / xlm->neo.rdir_x;
		else
			xlm->neo.dist = (xlm->neo.y - Y + (1 - xlm->neo.step_y) / 2) / xlm->neo.rdir_y;
		xlm->neo.l_x = (START_X + (X * SQUARE));
		xlm->neo.l_y = (START_Y + (Y * SQUARE));
		j = 0;
//		while (j < (int)(xlm->neo.dist * SQUARE)) FIXME ОТРИСОВКА ЛУЧЕЙ ! ! !
//		{
//			my_pixel_put(xlm, xlm->neo.l_x, xlm->neo.l_y, 0xDAF87D);
//			mlx_pixel_put(xlm->image, xlm->win, xlm->neo.l_x, xlm->neo.l_y, 0xDAF87D);
//			xlm->neo.l_x += 1 * xlm->player.dir_x + xlm->player.plan_x * xlm->neo.cam;
//			xlm->neo.l_y += 1 * xlm->player.dir_y + xlm->player.plan_y * xlm->neo.cam;
//			j++;
//		}
		xlm->neo.line_len = (int)(xlm->param.height / fabs(xlm->neo.dist));
		xlm->neo.draw_up = -xlm->neo.line_len / 2 + xlm->param.height / 2;
		if (xlm->neo.draw_up < 0)
			xlm->neo.draw_up = 0;
		xlm->neo.draw_down = xlm->neo.line_len / 2 + xlm->param.height / 2;
		if (xlm->neo.draw_down >= xlm->param.height)
			xlm->neo.draw_down = xlm->param.height - 1;
		if (xlm->neo.side == 0)
			xlm->neo.wall_x = Y + xlm->neo.dist * xlm->neo.rdir_y;
		else
			xlm->neo.wall_x = X + xlm->neo.dist * xlm->neo.rdir_x;
		xlm->neo.wall_x -= floor(xlm->neo.wall_x);
		if (xlm->neo.side == 0 && xlm->neo.step_x == 1)
		{
			xlm->neo.tex_wid = xlm->tex.ea.width;
			xlm->neo.tex_hei = xlm->tex.ea.height;
			xlm->neo.adr = xlm->tex.ea.adr;
			xlm->neo.bpp = xlm->tex.ea.bpp;
			xlm->neo.tex_line = xlm->tex.ea.line_len;
		}
		else if (xlm->neo.side == 0 && xlm->neo.step_x == -1)
		{
			xlm->neo.tex_wid = xlm->tex.we.width;
			xlm->neo.tex_hei = xlm->tex.we.height;
			xlm->neo.adr = xlm->tex.we.adr;
			xlm->neo.bpp = xlm->tex.we.bpp;
			xlm->neo.tex_line = xlm->tex.we.line_len;
		}
		else if (xlm->neo.side == 1 && xlm->neo.step_y == -1)
		{
			xlm->neo.tex_wid = xlm->tex.no.width;
			xlm->neo.tex_hei = xlm->tex.no.height;
			xlm->neo.adr = xlm->tex.no.adr;
			xlm->neo.bpp = xlm->tex.no.bpp;
			xlm->neo.tex_line = xlm->tex.no.line_len;
		}
		else if (xlm->neo.side == 1 && xlm->neo.step_y == 1)
		{
			xlm->neo.tex_wid = xlm->tex.so.width;
			xlm->neo.tex_hei = xlm->tex.so.height;
			xlm->neo.adr = xlm->tex.so.adr;
			xlm->neo.bpp = xlm->tex.so.bpp;
			xlm->neo.tex_line = xlm->tex.so.line_len;
		}
		xlm->neo.tex_x = (int)(xlm->neo.wall_x * (double)(xlm->neo.tex_wid));
		if ((xlm->neo.side == 0 && xlm->neo.rdir_x > 0) ||\
		(xlm->neo.side == 1 && xlm->neo.rdir_y < 0))
			xlm->neo.tex_x = xlm->neo.tex_wid - xlm->neo.tex_x - 1;
		if (xlm->neo.tex_x >= xlm->neo.tex_wid)
			xlm->neo.tex_x = xlm->neo.tex_wid - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		xlm->neo.step = 1.0 * xlm->neo.tex_hei / xlm->neo.line_len;
		xlm->neo.tex_pos = (xlm->neo.draw_up - xlm->param.height / 2 + xlm->neo.line_len / 2) * xlm->neo.step;
		j = xlm->neo.draw_up;
		while (j < xlm->neo.draw_down)
		{
			xlm->neo.tex_y = (int)xlm->neo.tex_pos;// & (xlm->neo.tex_hei - 1);
			if (xlm->neo.tex_y >= xlm->neo.tex_hei)
				xlm->neo.tex_y = xlm->neo.tex_hei - 1;
			else if (xlm->neo.tex_y < 0)
				xlm->neo.tex_y = 0;
			xlm->neo.tex_pos += xlm->neo.step;
			unsigned int *clr = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line * xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
//			printf("par:%p\n", xlm->tex.no.adr);
			my_pixel_put(xlm, i, j, (int)*clr);
			j++;
		}
		ft_draw_line(i, xlm->neo.draw_up, xlm->neo.draw_down, 0x800000, xlm);
//		printf("side_x:%f\nside_y:%f\n", xlm->neo.side_x, xlm->neo.side_y); //wall:%ftex_pos:%f xlm->neo.wall_x, xlm->neo.tex_pos,
//		printf("side:%d\n", xlm->neo.side);
//		printf("stepX:%d\nstepY:%d\n", xlm->neo.step_x, xlm->neo.step_y);
//		printf("cam:%f\n", xlm->neo.cam);
//		printf("wall_x:%f\n", xlm->neo.wall_x);
	}
}

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