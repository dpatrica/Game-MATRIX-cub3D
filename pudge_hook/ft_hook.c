/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:04:16 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:04:16 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		key_hook(t_all *xlm)
{
	if (!xlm->param.save)
		mlx_mouse_move(xlm->win, (int)(xlm->param.width / 2),\
		(int)(xlm->param.height / 2));
	ft_move(xlm);
	xlm->img.img = mlx_new_image(xlm->mlx, xlm->param.width, xlm->param.height);
	xlm->img.adr = mlx_get_data_addr(xlm->img.img, &xlm->img.bpp,\
	&xlm->img.line_len, &xlm->img.iend);
	ft_render(xlm);
	if (!xlm->param.save)
		mlx_put_image_to_window(xlm->mlx, xlm->win, xlm->img.img, 0, 0);
	else
		ft_screenshot(xlm);
	mlx_destroy_image(xlm->mlx, xlm->img.img);
	xlm->img.img = NULL;
	if (xlm->player.hp <= 0)
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, xlm->param.valid);
		exit(0);
	}
	return (0);
}
