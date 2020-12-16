//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

static t_map	mainik(t_map param, int argc, char **argv)
{
	if ((argc < 2) || (argc > 3))
		param.valid = (argc > 3) ? MANY_ARGS : NO_ARGS;
	else if ((**(argv + 1) == '.') || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5)))
		param.valid = MAP_CUB_ERROR;
	else if ((argc == 3) && (++param.save) && (ft_strncmp(argv[2], "--save", 7)))
		param.valid = SAVE_ERROR;
	if (!param.valid)
		param = ft_parser(param, argv[1]);
	if (!param.valid)
		param = ft_valid(param, 0, 0, 0);
	if (!param.valid)
	{
		printf("Valid:%d\nWidth:%d\nHeight:%d\nF.flag:%d\nF.r:%d\nF.g:%d\nF.b:%d\nC.flag:%d\nC.r:%d\nC.g:%d\nC.b:%d\nSave:%d\nNO:%s\nSO:%s\nWE:%s\nEA:%s\nS:%s\nGG\n\n",
			   param.valid, param.width, param.height, param.f.flag, param.f.r,
			   param.f.g, param.f.b, param.c.flag, param.c.r, param.c.g,
			   param.c.b, param.save, param.no, param.so, param.we, param.ea,
			   param.s);
		int i = 0;
		while (param.g_map[i])
			printf("%s\n", param.g_map[i++]);
	}
	return (param);
}

int	main(int argc, char **argv)
{
	t_all	xlm;

	xlm.param.valid = VALID;
	xlm = ft_fornull(xlm);
	xlm.param = mainik(xlm.param, argc, argv);
	if (xlm.param.valid)
		return (ft_error(xlm.param, xlm.param.valid));
	xlm.mlx = mlx_init();
	xlm.win = mlx_new_window(xlm.mlx, xlm.param.width, xlm.param.height, "dolbobob");
	ft_drow(&xlm);
	mlx_key_hook(xlm.win, &key_hook, &xlm);
	mlx_loop(xlm.mlx);
	ft_error(xlm.param, xlm.param.valid);
	exit(0);
}

/*
else if (xlm.param.g_map[y][x] == '0')
{
while (yy < yyy)
{
while (xx < xxx)
mlx_pixel_put(xlm.mlx, xlm.win, xx++, yy, 0xFFFFFF);
yy++;
xx -= 5;
}
}
else if (ft_rhr("NSWE", xlm.param.g_map[y][x]))
{
while (yy < yyy)
{
while (xx < xxx)
mlx_pixel_put(xlm.mlx, xlm.win, xx++, yy, 0xFF0000);
yy++;
xx -= 5;
}
}*/
