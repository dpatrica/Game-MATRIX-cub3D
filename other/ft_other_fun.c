//
// Created by Daisey Patrica on 12/8/20.
//

#include "../includes/cub3d.h"

t_all	ft_fornull(t_all xlm)
{
	xlm.win = NULL;
	xlm.mlx = NULL;
	xlm.param.valid = VALID;
	xlm.param.width = 0;
	xlm.param.height = 0;
	xlm.param.g_map = NULL;
	xlm.param.no = NULL;
	xlm.param.so = NULL;
	xlm.param.we = NULL;
	xlm.param.ea = NULL;
	xlm.param.s = NULL;
	xlm.param.f.r = -1;
	xlm.param.f.g = -1;
	xlm.param.f.b = -1;
	xlm.param.f.flag = 0;
	xlm.param.c.r = -1;
	xlm.param.c.g = -1;
	xlm.param.c.b = -1;
	xlm.param.c.flag = 0;
	xlm.param.save = 0;
	xlm.param.type = 0;
	xlm.param.temp1 = 0;
	xlm.param.temp2 = 0;
	return (xlm);
}

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

int				key_hook(int key, t_all *xlm)
{
	xlm->param.g_map[(int)Y][(int)X] = '0';
	if ((key == 13 || key == 126) &&\
	(xlm->param.g_map[(int)Y - 1][(int)X]) != '1')
		xlm->player.y--;
	if ((key == 1 || key == 125) &&\
	(xlm->param.g_map[(int)Y + 1][(int)X]) != '1')
		xlm->player.y++;
	if ((key == 2 || key == 124) &&\
	(xlm->param.g_map[(int)Y][(int)X + 1]) != '1')
		xlm->player.x++;
	if ((key == 0 || key == 123) &&\
	(xlm->param.g_map[(int)Y][(int)X - 1]) != '1')
		xlm->player.x--;
	xlm->param.g_map[(int)Y][(int)X] = 'N';
	mlx_clear_window(xlm->mlx, xlm->win);
	ft_drow(xlm);
}
