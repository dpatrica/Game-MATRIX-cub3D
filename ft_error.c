//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	ft_error(int error)
{
	if (error == NO_ARGS)
		write(1, "Error!\nNo arguments.", 20);
	if (error == MANY_ARGS)
		write(1, "Error!\nToo many arguments.", 26);
	if (error == MAP_CUB_ERROR)
		write(1, "Error!\nMap format not valid", 27);
	if (error == SAVE_ERROR)
		write(1, "Error!\nFlag --save not valid", 28);
	return (-1);
}
