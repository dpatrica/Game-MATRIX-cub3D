//
// Created by Daisey Patrica on 2/20/21.
//

#include "../includes/cub3d.h"

static int	count_timer_and_atack(t_all *xlm, char dir, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].timer > 0)
		xlm->sprite.pos[xlm->sprite.spr[i]].timer--;
	else
	{
		if (xlm->player.ammo > 0)
		{
			xlm->player.ammo -= 3;
			xlm->player.hp--;
			if (xlm->player.ammo < 0)
				xlm->player.ammo = 0;
			xlm->sprite.pos[xlm->sprite.spr[i]].timer = 100000;
		}
		else
		{
			xlm->player.hp -= 5;
			if (xlm->player.hp < 0)
				xlm->player.hp = 0;
			xlm->sprite.pos[xlm->sprite.spr[i]].timer = 100000;
		}
		xlm->sprite.pos[xlm->sprite.spr[i]].dir = (int)dir;
		ft_draw_sprite(xlm, 0, 0, -1);
		return (0);
	}
	return (1);
}

static void	move_sprite(t_all *xlm, int i)
{
	xlm->param.g_map[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].y)]\
	[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].x)] = '0';
	if (xlm->sprite.spr_x > 0 && !ft_rhr("13457Vv",\
	xlm->param.g_map[(int)xlm->sprite.pos[xlm->sprite.spr[i]].y]\
	[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].x - 1.1)]))
		xlm->sprite.pos[xlm->sprite.spr[i]].x -= 0.00007;
	else if (xlm->sprite.spr_x <= 0 && !ft_rhr("13457Vv",\
	xlm->param.g_map[(int)xlm->sprite.pos[xlm->sprite.spr[i]].y]\
	[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].x + 1.1)]))
		xlm->sprite.pos[xlm->sprite.spr[i]].x += 0.00007;
	if (xlm->sprite.spr_y > 0 && !ft_rhr("13457Vv",\
	xlm->param.g_map[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].y - 1.1)]\
	[(int)xlm->sprite.pos[xlm->sprite.spr[i]].x]))
		xlm->sprite.pos[xlm->sprite.spr[i]].y -= 0.00007;
	else if (xlm->sprite.spr_y <= 0 && !ft_rhr("13457Vv",\
	xlm->param.g_map[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].y + 1.1)]\
	[(int)xlm->sprite.pos[xlm->sprite.spr[i]].x]))
		xlm->sprite.pos[xlm->sprite.spr[i]].y += 0.00007;
	xlm->param.g_map[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].y)]\
	[(int)(xlm->sprite.pos[xlm->sprite.spr[i]].x)] = 'V';
}

int			ft_move_atack_sprite(t_all *xlm, int color, int i)
{
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'V' && color >= 0)
	{
		if (xlm->sprite.spr_dist[xlm->sprite.spr[i]] > 200)
			move_sprite(xlm, i);
		else
			if (!count_timer_and_atack(xlm, 'v', i))
				return (0);
	}
	if (xlm->sprite.pos[xlm->sprite.spr[i]].dir == 'G' && color >= 0)
		if (!count_timer_and_atack(xlm, 'g', i))
			return (0);
	return (1);
}
