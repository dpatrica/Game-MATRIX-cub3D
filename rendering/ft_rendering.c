/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:04:35 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:04:35 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_render(t_all *xlm)
{
	ft_draw_stdcf(xlm);
	ft_draw_tex(xlm);
	if (xlm->sprite.spr_len)
	{
		sprite_sort(xlm);
		ft_draw_sprite(xlm, 0, 0, -1);
	}
}
