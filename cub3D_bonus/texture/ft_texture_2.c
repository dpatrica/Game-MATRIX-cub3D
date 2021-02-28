/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:25:37 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:25:38 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	guardian(t_all *xlm)
{
	int i;

	i = -1;
	while (++i <= 29)
		if (!xlm->sprite.all_tex[i].tex)
		{
			ft_error(xlm, TEXTURE_ERROR);
			exit(0);
		}
}

void		ft_texture_5(t_all *xlm)
{
	xlm->sprite.all_tex[23].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/AgentHodyba.xpm",\
	&xlm->sprite.all_tex[23].width, &xlm->sprite.all_tex[23].height);
	xlm->sprite.all_tex[24].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/SmithStrelba.xpm",\
	&xlm->sprite.all_tex[24].width, &xlm->sprite.all_tex[24].height);
	xlm->sprite.all_tex[25].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/SmithStrelba2.xpm",\
	&xlm->sprite.all_tex[25].width, &xlm->sprite.all_tex[25].height);
	xlm->sprite.all_tex[26].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/SmithUvrot.xpm",\
	&xlm->sprite.all_tex[26].width, &xlm->sprite.all_tex[26].height);
	xlm->sprite.all_tex[27].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/capcan.xpm",\
	&xlm->sprite.all_tex[27].width, &xlm->sprite.all_tex[27].height);
	xlm->sprite.all_tex[28].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/ggwp.xpm",\
	&xlm->sprite.all_tex[28].width, &xlm->sprite.all_tex[28].height);
	xlm->sprite.all_tex[29].tex = mlx_xpm_file_to_image(xlm->mlx,\
	"./xpm/cubby.xpm",\
	&xlm->sprite.all_tex[29].width, &xlm->sprite.all_tex[29].height);
	guardian(xlm);
}
