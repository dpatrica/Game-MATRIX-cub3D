//
// Created by Daisey Patrica on 1/28/21.
//

#include "../includes/cub3d.h"

static void	sprite_malloc(t_all *xlm)
{
	if (!(xlm->sprite.wid_buf = malloc(xlm->param.width * sizeof(double))))
	{
		ft_error(xlm, SPR_MALLOC_ERROR);
		exit(0);
	}
	if (!(xlm->sprite.spr = malloc(xlm->sprite.spr_len * sizeof(int))))
	{
		ft_error(xlm, SPR_MALLOC_ERROR);
		exit(0);
	}
	if (!(xlm->sprite.spr_dist = malloc(xlm->sprite.spr_len * sizeof(double))))
	{
		ft_error(xlm, SPR_MALLOC_ERROR);
		exit(0);
	}
	if (!(xlm->sprite.pos = malloc(xlm->sprite.spr_len * sizeof(t_pos))))
	{
		ft_error(xlm, SPR_MALLOC_ERROR);
		exit(0);
	}
	xlm->sprite.flag_spr_len = 1;
}

static void	sprite_init(t_all *xlm)
{
	int i;

	i = -1;
	while (++i < xlm->sprite.spr_len)
	{
		xlm->sprite.pos[i].hp = 10000;
		if (xlm->sprite.pos[i].dir == '2')
			xlm->sprite.pos[i].hp = 5;
	}
}

void		sprite_len(t_all *xlm)
{
	int i;
	int j;

	i = -1;
	while (xlm->param.g_map[++i] && !(j = 0))
		while (xlm->param.g_map[i][j])
			if (ft_rhr("2MYPXHDZ", xlm->param.g_map[i][j++])) // 2 - обычный спрайт / M - мапа / Y - Морфиус / P - синяя пилюля / X - красная пилюля / H - ХП / A - патроны / D - дигл / Z - суперствол
				xlm->sprite.spr_len++;
	if (xlm->sprite.spr_len)
	{
		!xlm->sprite.flag_spr_len ? sprite_malloc(xlm) : 0;
		i = -1;
		xlm->sprite.spr_len = 0;
		while (xlm->param.g_map[++i] && (j = -1))
			while (xlm->param.g_map[i][++j])
				if (ft_rhr("2MYPXHDZ", xlm->param.g_map[i][j]))
				{
					xlm->sprite.pos[xlm->sprite.spr_len].dir =\
					(int)xlm->param.g_map[i][j];
					xlm->sprite.pos[xlm->sprite.spr_len].x = j + 0.5;
					xlm->sprite.pos[xlm->sprite.spr_len].y = i + 0.5;
					xlm->sprite.spr_len++;
				}
		sprite_init(xlm);
	}
}

void		sprite_sort(t_all *xlm)
{
	int	i;
	int	j;

	i = -1;
	while (++i < xlm->sprite.spr_len)
	{
		xlm->sprite.spr[i] = i;
		xlm->sprite.spr_dist[i] = pow(X - xlm->sprite.pos[i].x, 2) + pow(Y - xlm->sprite.pos[i].y, 2);
	}
	i = -1;
	while (++i < (xlm->sprite.spr_len - 1))
	{
		if (xlm->sprite.spr_dist[xlm->sprite.spr[i]] < xlm->sprite.spr_dist[xlm->sprite.spr[i + 1]])
		{
			j = xlm->sprite.spr[i];
			xlm->sprite.spr[i] = xlm->sprite.spr[i + 1];
			xlm->sprite.spr[i + 1] = j;
			i = -1;
		}
	}
}