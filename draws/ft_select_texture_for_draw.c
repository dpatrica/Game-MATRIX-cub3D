//
// Created by Daisey Patrica on 1/29/21.
//

#include "../includes/cub3d.h"

static void select_ea(t_all *xlm)
{
	xlm->neo.tex_wid = xlm->tex.ea.width;
	xlm->neo.tex_hei = xlm->tex.ea.height;
	xlm->neo.adr = xlm->tex.ea.adr;
	xlm->neo.bpp = xlm->tex.ea.bpp;
	xlm->neo.tex_line = xlm->tex.ea.line_len;
}

static void select_we(t_all *xlm)
{
	xlm->neo.tex_wid = xlm->tex.we.width;
	xlm->neo.tex_hei = xlm->tex.we.height;
	xlm->neo.adr = xlm->tex.we.adr;
	xlm->neo.bpp = xlm->tex.we.bpp;
	xlm->neo.tex_line = xlm->tex.we.line_len;
}

static void select_no(t_all *xlm)
{
	xlm->neo.tex_wid = xlm->tex.no.width;
	xlm->neo.tex_hei = xlm->tex.no.height;
	xlm->neo.adr = xlm->tex.no.adr;
	xlm->neo.bpp = xlm->tex.no.bpp;
	xlm->neo.tex_line = xlm->tex.no.line_len;
}

static void select_so(t_all *xlm)
{
	xlm->neo.tex_wid = xlm->tex.so.width;
	xlm->neo.tex_hei = xlm->tex.so.height;
	xlm->neo.adr = xlm->tex.so.adr;
	xlm->neo.bpp = xlm->tex.so.bpp;
	xlm->neo.tex_line = xlm->tex.so.line_len;
}

void 		ft_select_texture(t_all *xlm)
{
	if (xlm->neo.side == 0 && xlm->neo.step_x == 1)
		select_ea(xlm);
	else if (xlm->neo.side == 0 && xlm->neo.step_x == -1)
		select_we(xlm);
	else if (xlm->neo.side == 1 && xlm->neo.step_y == -1)
		select_no(xlm);
	else if (xlm->neo.side == 1 && xlm->neo.step_y == 1)
		select_so(xlm);
}