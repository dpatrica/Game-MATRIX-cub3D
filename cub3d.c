//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	param;

	param.valid = VALID;
	param = ft_fornull(param);
	if ((argc < 2) || (argc > 3))
		return (ft_error(param, argc > 3 ? MANY_ARGS : NO_ARGS));
	if ((**(argv + 1) == '.') || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5)))
		return (ft_error(param, MAP_CUB_ERROR));
	if ((argc == 3) && (++param.save) && (ft_strncmp(argv[2], "--save", 7)))
		return (ft_error(param, SAVE_ERROR));
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
	return (ft_error(param, param.valid));
}
