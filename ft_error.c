//
// Created by Daisey Patrica on 12/8/20.
//

#include "./includes/cub3d.h"

int	ft_error(t_map param, int error)
{
	int	i;

	param.no ? free(param.no) : 0;
	param.so ? free(param.so) : 0;
	param.we ? free(param.we) : 0;
	param.ea ? free(param.ea) : 0;
	param.s ? free(param.s) : 0;
	i = 0;
	if (param.g_map)
		while (param.g_map[i])
			free(param.g_map[i++]);
	param.g_map ? free(param.g_map) : 0;
	if (error == VALID)
		write(1, "!!!_ALL VALID AND EZ FREED_!!!", 30);
	else if (error == NO_ARGS)
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
	else if (error == MAP_TRASH_FRGB_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the floor RGB.", 57);
	else if (error == FRGB_NO_VALID_ERROR)
		write(1, "Error!\nFloor RGB not valid.", 27);
	else if (error == DOUBLE_CRGB_ERROR)
		write(1, "Error!\nDual ceiling RGB.", 24);
	else if (error == MAP_TRASH_CRGB_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the ceiling RGB.", 59);
	else if (error == CRGB_NO_VALID_ERROR)
		write(1, "Error!\nСeiling RGB not valid.", 29);
	else if (error == DOUBLE_SPRITE_ERROR)
		write(1, "Error!\nDual sprite.", 19);
	else if (error == MALLOC_SPRITE_ERROR)
		write(1, "Error!\nFailed to allocate memory for sprite.", 44);
	else if (error == MAP_TRASH_SPRITE_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the sprite.", 54);
	else if (error == NO_SPRITE_ERROR)
		write(1, "Error!\nMissing sprite.", 22);
	else if (error == DOUBLE_NORTH_ERROR)
		write(1, "Error!\nDual north.", 18);
	else if (error == MALLOC_NORTH_ERROR)
		write(1, "Error!\nFailed to allocate memory for north.", 28);
	else if (error == MAP_TRASH_NORTH_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the north.", 53);
	else if (error == NO_NORTH_ERROR)
		write(1, "Error!\nMissing north.", 21);
	else if (error == DOUBLE_SOUTH_ERROR)
		write(1, "Error!\nDual south.", 18);
	else if (error == MALLOC_SOUTH_ERROR)
		write(1, "Error!\nFailed to allocate memory for south.", 28);
	else if (error == MAP_TRASH_SOUTH_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the south.", 53);
	else if (error == NO_SOUTH_ERROR)
		write(1, "Error!\nMissing south.", 21);
	else if (error == DOUBLE_WEST_ERROR)
		write(1, "Error!\nDual west.", 17);
	else if (error == MALLOC_WEST_ERROR)
		write(1, "Error!\nFailed to allocate memory for west.", 27);
	else if (error == MAP_TRASH_WEST_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the west.", 52);
	else if (error == NO_WEST_ERROR)
		write(1, "Error!\nMissing west.", 20);
	else if (error == DOUBLE_EAST_ERROR)
		write(1, "Error!\nDual east.", 17);
	else if (error == MALLOC_EAST_ERROR)
		write(1, "Error!\nFailed to allocate memory for east.", 27);
	else if (error == MAP_TRASH_EAST_ERROR)
		write(1, "Error!\nPlease remove trash from the map on the east.", 52);
	else if (error == NO_EAST_ERROR)
		write(1, "Error!\nMissing east.", 20);
	else if (error == GNL_ERROR)
		write(1, "Error!\nMap reading error.", 25);
	else if (error == NO_PARAM_ERROR)
		write(1, "Error!\nMissing parameters, or they are set below the map.", 57);
	else if (error == NO_MAP_ERROR)
		write(1, "Error!\nMissing map.", 19);
	else if (error == MALLOC_MAP_ERROR)
		write(1, "Error!\nFailed to allocate memory for map.", 26);
	else if (error == T_ERROR)
		write(1, "Error!\nCouldn't open the texture.", 33);
	else if (error == MAP_NO_VALID)
		write(1, "Error!\nMap not valid.", 21);
	else if (error == DOUBLE_PLAYER_ERROR)
		write(1, "Error!\nDual player.", 19);
	else if (error == NO_PLAYER_ERROR)
		write(1, "Error!\nMissing player.", 22);
	return (-1);
}
