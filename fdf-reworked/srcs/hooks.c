/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:26:48 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 02:24:29 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	exit_hook(t_view *v)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	mlx_destroy_window(v->id, v->win);
	mlx_do_key_autorepeaton(v->id);
	exit(0);
}

int	expose_hook(t_view *v)
{

	//if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	redraw(v);
	//if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

void	rotate_hook(t_view *v)
{
	if (v->keys->w)
		v->theta += 0.05;
	if (v->keys->s)
		v->theta -= 0.05;
	if (v->keys->a)
		v->phi -= 0.05;
	if (v->keys->d)
		v->phi += 0.05;
	if (v->keys->q)
		v->psi += 0.05;
	if (v->keys->e)
		v->psi -= 0.05;
}

int	my_loop_hook(t_view *v)
{
	//if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
		usleep(10000);
	printf("00 =====================\n");
	//xx=====x======if (_SHOW_KEY_)
	//	keys_show(v);
	if (v->keys->c)
		color_hook(v);
	printf("01 =====================\n");
	translate_hook(v);
	rotate_hook(v);
	// if (v->keys->w)
	// 	v->theta += 0.05;
	// if (v->keys->s)
	// 	v->theta -= 0.05;
	// if (v->keys->a)
	// 	v->phi -= 0.05;
	// if (v->keys->d)
	// 	v->phi += 0.05;
	// if (v->keys->q)
	// 	v->psi += 0.05;
	// if (v->keys->e)
	// 	v->psi -= 0.05;
	if (v->keys->o && v->focal_dist < 9)
		v->focal_dist++;
	if (v->keys->p && v->focal_dist > 0)
		v->focal_dist--;
	if (v->keys->minus || v->keys->plus)
		scale_hook_work(v);
	else if (v->keys->status)
		redraw(v);
	printf("02 =====================\n");

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);

	return (0);
}

int	key_press_hook(int keycode, t_view *v)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);


	printf("Pressed keycode in = %c(%#x)\n", keycode,keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_M)
		v->project = v->project ? 0 : 1;
	toggle_pressed(keycode, v, 1);

	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}

int	key_release_hook(int keycode, t_view *v)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	printf("Release key code in = %c(%#x)\n", keycode,keycode);
	toggle_pressed(keycode, v, 0);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	return (0);
}
