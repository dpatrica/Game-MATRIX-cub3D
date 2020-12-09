//
// Created by Daisey Patrica on 12/9/20.
//

#include "../includes/cub3d.h"

t_map	ft_pars_reso(t_map param, char *map)
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
		if (*map)
			param.valid = MAP_TRASH_RESO_ERROR;
		else if (param.width <= 0 || param.height <= 0)
			param.valid = RESO_NO_VALID_ERROR;
	}
	else
		param.valid = DOUBLE_RESO_ERROR;
	return (param);
}

t_map	ft_pars_frgb(t_map param, char *map)
{
	if (!param.f.r && !param.f.g && !param.f.b)
	{

	}
	else
		param.valid = DOUBLE_FRGB_ERROR;
	return (param);
}
