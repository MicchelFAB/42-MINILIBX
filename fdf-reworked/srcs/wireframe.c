/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 05:27:57 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 01:56:38 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	local_to_world(t_view *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_id(mx);
	mx_t(mx, -(v->width / 2), -(v->height / 2), 0);
	mx_s(mx, v->x_scale, v->y_scale, v->z_scale);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->local, mx,
				v->points[y][x]->world);
		}
	}

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	world_to_aligned(t_view *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_id(mx);
	mx_r(mx, v->theta, v->phi, v->psi);
	mx_s(mx, (WIN_W * v->scale) / v->width,
		(WIN_H * v->scale) / v->height, v->scale);
	if (v->project)
		mx_t(mx, v->x_shift, v->y_shift, v->z_shift);
	else
		mx_t(mx, v->x_shift + WIN_W / 2, v->y_shift + WIN_H / 2, v->z_shift);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			v_mx_mul(v->points[y][x]->world, mx, v->points[y][x]->aligned);
			//v->points[y][x]->aligned->z = v->project ? v->points[y][x]->aligned->z : v->points[y][x]->local->z;
			if (!v->project)
				v->points[y][x]->aligned->z = v->points[y][x]->local->z;
		}
	}
	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	aligned_to_projected(t_view *v)
{
	float	mx[4][4];
	int		y;
	int		x;
	printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	mx_id(mx);
	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (!v->points[y][x]->aligned->z)
				v->points[y][x]->aligned->z = 0.001;
			v->points[y][x]->projected->x = v->focal_dist
				* v->points[y][x]->aligned->x
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ WIN_W / 2;
			v->points[y][x]->projected->y = v->focal_dist
				* v->points[y][x]->aligned->y
				/ (v->z_max - v->points[y][x]->aligned->z)
				+ WIN_H / 2;
			v->points[y][x]->projected->z = v->points[y][x]->local->z;
		}
	}
	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}


t_view	*init_v(void)
{
	t_view	*v;

	v = (t_view *)malloc(sizeof(t_view));
	v->project = 0;
	v->theta = 0.0;
	v->phi = 0.0;
	v->psi = 0.0;
	v->scale = 0.5;
	v->x_scale = 1;
	v->y_scale = 1;
	v->z_scale = 1;
	v->x_shift = 0.0;
	v->y_shift = 0.0;
	v->z_shift = 0.0;
	v->focal_dist = 7;
	v->r = 1;
	v->g = 1;
	v->b = 1;
	v->id = mlx_init();
	v->win = mlx_new_window(v->id, WIN_W, WIN_H, "FDF 42");
	v->keys = (t_keys *)malloc(sizeof(t_keys));
	keys_init(v);
	return (v);
}

void	keys_init(t_view *v)
{
	v->keys->status = 0;
	v->keys->c = 0;
	v->keys->semi = 0;
	v->keys->i = 0;
	v->keys->j = 0;
	v->keys->k = 0;
	v->keys->l = 0;
	v->keys->m = 0;
	v->keys->n = 0;
	v->keys->o = 0;
	v->keys->p = 0;

	v->keys->q = 0;
	v->keys->w = 0;
	v->keys->e = 0;
	v->keys->a = 0;
	v->keys->s = 0;
	v->keys->d = 0;

	v->keys->x = 0;
	v->keys->y = 0;
	v->keys->z = 0;

	v->keys->left = 0;
	v->keys->up = 0;
	v->keys->right = 0;
	v->keys->down = 0;
	v->keys->plus = 0;
	v->keys->minus = 0;
}

void	keys_show(t_view *v)
{
	printf("****************************************\n");
	printf("v->keys->status = %i\n", v->keys->status);
	printf("v->keys->a = %i\n", v->keys->a);
	printf("v->keys->b = %i\n", v->keys->b);
	printf("v->keys->c = %i\n", v->keys->c);
	printf("v->keys->d = %i\n", v->keys->d);
	printf("v->keys->e = %i\n", v->keys->e);
	printf("v->keys->f = %i\n", v->keys->f);
	printf("v->keys->g = %i\n", v->keys->g);
	printf("v->keys->h = %i\n", v->keys->h);
	printf("v->keys->i = %i\n", v->keys->i);
	printf("v->keys->j = %i\n", v->keys->j);
	printf("v->keys->k = %i\n", v->keys->k);
	printf("v->keys->l = %i\n", v->keys->l);
	printf("v->keys->m = %i\n", v->keys->m);
	printf("v->keys->n = %i\n", v->keys->n);
	printf("v->keys->o = %i\n", v->keys->o);
	printf("v->keys->p = %i\n", v->keys->p);
	printf("v->keys->q = %i\n", v->keys->q);
	printf("v->keys->r = %i\n", v->keys->r);
	printf("v->keys->s = %i\n", v->keys->s);
	printf("v->keys->t = %i\n", v->keys->t);
	printf("v->keys->u = %i\n", v->keys->u);
	printf("v->keys->v = %i\n", v->keys->v);
	printf("v->keys->w = %i\n", v->keys->w);
	printf("v->keys->x = %i\n", v->keys->x);
	printf("v->keys->y = %i\n", v->keys->y);
	printf("v->keys->z = %i\n", v->keys->z);
	printf("v->keys->tab = %i\n", v->keys->tab);
	printf("v->keys->semi = %i\n", v->keys->semi);
	printf("v->keys->brace_l = %i\n", v->keys->brace_l);
	printf("v->keys->brace_r = %i\n", v->keys->brace_r);
	printf("v->keys->plus = %i\n", v->keys->plus);
	printf("v->keys->minus = %i\n", v->keys->minus);
	printf("v->keys->up = %i\n", v->keys->up);
	printf("v->keys->down = %i\n", v->keys->down);
	printf("v->keys->left = %i\n", v->keys->left);
	printf("v->keys->right = %i\n", v->keys->right);
}
