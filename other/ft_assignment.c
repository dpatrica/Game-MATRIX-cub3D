//
// Created by Daisey Patrica on 12/26/20.
//

#include "../includes/cub3d.h"

static t_all	ft_fornulll(t_all xlm)
{
	xlm.move.up = 0;
	xlm.move.down = 0;
	xlm.move.right = 0;
	xlm.move.left = 0;
	xlm.width_square = 10;
	xlm.player.plan_x = 0;
	xlm.player.plan_y = 0;
	return (xlm);
}

t_all			ft_fornull(t_all xlm)
{
	xlm.win = NULL;
	xlm.mlx = NULL;
	xlm.param.width = 0;
	xlm.param.height = 0;
	xlm.param.g_map = NULL;
	xlm.param.no = NULL;
	xlm.param.so = NULL;
	xlm.param.we = NULL;
	xlm.param.ea = NULL;
	xlm.param.s = NULL;
	xlm.param.f.r = -1;
	xlm.param.f.g = -1;
	xlm.param.f.b = -1;
	xlm.param.f.flag = 0;
	xlm.param.c.r = -1;
	xlm.param.c.g = -1;
	xlm.param.c.b = -1;
	xlm.param.c.flag = 0;
	xlm.param.save = 0;
	xlm.param.resp_player.x = 0;
	xlm.param.resp_player.y = 0;
	xlm.param.resp_player.ammo = 50;
	xlm.param.resp_player.hp = 100;
	xlm.param.resp_player.dir = 0;
	return (ft_fornulll(xlm));
}

static t_map	cos_sin_e_ty_normi(t_map param)
{
	param.resp_player.dir_x = cos(2 * M_PI);
	param.resp_player.dir_y = sin(0);
	param.resp_player.plan_x = 0;
	param.resp_player.plan_y = 0.66;
	return (param);
}

t_map			dir_cos_sin(t_map param)
{
	if (param.resp_player.dir == 'N')
	{
		param.resp_player.dir_x = cos(M_PI / 2);
		param.resp_player.dir_y = sin((3 * M_PI) / 2);
		param.resp_player.plan_x = 0.66;
		param.resp_player.plan_y = 0;
	}
	else if (param.resp_player.dir == 'W')
	{
		param.resp_player.dir_x = cos(M_PI);
		param.resp_player.dir_y = sin(M_PI);
		param.resp_player.plan_x = 0;
		param.resp_player.plan_y = -0.66;
	}
	else if (param.resp_player.dir == 'S')
	{
		param.resp_player.dir_x = cos((3 * M_PI) / 2);
		param.resp_player.dir_y = sin(M_PI / 2);
		param.resp_player.plan_x = -0.66;
		param.resp_player.plan_y = 0;
	}
	else if (param.resp_player.dir == 'E')
		param = cos_sin_e_ty_normi(param);
	return (param);
}
