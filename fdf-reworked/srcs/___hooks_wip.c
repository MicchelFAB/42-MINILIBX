/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ___hooks_wip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:26:48 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 00:24:16 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void	view_set_hooks(t_view *view)
{
	mlx_expose_hook(view->win, expose_hook, view);

	mlx_do_key_autorepeatoff(view->id);

	mlx_hook(view->win, 2, 0, key_press_hook, view);

	mlx_hook(view->win, 3, 0, key_release_hook, view);

	mlx_hook(view->win, 17, 0, exit_hook, view);

	mlx_loop_hook(view->id, my_loop_hook, view);

}

int	exit_hook(t_view *view)
{
	mlx_destroy_window(view->id, view->win);
	exit(0);
}

int	expose_hook(t_view *view)
{
	redraw(view);
	return (0);
}

int	my_loop_hook(t_view *view)
{
	color_hook(view);
	translate_hook(view);
	if (view->keys->w)
		view->theta += 0.05;
	if (view->keys->s)
		view->theta -= 0.05;
	if (view->keys->a)
		view->phi -= 0.05;
	if (view->keys->d)
		view->phi += 0.05;
	if (view->keys->q)
		view->psi += 0.05;
	if (view->keys->e)
		view->psi -= 0.05;
	if (view->keys->o && view->focal_dist < 9)
		view->focal_dist++;
	if (view->keys->p && view->focal_dist > 0)
		view->focal_dist--;
	if (view->keys->minus || view->keys->plus)
		scale_hook_work(view);
	else
		redraw(view);
	return (0);
}

int		key_press_hook(int keycode, t_view *view)
{
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		view->project = !view->project;
	toggle_pressed(keycode, view, 1);
	return (0);
}

int		key_release_hook(int keycode, t_view *view)
{
	toggle_pressed(keycode, view, 0);
	return (0);
}

// *****************************************************************

mlx_expose_hook(win_ptr, expose_win, p);
int	expose_win(t_any *p)
{
	mlx_clear_window(p->win);
	mlx_put_image_to_window(p->mlx_ptr, p->win, p->img, p->x, p->y);
}

mlx_mouse_hook(win_ptr, mouse_win, 0);
int	mouse_win(int button, int x, int y, void *p);
{
	printf("Mouse in Win1,  button %d at %dx%d.\n", button, x, y);
	if (button == 1)
		exit(0);
	if (button == 2)
		printf("hello button 2.\n");
}
mlx_key_hook(win_ptr, key_win1, p);
int	key_win1(int key, void *p);
{
	printf("Key in Win : %d\n", key);
	if (key == 0xFF1B || key == 0x71)
		exit(0);
}

mlx_key_hook(wd->swin->win, key_win3, wd);
int	key_win3(int key, t_wd *wd);
{
	printf("Key in Win3 : %d\n", key);
	if (key == 0xFF1B || key == 'q')
		mlx_destroy_window(wd->smlx, wd->swin->win);
}

mlx_hook(wd->swin->win, MotionNotify, PointerMotionMask, mouse_win3, 0);
int	mouse_win3(int x, int y, void *p);
{
	printf("Mouse moving in Win3,  at %dx%d.\n", x, y);
}

// *****************************************************************

static void	toggle_set_1(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_W)
		view->keys->w = toggle;
	if (keycode == KEY_S)
		view->keys->s = toggle;
	if (keycode == 'a')
		view->keys->a = toggle;
	if (keycode == KEY_D)
		view->keys->d = toggle;
	if (keycode == KEY_I)
		view->keys->i = toggle;
	if (keycode == KEY_J)
		view->keys->j = toggle;
	if (keycode == KEY_K)
		view->keys->k = toggle;
	if (keycode == KEY_L)
		view->keys->l = toggle;
	if (keycode == KEY_C)
		view->keys->c = toggle;
}

static void	toggle_set_2(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_X)
		view->keys->x = toggle;
	if (keycode == KEY_Y)
		view->keys->y = toggle;
	if (keycode == KEY_Z)
		view->keys->z = toggle;
	if (keycode == KEY_Q)
		view->keys->q = toggle;
	if (keycode == KEY_E)
		view->keys->e = toggle;
	if (keycode == KEY_O)
		view->keys->o = toggle;
	if (keycode == KEY_P)
		view->keys->p = toggle;
	if (keycode == KEY_PLUS)
		view->keys->plus = toggle;
	if (keycode == KEY_MINUS)
		view->keys->minus = toggle;
}
void	toggle_pressed(int keycode, t_view *view, int toggle)
{
	printf("%s keycode = %d\n", __func__, keycode);
	toggle_set_1(keycode, view, toggle);
	toggle_set_2(keycode, view, toggle);
}
