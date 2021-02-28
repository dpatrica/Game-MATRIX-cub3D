/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_cefl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:01:04 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:01:38 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	draw_floor(t_all *xlm, int y)
{
	xlm->neo.rdir_x = xlm->player.dir_x - xlm->player.plan_x;
	xlm->neo.rdir_y = xlm->player.dir_y - xlm->player.plan_y;
	xlm->neo.rdir2_x = xlm->player.dir_x + xlm->player.plan_x;
	xlm->neo.rdir2_y = xlm->player.dir_y + xlm->player.plan_y;
	xlm->neo.z_pos = 0.5 * xlm->param.height;
	xlm->neo.dist_row =\
	xlm->neo.z_pos / (y - xlm->param.height / xlm->move.mouse_cam);
	xlm->neo.f_step_x =\
	xlm->neo.dist_row * (xlm->neo.rdir2_x - xlm->neo.rdir_x) / xlm->param.width;
	xlm->neo.f_step_y =\
	xlm->neo.dist_row * (xlm->neo.rdir2_y - xlm->neo.rdir_y) / xlm->param.width;
	xlm->neo.floor_x = X + xlm->neo.dist_row * xlm->neo.rdir_x;
	xlm->neo.floor_y = Y + xlm->neo.dist_row * xlm->neo.rdir_y;
	return (0);
}

static int	draw_floor_2(t_all *xlm, int x, int y)
{
	int				x_t;
	int				y_t;
	unsigned int	*color;

	xlm->neo.celling_x = (int)xlm->neo.floor_x;
	xlm->neo.celling_y = (int)xlm->neo.floor_y;
	x_t = (int)(xlm->tex.skybox.width *\
	(xlm->neo.floor_x - xlm->neo.celling_x)) & (xlm->tex.skybox.width - 1);
	y_t = (int)(xlm->tex.skybox.height *\
	(xlm->neo.floor_y - xlm->neo.celling_y)) & (xlm->tex.skybox.height - 1);
	xlm->neo.floor_x += xlm->neo.f_step_x;
	xlm->neo.floor_y += xlm->neo.f_step_y;
	color = (unsigned int*)\
	(xlm->tex.skybox.adr + xlm->tex.skybox.line_len * y_t + x_t *\
	(xlm->tex.skybox.bpp / 8));
	my_pixel_put(xlm, x, y, (int)*color);
	return (1);
}

static int	draw_ceiling(t_all *xlm, int y)
{
	xlm->neo.rdir_x = xlm->player.dir_x - xlm->player.plan_x;
	xlm->neo.rdir_y = xlm->player.dir_y - xlm->player.plan_y;
	xlm->neo.rdir2_x = xlm->player.dir_x + xlm->player.plan_x;
	xlm->neo.rdir2_y = xlm->player.dir_y + xlm->player.plan_y;
	xlm->neo.z_pos = xlm->param.height / xlm->move.mouse_cam;
	xlm->neo.dist_row = xlm->neo.z_pos / (y * xlm->move.mouse_cam);
	xlm->neo.f_step_x =\
	xlm->neo.dist_row * (xlm->neo.rdir2_x - xlm->neo.rdir_x) / xlm->param.width;
	xlm->neo.f_step_y =\
	xlm->neo.dist_row * (xlm->neo.rdir2_y - xlm->neo.rdir_y) / xlm->param.width;
	xlm->neo.floor_x = xlm->xxx + xlm->neo.dist_row * xlm->neo.rdir_x;
	xlm->neo.floor_y = xlm->yyy + xlm->neo.dist_row * xlm->neo.rdir_y;
	return (0);
}

static int	draw_ceiling_2(t_all *xlm, int x, int y)
{
	int				x_t;
	int				y_t;
	unsigned int	*color;

	xlm->neo.celling_x = (int)xlm->neo.floor_x;
	xlm->neo.celling_y = (int)xlm->neo.floor_y;
	x_t = (int)(xlm->tex.skybox.width * (xlm->neo.floor_x -\
	xlm->neo.celling_x)) & (xlm->tex.skybox.width - 1);
	y_t = (int)(xlm->tex.skybox.height * (xlm->neo.floor_y -\
	xlm->neo.celling_y)) & (xlm->tex.skybox.height - 1);
	xlm->neo.floor_x += xlm->neo.f_step_x;
	xlm->neo.floor_y += xlm->neo.f_step_y;
	color = (unsigned int*)(xlm->tex.skybox.adr + xlm->tex.skybox.line_len *\
	y_t + x_t * (xlm->tex.skybox.bpp / 8));
	my_pixel_put(xlm, x, y, (int)*color);
	return (1);
}

void		ft_draw_cefl(t_all *xlm)
{
	int		y;
	int		x;

	y = xlm->param.height / xlm->move.mouse_cam + 1;
	while (y < (xlm->param.height - 1))
	{
		x = draw_floor(xlm, y);
		while (x < (xlm->param.width - 1))
			x += draw_floor_2(xlm, x, y);
		y++;
	}
	y = 0;
	while (y < (xlm->param.height / xlm->move.mouse_cam - 1))
	{
		x = draw_ceiling(xlm, y);
		while (x < (xlm->param.width - 1))
			x += draw_ceiling_2(xlm, x, y);
		y++;
	}
}
