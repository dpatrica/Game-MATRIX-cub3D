//
// Created by Daisey Patrica on 2/20/21.
//

#include "../includes/cub3d.h"

static void ft_chek_texture_sprite_9(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == '8')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[27].tex;
		xlm->sprite.width = xlm->sprite.all_tex[27].width;
		xlm->sprite.height = xlm->sprite.all_tex[27].height;
		xlm->sprite.adr = xlm->sprite.all_tex[27].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[27].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[27].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[27].iend;
	}
}

static void ft_chek_texture_sprite_8(t_all *xlm, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'g')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[25].tex;
		xlm->sprite.width = xlm->sprite.all_tex[25].width;
		xlm->sprite.height = xlm->sprite.all_tex[25].height;
		xlm->sprite.adr = xlm->sprite.all_tex[25].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[25].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[25].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[25].iend;
	}
	else if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'i')
	{
		xlm->sprite.tex = xlm->sprite.all_tex[26].tex;
		xlm->sprite.width = xlm->sprite.all_tex[26].width;
		xlm->sprite.height = xlm->sprite.all_tex[26].height;
		xlm->sprite.adr = xlm->sprite.all_tex[26].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[26].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[26].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[26].iend;
	}
	else
		ft_chek_texture_sprite_9(xlm, i);
}

static void ft_chek_texture_sprite_7(t_all *xlm, int i)
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
		xlm->sprite.tex = xlm->sprite.all_tex[24].tex;
		xlm->sprite.width = xlm->sprite.all_tex[24].width;
		xlm->sprite.height = xlm->sprite.all_tex[24].height;
		xlm->sprite.adr = xlm->sprite.all_tex[24].adr;
		xlm->sprite.bpp = xlm->sprite.all_tex[24].bpp;
		xlm->sprite.line_len = xlm->sprite.all_tex[24].line_len;
		xlm->sprite.iend = xlm->sprite.all_tex[24].iend;
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
			xlm->sprite.tex = xlm->sprite.all_tex[23].tex;
			xlm->sprite.width = xlm->sprite.all_tex[23].width;
			xlm->sprite.height = xlm->sprite.all_tex[23].height;
			xlm->sprite.adr = xlm->sprite.all_tex[23].adr;
			xlm->sprite.bpp = xlm->sprite.all_tex[23].bpp;
			xlm->sprite.line_len = xlm->sprite.all_tex[23].line_len;
			xlm->sprite.iend = xlm->sprite.all_tex[23].iend;
		}
		else
		{
			xlm->sprite.tex = xlm->sprite.all_tex[22].tex;
			xlm->sprite.width = xlm->sprite.all_tex[22].width;
			xlm->sprite.height = xlm->sprite.all_tex[22].height;
			xlm->sprite.adr = xlm->sprite.all_tex[22].adr;
			xlm->sprite.bpp = xlm->sprite.all_tex[22].bpp;
			xlm->sprite.line_len = xlm->sprite.all_tex[22].line_len;
			xlm->sprite.iend = xlm->sprite.all_tex[22].iend;
		}
	}
	else
		ft_chek_texture_sprite_7(xlm, i);
}