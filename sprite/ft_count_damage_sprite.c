//
// Created by Daisey Patrica on 2/18/21.
//

#include "../includes/cub3d.h"

static int	thx_norminette(t_all *xlm, i)
{
	xlm->sprite.pos[xlm->sprite.spr[i]].dir = 'i';
	xlm->action.damage = 0;
	ft_draw_sprite(xlm);
	return (0);
}

int	ft_count_damage_weapon(t_all *xlm, int i)
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
			ft_draw_sprite(xlm);
			return (0);
		}
		xlm->action.damage = 0;
	}
	else if (ft_rhr("G", xlm->sprite.pos[xlm->sprite.spr[i]].dir) &&\
	xlm->move.rpm && xlm->action.damage > 0 && xlm->player.cartridges)
		return (thx_norminette(xlm, i));
	return (1);
}