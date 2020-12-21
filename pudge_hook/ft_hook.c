//
// Created by Daisey Patrica on 12/21/20.
//

#include "../includes/cub3d.h"

int		key_hook(t_all *xlm)
{
	xlm->param.g_map[(int)Y][(int)X] = '0';
	if (xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)(Y - (SPEED * xlm->player.dir_y))][(int)(X + (SPEED * xlm->player.dir_x))]) != '1')
	{
		Y -= SPEED * xlm->player.dir_y;
		X += SPEED * xlm->player.dir_x;
	}
	if (xlm->move.down == 1 &&\
	(xlm->param.g_map[(int)(Y + (SPEED * xlm->player.dir_y))][(int)(X - (SPEED * xlm->player.dir_x))]) != '1')
	{
		Y += SPEED * xlm->player.dir_y;
		X -= SPEED * xlm->player.dir_x;
	}
	if (xlm->move.right == 1 &&\
	(xlm->param.g_map[(int)(Y + (SPEED * xlm->player.dir_x))][(int)(X + (SPEED * xlm->player.dir_y))]) != '1')
	{
		X += SPEED * xlm->player.dir_y;
		Y += SPEED * xlm->player.dir_x;
	}
	if (xlm->move.left == 1 &&\
	(xlm->param.g_map[(int)(Y - (SPEED * xlm->player.dir_x))][(int)(X - (SPEED * xlm->player.dir_y))]) != '1')
	{
		X -= SPEED * xlm->player.dir_y;
		Y -= SPEED * xlm->player.dir_x;
	}
	xlm->param.g_map[(int)Y][(int)X] = 'N';
	mlx_clear_window(xlm->mlx, xlm->win);
	ft_draw_map(xlm, START_X, START_Y);
	ft_draw_beam(xlm);
	return (0);
}

int		key_press(int key, t_all *xlm)
{
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
	return (0);
}
