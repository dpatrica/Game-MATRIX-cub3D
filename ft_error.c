//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	ft_error(int error)
{
	if (error == NO_ARGS)
		write(1, "Error!\nNo arguments.", 20);
	else if (error == MANY_ARGS)
		write(1, "Error!\nToo many arguments.", 26);
	else if (error == MAP_CUB_ERROR)
		write(1, "Error!\nMap format not valid.", 28);
	else if (error == SAVE_ERROR)
		write(1, "Error!\nFlag --save not valid.", 29);
	else if (error == MAP_OPEN_ERROR)
		write(1, "Error!\nCouldn't open the map.", 29);
	else if (error == MAP_TRASH_ERROR)
		write(1, "Error!\nPlease remove trash from the map.", 40);
	else if (error == MAP_TRASH_RESO_ERROR)
		write(1, "Error!\nPlease remove trash from the map in resolution.", 54);
	else if (error == DOUBLE_RESO_ERROR)
		write(1, "Error!\nDual screen resolution.", 30);
	else if (error == RESO_NO_VALID_ERROR)
		write(1, "Error!\nScreen resolution not valid.", 35);
	else if (error == DOUBLE_FRGB_ERROR)
		write(1, "Error!\nDual floor RGB.", 22);
	return (-1);
}
