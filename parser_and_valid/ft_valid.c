//
// Created by Daisey Patrica on 12/11/20.
//

#include "../includes/cub3d.h"

static t_map	ft_valyas(t_map param, int i, int j, int flaglen)
{
	if (!flaglen)
	{
		if (!(ft_rhr("102NSWE", param.g_map[i][j - 1])) || \
		!(ft_rhr("102NSWE", param.g_map[i - 1][j - 1])) || \
		!(ft_rhr("102NSWE", param.g_map[i - 1][j])) || \
		!(ft_rhr("102NSWE", param.g_map[i - 1][j + 1])) || \
		!(ft_rhr("102NSWE", param.g_map[i][j + 1])) || \
		!(ft_rhr("102NSWE", param.g_map[i + 1][j + 1])) || \
		!(ft_rhr("102NSWE", param.g_map[i + 1][j])) || \
		!(ft_rhr("102NSWE", param.g_map[i + 1][j - 1])))
			param.valid = MAP_NO_VALID;
		return (param);
	}
	while (param.g_map[i][j] && (flaglen == -1 || flaglen--))
	{
		if (ft_rhr("02NSWE", param.g_map[i][j]))
			param = ft_valyas(param, i, j, 0);
		else if (!(ft_rhr("1 ", param.g_map[i][j])))
			param.valid = MAP_NO_VALID;
		if (param.valid)
			return (param);
		j++;
	}
	return (param);
}

static t_map	ft_validsym(t_map param, int i, int j, int len)
{
	if (!i && !(j = 0))
		while (param.g_map[i][j])
			if (!ft_rhr("1 ", param.g_map[i][j++]))
				param.valid = MAP_NO_VALID;
	if (((!param.g_map[i + 1] || !param.g_map[i + 1][0])) && !(j = 0))
		while (param.g_map[i][j])
			if (!ft_rhr("1 ", param.g_map[i][j++]))
				param.valid = MAP_NO_VALID;
	if (param.g_map[i + 1] && !param.valid && !(j = 0))
	{
		len = ft_strlen(param.g_map[i]) - ft_strlen(param.g_map[i + 1]);
		if ((len < 0) && (len = ft_strlen(param.g_map[i])))
		{
			while (param.g_map[i + 1][len])
				if (!(ft_rhr("1 ", param.g_map[i + 1][len++])))
					param.valid = MAP_NO_VALID;
		}
		else if ((len > 0) && (len = ft_strlen(param.g_map[i + 1])))
			while (param.g_map[i][len])
				if ((!ft_rhr("1 ", param.g_map[i][len++])))
					param.valid = MAP_NO_VALID;
	}
	if (param.g_map[i + 1] && i && !param.valid && !(j = 0))
		param = ft_valid(param, 1, i, j);
	return (param);
}

static t_map	ft_validm(t_map param, int i, int j, int flag)
{
	while (param.g_map[i] && !param.valid)
	{
		if (ft_rhr("1 ", param.g_map[i][j]))
		{
			while (param.g_map[i][j])
			{
				if (!flag && (ft_rhr("NSWE", param.g_map[i][j])))
					flag = 1;
				else if (flag && (ft_rhr("NSWE", param.g_map[i][j])))
					param.valid = DOUBLE_PLAYER_ERROR;
				j++;
			}
			j = 0;
			if (!param.valid)
				param = ft_validsym(param, i, j, 0);
			if (param.valid)
				return (param);
		}
		else if ((param.valid = MAP_NO_VALID))
			return (param);
		i++;
	}
	param.valid = (!param.valid && !flag) ? NO_PLAYER_ERROR : param.valid;
	return (param);
}

t_map			ft_valid(t_map param, int flaglen, int i, int j)
{
	int len;
	int len2;

	if (flaglen)
	{
		len = ft_strlen(param.g_map[i]) - ft_strlen(param.g_map[i + 1]);
		len2 = ft_strlen(param.g_map[i]) - ft_strlen(param.g_map[i - 1]);
		if (((len < len2) ? len2 : len) > 0)
			len = ft_strlen(param.g_map[(len < len2) ? (i + 1) : (i - 1)]);
		else if (((len < len2) ? len2 : len) <= 0)
			len = -1;
		param = ft_valyas(param, i, j, len);
		return (param);
	}
	close(param.valid = (open(param.no, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.so, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.we, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.ea, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	close(param.valid = (open(param.s, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	if (param.valid)
		return (param);
	return (ft_validm(param, 0, 0, 0));
}
