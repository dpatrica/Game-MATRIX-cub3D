//
// Created by Daisey Patrica on 12/10/20.
//

#include "../includes/cub3d.h"

t_map	ft_pars_no(t_map param, char *map)
{
	char	*temp;

	temp = NULL;
	if (!param.no)
	{
		drop_space(&map);
		if (*map)
			temp = ft_strchr(map, ' ');
		else if ((param.valid = NO_NORTH_ERROR))
			return (param);
		if (temp)
		{
			*temp++ = '\0';
			drop_space(&temp);
			if (*temp && (param.valid = MAP_TRASH_NORTH_ERROR))
				return (param);
		}
		if ((param.no = ft_strdup(map)) == NULL)
			param.valid = MALLOC_NORTH_ERROR;
	}
	else
		param.valid = DOUBLE_NORTH_ERROR;
	return (param);
}

t_map	ft_pars_so(t_map param, char *map)
{
	char	*temp;

	temp = NULL;
	if (!param.so)
	{
		drop_space(&map);
		if (*map)
			temp = ft_strchr(map, ' ');
		else if ((param.valid = NO_SOUTH_ERROR))
			return (param);
		if (temp)
		{
			*temp++ = '\0';
			drop_space(&temp);
			if (*temp && (param.valid = MAP_TRASH_SOUTH_ERROR))
				return (param);
		}
		if ((param.so = ft_strdup(map)) == NULL)
			param.valid = MALLOC_SOUTH_ERROR;
	}
	else
		param.valid = DOUBLE_SOUTH_ERROR;
	return (param);
}

t_map	ft_pars_we(t_map param, char *map)
{
	char	*temp;

	temp = NULL;
	if (!param.we)
	{
		drop_space(&map);
		if (*map)
			temp = ft_strchr(map, ' ');
		else if ((param.valid = NO_WEST_ERROR))
			return (param);
		if (temp)
		{
			*temp++ = '\0';
			drop_space(&temp);
			if (*temp && (param.valid = MAP_TRASH_WEST_ERROR))
				return (param);
		}
		if ((param.we = ft_strdup(map)) == NULL)
			param.valid = MALLOC_WEST_ERROR;
	}
	else
		param.valid = DOUBLE_WEST_ERROR;
	return (param);
}

t_map	ft_pars_ea(t_map param, char *map)
{
	char	*temp;

	temp = NULL;
	if (!param.ea)
	{
		drop_space(&map);
		if (*map)
			temp = ft_strchr(map, ' ');
		else if ((param.valid = NO_EAST_ERROR))
			return (param);
		if (temp)
		{
			*temp++ = '\0';
			drop_space(&temp);
			if (*temp && (param.valid = MAP_TRASH_EAST_ERROR))
				return (param);
		}
		if ((param.ea = ft_strdup(map)) == NULL)
			param.valid = MALLOC_EAST_ERROR;
	}
	else
		param.valid = DOUBLE_EAST_ERROR;
	return (param);
}

t_map	ft_pars_s(t_map param, char *map)
{
	char	*temp;

	temp = NULL;
	if (!param.s)
	{
		drop_space(&map);
		if (*map)
			temp = ft_strchr(map, ' ');
		else if ((param.valid = NO_SPRITE_ERROR))
			return (param);
		if (temp)
		{
			*temp++ = '\0';
			drop_space(&temp);
			if (*temp && (param.valid = MAP_TRASH_SPRITE_ERROR))
				return (param);
		}
		if ((param.s = ft_strdup(map)) == NULL)
			param.valid = MALLOC_SPRITE_ERROR;
	}
	else
		param.valid = DOUBLE_SPRITE_ERROR;
	return (param);
}
