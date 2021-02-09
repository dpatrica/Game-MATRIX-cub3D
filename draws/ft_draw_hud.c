//
// Created by Daisey Patrica on 2/9/21.
//

#include "../includes/cub3d.h"

void	ft_draw_hud(t_all *xlm)
{
//	int go_hp = 0;
//	int go_ar = 0;
	double step_hud = 0;
	double x_start_hp = 0;
	double x_end_hp = 0;
	double y_start_hp = 0;
	double y_end_hp = 0;
	double x_start_ar = 0;
	double x_end_ar = 0;
	double y_start_ar = 0;
	double y_end_ar = 0;
	int x;
	int y;
	unsigned int *color;
	double step_x;
	double pos_x;

//	select_tex(xlm);
	xlm->neo.tex_pos = (double)xlm->sprite.all_tex[17].height / (double)(xlm->param.height / 6);
	xlm->neo.step = xlm->neo.tex_pos;
	pos_x = (double)xlm->sprite.all_tex[17].width /(double)(xlm->param.width / 4);
	step_x = pos_x;
	x = 0;
	while (++x < (xlm->param.width / 4))
	{
		xlm->neo.tex_x = (int) pos_x;
		if (xlm->neo.tex_x >= xlm->sprite.all_tex[17].width)
			xlm->neo.tex_x = xlm->sprite.all_tex[17].width - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		y = 0;
		while (++y < (xlm->param.height / 6))
		{
			xlm->neo.tex_y = (int) xlm->neo.tex_pos;
			if (xlm->neo.tex_y >= xlm->sprite.all_tex[17].height)
				xlm->neo.tex_y = xlm->sprite.all_tex[17].height - 1;
			else if (xlm->neo.tex_y < 0)
				xlm->neo.tex_y = 0;
			color = (unsigned int *)(xlm->sprite.all_tex[17].adr + xlm->sprite.all_tex[17].line_len * \
            xlm->neo.tex_y + xlm->neo.tex_x * (xlm->sprite.all_tex[17].bpp / 8));
			if ((int)*color == rgb_color(0, 12, 255))
			{
				if (!x_start_ar && !y_start_ar)
				{
					x_start_ar = x;
					y_start_ar = y;

				}
				else if (x_start_ar && (x - 10) > x_start_ar)
				{
					x_end_ar = x;
					y_end_ar = y;
				}
			}
			else if ((int)*color == rgb_color(255, 0, 0))
			{
				if (!x_start_hp && !y_start_hp)
				{
					x_start_hp = x;
					y_start_hp = y;

				}
				else if (x_start_hp && (x - 10) > x_start_hp)
				{
					x_end_hp = x;
					y_end_hp = y;
				}
			}
			my_pixel_put(xlm, x, y, (int)*color);
			xlm->neo.tex_pos += xlm->neo.step;
		}
		pos_x += step_x;
		xlm->neo.tex_pos = (double) xlm->sprite.all_tex[17].height / (double)(xlm->param.height / 6);
	}

	step_hud = (x_end_hp - x_start_hp) / 100;
	int hit = xlm->player.hp * step_hud;
	int old_y_start_hp = y_start_hp;
	while (hit--)
	{
		y_start_hp = old_y_start_hp;
		while (y_start_hp < y_end_hp)
			my_pixel_put(xlm, (int)x_start_hp, (int)y_start_hp++, rgb_color(255, 0, 0));
		x_start_hp += 1;
	}

}