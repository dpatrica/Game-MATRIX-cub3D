//
// Created by Daisey Patrica on 1/29/21.
//

#include "../includes/cub3d.h"

static void turn_player_2(t_all *xlm, double start_dir_x, double start_plane_x)
{
	if (xlm->move.r_m_rot == 1)
	{
		xlm->player.dir_x = xlm->player.dir_x * cos(xlm->move.l_m_rot) -\
		xlm->player.dir_y * sin(xlm->move.l_m_rot);
		xlm->player.dir_y = start_dir_x * sin(xlm->move.l_m_rot) +\
		xlm->player.dir_y * cos(xlm->move.l_m_rot);
		xlm->player.plan_x = xlm->player.plan_x * cos(xlm->move.l_m_rot) -\
		xlm->player.plan_y * sin(xlm->move.l_m_rot);
		xlm->player.plan_y = start_plane_x * sin(xlm->move.l_m_rot) +\
		xlm->player.plan_y * cos(xlm->move.l_m_rot);
		xlm->move.r_m_rot = 0;
	}
	if (xlm->move.l_m_rot == 1)
	{
		xlm->player.dir_x = xlm->player.dir_x * cos(-xlm->move.r_m_rot) -\
		xlm->player.dir_y * sin(-xlm->move.r_m_rot);
		xlm->player.dir_y = start_dir_x * sin(-xlm->move.r_m_rot) +\
		xlm->player.dir_y * cos(-xlm->move.r_m_rot);
		xlm->player.plan_x = xlm->player.plan_x * cos(-xlm->move.r_m_rot) -\
		xlm->player.plan_y * sin(-xlm->move.r_m_rot);
		xlm->player.plan_y = start_plane_x * sin(-xlm->move.r_m_rot) +\
		xlm->player.plan_y * cos(-xlm->move.r_m_rot);
		xlm->move.l_m_rot = 0;
	}
}

static void turn_player(t_all *xlm, double start_dir_x, double start_plane_x)
{
	if (xlm->move.r_rot == 1)
	{
		xlm->player.dir_x =\
		xlm->player.dir_x * cos(SPEED) - xlm->player.dir_y * sin(SPEED);
		xlm->player.dir_y =\
		start_dir_x * sin(SPEED) + xlm->player.dir_y * cos(SPEED);
		xlm->player.plan_x =\
		xlm->player.plan_x * cos(SPEED) - xlm->player.plan_y * sin(SPEED);
		xlm->player.plan_y =\
		start_plane_x * sin(SPEED) + xlm->player.plan_y * cos(SPEED);
	}
	if (xlm->move.l_rot == 1)
	{
		xlm->player.dir_x =\
		xlm->player.dir_x * cos(-SPEED) - xlm->player.dir_y * sin(-SPEED);
		xlm->player.dir_y =\
		start_dir_x * sin(-SPEED) + xlm->player.dir_y * cos(-SPEED);
		xlm->player.plan_x =\
		xlm->player.plan_x * cos(-SPEED) - xlm->player.plan_y * sin(-SPEED);
		xlm->player.plan_y =\
		start_plane_x * sin(-SPEED) + xlm->player.plan_y * cos(-SPEED);
	}
}

static void move_player_2(t_all *xlm)
{
	if (xlm->move.left == 1 && ((xlm->param.g_map[(int)(Y - ((SPEED + 0.1) *\
	xlm->player.dir_x))][(int)X]) != '1') && (xlm->param.g_map[(int)(Y -\
	((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '2')
		Y -= SPEED * xlm->player.dir_x;
	if (xlm->move.left == 1 && ((xlm->param.g_map[(int)Y][(int)(X +\
	((SPEED + 0.1) * xlm->player.dir_y))]) != '1') && (xlm->param.g_map[(int)Y]\
	[(int)(X + ((SPEED + 0.1) * xlm->player.dir_y))]) != '2')
		X += SPEED * xlm->player.dir_y;
}

static void move_player(t_all *xlm)
{
	if ((xlm->move.up == 1 && (xlm->param.g_map[(int)(Y + ((SPEED + 0.1) *\
	xlm->player.dir_y))][(int)X]) != '1') && (xlm->param.g_map[(int)(Y +\
	((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '2')
		Y += SPEED * xlm->player.dir_y;
	if ((xlm->move.up == 1 && (xlm->param.g_map[(int)Y][(int)(X +\
	((SPEED + 0.1) * xlm->player.dir_x))]) != '1') && (xlm->param.g_map[(int)Y]\
	[(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]) != '2')
		X += SPEED * xlm->player.dir_x;
	if (xlm->move.down == 1 && ((xlm->param.g_map[(int)(Y - ((SPEED + 0.1) *\
	xlm->player.dir_y))][(int)X]) != '1') && (xlm->param.g_map[(int)(Y -\
	((SPEED + 0.1) * xlm->player.dir_y))][(int)X]) != '2')
		Y -= SPEED * xlm->player.dir_y;
	if (xlm->move.down == 1 && ((xlm->param.g_map[(int)Y][(int)(X -\
	((SPEED + 0.1) * xlm->player.dir_x))]) != '1') && (xlm->param.g_map[(int)Y]\
	[(int)(X - ((SPEED + 0.1) * xlm->player.dir_x))]) != '2')
		X -= SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 && ((xlm->param.g_map[(int)(Y + ((SPEED + 0.1) *\
	xlm->player.dir_x))][(int)X]) != '1') && (xlm->param.g_map[(int)(Y +\
	((SPEED + 0.1) * xlm->player.dir_x))][(int)X]) != '2')
		Y += SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 && ((xlm->param.g_map[(int)Y][(int)(X -\
	((SPEED + 0.1) * xlm->player.dir_y))]) != '1') && (xlm->param.g_map[(int)Y]\
	[(int)(X - ((SPEED + 0.1) * xlm->player.dir_y))]) != '2')
		X -= SPEED * xlm->player.dir_y;
}

void	ft_move(t_all *xlm)
{
	move_player(xlm);
	move_player_2(xlm);
	turn_player(xlm, xlm->player.dir_x, xlm->player.plan_x);
	turn_player_2(xlm, xlm->player.dir_x, xlm->player.plan_x);
	if (xlm->move.exit == 1)
	{
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(*xlm, xlm->param.valid);
		exit(0);
	}
}