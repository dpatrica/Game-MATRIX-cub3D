/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_damage_sprite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:25:10 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:25:10 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	thx_norminette(t_all *xlm, int i)
{
	xlm->sprite.pos[xlm->sprite.spr[i]].dir = 'i';
	xlm->action.damage = 0;
	ft_draw_sprite(xlm, 0, 0, -1);
	return (0);
}

int			ft_count_damage_weapon(t_all *xlm, int i)
{
	if (!ft_rhr("Gg", xlm->sprite.pos[xlm->sprite.spr[i]].dir) &&\
	xlm->move.rpm && xlm->action.damage > 0 && xlm->player.cartridges)
	{
		xlm->sprite.pos[xlm->sprite.spr[i]].hp -= xlm->action.damage;
		if (xlm->sprite.pos[xlm->sprite.spr[i]].hp <= 0)
		{
			xlm->param.g_map[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].y)]\
			[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].x)] = '0';
			xlm->sprite.pos[xlm->sprite.spr[i]].dir = '0';
			xlm->action.kill = xlm->sprite.spr[i];
			sprite_check(xlm);
			xlm->action.kill = -1;
			xlm->action.damage = 0;
			ft_draw_sprite(xlm, 0, 0, -1);
			return (0);
		}
		xlm->action.damage = 0;
	}
	else if (ft_rhr("G", xlm->sprite.pos[xlm->sprite.spr[i]].dir) &&\
	xlm->move.rpm && xlm->action.damage > 0 && xlm->player.cartridges)
		return (thx_norminette(xlm, i));
	return (1);
}

int			ft_count_damage_super_weapon(t_all *xlm, int i)
{
	xlm->sprite.pos[xlm->sprite.spr[i]].hp -= 0.005;
	if (xlm->sprite.pos[xlm->sprite.spr[i]].hp <= 0)
	{
		xlm->param.g_map[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].y)]\
		[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].x)] = '0';
		xlm->sprite.pos[xlm->sprite.spr[i]].dir = '0';
		xlm->action.kill = xlm->sprite.spr[i];
		sprite_check(xlm);
		xlm->action.kill = -1;
		ft_draw_sprite(xlm, 0, 0, -1);
		return (0);
	}
	return (1);
}
