/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:05:08 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:05:09 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	xlm->sprite.adr = mlx_get_data_addr(xlm->sprite.tex, &xlm->sprite.bpp,\
	&xlm->sprite.line_len, &xlm->sprite.iend);
	if (!xlm->tex.no.adr || !xlm->tex.so.adr || !xlm->tex.we.adr ||\
	!xlm->tex.ea.adr || !xlm->sprite.adr)
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
	xlm->sprite.tex = mlx_xpm_file_to_image(xlm->mlx, xlm->param.s,\
	&xlm->sprite.width, &xlm->sprite.height);
	if (!xlm->tex.no.tex || !xlm->tex.so.tex || !xlm->tex.we.tex ||\
	!xlm->tex.ea.tex || !xlm->sprite.tex)
	{
		ft_error(xlm, TEXTURE_ERROR);
		exit(0);
	}
	get_agr(xlm);
}
