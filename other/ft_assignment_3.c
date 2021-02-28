/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assignment_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:03:18 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:03:18 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_all	ft_fornull_3(t_all xlm)
{
	xlm.hud.y_start_ar = 0;
	xlm.hud.y_end_ar = 0;
	xlm.flag = 1;
	xlm.action.wall_damage = 5;
	xlm.action.wall_flag = 0;
	xlm.action.change_stvol = 0;
	xlm.map.x_print = 0;
	xlm.map.y_print = 0;
	xlm.sprite.x_t = 0;
	return (xlm);
}

void	check_screen(t_all *xlm)
{
	int	swap;

	mlx_get_screen_size(xlm->mlx, &xlm->param.scr_width,\
	&xlm->param.scr_height);
	if (xlm->param.scr_width < xlm->param.width)
	{
		swap = xlm->param.scr_width;
		xlm->param.scr_width = xlm->param.width;
		xlm->param.width = swap;
		xlm->param.scr_swap_w = 1;
	}
	if (xlm->param.scr_height < xlm->param.height)
	{
		swap = xlm->param.scr_height;
		xlm->param.scr_height = xlm->param.height;
		xlm->param.height = swap;
		xlm->param.scr_swap_h = 1;
	}
}
