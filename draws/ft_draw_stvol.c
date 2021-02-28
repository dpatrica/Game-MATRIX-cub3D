/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_stvol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:02:11 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:02:12 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		draw_stvol(t_all *xlm, int x, int y)
{
	unsigned int	*color;

	xlm->neo.tex_y = (int)xlm->hud.pos_y;
	if (xlm->neo.tex_y >= xlm->neo.tex_hei)
		xlm->neo.tex_y = xlm->neo.tex_hei - 1;
	else if (xlm->neo.tex_y < 0)
		xlm->neo.tex_y = 0;
	color = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line *\
			xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
	my_pixel_put(xlm, x, y, (int)*color);
	xlm->hud.pos_y += xlm->hud.step_y;
}

void			ft_draw_stvol(t_all *xlm)
{
	int				x;
	int				y;

	select_weapon_tex(xlm);
	xlm->hud.pos_y = (double)xlm->neo.tex_hei / (double)(xlm->param.height / 2);
	xlm->hud.step_y = xlm->hud.pos_y;
	xlm->hud.pos_x = (double)xlm->neo.tex_wid / (double)(xlm->param.width / 2);
	xlm->hud.step_x = xlm->hud.pos_x;
	x = (xlm->param.width / 2) - 1;
	while (++x < (xlm->param.width - 1))
	{
		xlm->neo.tex_x = (int)xlm->hud.pos_x;
		if (xlm->neo.tex_x >= xlm->neo.tex_wid)
			xlm->neo.tex_x = xlm->neo.tex_wid - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		y = (xlm->param.height / 2) - 1;
		while (++y < (xlm->param.height - 1))
			draw_stvol(xlm, x, y);
		xlm->hud.pos_x += xlm->hud.step_x;
		xlm->hud.pos_y = (double)xlm->neo.tex_hei /\
		(double)(xlm->param.height / 2);
	}
}

static void		draw_super_stvol(t_all *xlm, int x, int y)
{
	unsigned int	*color;

	xlm->neo.tex_y = (int)xlm->hud.pos_y;
	if (xlm->neo.tex_y >= xlm->neo.tex_hei)
		xlm->neo.tex_y = xlm->neo.tex_hei - 1;
	else if (xlm->neo.tex_y < 0)
		xlm->neo.tex_y = 0;
	color = (unsigned int*)(xlm->neo.adr + xlm->neo.tex_line *\
			xlm->neo.tex_y + xlm->neo.tex_x * (xlm->neo.bpp / 8));
	my_pixel_put(xlm, x, y, (int)*color);
	xlm->hud.pos_y += xlm->hud.step_y;
}

void			ft_draw_super_stvol(t_all *xlm)
{
	int				x;
	int				y;

	select_super_weapon_tex(xlm);
	xlm->hud.pos_y = (double)xlm->neo.tex_hei / (double)(xlm->param.height / 2);
	xlm->hud.step_y = xlm->hud.pos_y;
	xlm->hud.pos_x = (double)xlm->neo.tex_wid / (double)xlm->param.width;
	xlm->hud.step_x = xlm->hud.pos_x;
	x = -1;
	while (++x < (xlm->param.width - 1))
	{
		xlm->neo.tex_x = (int)xlm->hud.pos_x;
		if (xlm->neo.tex_x >= xlm->neo.tex_wid)
			xlm->neo.tex_x = xlm->neo.tex_wid - 1;
		else if (xlm->neo.tex_x < 0)
			xlm->neo.tex_x = 0;
		y = (xlm->param.height / 2) - 1;
		while (++y < (xlm->param.height - 1))
			draw_super_stvol(xlm, x, y);
		xlm->hud.pos_x += xlm->hud.step_x;
		xlm->hud.pos_y = (double)xlm->neo.tex_hei /\
		(double)(xlm->param.height / 2);
	}
}
