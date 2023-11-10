/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/26 00:52:54 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
//#include "../include/libgfx.h"

void	mx_zero(float mat[4][4])
{
	ft_bzero(mat[0], sizeof(float) * 4);
	ft_bzero(mat[1], sizeof(float) * 4);
	ft_bzero(mat[2], sizeof(float) * 4);
	ft_bzero(mat[3], sizeof(float) * 4);
}

void	mx_id(float mat[4][4])
{
	mx_zero(mat);
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
}

void	mx_mul(float m1[4][4], float m2[4][4], float dst[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dst[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
	}
}

void	mx_t(float mat[4][4], float x, float y, float z)
{
	float	tran_mat[4][4];

	mx_id(tran_mat);
	tran_mat[3][0] = x;
	tran_mat[3][1] = y;
	tran_mat[3][2] = z;
	mx_mul(mat, tran_mat, mat);
}

/// @brief 			Scale matrix
/// @param mat		Matrix to scale
/// @param x		X scale
/// @param y		Y scale
/// @param z		Z scale
void	mx_s(float mat[4][4], float x, float y, float z)
{
	float	scale_mat[4][4];

	mx_zero(scale_mat);
	scale_mat[0][0] = x;
	scale_mat[1][1] = y;
	scale_mat[2][2] = z;
	scale_mat[3][3] = 1;
	mx_mul(mat, scale_mat, mat);
}
