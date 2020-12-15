//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	mls;

	mls.param.valid = VALID;
	mls.param = ft_fornull(mls.param);
	if ((argc < 2) || (argc > 3))
		return (ft_error(mls.param, argc > 3 ? MANY_ARGS : NO_ARGS));
	if ((**(argv + 1) == '.') || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5)))
		return (ft_error(mls.param, MAP_CUB_ERROR));
	if ((argc == 3) && (++mls.param.save) && (ft_strncmp(argv[2], "--save", 7)))
		return (ft_error(mls.param, SAVE_ERROR));
	mls.param = ft_parser(mls.param, argv[1]);
	if (!mls.param.valid)
		mls.param = ft_valid(mls.param, 0, 0, 0);
	if (!mls.param.valid)
	{
		printf("Valid:%d\nWidth:%d\nHeight:%d\nF.flag:%d\nF.r:%d\nF.g:%d\nF.b:%d\nC.flag:%d\nC.r:%d\nC.g:%d\nC.b:%d\nSave:%d\nNO:%s\nSO:%s\nWE:%s\nEA:%s\nS:%s\nGG\n\n",
			   mls.param.valid, mls.param.width, mls.param.height, mls.param.f.flag, mls.param.f.r,
			   mls.param.f.g, mls.param.f.b, mls.param.c.flag, mls.param.c.r, mls.param.c.g,
			   mls.param.c.b, mls.param.save, mls.param.no, mls.param.so, mls.param.we, mls.param.ea,
			   mls.param.s);
		int i = 0;
		while (mls.param.g_map[i])
			printf("%s\n", mls.param.g_map[i++]);
	}
	mls.mlx = mlx_init();
	mlx_new_window(mls.mlx, mls.param.width, mls.param.height, "dolbobob");
	mlx_loop(mls.mlx);
	return (ft_error(mls.param, mls.param.valid));
}
