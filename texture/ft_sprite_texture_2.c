/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_texture_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:04:58 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:04:58 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_chek_texture_sprite_8(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'g')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[21].tex;
		xlm->sprite.width = xlm->sprite.all_tex[21].width;
		xlm->sprite.height = xlm->sprite.all_tex[21].height;
		xlm->sprite.adr = xlm->sprite.all_tex[21].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[21].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[21].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[21].iend;
	}
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'i')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[3].tex;
		xlm->sprite.width = xlm->sprite.all_tex[3].width;
		xlm->sprite.height = xlm->sprite.all_tex[3].height;
		xlm->sprite.adr = xlm->sprite.all_tex[3].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[3].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[3].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[3].iend;
	}
}

static void	ft_chek_texture_sprite_7(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'v')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[21].tex;
		xlm->sprite.width = xlm->sprite.all_tex[21].width;
		xlm->sprite.height = xlm->sprite.all_tex[21].height;
		xlm->sprite.adr = xlm->sprite.all_tex[21].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[21].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[21].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[21].iend;
	}
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'G')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[20].tex;
		xlm->sprite.width = xlm->sprite.all_tex[20].width;
		xlm->sprite.height = xlm->sprite.all_tex[20].height;
		xlm->sprite.adr = xlm->sprite.all_tex[20].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[20].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[20].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[20].iend;
	}
	else
		ft_chek_texture_sprite_8(xlm, i);
}

void		ft_chek_texture_sprite_6(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'V')
	{
		if (xlm->sprite.spr_dist[xlm->sprite.spr[i]] > 200)
		{
			xlm->sprite.tex = xlm->sprite.all_tex[3].tex;
			xlm->sprite.width = xlm->sprite.all_tex[3].width;
			xlm->sprite.height = xlm->sprite.all_tex[3].height;
			xlm->sprite.adr = xlm->sprite.all_tex[3].adr;
			xlm->sprite.bpp = xlm->sprite.all_tex[3].bpp;
			xlm->sprite.line_len = xlm->sprite.all_tex[3].line_len;
			xlm->sprite.iend = xlm->sprite.all_tex[3].iend;
		}
		else
		{
			xlm->sprite.tex = xlm->sprite.all_tex[20].tex;
			xlm->sprite.width = xlm->sprite.all_tex[20].width;
			xlm->sprite.height = xlm->sprite.all_tex[20].height;
			xlm->sprite.adr = xlm->sprite.all_tex[20].adr;
			xlm->sprite.bpp = xlm->sprite.all_tex[20].bpp;
			xlm->sprite.line_len = xlm->sprite.all_tex[20].line_len;
			xlm->sprite.iend = xlm->sprite.all_tex[20].iend;
		}
	}
	else
		ft_chek_texture_sprite_7(xlm, i);
}
