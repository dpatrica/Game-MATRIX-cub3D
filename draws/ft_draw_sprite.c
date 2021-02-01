//
// Created by Daisey Patrica on 1/29/21.
//

#include "../includes/cub3d.h"

static void	chek_tex_spr(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == '2')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[0].tex;
		xlm->sprite.width = xlm->sprite.all_tex[0].width;
		xlm->sprite.height = xlm->sprite.all_tex[0].height;
		xlm->sprite.adr = xlm->sprite.all_tex[0].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[0].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[0].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[0].iend;
	}
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'Y')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[1].tex;
		xlm->sprite.width = xlm->sprite.all_tex[1].width;
		xlm->sprite.height = xlm->sprite.all_tex[1].height;
		xlm->sprite.adr = xlm->sprite.all_tex[1].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[1].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[1].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[1].iend;
	}
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'P')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[2].tex;
		xlm->sprite.width = xlm->sprite.all_tex[2].width;
		xlm->sprite.height = xlm->sprite.all_tex[2].height;
		xlm->sprite.adr = xlm->sprite.all_tex[2].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[2].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[2].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[2].iend;
	}
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'X')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[3].tex;
		xlm->sprite.width = xlm->sprite.all_tex[3].width;
		xlm->sprite.height = xlm->sprite.all_tex[3].height;
		xlm->sprite.adr = xlm->sprite.all_tex[3].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[3].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[3].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[3].iend;
	}
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'M')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[4].tex;
		xlm->sprite.width = xlm->sprite.all_tex[4].width;
		xlm->sprite.height = xlm->sprite.all_tex[4].height;
		xlm->sprite.adr = xlm->sprite.all_tex[4].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[4].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[4].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[4].iend;
	}
}

static int	draw_sprite(t_all *xlm, int x_t, int x, int y)
{
	unsigned int	*color;
	int				y_t;
	int				temp;

	temp = (y - xlm->sprite.move_scr) * 256 -\
	xlm->param.height / xlm->move.mouse_cam * 256 + xlm->sprite.spr_hi * 128;
	y_t = ((temp * xlm->sprite.height) / xlm->sprite.spr_hi) / 256;
	color = (unsigned int*)(xlm->sprite.adr + xlm->sprite.line_len * y_t +\
	x_t * (xlm->sprite.bpp / 8));
	my_pixel_put(xlm, x, y, (int)*color);
	return (1);
}

static void	computation_param_spr(t_all *xlm, int i)
{
	chek_tex_spr(xlm, i);
	xlm->sprite.spr_x = xlm->sprite.pos[xlm->sprite.spr[i]].x - X;
	xlm->sprite.spr_y = xlm->sprite.pos[xlm->sprite.spr[i]].y - Y;
	xlm->sprite.inde = 1.0 / (xlm->player.plan_x * xlm->player.dir_y -\
	xlm->player.dir_x * xlm->player.plan_y);
	xlm->sprite.trans_x = xlm->sprite.inde * (xlm->player.dir_y *\
	xlm->sprite.spr_x - xlm->player.dir_x * xlm->sprite.spr_y);
	xlm->sprite.trans_y = xlm->sprite.inde * (-xlm->player.plan_y *\
	xlm->sprite.spr_x + xlm->player.plan_x * xlm->sprite.spr_y);
	xlm->sprite.spr_scr = (int)((xlm->param.width / 2) *\
	(1 + xlm->sprite.trans_x / xlm->sprite.trans_y));
	xlm->sprite.move_scr = (int)(0.0 / xlm->sprite.trans_y);
	xlm->sprite.spr_hi = abs((int)(xlm->param.height / xlm->sprite.trans_y)) / 1;
	xlm->sprite.draw_up_y = -xlm->sprite.spr_hi / 2 +\
	xlm->param.height / xlm->move.mouse_cam + xlm->sprite.move_scr;
}

static void computation_draw_up_down(t_all *xlm)
{
	if (xlm->sprite.draw_up_y < 0)
		xlm->sprite.draw_up_y = 0;
	xlm->sprite.draw_down_y = xlm->sprite.spr_hi / 2 +\
	xlm->param.height / xlm->move.mouse_cam + xlm->sprite.move_scr;
	if (xlm->sprite.draw_down_y >= xlm->param.height)
		xlm->sprite.draw_down_y = xlm->param.height - 1;
	xlm->sprite.spr_wi = abs((int)(xlm->param.height / xlm->sprite.trans_y)) / 1;
	xlm->sprite.draw_up_x = -xlm->sprite.spr_wi / 2 + xlm->sprite.spr_scr;
	if (xlm->sprite.draw_up_x < 0)
		xlm->sprite.draw_up_x = 0;
	xlm->sprite.draw_down_x = xlm->sprite.spr_wi / 2 + xlm->sprite.spr_scr;
	if (xlm->sprite.draw_down_x >= xlm->param.width)
		xlm->sprite.draw_down_x = xlm->param.width - 1;
}

void	ft_draw_sprite(t_all *xlm)
{
	int		i;
	int		x;
	int		y;
	int		x_t;

	i = -1;
	while (++i < xlm->sprite.spr_len)
	{
		computation_param_spr(xlm, i);
		computation_draw_up_down(xlm);
		x = xlm->sprite.draw_up_x;
		while (x < (xlm->sprite.draw_down_x - 1))
		{
			x_t = (int)(x - (-xlm->sprite.spr_wi / 2 + xlm->sprite.spr_scr)) *\
			xlm->sprite.width / xlm->sprite.spr_wi;
			if (xlm->sprite.trans_y > 0 && x > 0 && x < xlm->param.width &&\
			xlm->sprite.trans_y < xlm->sprite.wid_buf[x])
			{
				y = xlm->sprite.draw_up_y;
				while (y < (xlm->sprite.draw_down_y - 1))
					y += draw_sprite(xlm, x_t, x, y);
			}
			x++;
		}
	}
}
