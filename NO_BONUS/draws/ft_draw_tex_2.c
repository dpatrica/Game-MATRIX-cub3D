//
// Created by Daisey Patrica on 2/17/21.
//

#include "../includes/cub3d.h"

static void count_wall_damage(t_all *xlm)
{
	xlm->action.wall_damage--;
	if (!xlm->action.wall_damage)
	{
		xlm->param.g_map[xlm->neo.y][xlm->neo.x] = '0';
		xlm->action.wall_damage = 5;
	}
	xlm->action.wall_flag = 0;
}

void ft_draw_tex_2(t_all *xlm, int x, int y)
{
	unsigned int	*color;

	xlm->neo.tex_y = (int)xlm->neo.tex_pos;
	if (xlm->neo.tex_y >= xlm->neo.tex_hei)
		xlm->neo.tex_y = xlm->neo.tex_hei - 1;
	else if (xlm->neo.tex_y < 0)
		xlm->neo.tex_y = 0;
	xlm->neo.tex_pos += xlm->neo.step;
	if (xlm->neo.adr)
	{
		color = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line *\
		xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
		if (x == (xlm->param.width / 2) && y == (xlm->param.height / 2) &&\
		xlm->param.g_map[xlm->neo.y][xlm->neo.x] == '7' && (int)*color >= 0)
		{
			if (xlm->move.rpm && xlm->action.damage && xlm->player.digl &&\
			xlm->player.cartridges && xlm->action.wall_flag)
				count_wall_damage(xlm);
		}
		my_pixel_put(xlm, x, y, (int)*color);
	}
}