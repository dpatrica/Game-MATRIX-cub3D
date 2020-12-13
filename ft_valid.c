//
// Created by Daisey Patrica on 12/11/20.
//

#include "./includes/cub3d.h"

static t_map	ft_validsym(t_map param, int i, int j)
{
	if (!param.g_map[i][j - 1] ||\
	!(ft_rhr("102NSWE", param.g_map[i][j - 1])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i][j + 1] || \
	!(ft_rhr("102NSWE", param.g_map[i][j + 1])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i - 1][j] || \
	!(ft_rhr("102NSWE", param.g_map[i - 1][j])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i + 1][j] || \
	!(ft_rhr("102NSWE", param.g_map[i + 1][j])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i - 1][j - 1] || \
	!(ft_rhr("102NSWE", param.g_map[i - 1][j - 1])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i - 1][j + 1] || \
	!(ft_rhr("102NSWE", param.g_map[i - 1][j + 1])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i + 1][j - 1] || \
	!(ft_rhr("102NSWE", param.g_map[i + 1][j - 1])))
		param.valid = MAP_NO_VALID;
	else if (!param.g_map[i + 1][j + 1] || \
	!(ft_rhr("102NSWE", param.g_map[i + 1][j + 1])))
		param.valid = MAP_NO_VALID;
	return (param);
}

static t_map	ft_validm(t_map param, int i, int j, int flag)
{
	while (param.g_map[i] && !param.valid)
	{
		while (param.g_map[i][j] == '1' || param.g_map[i][j] == ' ')
			j++;
		if (ft_rhr("02NSWE", param.g_map[i][j]))
		{
			if (!flag && (ft_rhr("NSWE", param.g_map[i][j])))
				flag = 1;
			else if (flag && (ft_rhr("NSWE", param.g_map[i][j])))
				param.valid = DOUBLE_PLAYER_ERROR;
			if (!param.valid)
				param = ft_validsym(param, i, j);
			if (param.valid)
				return (param);
			j++;
			continue ;
		}
		if (!param.g_map[i][j] && !(j = 0))
			i++;
		else
			param.valid = MAP_TRASH_ERROR;
	}
	param.valid = (!param.valid && !flag) ? NO_PLAYER_ERROR : param.valid;
	return (param);
}

t_map	ft_valid(t_map param)
{
	int i;
	int j;
	int flag;
	int len;

	i = 0;
	j = 0;
	flag = 0;
	close(param.valid = (open(param.no, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.so, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.we, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.ea, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.s, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	if (!param.valid)
		while (param.g_map[0][j])
			if (ft_rhr("02NSWE", param.g_map[0][j++]))
				param.valid = MAP_NO_VALID;
		while (param.g_map[i] && !(j = 0))
		{
			if (!(ft_rhr("1 ", param.g_map[i][0])))
				param.valid = MAP_NO_VALID;
			if (param.g_map[i + 1])
				len = ft_strlen(param.g_map[i]) - ft_strlen(param.g_map[i + 1]);
					if ((len < 0) && (len = ft_strlen(param.g_map[i])))
						while (param.g_map[i][len])
							if (ft_rhr("02NSWE", param.g_map[i][len++]))
								param.valid = MAP_NO_VALID;
//					else ((len > 0) && (len = ft_strlen(param.g_map[i])))
			else
				while (param.g_map[i][j])
					if (ft_rhr("02NSWE", param.g_map[i][j++]) && (param.valid = MAP_NO_VALID))
						return (param);
//			while (param.g_map[i][j] == '1' || param.g_map[i][j] == ' ')
//				j++;
//			if (!i)
//				if ((len = ft_strlen(param.g_map[i - 1]) - ft_strlen(param.g_map[i])) != 0)

//			if (ft_rhr("02NSWE", param.g_map[i][j]))
//				param.valid = MAP_NO_VALID;
//
		}
	if (param.valid)
		return (param);
	return (ft_validm(param, i, j, flag));
}
