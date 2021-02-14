//
// Created by Daisey Patrica on 2/14/21.
//

#include "../includes/cub3d.h"

void	ft_screenshot(t_all *xlm)
{
	// КОД СКРИНШОТА //

	mlx_destroy_image(xlm->mlx, xlm->img.img);
	xlm->img.img = NULL;
	ft_error(xlm, 0);
	exit(0);
}
