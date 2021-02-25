//
// Created by Daisey Patrica on 12/9/20.
//

#include "../includes/cub3d.h"

t_map	ft_pars_reso(t_map param, char *map)
{
	if (!param.width && !param.height)
	{
		drop_space(&map);
		map += ft_mpldig(*map) ? ft_digitlen(param.width = ft_atoi(map)) : 0;
		while (ft_isdigit(*map))
			map++;
		drop_space(&map);
		map += ft_mpldig(*map) ? ft_digitlen(param.height = ft_atoi(map)) : 0;
		while (ft_isdigit(*map))
			map++;
		drop_space(&map);
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
	if (!param.f.flag)
	{
		drop_space(&map);
		map += ft_isdigit(*map) ? ft_digitlen(param.f.r = ft_atoi(map)) : 0;
		drop_space(&map);
		map += *map == ',' ? 1 : 0;
		drop_space(&map);
		map += ft_isdigit(*map) ? ft_digitlen(param.f.g = ft_atoi(map)) : 0;
		drop_space(&map);
		map += *map == ',' ? 1 : 0;
		drop_space(&map);
		map += ft_isdigit(*map) ? ft_digitlen(param.f.b = ft_atoi(map)) : 0;
		drop_space(&map);
		if (*map)
			param.valid = MAP_TRASH_FRGB_ERROR;
		else if (param.f.r < 0 || param.f.r > 255 || param.f.g < 0 ||\
		param.f.g > 255 || param.f.b < 0 || param.f.b > 255)
			param.valid = FRGB_NO_VALID_ERROR;
		param.f.flag = 1;
	}
	else
		param.valid = DOUBLE_FRGB_ERROR;
	if (!param.valid)
		param.f.rgb = rgb_color(param.f.r, param.f.g, param.f.b);
	return (param);
}

t_map	ft_pars_crgb(t_map param, char *map)
{
	if (!param.c.flag)
	{
		drop_space(&map);
		map += ft_isdigit(*map) ? ft_digitlen(param.c.r = ft_atoi(map)) : 0;
		drop_space(&map);
		map += *map == ',' ? 1 : 0;
		drop_space(&map);
		map += ft_isdigit(*map) ? ft_digitlen(param.c.g = ft_atoi(map)) : 0;
		drop_space(&map);
		map += *map == ',' ? 1 : 0;
		drop_space(&map);
		map += ft_isdigit(*map) ? ft_digitlen(param.c.b = ft_atoi(map)) : 0;
		drop_space(&map);
		if (*map)
			param.valid = MAP_TRASH_CRGB_ERROR;
		else if (param.c.r < 0 || param.c.r > 255 || param.c.g < 0 ||\
		param.c.g > 255 || param.c.b < 0 || param.c.b > 255)
			param.valid = CRGB_NO_VALID_ERROR;
		param.c.flag = 1;
	}
	else
		param.valid = DOUBLE_CRGB_ERROR;
	if (!param.valid)
		param.c.rgb = rgb_color(param.c.r, param.c.g, param.c.b);
	return (param);
}
