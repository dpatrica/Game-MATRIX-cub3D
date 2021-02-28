/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:24:01 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:24:01 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		drop_space(char **map)
{
	int	i;

	i = 0;
	while ((**map == ' ') && (++i))
		(*map)++;
	return (i);
}

char	*freesher(char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	return (NULL);
}

int		rgb_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_pixel_put(t_all *xlm, int x, int y, int color)
{
	char *dst;

	if (color >= 0)
	{
		dst = xlm->img.adr + (y * xlm->img.line_len + x * (xlm->img.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	check_map(t_all *xlm)
{
	double temp;

	SQUARE_X = (double)(xlm->param.width - 3) / (xlm->param.map_x + 3);
	SQUARE_Y = (double)(xlm->param.height - 3) / (xlm->param.map_y + 3);
	SQUARE_X -= 0.1;
	SQUARE_Y -= 0.1;
	if (SQUARE_X <= 0.3 || SQUARE_Y <= 0.3)
	{
		SQUARE_X = 0;
		SQUARE_Y = 0;
	}
	else
	{
		temp = SQUARE_Y - SQUARE_X;
		if (temp < 0)
			SQUARE_X = SQUARE_Y;
		if (temp > 0)
			SQUARE_Y = SQUARE_X;
		if (temp > 1)
			SQUARE_Y = SQUARE_X + 1;
		if (temp > 2)
			SQUARE_Y = SQUARE_X + 2;
		if (temp > 3)
			SQUARE_Y = SQUARE_X + 3;
	}
}
