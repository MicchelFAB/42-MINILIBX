/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:35:36 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/25 20:19:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"
#include	"mlx_int.h"
#include	"mlx_test.h"

int	expose_win1(t_wd *wd)
{
	if (window_find(wd, 1) && image_find(wd, 2))
	{
		mlx_clear_window(wd->smlx, wd->swin->win);
		sleep(2);
		mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 0, 0);
		sleep(2);
	}
}

int	expose_win2(t_wd *wd)
{

	if (window_find(wd, 2) && image_find(wd, 1))
		mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 0, 0);

	if (window_find(wd, 2) && image_find(wd, 2))
		mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 20, 20);

	if (window_find(wd, 2) && image_find(wd, 3))
		mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 40, 40);

	if (window_find(wd, 2) && image_find(wd, 4))
		mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 60, 60);
}

int	key_win1(int key, void *p)
{
	printf("Key in Win1 : %d\n", key);
	if (key == 0xFF1B || key == 0x71)
		exit(0);
}

int	key_win2(int key, void *p)
{
	printf("Key in Win2 : %d\n", key);
	if (key == 0xFF1B || key == 0x71)
		exit(0);
}

int	key_win3(int key, t_wd *wd)
{
	printf("Key in Win3 : %#x\n", key);
	window_find(wd, 3);
	if (key == 0xFF1B || key == 'q')
	{
		mlx_destroy_window(wd->smlx, wd->swin->win);
	}
}

int	mouse_win1(int button, int x, int y, void *p)
{
	printf("Mouse in Win1,  button %d at %dx%d.\n", button, x, y);
	if (button == 1)
	{
		printf("Mouse button %d in Window 1 closing program\n", button);
		exit(0);
	}
	if (button == 2)
		printf("Mouse button %d in Window 1 testing hook\n", button);
}

int	mouse_win2(int button, int x, int y, void *p)
{
	printf("Mouse in Win2,  button %d at %dx%d.\n", button, x, y);
}

int	mouse_win3(int x, int y, void *p)
{
	printf("Mouse moving in Win3,  at %dx%d.\n", x, y);
}
