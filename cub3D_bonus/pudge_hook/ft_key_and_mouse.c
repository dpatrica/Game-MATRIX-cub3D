//
// Created by Daisey Patrica on 1/29/21.
//

#include "../includes/cub3d.h"

int			key_press(int key, t_all *xlm)
{
//	printf("%d\n", key);
	if (key == 13 || key == 126)
		xlm->move.up = 1;
	if (key == 1 || key == 125)
		xlm->move.down = 1;
	if (key == 2)
		xlm->move.right = 1;
	if (key == 0)
		xlm->move.left = 1;
	if (key == 124)
		xlm->move.r_rot = 1;
	if (key == 123)
		xlm->move.l_rot = 1;
	if (key == 46)
		xlm->move.map = 1;
	if (key == 53)
		xlm->move.exit = 1;
	if (key == 49)
		xlm->move.open = 1;
	return (0);
}

int		key_release(int key, t_all *xlm)
{
	if (key == 13 || key == 126)
		xlm->move.up = 0;
	if (key == 1 || key == 125)
		xlm->move.down = 0;
	if (key == 2)
		xlm->move.right = 0;
	if (key == 0)
		xlm->move.left = 0;
	if (key == 124)
		xlm->move.r_rot = 0;
	if (key == 123)
		xlm->move.l_rot = 0;
	if (key == 46)
		xlm->move.map = 0;
	if (key == 53)
		xlm->move.exit = 0;
	if (key == 49)
		xlm->move.open = 0;
	return (0);
}

int 	mouse(int x, int y, t_all *xlm)
{
	int mouse;

	if (x > (X / 2))
	{
		xlm->move.l_m_rot = x - (xlm->param.width / 2);
		xlm->move.l_m_rot *= 0.001;
		xlm->move.r_m_rot = 1;
	}
	if (x < (X / 2))
	{
		xlm->move.r_m_rot = (xlm->param.width / 2) - x;
		xlm->move.r_m_rot *= 0.001;
		xlm->move.l_m_rot = 1;
	}
	if (y != (xlm->param.height / 2))
	{
		mouse = (y - (xlm->param.height / 2));
		xlm->move.mouse_cam += mouse * 0.003;
		if (xlm->move.mouse_cam > 2.9)
			xlm->move.mouse_cam = 2.9;
		if (xlm->move.mouse_cam < 1.1)
			xlm->move.mouse_cam = 1.1;
	}
	return (0);
}

int		button_press(int key, int key2, int key3, t_all *xlm)
{
	(void)key2;
	(void)key3;

	if (key == 1)
		xlm->move.rpm = 1;
	if (xlm->player.super_stvol && xlm->player.digl && (key == 4 || key == 5))
	{
		xlm->action.change_stvol = 1;
		xlm->player.super_stvol = 0;
	}
	else if (!xlm->player.super_stvol && xlm->action.change_stvol &&\
	xlm->player.digl && (key == 4 || key == 5))
	{
		xlm->action.change_stvol = 0;
		xlm->player.super_stvol = 1;
	}
	return (0);
}

int		button_release(int key, int key2, int key3, t_all *xlm)
{
	(void)key2;
	(void)key3;

	if (key == 1)
		xlm->move.rpm = 0;
	return (0);
}
