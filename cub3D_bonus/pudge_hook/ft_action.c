/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:24:37 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:24:37 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_action_4(t_all *xlm)
{
	if (xlm->param.g_map[(int)Y][(int)X] == 'Z')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.super_stvol = 1;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'A' && xlm->player.ammo < 100)
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.ammo += 10;
		if (xlm->player.ammo > 100)
			xlm->player.ammo = 100;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	if (xlm->flag && xlm->param.g_map[(int)Y][(int)X] == '6')
	{
		xlm->param.g_map[(int)Y + 1][(int)X] = '5';
		xlm->flag = 0;
	}
	if (xlm->flag && xlm->param.g_map[(int)Y][(int)X] == 'B')
		Y -= 1;
}

static void	ft_action_3(t_all *xlm)
{
	if (xlm->param.g_map[(int)Y][(int)X] == 'C')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.cartridges += 30;
		play_music(3);
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'D' && (xlm->player.digl = 1))
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	if (xlm->param.g_map[(int)Y][(int)X] == '8')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.hp -= 10;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	ft_action_4(xlm);
}

static void	ft_action_2(t_all *xlm)
{
	if (xlm->param.g_map[(int)Y][(int)X] == 'M')
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.map = 1;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'H' && xlm->player.hp < 100)
	{
		xlm->param.g_map[(int)Y][(int)X] = '0';
		xlm->player.hp += 10;
		if (xlm->player.hp > 100)
			xlm->player.hp = 100;
		xlm->action.kill = xlm->sprite.spr[xlm->sprite.spr_len - 1];
		sprite_check(xlm);
		xlm->action.kill = -1;
	}
	ft_action_3(xlm);
}

void		ft_action(t_all *xlm)
{
	char *map;

	if (xlm->param.g_map[(int)Y][(int)X] == 'P')
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, VALID);
		write(1, "lvl UP!\n", 8);
		map = "./maps/map3.cub";
		cub3d(2, &map, 2);
		exit(0);
	}
	if (xlm->param.g_map[(int)Y][(int)X] == 'X')
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, VALID);
		write(1, "lvl UP!\n", 8);
		map = "./maps/map2.cub";
		cub3d(2, &map, 1);
		exit(0);
	}
	ft_action_2(xlm);
}

void		play_music(int music_key)
{
	if (!music_key)
		system("afplay ./cub3D_bonus/music/RobDougan_Clubbed_to_death.mp3 &");
	else if (music_key == 1)
		system("afplay ./cub3D_bonus/music/vistrel.mp3 &");
	else if (music_key == 2)
		system("afplay ./cub3D_bonus/music/holostoi.mp3 &");
	else if (music_key == 3)
		system("afplay ./cub3D_bonus/music/podobral.mp3 &");
}
