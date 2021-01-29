//
// Created by Daisey Patrica on 12/21/20.
//

#include "../includes/cub3d.h"

int		key_hook(t_all *xlm)
{
	double	start_dir_x;
	double	start_plane_x;

	xlm->yyy += SPEED * xlm->player.dir_y;
//	xlm->xxx -= SPEED * xlm->player.dir_y;
//	xlm->param.g_map[(int)Y][(int)X] = '0';
//	mlx_mouse_get_pos(xlm->win, (int)(X / 2), (int)(Y / 2));
	mlx_mouse_move(xlm->win, (int)(xlm->param.width / 2), (int)(xlm->param.height / 2));
	if ((xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '1') &&\
	(xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '2')
		Y += SPEED * xlm->player.dir_y;
	if ((xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]) != '1') &&\
	(xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]) != '2')
		X += SPEED * xlm->player.dir_x;
	if (xlm->move.down == 1 &&\
	((xlm->param.g_map[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '1') &&\
	(xlm->param.g_map[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '2')
		Y -= SPEED * xlm->player.dir_y;
	if (xlm->move.down == 1 &&\
	((xlm->param.g_map[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_x))]) != '1') &&\
	(xlm->param.g_map[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_x))]) != '2')
		X -= SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 &&\
	((xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '1') &&\
	(xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '2')
		Y += SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 &&\
	((xlm->param.g_map[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_y))]) != '1') &&\
	(xlm->param.g_map[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_y))]) != '2')
		X -= SPEED * xlm->player.dir_y;
	if (xlm->move.left == 1 &&\
	((xlm->param.g_map[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '1') &&\
	(xlm->param.g_map[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '2')
		Y -= SPEED * xlm->player.dir_x;
	if (xlm->move.left == 1 &&\
	((xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_y))]) != '1') &&\
	(xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_y))]) != '2')
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
	if (xlm->move.r_m_rot == 1)
	{
		start_dir_x = xlm->player.dir_x;
		xlm->player.dir_x = xlm->player.dir_x * cos(xlm->move.l_m_rot) - xlm->player.dir_y * sin(xlm->move.l_m_rot);
		xlm->player.dir_y = start_dir_x * sin(xlm->move.l_m_rot) + xlm->player.dir_y * cos(xlm->move.l_m_rot);
		start_plane_x = xlm->player.plan_x;
		xlm->player.plan_x = xlm->player.plan_x * cos(xlm->move.l_m_rot) - xlm->player.plan_y * sin(xlm->move.l_m_rot);
		xlm->player.plan_y = start_plane_x * sin(xlm->move.l_m_rot) + xlm->player.plan_y * cos(xlm->move.l_m_rot);
		xlm->move.r_m_rot = 0;
//		printf("DIR_X:%f\nDIR_Y:%f\n", xlm->player.dir_x, xlm->player.dir_y);
	}
	if (xlm->move.l_m_rot == 1)
	{
		start_dir_x = xlm->player.dir_x;
		xlm->player.dir_x = xlm->player.dir_x * cos(-xlm->move.r_m_rot) - xlm->player.dir_y * sin(-xlm->move.r_m_rot);
		xlm->player.dir_y = start_dir_x * sin(-xlm->move.r_m_rot) + xlm->player.dir_y * cos(-xlm->move.r_m_rot);
		start_plane_x = xlm->player.plan_x;
		xlm->player.plan_x = xlm->player.plan_x * cos(-xlm->move.r_m_rot) - xlm->player.plan_y * sin(-xlm->move.r_m_rot);
		xlm->player.plan_y = start_plane_x * sin(-xlm->move.r_m_rot) + xlm->player.plan_y * cos(-xlm->move.r_m_rot);
		xlm->move.l_m_rot = 0;
//		printf("DIR_X:%f\nDIR_Y:%f\n", xlm->player.dir_x, xlm->player.dir_y);
	}
	if (xlm->move.exit == 1)
	{
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(*xlm, xlm->param.valid);
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
	mlx_destroy_image(xlm->mlx, xlm->img.img);
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
