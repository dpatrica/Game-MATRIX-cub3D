//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

static t_map	mainik(t_map param, int argc, char **argv)
{
//	if ((argc < 2) || (argc > 3))
//		param.valid = (argc > 3) ? MANY_ARGS : NO_ARGS;
//	else if ((**(argv + 1) == '.') || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5)))
//		param.valid = MAP_CUB_ERROR;
//	else if ((argc == 3) && (++param.save) && (ft_strncmp(argv[2], "--save", 7)))
//		param.valid = SAVE_ERROR;
	if (!param.valid)
		param = ft_parser(param, "../maps/map.cub");
//		param = ft_parser(param, argv[1]);
	if (!param.valid)
		param = ft_valid(param, 0, 0, 0);
	if (!param.valid)
	{
		printf("Valid:%d\nWidth:%d\nHeight:%d\nF.flag:%d\nF.r:%d\nF.g:%d\nF.b:%d\nC.flag:%d\nC.r:%d\nC.g:%d\nC.b:%d\nSave:%d\nNO:%s\nSO:%s\nWE:%s\nEA:%s\nS:%s\nFRGB:%X\nCRGB:%X\nGG\n\n",
			   param.valid, param.width, param.height, param.f.flag, param.f.r,
			   param.f.g, param.f.b, param.c.flag, param.c.r, param.c.g,
			   param.c.b, param.save, param.no, param.so, param.we, param.ea,
			   param.s, param.f.rgb, param.c.rgb);
		int i = 0;
		while (param.g_map[i])
			printf("%s\n", param.g_map[i++]);
	}
	return (param);
}

int				main(int argc, char **argv)
{
	t_all	xlm;

	xlm.param.valid = VALID;
	xlm = ft_fornull(xlm);
	xlm.param = mainik(xlm.param, argc, argv);
	if (xlm.param.valid)
		return (ft_error(xlm.param, xlm.param.valid));
//	save_player(&xlm);
	xlm.player = xlm.param.resp_player;
	printf("\nPlayer POSITION:\nX:%f\nY:%f\ndir:%c\n", xlm.player.x, xlm.player.y, xlm.player.dir);
	xlm.mlx = mlx_init();
	xlm.win = mlx_new_window(xlm.mlx, xlm.param.width, xlm.param.height, "dolbobob");
	xlm.tex.no.tex = mlx_xpm_file_to_image(xlm.mlx, xlm.param.no, &xlm.tex.no.width, &xlm.tex.no.height);
	xlm.tex.so.tex = mlx_xpm_file_to_image(xlm.mlx, xlm.param.so, &xlm.tex.so.width, &xlm.tex.so.height);
	xlm.tex.we.tex = mlx_xpm_file_to_image(xlm.mlx, xlm.param.we, &xlm.tex.we.width, &xlm.tex.we.height);
	xlm.tex.ea.tex = mlx_xpm_file_to_image(xlm.mlx, xlm.param.ea, &xlm.tex.ea.width, &xlm.tex.ea.height);
//	xlm.neo.tex_hei = xlm.tex.no.height;
//	xlm.neo.tex_wid = xlm.tex.no.width;
	if (xlm.tex.no.tex == NULL || xlm.tex.so.tex == NULL || xlm.tex.we.tex == NULL || xlm.tex.ea.tex == NULL)
	{
		ft_error(xlm.param, UN_ERROR);
		exit(0);
	}
	xlm.tex.no.adr = mlx_get_data_addr(xlm.tex.no.tex, &xlm.tex.no.bpp, &xlm.tex.no.line_len, &xlm.tex.no.iend);
//	printf("%d\n%d\n", xlm.tex.no.width, xlm.tex.no.height);
	xlm.tex.so.adr = mlx_get_data_addr(xlm.tex.so.tex, &xlm.tex.so.bpp, &xlm.tex.so.line_len, &xlm.tex.so.iend);
	xlm.tex.we.adr = mlx_get_data_addr(xlm.tex.we.tex, &xlm.tex.we.bpp, &xlm.tex.we.line_len, &xlm.tex.we.iend);
	xlm.tex.ea.adr = mlx_get_data_addr(xlm.tex.ea.tex, &xlm.tex.ea.bpp, &xlm.tex.ea.line_len, &xlm.tex.ea.iend);
//	xlm.img.img = mlx_new_image(xlm.mlx, xlm.param.width, xlm.param.height);
//	xlm.img.adr = mlx_get_data_addr(xlm.img.img, &xlm.img.bpp, &xlm.img.line_len, &xlm.img.iend);
//	ft_draw_map(&xlm, START_X, START_Y);
//	ft_draw_beam(&xlm);
//	mlx_key_hook(xlm.win, &key_hook, &xlm);
	mlx_hook(xlm.win, 2, 0, &key_press, &xlm);
	mlx_hook(xlm.win, 3, 0, &key_release, &xlm);
//	ft_render(&xlm);
	mlx_loop_hook(xlm.mlx, &key_hook, &xlm);
//	mlx_put_image_to_window(xlm.mlx, xlm.win, xlm.image, xlm.param.width, xlm.param.height);
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
