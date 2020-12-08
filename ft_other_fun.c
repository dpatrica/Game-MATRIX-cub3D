//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

t_map	ft_fornull(t_map param)
{
	param.valid = 0;
	param.width = 0;
	param.height = 0;
	param.no = NULL;
	param.so = NULL;
	param.we = NULL;
	param.ea = NULL;
	param.s = NULL;
	param.f.r = 0;
	param.f.g = 0;
	param.f.b = 0;
	param.c.r = 0;
	param.c.g = 0;
	param.c.b = 0;
	param.flag = 0;
	param.type = 0;
	param.temp = 0;
	return (param);
}
