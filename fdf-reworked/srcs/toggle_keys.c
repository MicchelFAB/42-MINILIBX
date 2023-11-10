/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/26 02:29:24 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
// #include "libgfx.h"

static void	toggle_set_1(int keycode, t_view *view, int toggle)
{
	if (keycode == KEY_W)
		view->keys->w = toggle;
	if (keycode == KEY_S)
		view->keys->s = toggle;
	if (keycode == KEY_A)
		view->keys->a = toggle;
	if (keycode == KEY_D)
		view->keys->d = toggle;
	if (keycode == KEY_UP)
		view->keys->up = toggle;
	if (keycode == KEY_DOWN)
		view->keys->down = toggle;
	if (keycode == KEY_LEFT)
		view->keys->left = toggle;
	if (keycode == KEY_RIGHT)
		view->keys->right = toggle;
}

static void	toggle_set_2(int keycode, t_view *view, int toggle)
{
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

static void	toggle_set_3(int keycode, t_view *view, int toggle)
{
	printf("toggle set 3 key code = %#x\n", keycode);
	if (keycode == KEY_X)
		view->keys->x = toggle;
	if (keycode == KEY_Y)
		view->keys->y = toggle;
	//if (keycode == KEY_Z)
	if (keycode == 'z' || keycode == 'Z')
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
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	printf("Toggle to %d keycode in = %c(%#x)\n", toggle, keycode, keycode);
	view->keys->status = toggle;
	toggle_set_1(keycode, view, toggle);
	toggle_set_2(keycode, view, toggle);
	toggle_set_3(keycode, view, toggle);

}
