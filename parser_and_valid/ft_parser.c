//
// Created by Daisey Patrica on 12/6/20.
//

#include "../includes/cub3d.h"

static char		*strjoiner(short int *valid, char *super_map, char *map)
{
	char	*temp1;
	char	*temp2;

	if (ft_rhr(map, '&'))
	{
		*valid = MAP_TRASH_ERROR;
		return (freesher(map, super_map, NULL));
	}
	temp1 = super_map;
	if ((temp2 = ft_strjoin("&", map)) == NULL)
	{
		*valid = MALLOC_MAP_ERROR;
		return (freesher(map, super_map, NULL));
	}
	if ((super_map = ft_strjoin(super_map, temp2)) == NULL)
	{
		*valid = MALLOC_MAP_ERROR;
		return (freesher(map, temp1, temp2));
	}
	freesher(map, temp1, temp2);
	return (super_map);
}

static t_map	ft_parsm(t_map param, int fd, char *map)
{
	short int	i;
	char		*super_map;

	if ((super_map = ft_strdup(map)) == NULL)
	{
		param.valid = MALLOC_MAP_ERROR;
		free(map);
		return (param);
	}
	free(map);
	while ((i = get_next_line(fd, &map)) >= 0)
	{
		if (!*map && i == 1 && (param.valid = MAP_EMPTY_LINE_ERROR))
			break ;
		if ((super_map = strjoiner(&param.valid, super_map, map)) == NULL)
			return (param);
		if (i == 0)
			break ;
	}
	param.valid = (i == -1) ? GNL_ERROR : param.valid;
	if ((!param.valid) && ((param.g_map = ft_split(super_map, '&')) == NULL))
		param.valid = MALLOC_MAP_ERROR;
	free(super_map);
	return (param);
}

static t_map	ft_check_and_parsm(t_map param, int fd, char *map)
{
	if (!param.no || !param.so || !param.we || !param.ea || !param.s ||\
	!param.width || !param.height || !param.f.flag || !param.c.flag)
	{
		param.valid = NO_PARAM_ERROR;
		free(map);
	}
	else if (!ft_rhr(map, '&'))
		param = ft_parsm(param, fd, map);
	else
	{
		param.valid = MAP_TRASH_ERROR;
		free(map);
	}
	return (param);
}

static t_map	ft_parsf(t_map param, char *map)
{
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
	int			fd;
	short int	i;
	int			j;

	if (((fd = open(map, O_RDONLY)) < 0) && (param.valid = MAP_OPEN_ERROR))
		return (param);
	while ((i = get_next_line(fd, &map)) >= 0)
	{
		j = drop_space(&map);
		if (*map && *map != '1')
			param = ft_parsf(param, map);
		else if ((*map == '1') && (i == 1))
		{
			param = ft_check_and_parsm(param, fd, map - j);
			break ;
		}
		free(map - j);
		if (param.valid)
			break ;
		if ((i == 0) && (param.valid = NO_MAP_ERROR))
			break ;
	}
	close(fd);
	param.valid = (i == -1) ? GNL_ERROR : param.valid;
	return (param);
}
