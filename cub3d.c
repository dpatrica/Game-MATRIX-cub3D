//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

static t_map	mainik(t_map param, int argc, char **argv)
{
	(void)argc;
//	if ((argc < 2) || (argc > 3))
//		param.valid = (argc > 3) ? MANY_ARGS : NO_ARGS;
//	else if ((**(argv + 1) == '.') || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5)))
//		param.valid = MAP_CUB_ERROR;
//	else if ((argc == 3) && (++param.save) && (ft_strncmp(argv[2], "--save", 7)))
//		param.valid = SAVE_ERROR;
	if (!param.valid)
		param = ft_parser(param,(param.lvl ? *argv : "../maps/map.cub"));
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

int				cub3d(int argc, char **argv, int lvl)
{
	t_all	xlm;

	xlm.param.lvl = lvl;
	xlm = ft_fornull(xlm);
	xlm.param = mainik(xlm.param, argc, argv);
	if (xlm.param.valid)
		return (ft_error(&xlm, xlm.param.valid));
	xlm.player = xlm.param.resp_player;
	printf("\nPlayer POSITION:\nX:%f\nY:%f\ndir:%c\n", xlm.player.x, xlm.player.y, xlm.player.dir);
	xlm.mlx = mlx_init();
	xlm.img.img = mlx_new_image(xlm.mlx, xlm.param.width, xlm.param.height);
	xlm.img.adr = mlx_get_data_addr(xlm.img.img, &xlm.img.bpp, &xlm.img.line_len, &xlm.img.iend);
//	check_screen(&xlm);
	sprite_map_len(&xlm);
	printf("map_x:%d\nmap_y:%d\n", xlm.param.map_x, xlm.param.map_y);
	check_map(&xlm);
	printf("x:%f\ny:%f\n", xlm.width_square, xlm.height_square);
	xlm.win = mlx_new_window(xlm.mlx, xlm.param.width, xlm.param.height, "dolbobob");
	ft_texture(&xlm);
	if (xlm.sprite.spr_len)
		sprite_check(&xlm);
	printf("spr_len:%d\n", xlm.sprite.spr_len);
	mlx_mouse_hide();
	xlm.xxx = xlm.player.x;
	xlm.yyy = xlm.player.y;

//	t_move *lol;
//	lol = &(xlm.move);
	mlx_hook(xlm.win, 2, 0, &key_press, &xlm);
	mlx_hook(xlm.win, 3, 0, &key_release, &xlm);
//	mlx_hook(xlm.win, 4, (1L<<8), &button_press, lol);
//	mlx_hook(xlm.win, 5, (1L<<9), &button_release, lol);
//	mlx_hook(xlm.win, 4, 0, &key_press, &xlm);
//	mlx_hook(xlm.win, 5, 0, &key_release, &xlm);
	mlx_hook(xlm.win, 6, 0, &mouse, &xlm);
//	ft_render(&xlm);
	mlx_loop_hook(xlm.mlx, &key_hook, &xlm);
	mlx_loop(xlm.mlx);
	ft_error(&xlm, xlm.param.valid);
	return (0);
}

int				main(int argc, char **argv)
{
	cub3d(argc, argv, 0);
//	xlm = ft_fornull(xlm);
/*	xlm.param = mainik(xlm.param, argc, argv);
	if (xlm.param.valid)
		return (ft_error(xlm, xlm.param.valid));
	xlm.player = xlm.param.resp_player;
	printf("\nPlayer POSITION:\nX:%f\nY:%f\ndir:%c\n", xlm.player.x, xlm.player.y, xlm.player.dir);
	xlm.mlx = mlx_init();
	xlm.img.img = mlx_new_image(xlm.mlx, xlm.param.width, xlm.param.height);
	xlm.img.adr = mlx_get_data_addr(xlm.img.img, &xlm.img.bpp, &xlm.img.line_len, &xlm.img.iend);
//	chek_screen(&xlm);
	xlm.win = mlx_new_window(xlm.mlx, xlm.param.width, xlm.param.height, "dolbobob");
	ft_texture(&xlm);
	sprite_len(&xlm);
	printf("spr_len:%d\n", xlm.sprite.spr_len);
	mlx_mouse_hide();
	xlm.xxx = xlm.player.x;
	xlm.yyy = xlm.player.y;

	mlx_hook(xlm.win, 2, 0, &key_press, &xlm);
	mlx_hook(xlm.win, 3, 0, &key_release, &xlm);
	mlx_hook(xlm.win, 6, 0, &mouse, &xlm);
//	ft_render(&xlm);
	mlx_loop_hook(xlm.mlx, &key_hook, &xlm);
	mlx_loop(xlm.mlx);
	ft_error(xlm, xlm.param.valid);*/
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
