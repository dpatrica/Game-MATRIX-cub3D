/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:02:48 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:02:49 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_errorrrrr(int error)
{
	if (error == GNL_ERROR)
		write(1, "Error!\nMap reading error.", 25);
	else if (error == NO_PARAM_ERROR)
		write(1, "Error!\n"
				"Missing parameters, or they are set below the map.", 57);
	else if (error == NO_MAP_ERROR)
		write(1, "Error!\nMissing map.", 19);
	else if (error == MALLOC_MAP_ERROR)
		write(1, "Error!\nFailed to allocate memory for map.", 26);
	else if (error == T_ERROR)
		write(1, "Error!\nCouldn't open the texture.", 33);
	else if (error == MAP_NO_VALID)
		write(1, "Error!\nMap not valid.", 21);
	else if (error == DOUBLE_PLAYER_ERROR)
		write(1, "Error!\nToo many players.", 24);
	else if (error == NO_PLAYER_ERROR)
		write(1, "Error!\nMissing player.", 22);
	else if (error == MAP_EMPTY_LINE_ERROR)
		write(1, "Error!\nEmpty line in the map.", 29);
	else if (error == TEXTURE_ERROR)
		write(1, "Error!\nFailed to load texture.", 30);
	else if (error == SPR_MALLOC_ERROR)
		write(1, "Error!\nFailed to allocate memory for sprite.", 44);
	return (-1);
}

static int	ft_errorrrr(int error)
{
	if (error == MAP_TRASH_SOUTH_ERROR)
		write(1, "Error!\n"
				"Please remove trash from the map on the south.", 53);
	else if (error == MAP_TRASH_NORTH_ERROR)
		write(1, "Error!\n"
				"Please remove trash from the map on the north.", 53);
	else if (error == DOUBLE_WEST_ERROR)
		write(1, "Error!\nToo many west.", 21);
	else if (error == MALLOC_WEST_ERROR)
		write(1, "Error!\nFailed to allocate memory for west.", 27);
	else if (error == MAP_TRASH_WEST_ERROR)
		write(1, "Error!\n"
				"Please remove trash from the map on the west.", 52);
	else if (error == NO_WEST_ERROR)
		write(1, "Error!\nMissing west.", 20);
	else if (error == DOUBLE_EAST_ERROR)
		write(1, "Error!\nToo many east.", 21);
	else if (error == MALLOC_EAST_ERROR)
		write(1, "Error!\nFailed to allocate memory for east.", 27);
	else if (error == MAP_TRASH_EAST_ERROR)
		write(1, "Error!\n"
				"Please remove trash from the map on the east.", 52);
	else if (error == NO_EAST_ERROR)
		write(1, "Error!\nMissing east.", 20);
	return (ft_errorrrrr(error));
}

static int	ft_errorrr(int error)
{
	if (error == MAP_TRASH_CRGB_ERROR)
		write(1, "Error!\n"
				"Please remove trash from the map on the ceiling RGB.", 59);
	else if (error == DOUBLE_SPRITE_ERROR)
		write(1, "Error!\nToo many sprite.", 23);
	else if (error == MALLOC_SPRITE_ERROR)
		write(1, "Error!\nFailed to allocate memory for sprite.", 44);
	else if (error == MAP_TRASH_SPRITE_ERROR)
		write(1, "Error!\n"
				"Please remove trash from the map on the sprite.", 54);
	else if (error == NO_SPRITE_ERROR)
		write(1, "Error!\nMissing sprite.", 22);
	else if (error == DOUBLE_NORTH_ERROR)
		write(1, "Error!\nToo many north.", 22);
	else if (error == MALLOC_NORTH_ERROR)
		write(1, "Error!\nFailed to allocate memory for north.", 28);
	else if (error == NO_NORTH_ERROR)
		write(1, "Error!\nMissing north.", 21);
	else if (error == DOUBLE_SOUTH_ERROR)
		write(1, "Error!\nToo many south.", 22);
	else if (error == MALLOC_SOUTH_ERROR)
		write(1, "Error!\nFailed to allocate memory for south.", 28);
	else if (error == NO_SOUTH_ERROR)
		write(1, "Error!\nMissing south.", 21);
	return (ft_errorrrr(error));
}

static int	ft_errorr(int error)
{
	if (error == SAVE_ERROR)
		write(1, "Error!\nFlag --save not valid.", 29);
	else if (error == MAP_OPEN_ERROR)
		write(1, "Error!\nCouldn't open the map.", 29);
	else if (error == MAP_TRASH_ERROR)
		write(1, "Error!\nPlease remove trash from the map.", 40);
	else if (error == MAP_TRASH_RESO_ERROR)
		write(1, "Error!\n"
		"Please remove trash from the map in resolution.", 54);
	else if (error == DOUBLE_RESO_ERROR)
		write(1, "Error!\nToo many screen resolution.", 34);
	else if (error == RESO_NO_VALID_ERROR)
		write(1, "Error!\nScreen resolution not valid.", 35);
	else if (error == DOUBLE_FRGB_ERROR)
		write(1, "Error!\nToo many floor RGB.", 26);
	else if (error == MAP_TRASH_FRGB_ERROR)
		write(1, "Error!\n"
		"Please remove trash from the map on the floor RGB.", 57);
	else if (error == FRGB_NO_VALID_ERROR)
		write(1, "Error!\nFloor RGB not valid.", 27);
	else if (error == DOUBLE_CRGB_ERROR)
		write(1, "Error!\nToo many ceiling RGB.", 28);
	else if (error == CRGB_NO_VALID_ERROR)
		write(1, "Error!\n??eiling RGB not valid.", 29);
	return (ft_errorrr(error));
}

int			ft_error(t_all *xlm, int error)
{
	int	i;

	xlm->param.no ? free(xlm->param.no) : 0;
	xlm->param.so ? free(xlm->param.so) : 0;
	xlm->param.we ? free(xlm->param.we) : 0;
	xlm->param.ea ? free(xlm->param.ea) : 0;
	xlm->param.s ? free(xlm->param.s) : 0;
	xlm->sprite.wid_buf ? free(xlm->sprite.wid_buf) : 0;
	xlm->sprite.spr ? free(xlm->sprite.spr) : 0;
	xlm->sprite.spr_dist ? free(xlm->sprite.spr_dist) : 0;
	xlm->sprite.pos ? free(xlm->sprite.pos) : 0;
	i = 0;
	if (xlm->param.g_map)
		while (xlm->param.g_map[i])
			free(xlm->param.g_map[i++]);
	xlm->param.g_map ? free(xlm->param.g_map) : 0;
	if (error == NO_ARGS)
		write(1, "Error!\nNo arguments.", 20);
	else if (error == MANY_ARGS)
		write(1, "Error!\nToo many arguments.", 26);
	else if (error == MAP_CUB_ERROR)
		write(1, "Error!\nMap format not valid.", 28);
	return (ft_errorr(error));
}
