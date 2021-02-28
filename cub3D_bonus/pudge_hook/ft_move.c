/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:24:55 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:24:55 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	turn_player_2(t_all *xlm, double start_dir_x, double start_plane_x)
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

static void	turn_player(t_all *xlm, double start_dir_x, double start_plane_x)
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

static void	move_player_2(t_all *xlm)
{
	if (xlm->move.right == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]))
		Y += SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_y))]))
		X -= SPEED * xlm->player.dir_y;
	if (xlm->move.left == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_x))][(int)X]))
		Y -= SPEED * xlm->player.dir_x;
	if (xlm->move.left == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_y))]))
		X += SPEED * xlm->player.dir_y;
}

static void	move_player(t_all *xlm)
{
	if (xlm->move.open == 1 && ft_rhr("3", xlm->param.g_map[(int)(Y +\
	((SPEED + 0.1) * xlm->player.dir_y))][(int)X]))
		xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_y))]\
		[(int)X] = '0';
	if (xlm->move.open == 1 && ft_rhr("3", xlm->param.g_map[(int)Y]\
	[(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]))
		xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) *\
		xlm->player.dir_x))] = '0';
	if (xlm->move.up == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]))
		Y += SPEED * xlm->player.dir_y;
	if (xlm->move.up == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]))
		X += SPEED * xlm->player.dir_x;
	if (xlm->move.down == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)(Y - ((SPEED + 0.1) * xlm->player.dir_y))][(int)X]))
		Y -= SPEED * xlm->player.dir_y;
	if (xlm->move.down == 1 && !ft_rhr("123457YVvGgi9Q", xlm->param.g_map\
	[(int)Y][(int)(X - ((SPEED + 0.1) * xlm->player.dir_x))]))
		X -= SPEED * xlm->player.dir_x;
}

void		ft_move(t_all *xlm)
{
	move_player(xlm);
	move_player_2(xlm);
	turn_player(xlm, xlm->player.dir_x, xlm->player.plan_x);
	turn_player_2(xlm, xlm->player.dir_x, xlm->player.plan_x);
	ft_action(xlm);
	if (xlm->move.exit == 1 || xlm->player.hp <= 0)
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		if (xlm->param.lvl == 1)
			system("killall afplay");
		if (xlm->player.hp <= 0)
			write(1, "Your died.\n", 11);
		ft_error(xlm, xlm->param.valid);
		exit(0);
	}
}
