//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

t_map	ft_fornull(t_map param)
{
	param.valid = 0;
	param.width = 0;
	param.height = 0;
	param.no = NULL;
	param.so = NULL;
	param.we = NULL;
	param.ea = NULL;
	param.s = NULL;
	param.f.r = -1;
	param.f.g = -1;
	param.f.b = -1;
	param.f.flag = 0;
	param.c.r = -1;
	param.c.g = -1;
	param.c.b = -1;
	param.c.flag = 0;
	param.save = 0;
	param.type = 0;
	param.temp = 0;
	return (param);
}

int	drop_space(char **map)
{
	int	i;

	i = 0;
	while (**map == ' ')
		(*map)++;
	return(i);
}
