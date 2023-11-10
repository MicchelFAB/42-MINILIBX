/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:27:57 by myoung            #+#    #+#             */
/*   Updated: 2023/10/24 23:12:16 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	local_to_world(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	get_id_matrix(global);
	mat_translate(global, -(view->width / 2), -(view->height / 2), 0);
	mat_scale(global, view->x_scale, view->y_scale, view->z_scale);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			vec_mat_mult(view->points[y][x]->local, global,
				view->points[y][x]->world);
		}
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

void	world_to_aligned(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	get_id_matrix(global);
	mat_rotate(global, view->theta, view->phi, view->psi);
	mat_scale(global, (WIN_WIDTH * view->scale) / view->width,
		(WIN_HEIGHT * view->scale) / view->height, view->scale);

	mat_translate(global, (view->project) ? view->x_shift :
		view->x_shift + WIN_WIDTH / 2,
		(view->project) ? view->y_shift : view->y_shift + WIN_HEIGHT / 2,
		view->z_shift);

	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			vec_mat_mult(view->points[y][x]->world, global,
				view->points[y][x]->aligned);
			view->points[y][x]->aligned->z =
				(view->project) * view->points[y][x]->aligned->z
				+ (!view->project) * view->points[y][x]->local->z;
		}
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

void	aligned_to_projected(t_view *view)
{
	float	global[4][4];
	int		y;
	int		x;

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	get_id_matrix(global);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (!view->points[y][x]->aligned->z)
				view->points[y][x]->aligned->z = 0.001;
			view->points[y][x]->projected->x = view->focal_dist
				* view->points[y][x]->aligned->x
				/ (view->z_max - view->points[y][x]->aligned->z)
				+ WIN_WIDTH / 2;
			view->points[y][x]->projected->y = view->focal_dist
				* view->points[y][x]->aligned->y
				/ (view->z_max - view->points[y][x]->aligned->z)
				+ WIN_HEIGHT / 2;
			view->points[y][x]->projected->z = view->points[y][x]->local->z;
		}
	}
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

t_view	*new_map(void)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view));
	view->project = 0;
	view->theta = 0.0;
	view->phi = 0.0;
	view->psi = 0.0;
	view->scale = 0.5;
	view->x_scale = 1;
	view->y_scale = 1;
	view->z_scale = 1;
	view->x_shift = 0.0;
	view->y_shift = 0.0;
	view->z_shift = 0.0;
	view->focal_dist = 7;
	view->r = 1;
	view->g = 1;
	view->b = 1;
	view->id = mlx_init();
	view->win = mlx_new_window(view->id, WIN_WIDTH, WIN_HEIGHT, "FDF 42");
	view->pressed = (t_keys *)malloc(sizeof(t_keys));
	//keys_init(view);
	return (view);
}

void	keys_init(t_view *view)
{
	view->pressed->c = 0;
	view->pressed->semi = 0;
	view->pressed->i = 0;
	view->pressed->j = 0;
	view->pressed->k = 0;
	view->pressed->l = 0;
	view->pressed->m = 0;
	view->pressed->n = 0;
	view->pressed->o = 0;
	view->pressed->p = 0;

	view->pressed->q = 0;
	view->pressed->w = 0;
	view->pressed->e = 0;
	view->pressed->a = 0;
	view->pressed->s = 0;
	view->pressed->d = 0;

	view->pressed->x = 0;
	view->pressed->y = 0;
	view->pressed->z = 0;

	view->pressed->left = 0;
	view->pressed->up = 0;
	view->pressed->right = 0;
	view->pressed->down = 0;
	view->pressed->plus = 0;
	view->pressed->minus = 0;
}

void	keys_show(t_view *v)
{
	printf("****************************************\n");
	printf("view->pressed->c = %i\n", v->pressed->c);
	printf("view->pressed->semi = %i\n", v->pressed->semi);
	printf("view->pressed->i = %i\n", v->pressed->i);
	printf("view->pressed->j = %i\n", v->pressed->j);
	printf("view->pressed->k = %i\n", v->pressed->k);
	printf("view->pressed->l = %i\n", v->pressed->l);
	printf("view->pressed->m = %i\n", v->pressed->m);
	printf("view->pressed->n = %i\n", v->pressed->n);
	printf("view->pressed->o = %i\n", v->pressed->o);
	printf("view->pressed->p = %i\n", v->pressed->p);

	printf("view->pressed->q = %i\n", v->pressed->q);
	printf("view->pressed->w = %i\n", v->pressed->w);
	printf("view->pressed->e = %i\n", v->pressed->e);
	printf("view->pressed->a = %i\n", v->pressed->a);
	printf("view->pressed->s = %i\n", v->pressed->s);
	printf("view->pressed->d = %i\n", v->pressed->d);

	printf("view->pressed->x = %i\n", v->pressed->x);
	printf("view->pressed->y = %i\n", v->pressed->y);
	printf("view->pressed->z = %i\n", v->pressed->z);

	printf("view->pressed->left = %i\n", v->pressed->left);
	printf("view->pressed->up = %i\n", v->pressed->up);
	printf("view->pressed->right = %i\n", v->pressed->right);
	printf("view->pressed->down = %i\n", v->pressed->down);
	printf("view->pressed->plus = %i\n", v->pressed->plus);
	printf("view->pressed->minus = %i\n", v->pressed->minus);

}
