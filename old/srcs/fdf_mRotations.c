/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mRotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:59:43 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 07:38:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

void	rotation_x(t_v3d *i, t_v3d *o, float theta)
{
	o->x = i->x;
	o->y = i->y * cos(theta) - i->z * sin(theta);
	o->z = i->y * sin(theta) + i->z * cos(theta);
	return ;
}

void	rotation_x(t_v3d *i, t_v3d *o, float theta)
{
	o->x = i->x * cos(theta) + i->z * sin(theta);
	o->y = i->y;
	o->z = i->x * -sin(theta) + i->z * cos(theta);
	return ;
}

void	rotation_z(t_v3d *i, t_v3d *o, float theta)
{
	o->x = i->x * cos(theta) - i->y * sin(theta);
	o->y = i->x * sin(theta) + i->y * cos(theta);
	o->z = i->z;
	return ;
}

void	rotation(t_v3d *i, t_v3d *o, float thetaX, float thetaY, float thetaZ)
{
	t_v3d	tmp;

	rotation_x(i, &tmp, thetaX);
	rotation_x(&tmp, o, thetaY);
	rotation_z(o, &tmp, thetaZ);
	*o = tmp;
	return ;
}

void	rotation_any_axis(t_v3d *i, t_v3d *o, t_v3d *ax, float theta)
{
	t_v3d	tmp;
	t_v3d	axis;

	axis = *ax;
	normalize(&axis);
	tmp.x = (axis.x * axis.x) * (1 - cos(theta)) + cos(theta);
	tmp.y = (axis.x * axis.y) * (1 - cos(theta)) - axis.z * sin(theta);
	tmp.z = (axis.x * axis.z) * (1 - cos(theta)) + axis.y * sin(theta);
	o->x = i->x * tmp.x + i->y * tmp.y + i->z * tmp.z;
	tmp.x = (axis.y * axis.x) * (1 - cos(theta)) + axis.z * sin(theta);
	tmp.y = (axis.y * axis.y) * (1 - cos(theta)) + cos(theta);
	tmp.z = (axis.y * axis.z) * (1 - cos(theta)) - axis.x * sin(theta);
	o->y = i->x * tmp.x + i->y * tmp.y + i->z * tmp.z;
	tmp.x = (axis.z * axis.x) * (1 - cos(theta)) - axis.y * sin(theta);
	tmp.y = (axis.z * axis.y) * (1 - cos(theta)) + axis.x * sin(theta);
	tmp.z = (axis.z * axis.z) * (1 - cos(theta)) + cos(theta);
	o->z = i->x * tmp.x + i->y * tmp.y + i->z * tmp.z;
	return ;
}
