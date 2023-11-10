/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:59:31 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/09 22:03:36 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	mat_rotx(float mat[4][4], float theta)
{
	mat_bzero(mat);
	mat[0][0] = 1;
	mat[1][1] = cos(theta);
	mat[1][2] = sin(theta);
	mat[2][1] = -sin(theta);
	mat[2][2] = cos(theta);
	mat[3][3] = 1;
}

static void	mat_roty(float mat[4][4], float phi)
{
	mat_bzero(mat);
	mat[0][0] = cos(phi);
	mat[0][2] = -sin(phi);
	mat[1][1] = 1;
	mat[2][0] = sin(phi);
	mat[2][2] = cos(phi);
	mat[3][3] = 1;
}

static void	mat_rotz(float mat[4][4], float psi)
{
	mat_bzero(mat);
	mat[0][0] = cos(psi);
	mat[0][1] = sin(psi);
	mat[1][0] = -sin(psi);
	mat[1][1] = cos(psi);
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void	mat_rotate(float mat[4][4], float theta, float phi, float psi)
{
	float	rotx[4][4];
	float	roty[4][4];
	float	rotz[4][4];
	float	mat1[4][4];
	float	mat2[4][4];

	mat_rotx(rotx, theta);
	mat_roty(roty, phi);
	mat_rotz(rotz, psi);
	mat_mult(mat, roty, mat1);
	mat_mult(mat1, rotx, mat2);
	mat_mult(mat2, rotz, mat);
}

void	vec_mat_mult(t_3dp *src, float mat[4][4], t_3dp *dst)
{
	dst->x = src->x * mat[0][0] + src->y * mat[1][0]
		+ src->z * mat[2][0] + mat[3][0];
	dst->y = src->x * mat[0][1] + src->y * mat[1][1]
		+ src->z * mat[2][1] + mat[3][1];
	dst->z = src->x * mat[0][2] + src->y * mat[1][2]
		+ src->z * mat[2][2] + mat[3][2];
}
