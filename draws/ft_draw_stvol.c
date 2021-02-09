//
// Created by Daisey Patrica on 2/6/21.
//

#include "../includes/cub3d.h"

static	void	select_tex(t_all *xlm)
{
	if (xlm->move.rpm && xlm->action.shot && xlm->player.cartridges)
	{
		xlm->neo.tex_wid = xlm->sprite.all_tex[10].width;
		xlm->neo.tex_hei = xlm->sprite.all_tex[10].height;
		xlm->neo.adr = xlm->sprite.all_tex[10].adr;
		xlm->neo.bpp = xlm->sprite.all_tex[10].bpp;
		xlm->neo.tex_line = xlm->sprite.all_tex[10].line_len;
		xlm->move.mouse_cam -= 0.1;
		if (xlm->move.mouse_cam < 1.1)
			xlm->move.mouse_cam = 1.1;
		xlm->player.cartridges--;
		xlm->action.shot = 0;
	}
	else
	{
		xlm->neo.tex_wid = xlm->sprite.all_tex[9].width;
		xlm->neo.tex_hei = xlm->sprite.all_tex[9].height;
		xlm->neo.adr = xlm->sprite.all_tex[9].adr;
		xlm->neo.bpp = xlm->sprite.all_tex[9].bpp;
		xlm->neo.tex_line = xlm->sprite.all_tex[9].line_len;
	}
}

static	void	select_super_tex(t_all *xlm)
{
	if (xlm->move.rpm)
	{
		if (xlm->action.shot == 5)
		{
			xlm->neo.tex_wid = xlm->sprite.all_tex[12].width;
			xlm->neo.tex_hei = xlm->sprite.all_tex[12].height;
			xlm->neo.adr = xlm->sprite.all_tex[12].adr;
			xlm->neo.bpp = xlm->sprite.all_tex[12].bpp;
			xlm->neo.tex_line = xlm->sprite.all_tex[12].line_len;
			xlm->action.shot--;
			xlm->move.mouse_cam -= 0.0187;
			xlm->move.l_m_rot -= 0.001;
			xlm->move.r_m_rot = 1;
		}
		else if (xlm->action.shot == 4)
		{
			xlm->neo.tex_wid = xlm->sprite.all_tex[13].width;
			xlm->neo.tex_hei = xlm->sprite.all_tex[13].height;
			xlm->neo.adr = xlm->sprite.all_tex[13].adr;
			xlm->neo.bpp = xlm->sprite.all_tex[13].bpp;
			xlm->neo.tex_line = xlm->sprite.all_tex[13].line_len;
			xlm->action.shot--;
			xlm->move.mouse_cam += 0.09;
			xlm->move.r_m_rot += 0.005;
			xlm->move.l_m_rot = 1;
		}
		else if (xlm->action.shot == 3)
		{
			xlm->neo.tex_wid = xlm->sprite.all_tex[14].width;
			xlm->neo.tex_hei = xlm->sprite.all_tex[14].height;
			xlm->neo.adr = xlm->sprite.all_tex[14].adr;
			xlm->neo.bpp = xlm->sprite.all_tex[14].bpp;
			xlm->neo.tex_line = xlm->sprite.all_tex[14].line_len;
			xlm->action.shot--;
			xlm->move.mouse_cam -= 0.028;
			xlm->move.l_m_rot += 0.002;
			xlm->move.r_m_rot = 1;
		}
		else if (xlm->action.shot == 2)
		{
			xlm->neo.tex_wid = xlm->sprite.all_tex[15].width;
			xlm->neo.tex_hei = xlm->sprite.all_tex[15].height;
			xlm->neo.adr = xlm->sprite.all_tex[15].adr;
			xlm->neo.bpp = xlm->sprite.all_tex[15].bpp;
			xlm->neo.tex_line = xlm->sprite.all_tex[15].line_len;
			xlm->action.shot--;
			xlm->move.mouse_cam += 0.05;
			xlm->move.r_m_rot += 0.0025;
			xlm->move.l_m_rot = 1;
		}
		else if (xlm->action.shot == 1)
		{
			xlm->neo.tex_wid = xlm->sprite.all_tex[16].width;
			xlm->neo.tex_hei = xlm->sprite.all_tex[16].height;
			xlm->neo.adr = xlm->sprite.all_tex[16].adr;
			xlm->neo.bpp = xlm->sprite.all_tex[16].bpp;
			xlm->neo.tex_line = xlm->sprite.all_tex[16].line_len;
			xlm->action.shot = 3;
			xlm->move.mouse_cam -= 0.03;
			xlm->move.l_m_rot += 0.00015;
			xlm->move.r_m_rot = 1;
		}
		if (xlm->move.mouse_cam < 1.1)
			xlm->move.mouse_cam = 1.1;

	}
	else
	{
		xlm->neo.tex_wid = xlm->sprite.all_tex[12].width;
		xlm->neo.tex_hei = xlm->sprite.all_tex[12].height;
		xlm->neo.adr = xlm->sprite.all_tex[12].adr;
		xlm->neo.bpp = xlm->sprite.all_tex[12].bpp;
		xlm->neo.tex_line = xlm->sprite.all_tex[12].line_len;
	}
}

