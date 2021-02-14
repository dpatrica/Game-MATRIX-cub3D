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
	if (xlm->move.left == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)(Y -\
	((SPEED + 0.1) * xlm->player.dir_x))][(int)X]))
		Y -= SPEED * xlm->player.dir_x;
	if (xlm->move.left == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)Y]\
	[(int)(X + ((SPEED + 0.1) * xlm->player.dir_y))]))
		X += SPEED * xlm->player.dir_y;
	if (xlm->param.g_map[(int)Y][(int)X] == 'P')
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, VALID);
		char *map;
		map = "../maps/map3.cub";
		cub3d(2, &map, 2);
		exit(0);
/*		X = 15.5;
		Y = 3.5;
		xlm->player.dir_x = cos(2 * M_PI);
		xlm->player.dir_y = sin(0);
		xlm->player.plan_x = 0;
		xlm->player.plan_y = 0.66;*/
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'X')
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, VALID);
		char *map;
		map = "../maps/map2.cub";
		cub3d(2, &map, 1);
		exit(0);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'M')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.map = 1;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_init(xlm);
		xlm->action.kill = -1;
//		xlm->sprite.pos[xlm->sprite.spr[xlm->sprite.spr_len - 1]].hp = 0;
//		sprite_check(xlm);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'H' && xlm->player.hp < 100)
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.hp += 10;
		if (xlm->player.hp > 100)
			xlm->player.hp = 100;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_init(xlm);
		xlm->action.kill = -1;
//		xlm->sprite.pos[xlm->sprite.spr[xlm->sprite.spr_len - 1]].hp = 0;
//		sprite_check(xlm);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'C')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.cartridges += 10;
		xlm->player.hp -= 7;
		xlm->player.ammo -= 7;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_init(xlm);
		xlm->action.kill = -1;
//		xlm->sprite.pos[xlm->sprite.spr[xlm->sprite.spr_len - 1]].hp = 0;
//		sprite_check(xlm);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'D')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.digl = 1;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_init(xlm);
		xlm->action.kill = -1;
//		xlm->sprite.pos[xlm->sprite.spr[xlm->sprite.spr_len - 1]].hp = 0;
//		sprite_check(xlm);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'Z')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.super_stvol = 1;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_init(xlm);
		xlm->action.kill = -1;
//		xlm->sprite.pos[xlm->sprite.spr[xlm->sprite.spr_len - 1]].hp = 0;
//		sprite_check(xlm);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'A' && xlm->player.ammo < 100)
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.ammo += 10;
		if (xlm->player.ammo > 100)
			xlm->player.ammo = 100;
//		xlm->player.hp -= 7;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_init(xlm);
		xlm->action.kill = -1;
//		xlm->sprite.pos[xlm->sprite.spr[xlm->sprite.spr_len - 1]].hp = 0;
//		sprite_check(xlm);
	}
	if (xlm->flag && xlm->param.g_map[(int)Y][(int)X] == '6')
	{
		xlm->param.g_map[(int)Y + 1][(int)X] = '5';
		xlm->flag = 0;
	}
	if (xlm->flag && xlm->param.g_map[(int)Y][(int)X] == 'B')
		Y -= 1;
}

static void move_player(t_all *xlm)
{
	if (xlm->move.open == 1 && ft_rhr("3", xlm->param.g_map[(int)(Y +\
	((SPEED + 0.1) * xlm->player.dir_y))][(int)X]))
		xlm->param.g_map[(int)(Y + ((SPEED + 0.1) * xlm->player.dir_y))][(int)X] = '0';
	if (xlm->move.open == 1 && ft_rhr("3", xlm->param.g_map[(int)Y]\
	[(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]))
		xlm->param.g_map[(int)Y][(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))] = '0';
	if (xlm->move.up == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)(Y +\
	((SPEED + 0.1) * xlm->player.dir_y))][(int)X]))
		Y += SPEED * xlm->player.dir_y;
	if (xlm->move.up == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)Y]\
	[(int)(X + ((SPEED + 0.1) * xlm->player.dir_x))]))
		X += SPEED * xlm->player.dir_x;
	if (xlm->move.down == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)(Y -\
	((SPEED + 0.1) * xlm->player.dir_y))][(int)X]))
		Y -= SPEED * xlm->player.dir_y;
	if (xlm->move.down == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)Y]\
	[(int)(X - ((SPEED + 0.1) * xlm->player.dir_x))]))
		X -= SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 && !ft_rhr("12345YVv", xlm->param.g_map[(int)(Y +\
	((SPEED + 0.1) * xlm->player.dir_x))][(int)X]))
		Y += SPEED * xlm->player.dir_x;
	if (xlm->move.right == 1 && !ft_rhr("12345YVvGgi", xlm->param.g_map[(int)Y]\
	[(int)(X - ((SPEED + 0.1) * xlm->player.dir_y))]))
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
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, xlm->param.valid);
		exit(0);
	}
}