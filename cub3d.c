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
	return (param);
}

static void 	mainik_2(t_all *xlm)
{
	check_screen(xlm);
	sprite_map_len(xlm);
	check_map(xlm);
	if (!xlm->param.save)
		xlm->win = mlx_new_window(xlm->mlx, xlm->param.width, xlm->param.height,\
		"cub3D");
	ft_texture(xlm);
	if (xlm->sprite.spr_len)
		sprite_check(xlm);
	mlx_mouse_hide();
	if (xlm->param.save)
	{
		if (xlm->param.scr_swap_w)
			xlm->param.width = xlm->param.scr_width;
		if (xlm->param.width > 10000)
			xlm->param.width = 10000;
		if (xlm->param.scr_swap_h)
			xlm->param.height = xlm->param.scr_height;
		if (xlm->param.height > 5000)
			xlm->param.height = 5000;
		key_hook(xlm);
	}
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
	xlm.mlx = mlx_init();
	mainik_2(&xlm);
	mlx_hook(xlm.win, 2, 0, &key_press, &xlm);
	mlx_hook(xlm.win, 3, 0, &key_release, &xlm);
	mlx_hook(xlm.win, 6, 0, &mouse, &xlm);
	mlx_loop_hook(xlm.mlx, &key_hook, &xlm);
	mlx_loop(xlm.mlx);
	ft_error(&xlm, xlm.param.valid);
	return (0);
}

int				main(int argc, char **argv)
{
	cub3d(argc, argv, 0);
	exit(0);
}
