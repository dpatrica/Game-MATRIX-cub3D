//
// Created by Daisey Patrica on 2/22/21.
//

#include "../includes/cub3d.h"

void	ft_texture_5(t_all *xlm)
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
}
