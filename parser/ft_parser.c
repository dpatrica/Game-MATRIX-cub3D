//
// Created by Daisey Patrica on 12/6/20.
//

#include "../includes/cub3d.h"

static t_map	ft_parsf(t_map param, char *map)
{
	drop_space(&map);
	if (*map)
	{
		if (!ft_strncmp(map, "R ", 2))
			param = ft_pars_reso(param, map + 2);
		else if (!ft_strncmp(map, "NO ", 3))
			param = ft_pars_no(param, map + 3);
		else if (!ft_strncmp(map, "SO ", 3))
			param = ft_pars_so(param, map + 3);
		else if (!ft_strncmp(map, "WE ", 3))
			param = ft_pars_we(param, map + 3);
		else if (!ft_strncmp(map, "EA ", 3))
			param = ft_pars_ea(param, map + 3);
		else if (!ft_strncmp(map, "S ", 2))
			param = ft_pars_s(param, map + 2);
		else if (!ft_strncmp(map, "F ", 2))
			param = ft_pars_frgb(param, map + 2);
		else if (!ft_strncmp(map, "C ", 2))
			param = ft_pars_crgb(param, map + 2);
		else
			param.valid = MAP_TRASH_ERROR;
	}
	return (param);
}

t_map			ft_parser(t_map param, char *map)
{
	int		fd;

	if ((open(map, fd, O_RDONLY) < 0) && (param.valid = MAP_OPEN_ERROR))
		return (param);
	while (get_next_line(fd, &map) >= 0) // FIXME ЗАФРИШЬ ЕСЛИ ВЫЙДЕТ -1 ! ! !
	{
		if (*map)
			param = ft_parsf(param, map);
		free(map);
		if (param.valid) // FIXME ЗАФРИШЬ СТРУКТУРУ ! ! !
			return (param);
	}
	return (param);
}
