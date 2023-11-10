/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:59:43 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/05 13:35:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

void	dot_product(t_v3d *a, t_v3d *b, t_v3d *c)
{
	c->x = a->x * b->x;
	c->y = a->y * b->y;
	c->z = a->z * b->z;
	return ;
}

void	cross_product(t_v3d *a, t_v3d *b, t_v3d *c)
{
	c->x = a->y * b->z - a->z * b->y;
	c->y = a->z * b->x - a->x * b->z;
	c->z = a->x * b->y - a->y * b->x;
	return ;
}

float	vect_magn(t_v3d *a)
{
	return (sqrt(a->x * a->x + a->y * a->y + a->z * a->z));
}

void	normalize(t_v3d *a)
{
	float	magnitude;

	magnitude = vect_magn(a);
	a->x /= magnitude;
	a->y /= magnitude;
	a->z /= magnitude;
	return ;
}

float	dot_product_2d(t_v2d *a, t_v2d *b)
{
	return (a->x * b->x + a->y * b->y);
}
