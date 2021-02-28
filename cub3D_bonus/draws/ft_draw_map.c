/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:22:41 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:22:42 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_select_color(t_all *xlm, int x, int y)
{
	if (ft_rhr("137", xlm->param.g_map[y][x]))
		ft_draw_square(xlm, xlm->map.x_print, xlm->map.y_print, 0x023203);
	else if (ft_rhr("2089QNSWEAMHCDZVvGgi", xlm->param.g_map[y][x]))
		ft_draw_square(xlm, xlm->map.x_print, xlm->map.y_print, 0xFFFFFF);
	else if (ft_rhr("Y", xlm->param.g_map[y][x]))
		ft_draw_square(xlm, xlm->map.x_print, xlm->map.y_print, 0x9400D3);
	xlm->map.x_print += SQUARE_X;
	return (1);
}

void		ft_draw_map(t_all *xlm)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	xlm->map.y_print = START_Y;
	while (xlm->param.g_map[y] && xlm->param.g_map[y][x])
	{
		xlm->map.x_print = START_X;
		while (xlm->param.g_map[y][x])
			x += ft_select_color(xlm, x, y);
		xlm->map.y_print += SQUARE_Y;
		y++;
		x = 0;
	}
	ft_draw_square(xlm, START_X + (X * SQUARE_X) - (SQUARE_X / 2),\
	START_Y + (Y * SQUARE_Y) - (SQUARE_Y / 2), 0xFF0000);
}
