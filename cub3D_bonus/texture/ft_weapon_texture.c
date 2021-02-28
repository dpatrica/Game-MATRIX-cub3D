//
// Created by Daisey Patrica on 2/17/21.
//

#include "../includes/cub3d.h"

void		select_weapon_tex(t_all *xlm)
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
		play_music(1);
		xlm->action.shot = 0;
	}
	else
	{
		xlm->neo.tex_wid = xlm->sprite.all_tex[9].width;
		xlm->neo.tex_hei = xlm->sprite.all_tex[9].height;
		xlm->neo.adr = xlm->sprite.all_tex[9].adr;
		xlm->neo.bpp = xlm->sprite.all_tex[9].bpp;
		xlm->neo.tex_line = xlm->sprite.all_tex[9].line_len;
		if (xlm->move.rpm && xlm->action.shot && !xlm->player.cartridges &&\
		!(xlm->action.shot = 0))
			play_music(2);
	}
}

static void	select_super_weapon_tex_4(t_all *xlm)
{
	if (xlm->action.shot == 2)
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
}

static void	select_super_weapon_tex_3(t_all *xlm)
{
	if (xlm->action.shot == 3)
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
	else
		select_super_weapon_tex_4(xlm);
}

static void	select_super_weapon_tex_2(t_all *xlm)
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
	else if (xlm->action.shot == 4 && xlm->action.shot--)
	{
		xlm->neo.tex_wid = xlm->sprite.all_tex[13].width;
		xlm->neo.tex_hei = xlm->sprite.all_tex[13].height;
		xlm->neo.adr = xlm->sprite.all_tex[13].adr;
		xlm->neo.bpp = xlm->sprite.all_tex[13].bpp;
		xlm->neo.tex_line = xlm->sprite.all_tex[13].line_len;
		xlm->move.mouse_cam += 0.09;
		xlm->move.r_m_rot += 0.005;
		xlm->move.l_m_rot = 1;
	}
	else
		select_super_weapon_tex_3(xlm);
}

void		select_super_weapon_tex(t_all *xlm)
{
	if (xlm->move.rpm)
	{
		select_super_weapon_tex_2(xlm);
		if (xlm->move.mouse_cam < 1.1)
			xlm->move.mouse_cam = 1.1;
		if (xlm->player.ammo > 0)
			xlm->player.ammo -= 0.1;
		else
			xlm->player.hp -= 0.1;
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
