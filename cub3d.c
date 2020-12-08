//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	param;
	char	*cub;

	if ((argc < 2) || (argc > 3))
		return (ft_error(argc > 3 ? MANY_ARGS : NO_ARGS));
	if (ft_strncmp((cub = ft_strrchr(argv[1], '.')) ? cub : "error", ".cub", 5))
		return (ft_error(MAP_CUB_ERROR));
	if ((argc == 3) && (ft_strncmp(argv[2], "--save", 7)))
		return (SAVE_ERROR);
	param = ft_fornull(param);
	param = ft_parser(param, argv[1]);
	return (0);
}
