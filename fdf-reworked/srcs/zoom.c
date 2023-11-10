/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 22:01:22 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 02:30:26 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	t_hook_show(t_view *v)
{
	printf("v->x_shift = %f\n", v->x_shift);
	printf("v->y_shift = %f\n", v->y_shift);
}

void	translate_hook(t_view *v)
{

	printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);

	if (v->keys->l || v->keys->right)
		v->x_shift++;
	else if (v->keys->j || v->keys->left)
		v->x_shift--;
	if (v->keys->k || v->keys->down)
		v->y_shift++;
	else if (v->keys->i || v->keys->up)
		v->y_shift--;
	//t_hook_show(v);
	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

static void	zoom_hook(t_view *v)
{

	printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);

	if (!v->keys->x && !v->keys->y && !v->keys->z)
	{
		if (v->keys->plus)
			v->scale += 0.1;
		if (v->keys->minus)
			v->scale -= 0.1;
	}

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	scale_hook_work(t_view *v)
{
	printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);

	if (v->keys->x)
	{
		if (v->keys->plus)
			v->x_scale += 0.1;
		if (v->keys->minus)
			v->x_scale -= 0.1;
	}
	if (v->keys->y)
	{
		if (v->keys->plus)
			v->y_scale += 0.1;
		if (v->keys->minus)
			v->y_scale -= 0.1;
	}
	if (v->keys->z)
	{
		if (v->keys->plus)
			v->z_scale += 0.1;
		if (v->keys->minus)
			v->z_scale -= 0.1;
	}
	zoom_hook(v);
	full_redraw(v);

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
