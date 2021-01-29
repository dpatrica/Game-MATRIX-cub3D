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

void	my_pixel_put(t_all *xlm, int x, int y, int color)
{
	char *dst;

	if (color != 0)
	{
		dst = xlm->img.adr + (y * xlm->img.line_len + x * (xlm->img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

/*void 	chek_screen(t_all *xlm)
{
	int	swap;

	mlx_get_screen_size(xlm->mlx, &xlm->param.scr_width, &xlm->param.scr_height);
	if (xlm->param.scr_width < xlm->param.width)
	{
		swap = xlm->param.scr_width;
		xlm->param.scr_width = xlm->param.width;
		xlm->param.width = swap;
		xlm->param.scr_swap_w = 1;
	}
	if (xlm->param.scr_height < xlm->param.height)
	{
		swap = xlm->param.scr_height;
		xlm->param.scr_height = xlm->param.height;
		xlm->param.height = swap;
		xlm->param.scr_swap_h = 1;
	}
}*/

/*int 	mouse(int x, int y, t_all *xlm)
{
	if (x > (X / 2))
	{
		xlm->move.l_m_rot = x - (X / 2);
		xlm->move.r_m_rot = 1;
	}
	if (x > (X / 2))
	{
		xlm->move.r_m_rot = (X / 2) - x;
		xlm->move.l_m_rot = 1;
	}
//	if (y != (Y / 2))
//	{
//		xlm->move.mouse_cam = (y - (Y / 2));
//	}
	return (0);
}*/

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

/*int		ft_render(t_all *xlm)
{
	mlx_hook(xlm->win, 2, 0, &key_press, &xlm);
	mlx_hook(xlm->win, 3, 0, &key_release, &xlm);
	return (0);
}*/

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
