/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:23:08 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:23:08 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_aim(t_all *xlm)
{
	int x;
	int y;
	int i;

	i = 10;
	x = (xlm->param.width / 2) - 5;
	y = (xlm->param.height / 2);
	while (i--)
		my_pixel_put(xlm, x++, y, 0xFF0000);
	i = 10;
	x = (xlm->param.width / 2);
	y -= 5;
	while (i--)
		my_pixel_put(xlm, x, y++, 0xFF0000);
}

void	ft_draw_square(t_all *xlm, double x, double y, int color)
{
	double	start_x;
	double	start_y;

	start_x = x;
	start_y = y;
	while (y < (SQUARE_Y + start_y))
	{
		x = start_x;
		while (x < (SQUARE_X + start_x))
			my_pixel_put(xlm, (int)x++, (int)y, color);
		y++;
	}
}

void	ft_draw_line(t_all *xlm, int x)
{
	int y;
	int draw_down;

	draw_down = xlm->neo.draw_down;
	y = 0;
	if (xlm->neo.draw_up <= xlm->neo.draw_down)
	{
		while (y < xlm->neo.draw_up)
			my_pixel_put(xlm, x, y++, xlm->param.c.rgb);
		while (draw_down < (xlm->param.height - 1))
			my_pixel_put(xlm, x, draw_down++, xlm->param.f.rgb);
	}
}

void	ft_draw_stdcf(t_all *xlm)
{
	int x;
	int y;
	int end;

	end = (int)((double)xlm->param.height / xlm->move.mouse_cam);
	x = -1;
	while (++x < (xlm->param.width - 1) && !(y = 0))
		while (y < end)
			my_pixel_put(xlm, x, y++, xlm->param.c.rgb);
	x = -1;
	while (++x < (xlm->param.width - 1) && (y = end))
		while (y < (xlm->param.height - 1))
			my_pixel_put(xlm, x, y++, xlm->param.f.rgb);
}
