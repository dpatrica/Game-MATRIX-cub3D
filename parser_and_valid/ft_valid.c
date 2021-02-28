/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:04:01 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:04:01 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		param = ft_valid(param, i, j, 1);
	return (param);
}

static t_map	ft_validm(t_map param, int i, int j, int flag)
{
	if (flag)
	{
		param.resp_player.dir = (int)param.g_map[i][j];
		param.resp_player.x = j + 0.5;
		param.resp_player.y = i + 0.5;
		return (dir_cos_sin(param));
	}
	while (param.g_map[i])
	{
		if (ft_rhr("1 ", param.g_map[i][j]))
			param = ft_validsym(param, i, j, 0);
		else
			param.valid = MAP_NO_VALID;
		if (param.valid)
			return (param);
		i++;
	}
	param.valid = !param.resp_player.dir ? NO_PLAYER_ERROR : param.valid;
	return (param);
}

static t_map	ft_valyas(t_map param, int i, int j, int flaglen)
{
	while (param.g_map[i][j] && (flaglen == -1 || flaglen--))
	{
		if (ft_rhr("02NSWE", param.g_map[i][j]))
		{
			if (!param.resp_player.dir && ft_rhr("NSWE", param.g_map[i][j]))
				param = ft_validm(param, i, j, 1);
			else if (param.resp_player.dir && ft_rhr("NSWE", param.g_map[i][j]))
				param.valid = DOUBLE_PLAYER_ERROR;
			if (!(ft_rhr("102NSWE", param.g_map[i][j - 1])) ||\
			!(ft_rhr("102NSWE", param.g_map[i - 1][j - 1])) ||\
			!(ft_rhr("102NSWE", param.g_map[i - 1][j])) ||\
			!(ft_rhr("102NSWE", param.g_map[i - 1][j + 1])) ||\
			!(ft_rhr("102NSWE", param.g_map[i][j + 1])) ||\
			!(ft_rhr("102NSWE", param.g_map[i + 1][j + 1])) ||\
			!(ft_rhr("102NSWE", param.g_map[i + 1][j])) ||\
			!(ft_rhr("102NSWE", param.g_map[i + 1][j - 1])))
				param.valid = MAP_NO_VALID;
		}
		else if (!(ft_rhr("1 ", param.g_map[i][j])))
			param.valid = MAP_NO_VALID;
		if (param.valid)
			return (param);
		j++;
	}
	return (param);
}

t_map			ft_valid(t_map param, int i, int j, int flaglen)
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
	return (ft_validm(param, i, j, flaglen));
}
