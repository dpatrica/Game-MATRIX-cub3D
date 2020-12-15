//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

t_map	ft_fornull(t_map param)
{
	param.valid = VALID;
	param.width = 0;
	param.height = 0;
	param.g_map = NULL;
	param.no = NULL;
	param.so = NULL;
	param.we = NULL;
	param.ea = NULL;
	param.s = NULL;
	param.f.r = -1;
	param.f.g = -1;
	param.f.b = -1;
	param.f.flag = 0;
	param.c.r = -1;
	param.c.g = -1;
	param.c.b = -1;
	param.c.flag = 0;
	param.save = 0;
	param.type = 0;
	param.temp1 = 0;
	param.temp2 = 0;
	return (param);
}

int		drop_space(char **map)
{
	int	i;

	i = 0;
	while ((**map == ' ') && (++i))
		(*map)++;
	return(i);
}

char	*freesher(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (NULL);
}
