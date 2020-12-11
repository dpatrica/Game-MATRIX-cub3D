//
// Created by Daisey Patrica on 12/11/20.
//

#include "./includes/cub3d.h"

static t_map	ft_validsym(t_map param, int i, int j)
{
	printf("\n%d\n", param.g_map[i][j]);
	printf("i:%d\nj:%d\n", i, j);
	if (!param.g_map[i][j - 1] ||\
	(ft_strchr("102NSWE", param.g_map[i][j - 1])) == NULL)
	{
		printf("--->1<---");
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i][j + 1] || \
	(ft_strchr("102NSWE", param.g_map[i][j + 1])) == NULL)
	{
		printf("--->2<---\n");
		printf("%c\n", param.g_map[i][j + 1]);
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i - 1][j] || \
	(ft_strchr("102NSWE", param.g_map[i - 1][j])) == NULL)
	{
		printf("--->3<---");
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i + 1][j] || \
	(ft_strchr("102NSWE", param.g_map[i + 1][j])) == NULL)
	{
		printf("--->4<---");
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i - 1][j - 1] || \
	(ft_strchr("102NSWE", param.g_map[i - 1][j - 1])) == NULL)
	{
		printf("--->5<---");
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i - 1][j + 1] || \
	(ft_strchr("102NSWE", param.g_map[i - 1][j + 1])) == NULL)
	{
		printf("--->6<---");
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i + 1][j - 1] || \
	(ft_strchr("102NSWE", param.g_map[i + 1][j - 1])) == NULL)
	{
		printf("--->7<---");
		param.valid = MAP_NO_VALID;
	}
	else if (!param.g_map[i + 1][j + 1] || \
	(ft_strchr("102NSWE", param.g_map[i + 1][j + 1])) == NULL)
	{
		printf("--->8<---");
		param.valid = MAP_NO_VALID;
	}
	return (param);
}

static t_map	ft_validm(t_map param, int i, int j, int flag)
{
	while (param.g_map[i] && !param.valid)
	{
		while (param.g_map[i][j] == '1' || param.g_map[i][j] == ' ')
			j++;
		if (param.g_map[i][j] && (ft_strchr("02NSWE", param.g_map[i][j])))
		{
			if (!flag && (ft_strchr("NSWE", param.g_map[i][j])))
				flag = 1;
			else if (flag && ((ft_strchr("NSWE", param.g_map[i][j])) != NULL))
				param.valid = DOUBLE_PLAYER_ERROR;
			if (!param.valid)
				param = ft_validsym(param, i, j);
			if (param.valid)
				return (param);
			j++;
			continue ;
		}
		if (!param.g_map[i][j])
			i++;
		else
			param.valid = MAP_TRASH_ERROR;
	}
	if (!param.valid && !flag)
		param.valid = NO_PLAYER_ERROR;
	return (param);
}

t_map	ft_valid(t_map param)
{
	int i;
	int j;
	int flag;

//	close(param.valid = (open(param.no, O_RDONLY)) < 0 ? T_ERROR : param.valid);
//	close(param.valid = (open(param.so, O_RDONLY)) < 0 ? T_ERROR : param.valid);
//	close(param.valid = (open(param.we, O_RDONLY)) < 0 ? T_ERROR : param.valid);
//	close(param.valid = (open(param.ea, O_RDONLY)) < 0 ? T_ERROR : param.valid);
//	close(param.valid = (open(param.s, O_RDONLY)) < 0 ? T_ERROR : param.valid);
	if (param.valid)
		return (param);
	i = 0;
	j = 0;
	flag = 0;
	return (ft_validm(param, i, j, flag));
}
