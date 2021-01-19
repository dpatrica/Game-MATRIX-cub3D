//
// Created by Daisey Patrica on 12/8/20.
//

#include "../includes/cub3d.h"

int		drop_space(char **map)
{
	int	i;

	i = 0;
	while ((**map == ' ') && (++i))
		(*map)++;
	return(i);
}

char	*freesher(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (NULL);
}

int		rgb_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	sprite_len(t_all *xlm)
{
	int i;
	int j;

	i = -1;
	while (xlm->param.g_map[++i] && !(j = 0))
		while (xlm->param.g_map[i][j])
			if (xlm->param.g_map[i][j++] == '2')
				xlm->sprite.spr_len++;
	if (xlm->sprite.spr_len)
	{
		if (!(xlm->sprite.wid_buf = malloc(xlm->param.width * sizeof(double))))
			exit(0);
		if (!(xlm->sprite.spr = malloc(xlm->sprite.spr_len * sizeof(int))))
			exit(0);
		if (!(xlm->sprite.spr_dist = malloc(xlm->sprite.spr_len * sizeof(double))))
			exit(0);
		if (!(xlm->sprite.pos = malloc(xlm->sprite.spr_len * sizeof(t_pos))))
			exit(0);
		i = -1;
		xlm->sprite.spr_len = 0;
		while (xlm->param.g_map[++i] && (j = -1))
			while (xlm->param.g_map[i][++j])
				if (xlm->param.g_map[i][j] == '2')
				{
					xlm->sprite.pos[xlm->sprite.spr_len].x = j + 0.5;
					xlm->sprite.pos[xlm->sprite.spr_len].y = i + 0.5;
					xlm->sprite.spr_len++;
				}
	}
}

/*void	save_player(t_all *xlm)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (xlm->param.g_map[y] && xlm->param.g_map[y][x])
	{
		while (xlm->param.g_map[y][x])
		{
			if (ft_rhr("NSWE", xlm->param.g_map[y][x]))
			{
				xlm->player.dir = xlm->param.g_map[y][x];
				X = x;
				Y = y;
				dir_cos_sin(xlm);
				return ;
			}
			x++;
		}
		y++;
		x = 0;
	}
}*/

/*void	dir_cos_sin(t_all *xlm)
{
	if (xlm->player.dir == 'N')
	{
		xlm->player.dir_x = cos(M_PI / 2);
		xlm->player.dir_y = sin((3 * M_PI) / 2);
		xlm->player.plan_x = 0.66;
		xlm->player.plan_y = 0;
//		xlm->player.dir_x = 0;
//		xlm->player.dir_y = -1;
//		xlm->player.dir_y = sin(M_PI / 2);
	}
	else if (xlm->player.dir == 'W')
	{
		xlm->player.dir_x = cos(M_PI);
		xlm->player.dir_y = sin(M_PI);
		xlm->player.plan_x = 0;
		xlm->player.plan_y = -0.66;
	}
	else if (xlm->player.dir == 'S')
	{
		xlm->player.dir_x = cos((3 * M_PI) / 2);
		xlm->player.dir_y = sin(M_PI / 2);
		xlm->player.plan_x = -0.66;
		xlm->player.plan_y = 0;
//		xlm->player.dir_y = sin((3 * M_PI) / 2);
	}
	else if (xlm->player.dir == 'E')
	{
		xlm->player.dir_x = cos(2 * M_PI);
		xlm->player.dir_y = sin(0);
		xlm->player.plan_x = 0;
		xlm->player.plan_y = 0.66;
	}
}*/

int		ft_render(t_all *xlm)
{
	mlx_hook(xlm->win, 2, 0, &key_press, &xlm);
	mlx_hook(xlm->win, 3, 0, &key_release, &xlm);
	return (0);
}

/*
int		key_hook(t_all *xlm)
{
	xlm->param.g_map[(int)Y][(int)X] = '0';
	if (xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)(Y - SPEED)][(int)X]) != '1')
		Y -= SPEED;
	if (xlm->move.down == 1 &&\
	(xlm->param.g_map[(int)(Y + SPEED)][(int)X]) != '1')
		Y += SPEED;
	if (xlm->move.right == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X + SPEED)]) != '1')
		X += SPEED;
	if (xlm->move.left == 1 &&\
	(xlm->param.g_map[(int)Y][(int)(X - SPEED)]) != '1')
		X -= SPEED;
	xlm->param.g_map[(int)Y][(int)X] = 'N';
	mlx_clear_window(xlm->mlx, xlm->win);
	ft_drow_map(xlm, START_X, START_Y);
	return (0);
}

int		key_press(int key, t_all *xlm)
{
	if (key == 13 || key == 126)
		xlm->move.up = 1;
	if (key == 1 || key == 125)
		xlm->move.down = 1;
	if (key == 2 || key == 124)
		xlm->move.right = 1;
	if (key == 0 || key == 123)
		xlm->move.left = 1;
	return (0);
}

int		key_release(int key, t_all *xlm)
{
	if (key == 13 || key == 126)
		xlm->move.up = 0;
	if (key == 1 || key == 125)
		xlm->move.down = 0;
	if (key == 2 || key == 124)
		xlm->move.right = 0;
	if (key == 0 || key == 123)
		xlm->move.left = 0;
	return (0);
}
*/
