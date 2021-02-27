//
// Created by Daisey Patrica on 1/28/21.
//

#include "../includes/cub3d.h"

static void	get_agr(t_all *xlm, int i)
{
	xlm->tex.no.adr = mlx_get_data_addr(xlm->tex.no.tex, &xlm->tex.no.bpp,\
	&xlm->tex.no.line_len, &xlm->tex.no.iend);
	xlm->tex.so.adr = mlx_get_data_addr(xlm->tex.so.tex, &xlm->tex.so.bpp,\
	&xlm->tex.so.line_len, &xlm->tex.so.iend);
	xlm->tex.we.adr = mlx_get_data_addr(xlm->tex.we.tex, &xlm->tex.we.bpp,\
	&xlm->tex.we.line_len, &xlm->tex.we.iend);
	xlm->tex.ea.adr = mlx_get_data_addr(xlm->tex.ea.tex, &xlm->tex.ea.bpp,\
	&xlm->tex.ea.line_len, &xlm->tex.ea.iend);
	xlm->tex.skybox.adr = mlx_get_data_addr(xlm->tex.skybox.tex,\
	&xlm->tex.skybox.bpp, &xlm->tex.skybox.line_len, &xlm->tex.skybox.iend);
	while (++i <= 27)
	{
		xlm->sprite.all_tex[i].adr = mlx_get_data_addr\
		(xlm->sprite.all_tex[i].tex, &xlm->sprite.all_tex[i].bpp,\
		&xlm->sprite.all_tex[i].line_len, &xlm->sprite.all_tex[i].iend);
	}
	if (!xlm->tex.no.adr || !xlm->tex.so.adr || !xlm->tex.we.adr ||\
	!xlm->tex.ea.adr ||	!xlm->tex.skybox.adr)
	{
		ft_error(xlm, TEXTURE_ERROR);
		exit(0);
	}
}

static void ft_texture_4(t_all *xlm)
{
	xlm->sprite.all_tex[15].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/superstvolNEW2_V3S.xpm",\
	&xlm->sprite.all_tex[15].width, &xlm->sprite.all_tex[15].height);
	xlm->sprite.all_tex[16].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/superstvolNEW2_V4S.xpm",\
	&xlm->sprite.all_tex[16].width, &xlm->sprite.all_tex[16].height);
	xlm->sprite.all_tex[17].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/HUD2RGB.xpm",\
	&xlm->sprite.all_tex[17].width, &xlm->sprite.all_tex[17].height);
	xlm->sprite.all_tex[18].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/armor.xpm",\
	&xlm->sprite.all_tex[18].width, &xlm->sprite.all_tex[18].height);
	xlm->sprite.all_tex[19].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/dverINVERS2.xpm",\
	&xlm->sprite.all_tex[19].width, &xlm->sprite.all_tex[19].height);
	xlm->sprite.all_tex[20].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/morf500х500.xpm",\
	&xlm->sprite.all_tex[20].width, &xlm->sprite.all_tex[20].height);
	xlm->sprite.all_tex[21].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/AgentStrelba2.xpm",\
	&xlm->sprite.all_tex[21].width, &xlm->sprite.all_tex[21].height);
	xlm->sprite.all_tex[22].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/AgentStrelba.xpm",\
	&xlm->sprite.all_tex[22].width, &xlm->sprite.all_tex[22].height);
}

static void ft_texture_3(t_all *xlm)
{
	xlm->sprite.all_tex[7].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/apt.xpm",\
	&xlm->sprite.all_tex[7].width, &xlm->sprite.all_tex[7].height);
	xlm->sprite.all_tex[8].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/superstvol.xpm",\
	&xlm->sprite.all_tex[8].width, &xlm->sprite.all_tex[8].height);
	xlm->sprite.all_tex[9].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/PUshkaNEW.xpm",\
	&xlm->sprite.all_tex[9].width, &xlm->sprite.all_tex[9].height);
	xlm->sprite.all_tex[10].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/PUshkaVISTRELNEW.xpm",\
	&xlm->sprite.all_tex[10].width, &xlm->sprite.all_tex[10].height);
	xlm->sprite.all_tex[11].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/dverINVERS2.xpm",\
	&xlm->sprite.all_tex[11].width, &xlm->sprite.all_tex[11].height);
	xlm->sprite.all_tex[12].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/superstvolNEW.xpm",\
	&xlm->sprite.all_tex[12].width, &xlm->sprite.all_tex[12].height);
	xlm->sprite.all_tex[13].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/superstvolNEW2_VS.xpm",\
	&xlm->sprite.all_tex[13].width, &xlm->sprite.all_tex[13].height);
	xlm->sprite.all_tex[14].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/superstvolNEW2_V2S.xpm",\
	&xlm->sprite.all_tex[14].width, &xlm->sprite.all_tex[14].height);
}

static void ft_texture_2(t_all *xlm)
{
	xlm->tex.skybox.tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/matrix.xpm", &xlm->tex.skybox.width, &xlm->tex.skybox.height);
	xlm->sprite.all_tex[0].tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.s,\
	&xlm->sprite.all_tex[0].width, &xlm->sprite.all_tex[0].height);
	xlm->sprite.all_tex[1].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/morf500х500.xpm",\
	&xlm->sprite.all_tex[1].width, &xlm->sprite.all_tex[1].height);
	xlm->sprite.all_tex[2].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/pils1.xpm",\
	&xlm->sprite.all_tex[2].width, &xlm->sprite.all_tex[2].height);
	xlm->sprite.all_tex[3].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/pils0.xpm",\
	&xlm->sprite.all_tex[3].width, &xlm->sprite.all_tex[3].height);
	xlm->sprite.all_tex[4].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/mapa.xpm",\
	&xlm->sprite.all_tex[4].width, &xlm->sprite.all_tex[4].height);
	xlm->sprite.all_tex[5].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/digl500.xpm",\
	&xlm->sprite.all_tex[5].width, &xlm->sprite.all_tex[5].height);
	xlm->sprite.all_tex[6].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/pulka.xpm",\
	&xlm->sprite.all_tex[6].width, &xlm->sprite.all_tex[6].height);
}

void		ft_texture(t_all *xlm)
{
	xlm->tex.no.tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.no,\
	&xlm->tex.no.width, &xlm->tex.no.height);
	xlm->tex.so.tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.so,\
	&xlm->tex.so.width, &xlm->tex.so.height);
	xlm->tex.we.tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.we,\
	&xlm->tex.we.width, &xlm->tex.we.height);
	xlm->tex.ea.tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.ea,\
	&xlm->tex.ea.width, &xlm->tex.ea.height);
	ft_texture_2(xlm);
	ft_texture_3(xlm);
	ft_texture_4(xlm);
	ft_texture_5(xlm);
	if (!xlm->tex.no.tex || !xlm->tex.so.tex || !xlm->tex.we.tex ||\
	!xlm->tex.ea.tex || !xlm->tex.skybox.tex)
	{
		ft_error(xlm, TEXTURE_ERROR);
		exit(0);
	}
	get_agr(xlm, -1);
}
