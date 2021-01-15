//
// Created by Daisey Patrica on 12/21/20.
//

#include "../includes/cub3d.h"

int		key_hook(t_all *xlm)
{
	double	start_dir_x;
	double	start_plane_x;

//	xlm->param.g_map[(int)Y][(int)X] = '0';
	if (xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '1')
		Y += SPEED * xlm->player.dir_y;
	if (xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]) != '1')
		X += SPEED * xlm->player.dir_x;
	if (xlm->move.down == 1 &&\
	(xlm->param.g_map[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '1')
		Y -= SPEED * xlm->player.dir_y;
	if (xlm->move.down == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_x))]) != '1')
		X -= SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 &&\
	(xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '1')
		Y += SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_y))]) != '1')
		X -= SPEED * xlm->player.dir_y;
	if (xlm->move.left == 1 &&\
	(xlm->param.g_map[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '1')
		Y -= SPEED * xlm->player.dir_x;
	if (xlm->move.left == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_y))]) != '1')
		X += SPEED * xlm->player.dir_y;
	if (xlm->move.r_rot == 1)
	{
		start_dir_x = xlm->player.dir_x;
		xlm->player.dir_x = xlm->player.dir_x * cos(SPEED) - xlm->player.dir_y * sin(SPEED);
		xlm->player.dir_y = start_dir_x * sin(SPEED) + xlm->player.dir_y * cos(SPEED);
		start_plane_x = xlm->player.plan_x;
		xlm->player.plan_x = xlm->player.plan_x * cos(SPEED) - xlm->player.plan_y * sin(SPEED);
		xlm->player.plan_y = start_plane_x * sin(SPEED) + xlm->player.plan_y * cos(SPEED);
//		printf("DIR_X:%f\nDIR_Y:%f\n", xlm->player.dir_x, xlm->player.dir_y);
	}
	if (xlm->move.l_rot == 1)
	{
		start_dir_x = xlm->player.dir_x;
		xlm->player.dir_x = xlm->player.dir_x * cos(-SPEED) - xlm->player.dir_y * sin(-SPEED);
		xlm->player.dir_y = start_dir_x * sin(-SPEED) + xlm->player.dir_y * cos(-SPEED);
		start_plane_x = xlm->player.plan_x;
		xlm->player.plan_x = xlm->player.plan_x * cos(-SPEED) - xlm->player.plan_y * sin(-SPEED);
		xlm->player.plan_y = start_plane_x * sin(-SPEED) + xlm->player.plan_y * cos(-SPEED);
//		printf("DIR_X:%f\nDIR_Y:%f\n", xlm->player.dir_x, xlm->player.dir_y);
	}
	if (xlm->move.exit == 1)
	{
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm->param, xlm->param.valid);
		exit(0);
	}
//	xlm->param.g_map[(int)Y][(int)X] = (char)xlm->param.resp_player.dir;
	xlm->img.img = mlx_new_image(xlm->mlx, xlm->param.width, xlm->param.height);
	xlm->img.adr = mlx_get_data_addr(xlm->img.img, &xlm->img.bpp, &xlm->img.line_len, &xlm->img.iend);
//	xlm->image = mlx_new_image(xlm->mlx, xlm->param.width, xlm->param.height);
	ft_draw_beam(xlm);
	ft_draw_map(xlm, START_X, START_Y);
//	mlx_clear_window(xlm->mlx, xlm->win);
	mlx_put_image_to_window(xlm->mlx, xlm->win, xlm->img.img, 0, 0);
//	mlx_destroy_image(xlm->mlx, xlm->img.img);
	return (0);
}

int		key_press(int key, t_all *xlm)
{
//	printf("%d\n", key);
	if (key == 13 || key == 126)
		xlm->move.up = 1;
	if (key == 1 || key == 125)
		xlm->move.down = 1;
	if (key == 2)
		xlm->move.right = 1;
	if (key == 0)
		xlm->move.left = 1;
	if (key == 124)
		xlm->move.r_rot = 1;
	if (key == 123)
		xlm->move.l_rot = 1;
	if (key == 53)
		xlm->move.exit = 1;
	return (0);
}

int		key_release(int key, t_all *xlm)
{
	if (key == 13 || key == 126)
		xlm->move.up = 0;
	if (key == 1 || key == 125)
		xlm->move.down = 0;
	if (key == 2)
		xlm->move.right = 0;
	if (key == 0)
		xlm->move.left = 0;
	if (key == 124)
		xlm->move.r_rot = 0;
	if (key == 123)
		xlm->move.l_rot = 0;
	if (key == 53)
		xlm->move.exit = 0;
	return (0);
}

/*
if (xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)(Y + (SPEED * xlm->player.dir_y))][(int)(X + (SPEED * xlm->player.dir_x))]) != '1')
{
Y += SPEED * xlm->player.dir_y;
X += SPEED * xlm->player.dir_x;
}
if (xlm->move.down == 1 &&\
	(xlm->param.g_map[(int)(Y - (SPEED * xlm->player.dir_y))][(int)(X - (SPEED * xlm->player.dir_x))]) != '1')
{
Y -= SPEED * xlm->player.dir_y;
X -= SPEED * xlm->player.dir_x;
}
if (xlm->move.right == 1 &&\
	(xlm->param.g_map[(int)(Y + (SPEED * xlm->player.dir_x))][(int)(X - (SPEED * xlm->player.dir_y))]) != '1')
{
X -= SPEED * xlm->player.dir_y;
Y += SPEED * xlm->player.dir_x;
}
if (xlm->move.left == 1 &&\
	(xlm->param.g_map[(int)(Y - (SPEED * xlm->player.dir_x))][(int)(X + (SPEED * xlm->player.dir_y))]) != '1')
{
X += SPEED * xlm->player.dir_y;
Y -= SPEED * xlm->player.dir_x;
}*/
