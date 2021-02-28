/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpatrica <dpatrica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 09:24:05 by dpatrica          #+#    #+#             */
/*   Updated: 2021/02/28 09:24:06 by dpatrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned int	pixel_get(t_all *xlm, int x, int y)
{
	char *dst;

	dst = xlm->img.adr + (y * xlm->img.line_len + x * (xlm->img.bpp / 8));
	return (*(unsigned int*)dst);
}

static void			data_to_fd(t_all *xlm, int fd)
{
	int				x;
	int				y;
	unsigned int	data;

	y = xlm->param.height;
	while (--y >= 0)
	{
		x = -1;
		while (++x < xlm->param.width)
		{
			data = pixel_get(xlm, x, y);
			write(fd, &data, xlm->img.bpp / 8);
		}
	}
}

static void			convert_int_char(unsigned char *str, int size)
{
	str[0] = (unsigned char)size;
	str[1] = (unsigned char)(size >> 8);
	str[2] = (unsigned char)(size >> 16);
	str[3] = (unsigned char)(size >> 24);
}

static void			header_to_fd(t_all *xlm, int fd, int size_file)
{
	unsigned char header[54];

	ft_bzero(&header, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	convert_int_char(&header[2], size_file);
	convert_int_char(&header[10], 54);
	convert_int_char(&header[14], 40);
	convert_int_char(&header[18], xlm->param.width);
	convert_int_char(&header[22], xlm->param.height);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)xlm->img.bpp;
	write(fd, &header, 54);
}

void				ft_screenshot(t_all *xlm)
{
	int fd;
	int size_file;

	size_file = (xlm->img.line_len * xlm->param.height) + 54;
	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777)) < 0)
		ft_error(xlm, (xlm->param.valid = SAVE_ERROR));
	if (!xlm->param.valid)
	{
		header_to_fd(xlm, fd, size_file);
		data_to_fd(xlm, fd);
		close(fd);
		ft_error(xlm, 0);
	}
	mlx_destroy_image(xlm->mlx, xlm->img.img);
	xlm->img.img = NULL;
	exit(0);
}
