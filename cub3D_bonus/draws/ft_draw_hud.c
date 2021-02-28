/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:22:35 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:22:36 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_pos_hud(t_all *xlm, int x, int y, int color)
{
	if (color == rgb_color(0, 12, 255))
	{
		if (!xlm->hud.x_start_ar && !xlm->hud.y_start_ar)
		{
			xlm->hud.x_start_ar = x;
			xlm->hud.y_start_ar = y;
		}
		else if ((xlm->hud.x_end_ar = x))
			xlm->hud.y_end_ar = y;
	}
	else if (color == rgb_color(255, 0, 0))
	{
		if (!xlm->hud.x_start_hp && !xlm->hud.y_start_hp)
		{
			xlm->hud.x_start_hp = x;
			xlm->hud.y_start_hp = y;
		}
		else if ((xlm->hud.x_end_hp = x))
			xlm->hud.y_end_hp = y;
	}
}

static void	draw_hp_ar(t_all *xlm)
{
	int		quantity;
	double	old_y_start;
	double	step_hud;

	old_y_start = xlm->hud.y_start_hp;
	step_hud = (xlm->hud.x_end_hp - xlm->hud.x_start_hp) / 100;
	quantity = (int)(xlm->player.hp * step_hud) + 1;
	while (--quantity && quantity > 0)
	{
		xlm->hud.y_start_hp = old_y_start;
		while (xlm->hud.y_start_hp < xlm->hud.y_end_hp)
			my_pixel_put(xlm, (int)xlm->hud.x_start_hp,\
			(int)xlm->hud.y_start_hp++, rgb_color(255, 0, 0));
		xlm->hud.x_start_hp += 1;
	}
	old_y_start = xlm->hud.y_start_ar;
	quantity = (int)(xlm->player.ammo * step_hud) + 1;
	while (--quantity && quantity > 0)
	{
		xlm->hud.y_start_ar = old_y_start;
		while (xlm->hud.y_start_ar < xlm->hud.y_end_ar)
			my_pixel_put(xlm, (int)xlm->hud.x_start_ar,\
			(int)xlm->hud.y_start_ar++, rgb_color(0, 12, 255));
		xlm->hud.x_start_ar += 1;
	}
}

static void	obnulay(t_all *xlm)
{
	xlm->hud.x_start_hp = 0;
	xlm->hud.x_end_hp = 0;
	xlm->hud.y_start_hp = 0;
	xlm->hud.y_end_hp = 0;
	xlm->hud.x_start_ar = 0;
	xlm->hud.x_end_ar = 0;
	xlm->hud.y_start_ar = 0;
	xlm->hud.y_end_ar = 0;
}

static void	ft_draw_hud_y(t_all *xlm, int x)
{
	unsigned int	*color;
	int				y;

	xlm->neo.tex_x = (int)xlm->hud.pos_x;
	if (xlm->neo.tex_x >= xlm->sprite.all_tex[17].width)
		xlm->neo.tex_x = xlm->sprite.all_tex[17].width - 1;
	else if (xlm->neo.tex_x < 0)
		xlm->neo.tex_x = 0;
	y = -1;
	while (++y < (xlm->param.height / 6))
	{
		xlm->neo.tex_y = (int)xlm->hud.pos_y;
		if (xlm->neo.tex_y >= xlm->sprite.all_tex[17].height)
			xlm->neo.tex_y = xlm->sprite.all_tex[17].height - 1;
		else if (xlm->neo.tex_y < 0)
			xlm->neo.tex_y = 0;
		color = (unsigned int*)(xlm->sprite.all_tex[17].adr +\
		xlm->sprite.all_tex[17].line_len * xlm->neo.tex_y + xlm->neo.tex_x *\
		(xlm->sprite.all_tex[17].bpp / 8));
		check_pos_hud(xlm, x, y, (int)*color);
		my_pixel_put(xlm, x, y, (int)*color);
		xlm->hud.pos_y += xlm->hud.step_y;
	}
}

void		ft_draw_hud(t_all *xlm)
{
	int x;

	obnulay(xlm);
	xlm->hud.pos_y = (double)xlm->sprite.all_tex[17].height /\
	((double)xlm->param.height / 6);
	xlm->hud.step_y = xlm->hud.pos_y;
	xlm->hud.pos_x = (double)xlm->sprite.all_tex[17].width /\
	((double)xlm->param.width / 4);
	xlm->hud.step_x = xlm->hud.pos_x;
	x = -1;
	while (++x < (xlm->param.width / 4))
	{
		ft_draw_hud_y(xlm, x);
		xlm->hud.pos_x += xlm->hud.step_x;
		xlm->hud.pos_y = (double)xlm->sprite.all_tex[17].height /\
		((double)xlm->param.height / 6);
	}
	draw_hp_ar(xlm);
}