void			ft_draw_stvol(t_all *xlm)
{
	int				x;
	int				y;
	unsigned int	*color;
	double			step_x;
	double			pos_x;

	select_tex(xlm);
	xlm->neo.tex_pos = (double)xlm->neo.tex_hei / (double)(xlm->param.height / 2);
	xlm->neo.step = xlm->neo.tex_pos;
	pos_x = (double)xlm->neo.tex_wid / (double)(xlm->param.width / 2);
	step_x = pos_x;
	x = (xlm->param.width / 2) - 1;
	while (++x < (xlm->param.width - 1))
	{
		xlm->neo.tex_x = (int)pos_x;
		if (xlm->neo.tex_x >= xlm->neo.tex_wid)
			xlm->neo.tex_x = xlm->neo.tex_wid - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		y = (xlm->param.height / 2) - 1;
		while (++y < (xlm->param.height - 1))
		{
			xlm->neo.tex_y = (int)xlm->neo.tex_pos;
			if (xlm->neo.tex_y >= xlm->neo.tex_hei)
				xlm->neo.tex_y = xlm->neo.tex_hei - 1;
			else if (xlm->neo.tex_y < 0)
				xlm->neo.tex_y = 0;
			color = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line *\
			xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
			my_pixel_put(xlm, x, y, (int)*color);
			xlm->neo.tex_pos += xlm->neo.step;
		}
		pos_x += step_x;
		xlm->neo.tex_pos = (double)xlm->neo.tex_hei / (double)(xlm->param.height / 2);
	}
}

void			ft_draw_super_stvol(t_all *xlm)
{
	int				x;
	int				y;
	unsigned int	*color;
	double			step_x;
	double			pos_x;

	select_super_tex(xlm);
	xlm->neo.tex_pos = (double)xlm->neo.tex_hei / (double)(xlm->param.height / 2);
	xlm->neo.step = xlm->neo.tex_pos;
	pos_x = (double)xlm->neo.tex_wid / (double)xlm->param.width;
	step_x = pos_x;
	x = -1;
	while (++x < (xlm->param.width - 1))
	{
		xlm->neo.tex_x = (int)pos_x;
		if (xlm->neo.tex_x >= xlm->neo.tex_wid)
			xlm->neo.tex_x = xlm->neo.tex_wid - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		y = (xlm->param.height / 2) - 1;
		while (++y < (xlm->param.height - 1))
		{
			xlm->neo.tex_y = (int)xlm->neo.tex_pos;
			if (xlm->neo.tex_y >= xlm->neo.tex_hei)
				xlm->neo.tex_y = xlm->neo.tex_hei - 1;
			else if (xlm->neo.tex_y < 0)
				xlm->neo.tex_y = 0;
			color = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line *\
			xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
			my_pixel_put(xlm, x, y, (int)*color);
			xlm->neo.tex_pos += xlm->neo.step;
		}
		pos_x += step_x;
		xlm->neo.tex_pos = (double)xlm->neo.tex_hei / (double)(xlm->param.height / 2);
	}
}