//
// Created by Daisey Patrica on 1/28/21.
//

#include "../includes/cub3d.h"

void ft_render(t_all *xlm)
{
	if (!xlm->move.rpm)
	{
		xlm->action.damage = 1;
		xlm->action.shot = 5;
	}
	if (xlm->param.lvl != 2)
		ft_draw_cefl(xlm);
	ft_draw_tex(xlm);
	if (xlm->sprite.spr_len)
	{
		sprite_sort(xlm);
		ft_draw_sprite(xlm);
		if (xlm->action.kill != -1)
		{
			sprite_init(xlm);
			xlm->action.kill = -1;
		}
	}
	if (xlm->player.digl && !xlm->player.super_stvol)
		ft_draw_aim(xlm);
	if (xlm->player.digl && !xlm->player.super_stvol)
		ft_draw_stvol(xlm);
	else if (xlm->player.super_stvol)
		ft_draw_super_stvol(xlm);
	ft_draw_hud(xlm);
	if (xlm->player.map && xlm->move.map && xlm->height_square && xlm->width_square)
		ft_draw_map(xlm, START_X, START_Y);
}
