//
// Created by Daisey Patrica on 1/28/21.
//

#include "../includes/cub3d.h"

static void	get_agr(t_all *xlm)
{
	xlm->tex.no.adr = mlx_get_data_addr(xlm->tex.no.tex, &xlm->tex.no.bpp,\
	&xlm->tex.no.line_len, &xlm->tex.no.iend);
	xlm->tex.so.adr = mlx_get_data_addr(xlm->tex.so.tex, &xlm->tex.so.bpp,\
	&xlm->tex.so.line_len, &xlm->tex.so.iend);
	xlm->tex.we.adr = mlx_get_data_addr(xlm->tex.we.tex, &xlm->tex.we.bpp,\
	&xlm->tex.we.line_len, &xlm->tex.we.iend);
	xlm->tex.ea.adr = mlx_get_data_addr(xlm->tex.ea.tex, &xlm->tex.ea.bpp,\
	&xlm->tex.ea.line_len, &xlm->tex.ea.iend);
	xlm->sprite.all_tex[0].adr = mlx_get_data_addr(xlm->sprite.all_tex[0].tex, &xlm->sprite.all_tex[0].bpp,\
	&xlm->sprite.all_tex[0].line_len, &xlm->sprite.all_tex[0].iend);
	xlm->sprite.all_tex[1].adr = mlx_get_data_addr(xlm->sprite.all_tex[1].tex, &xlm->sprite.all_tex[1].bpp,\
	&xlm->sprite.all_tex[1].line_len, &xlm->sprite.all_tex[1].iend);
	xlm->sprite.all_tex[2].adr = mlx_get_data_addr(xlm->sprite.all_tex[2].tex, &xlm->sprite.all_tex[2].bpp,\
	&xlm->sprite.all_tex[2].line_len, &xlm->sprite.all_tex[2].iend);
	xlm->sprite.all_tex[3].adr = mlx_get_data_addr(xlm->sprite.all_tex[3].tex, &xlm->sprite.all_tex[3].bpp,\
	&xlm->sprite.all_tex[3].line_len, &xlm->sprite.all_tex[3].iend);
	xlm->sprite.all_tex[4].adr = mlx_get_data_addr(xlm->sprite.all_tex[4].tex, &xlm->sprite.all_tex[4].bpp,\
	&xlm->sprite.all_tex[4].line_len, &xlm->sprite.all_tex[4].iend);
	xlm->sprite.all_tex[5].adr = mlx_get_data_addr(xlm->sprite.all_tex[5].tex, &xlm->sprite.all_tex[5].bpp,\
	&xlm->sprite.all_tex[5].line_len, &xlm->sprite.all_tex[5].iend);
	xlm->sprite.all_tex[6].adr = mlx_get_data_addr(xlm->sprite.all_tex[6].tex, &xlm->sprite.all_tex[6].bpp,\
	&xlm->sprite.all_tex[6].line_len, &xlm->sprite.all_tex[6].iend);
	xlm->sprite.all_tex[7].adr = mlx_get_data_addr(xlm->sprite.all_tex[7].tex, &xlm->sprite.all_tex[7].bpp,\
	&xlm->sprite.all_tex[7].line_len, &xlm->sprite.all_tex[7].iend);
	xlm->sprite.all_tex[8].adr = mlx_get_data_addr(xlm->sprite.all_tex[8].tex, &xlm->sprite.all_tex[8].bpp,\
	&xlm->sprite.all_tex[8].line_len, &xlm->sprite.all_tex[8].iend);
	xlm->sprite.all_tex[9].adr = mlx_get_data_addr(xlm->sprite.all_tex[9].tex, &xlm->sprite.all_tex[9].bpp,\
	&xlm->sprite.all_tex[9].line_len, &xlm->sprite.all_tex[9].iend);
	xlm->sprite.all_tex[10].adr = mlx_get_data_addr(xlm->sprite.all_tex[10].tex, &xlm->sprite.all_tex[10].bpp,\
	&xlm->sprite.all_tex[10].line_len, &xlm->sprite.all_tex[10].iend);
//	xlm->sprite.all_tex[11].adr = mlx_get_data_addr(xlm->sprite.all_tex[11].tex, &xlm->sprite.all_tex[11].bpp,\
//	&xlm->sprite.all_tex[11].line_len, &xlm->sprite.all_tex[11].iend);
//	xlm->sprite.all_tex[12].adr = mlx_get_data_addr(xlm->sprite.all_tex[12].tex, &xlm->sprite.all_tex[12].bpp,\
//	&xlm->sprite.all_tex[12].line_len, &xlm->sprite.all_tex[12].iend);
//	xlm->sprite.all_tex[13].adr = mlx_get_data_addr(xlm->sprite.all_tex[13].tex, &xlm->sprite.all_tex[13].bpp,\
//	&xlm->sprite.all_tex[13].line_len, &xlm->sprite.all_tex[13].iend);
//	xlm->sprite.all_tex[14].adr = mlx_get_data_addr(xlm->sprite.all_tex[14].tex, &xlm->sprite.all_tex[14].bpp,\
//	&xlm->sprite.all_tex[14].line_len, &xlm->sprite.all_tex[14].iend);
//	xlm->sprite.all_tex[15].adr = mlx_get_data_addr(xlm->sprite.all_tex[15].tex, &xlm->sprite.all_tex[15].bpp,\
//	&xlm->sprite.all_tex[15].line_len, &xlm->sprite.all_tex[15].iend);
	xlm->tex.skybox.adr = mlx_get_data_addr(xlm->tex.skybox.tex,\
	&xlm->tex.skybox.bpp, &xlm->tex.skybox.line_len, &xlm->tex.skybox.iend);
	if (!xlm->tex.no.adr || !xlm->tex.so.adr || !xlm->tex.we.adr ||\
	!xlm->tex.ea.adr || !xlm->tex.skybox.adr)
	{
		ft_error(xlm, TEXTURE_ERROR);
		exit(0);
	}
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
	xlm->sprite.all_tex[0].tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.s,\
	&xlm->sprite.all_tex[0].width, &xlm->sprite.all_tex[0].height);
	xlm->sprite.all_tex[1].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/morf500х500.xpm",\
	&xlm->sprite.all_tex[1].width, &xlm->sprite.all_tex[1].height);
	xlm->sprite.all_tex[2].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/pils1.xpm",\
	&xlm->sprite.all_tex[2].width, &xlm->sprite.all_tex[2].height);
	xlm->sprite.all_tex[3].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/pils0.xpm",\
	&xlm->sprite.all_tex[3].width, &xlm->sprite.all_tex[3].height);
	xlm->sprite.all_tex[4].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/mapa.xpm",\
	&xlm->sprite.all_tex[4].width, &xlm->sprite.all_tex[4].height);
	xlm->sprite.all_tex[5].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/digl500.xpm",\
	&xlm->sprite.all_tex[5].width, &xlm->sprite.all_tex[5].height);
	xlm->sprite.all_tex[6].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/pulka.xpm",\
	&xlm->sprite.all_tex[6].width, &xlm->sprite.all_tex[6].height);
	xlm->sprite.all_tex[7].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/apt.xpm",\
	&xlm->sprite.all_tex[7].width, &xlm->sprite.all_tex[7].height);
	xlm->sprite.all_tex[8].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/superstvol.xpm",\
	&xlm->sprite.all_tex[8].width, &xlm->sprite.all_tex[8].height);
	xlm->sprite.all_tex[9].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/diglruka.xpm",\
	&xlm->sprite.all_tex[9].width, &xlm->sprite.all_tex[9].height);
	xlm->sprite.all_tex[10].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/oboi4.xpm",\
	&xlm->sprite.all_tex[10].width, &xlm->sprite.all_tex[10].height);
