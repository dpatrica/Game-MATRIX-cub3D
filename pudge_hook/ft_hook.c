//
// Created by Daisey Patrica on 12/21/20.
//

#include "../includes/cub3d.h"

int		key_hook(t_all *xlm)
{
	xlm->yyy += SPEED * xlm->player.dir_y;
	mlx_mouse_move(xlm->win, (int)(xlm->param.width / 2), (int)(xlm->param.height / 2));
	ft_move(xlm);
	xlm->img.img = mlx_new_image(xlm->mlx, xlm->param.width, xlm->param.height);
	xlm->img.adr = mlx_get_data_addr(xlm->img.img, &xlm->img.bpp, &xlm->img.line_len, &xlm->img.iend);
	ft_render(xlm);
	if (!xlm->param.save)
		mlx_put_image_to_window(xlm->mlx, xlm->win, xlm->img.img, 0, 0);
	else
		ft_screenshot(xlm);
	mlx_destroy_image(xlm->mlx, xlm->img.img);
	xlm->img.img = NULL;
	if (xlm->player.hp <= 0)
	{
		xlm->img.img ? mlx_destroy_image(xlm->mlx, xlm->img.img) : 0;
		mlx_destroy_window(xlm->mlx, xlm->win);
		ft_error(xlm, xlm->param.valid);
		exit(0);
	}
	return (0);
}

/*
if (xlm->move.up == 1 &&\
	(xlm->param.g_map[(int)(Y + (SPEED * xlm->player.dir_y))][(int)(X + (SPEED * xlm->player.dir_x))]) != '1')
{
Y += SPEED * xlm->player.dir_y;
X += SPEED * xlm->player.dir_x;
}
if (xlm->move.down == 1 &&\
	(xlm->param.g_map[(int)(Y - (SPEED * xlm->player.dir_y))][(int)(X - (SPEED * xlm->player.dir_x))]) != '1')
{
Y -= SPEED * xlm->player.dir_y;
X -= SPEED * xlm->player.dir_x;
}
if (xlm->move.right == 1 &&\
	(xlm->param.g_map[(int)(Y + (SPEED * xlm->player.dir_x))][(int)(X - (SPEED * xlm->player.dir_y))]) != '1')
{
X -= SPEED * xlm->player.dir_y;
Y += SPEED * xlm->player.dir_x;
}
if (xlm->move.left == 1 &&\
	(xlm->param.g_map[(int)(Y - (SPEED * xlm->player.dir_x))][(int)(X + (SPEED * xlm->player.dir_y))]) != '1')
{
X += SPEED * xlm->player.dir_y;
Y -= SPEED * xlm->player.dir_x;
}*/
