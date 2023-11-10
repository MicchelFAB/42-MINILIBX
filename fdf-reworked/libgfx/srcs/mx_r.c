/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:18:37 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/26 00:33:49 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
//#include "../include/libgfx.h"

static void	mx_rx(float mat[4][4], float theta)
{
	mx_zero(mat);
	mat[0][0] = 1;
	mat[1][1] = cos(theta);
	mat[1][2] = sin(theta);
	mat[2][1] = -sin(theta);
	mat[2][2] = cos(theta);
	mat[3][3] = 1;
}

static void	mx_ry(float mat[4][4], float phi)
{
	mx_zero(mat);
	mat[0][0] = cos(phi);
	mat[0][2] = -sin(phi);
	mat[1][1] = 1;
	mat[2][0] = sin(phi);
	mat[2][2] = cos(phi);
	mat[3][3] = 1;
}

static void	mx_rz(float mat[4][4], float psi)
{
	mx_zero(mat);
	mat[0][0] = cos(psi);
	mat[0][1] = sin(psi);
	mat[1][0] = -sin(psi);
	mat[1][1] = cos(psi);
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void	mx_r(float mat[4][4], float theta, float phi, float psi)
{
	float	rotx[4][4];
	float	roty[4][4];
	float	rotz[4][4];
	float	mat1[4][4];
	float	mat2[4][4];

	mx_rx(rotx, theta);
	mx_ry(roty, phi);
	mx_rz(rotz, psi);
	mx_mul(mat, roty, mat1);
	mx_mul(mat1, rotx, mat2);
	mx_mul(mat2, rotz, mat);
}

void	v_mx_mul(t_3dp *src, float mat[4][4], t_3dp *dst)
{
	dst->x = src->x * mat[0][0]
		+ src->y * mat[1][0]
		+ src->z * mat[2][0] + mat[3][0];
	dst->y = src->x * mat[0][1]
		+ src->y * mat[1][1]
		+ src->z * mat[2][1] + mat[3][1];
	dst->z = src->x * mat[0][2]
		+ src->y * mat[1][2]
		+ src->z * mat[2][2] + mat[3][2];
}