//	xlm->sprite.all_tex[11].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/apt.xpm",\
//	&xlm->sprite.all_tex[11].width, &xlm->sprite.all_tex[11].height);
//	xlm->sprite.all_tex[12].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/apt.xpm",\
//	&xlm->sprite.all_tex[12].width, &xlm->sprite.all_tex[12].height);
//	xlm->sprite.all_tex[13].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/apt.xpm",\
//	&xlm->sprite.all_tex[13].width, &xlm->sprite.all_tex[13].height);
//	xlm->sprite.all_tex[14].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/apt.xpm",\
//	&xlm->sprite.all_tex[14].width, &xlm->sprite.all_tex[14].height);
//	xlm->sprite.all_tex[15].tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/apt.xpm",\
//	&xlm->sprite.all_tex[15].width, &xlm->sprite.all_tex[15].height);
	xlm->tex.skybox.tex = mlx_xpm_file_to_image(xlm->mlx, "../xpm/matrix.xpm", &xlm->tex.skybox.width, &xlm->tex.skybox.height);
	if (!xlm->tex.no.tex || !xlm->tex.so.tex || !xlm->tex.we.tex ||\
	!xlm->tex.ea.tex || !xlm->tex.skybox.tex)
	{
		ft_error(xlm, TEXTURE_ERROR);
		exit(0);
	}
	get_agr(xlm);
}
