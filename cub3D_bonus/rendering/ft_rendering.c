//
// Created by Daisey Patrica on 1/28/21.
//

#include "../includes/cub3d.h"

void ft_render(t_all *xlm)
{
	if (!xlm->move.rpm)
	{
		xlm->action.damage = 100;
		xlm->action.wall_flag = 1;
		xlm->action.shot = 5;
	}
	if (xlm->param.lvl == 1)
		ft_draw_cefl(xlm);
	else
		ft_draw_stdcf(xlm);
	ft_draw_tex(xlm);
	if (xlm->sprite.spr_len)
	{
		sprite_sort(xlm);
		ft_draw_sprite(xlm, 0, 0, -1);
		if (xlm->action.kill != -1)
		{
			sprite_check(xlm);
			xlm->action.kill = -1;
		}
	}
	if (xlm->player.digl && !xlm->player.super_stvol)
		ft_draw_aim(xlm);
	if (xlm->player.digl && !xlm->player.super_stvol)
		ft_draw_stvol(xlm);
	else if (xlm->player.super_stvol)
		ft_draw_super_stvol(xlm);
	if (xlm->param.lvl == 1)
		ft_draw_hud(xlm);
	if (xlm->player.map && xlm->move.map && xlm->height_square && xlm->width_square)
		ft_draw_map(xlm);
}
