//
// Created by Daisey Patrica on 12/6/20.
//

#include "../includes/cub3d.h"

static t_map	ft_pars1(t_map param, char *map, short int flag)
{
	if (flag == 1)
	{
		if (!param.width && !param.height)
		{
			while (*map == ' ')
				map++;
			map += *map ? ft_digitlen(param.width = ft_atoi(map)) : 0;
			while (*map == ' ')
				map++;
			map += *map ? ft_digitlen(param.height = ft_atoi(map)) : 0;
			while (*map == ' ')
				map++;
			if ((*map) && (param.valid = MAP_TRASH_ERROR))
				return (param);
		}
		else
			param.valid = DOUBLE_RESO_ERROR;
	}
	return (param);
}

static t_map	ft_parsf(t_map param, char *map)
{
	if (!ft_strncmp(map, "R ", 2))
		param = ft_pars_reso(param, map + 2);
	else if (!ft_strncmp(map, "NO ", 3))
		param = ft_pars1(param, map + 3, 2);
	else if (!ft_strncmp(map, "SO ", 3))
		param = ft_pars1(param, map + 3, 3);
	else if (!ft_strncmp(map, "WE ", 3))
		param = ft_pars1(param, map + 3, 4);
	else if (!ft_strncmp(map, "EA ", 3))
		param = ft_pars1(param, map + 3, 5);
	else if (!ft_strncmp(map, "S ", 2))
		param = ft_pars1(param, map + 2, 6);
	else if (!ft_strncmp(map, "F ", 2))
		param = ft_pars1(param, map + 2, 7);
	else if (!ft_strncmp(map, "C ", 2))
		param = ft_pars1(param, map + 2, 8);
	else
		param.valid = MAP_TRASH_ERROR;
	return (param);
}

t_map			ft_parser(t_map param, char *map)
{
	int		fd;
	int		i;

	if ((open(map, fd, O_RDONLY) < 0) && (param.valid = MAP_OPEN_ERROR))
		return (param);
	i = 0;
	while (get_next_line(fd, &map) >= 0)
	{
		while (map[i] == ' ')
			i++;
		if (map[i])
			param = ft_parsf(param, &map[i]);
		free(map);
		if (param.valid)
			return (param);
	}
	return (param);
}
