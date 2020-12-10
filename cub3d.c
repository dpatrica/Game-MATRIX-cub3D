//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	param;

	if ((argc < 2) || (argc > 3))
		return (ft_error(argc > 3 ? MANY_ARGS : NO_ARGS));
	if ((**(argv + 1) == '.') || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 5)))
		return (ft_error(MAP_CUB_ERROR));
	param = ft_fornull(param);
	if ((argc == 3) && (++param.save) && (ft_strncmp(argv[2], "--save", 7)))
		return (SAVE_ERROR);
	param = ft_parser(param, argv[1]);
	return (param.valid ? ft_error(param.valid) : 0);
}
