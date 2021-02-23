//
// Created by Daisey Patrica on 1/28/21.
//

#include "../includes/cub3d.h"

void ft_render(t_all *xlm)
{
	ft_draw_stdcf(xlm);
	ft_draw_tex(xlm);
	if (xlm->sprite.spr_len)
	{
		sprite_sort(xlm);
		ft_draw_sprite(xlm, 0, 0, -1);
	}
}
