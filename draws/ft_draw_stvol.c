//
// Created by Daisey Patrica on 2/6/21.
//

#include "../includes/cub3d.h"

void	ft_draw_stvol(t_all *xlm)
{
	int				x;
	int				y;
	unsigned int	*color;
	double			step_x;
	double			pos_x;

	xlm->neo.tex_pos = (double)xlm->sprite.all_tex[9].height / (double)(xlm->param.height / 2);
	xlm->neo.step = xlm->neo.tex_pos;
	pos_x = (double)xlm->sprite.all_tex[9].width / (double)(xlm->param.width / 2);
	step_x = pos_x;
	x = (xlm->param.width / 2) - 1;
	while (++x < (xlm->param.width - 1))
	{
		xlm->neo.tex_x = (int)pos_x;
		if (xlm->neo.tex_x >= xlm->sprite.all_tex[9].width)
			xlm->neo.tex_x = xlm->sprite.all_tex[9].width - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		y = (xlm->param.height / 2) - 1;
		while (++y < (xlm->param.height - 1))
		{
			xlm->neo.tex_y = (int)xlm->neo.tex_pos;
			if (xlm->neo.tex_y >= xlm->sprite.all_tex[9].height)
				xlm->neo.tex_y = xlm->sprite.all_tex[9].height - 1;
			else if (xlm->neo.tex_y < 0)
				xlm->neo.tex_y = 0;
			color = (unsigned int*)(xlm->sprite.all_tex[9].adr + xlm->sprite.all_tex[9].line_len *\
			xlm->neo.tex_y + xlm->neo.tex_x * (xlm->sprite.all_tex[9].bpp / 8));
			my_pixel_put(xlm, x, y, (int)*color);
			xlm->neo.tex_pos += xlm->neo.step;
		}
		pos_x += step_x;
		xlm->neo.tex_pos = (double)xlm->sprite.all_tex[9].height / (double)(xlm->param.height / 2);
	}
}