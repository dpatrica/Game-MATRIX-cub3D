/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:25:32 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:25:32 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_chek_texture_sprite_5(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'Z')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[8].tex;
		xlm->sprite.width = xlm->sprite.all_tex[8].width;
		xlm->sprite.height = xlm->sprite.all_tex[8].height;
		xlm->sprite.adr = xlm->sprite.all_tex[8].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[8].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[8].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[8].iend;
	}
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'A')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[18].tex;
		xlm->sprite.width = xlm->sprite.all_tex[18].width;
		xlm->sprite.height = xlm->sprite.all_tex[18].height;
		xlm->sprite.adr = xlm->sprite.all_tex[18].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[18].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[18].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[18].iend;
	}
	else
		ft_chek_texture_sprite_6(xlm, i);
}

static void	ft_chek_texture_sprite_4(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'C')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[6].tex;
		xlm->sprite.width = xlm->sprite.all_tex[6].width;
		xlm->sprite.height = xlm->sprite.all_tex[6].height;
		xlm->sprite.adr = xlm->sprite.all_tex[6].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[6].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[6].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[6].iend;
	}
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'H')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[7].tex;
		xlm->sprite.width = xlm->sprite.all_tex[7].width;
		xlm->sprite.height = xlm->sprite.all_tex[7].height;
		xlm->sprite.adr = xlm->sprite.all_tex[7].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[7].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[7].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[7].iend;
	}
	else
		ft_chek_texture_sprite_5(xlm, i);
}

static void	ft_chek_texture_sprite_3(t_all *xlm, int i)
{
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
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'D')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[5].tex;
		xlm->sprite.width = xlm->sprite.all_tex[5].width;
		xlm->sprite.height = xlm->sprite.all_tex[5].height;
		xlm->sprite.adr = xlm->sprite.all_tex[5].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[5].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[5].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[5].iend;
	}
	else
		ft_chek_texture_sprite_4(xlm, i);
}

static void	ft_chek_texture_sprite_2(t_all *xlm, int i)
{
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
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'X')
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
		ft_chek_texture_sprite_3(xlm, i);
}

void		ft_chek_texture_sprite(t_all *xlm, int i)
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
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'Y')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[1].tex;
		xlm->sprite.width = xlm->sprite.all_tex[1].width;
		xlm->sprite.height = xlm->sprite.all_tex[1].height;
		xlm->sprite.adr = xlm->sprite.all_tex[1].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[1].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[1].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[1].iend;
	}
	else
		ft_chek_texture_sprite_2(xlm, i);
}
