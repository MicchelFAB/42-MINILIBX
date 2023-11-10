/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mTransforms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:34:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 07:50:15 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

// Define the camera position
double camX = 0;
double camY = 0;
double camZ = -10;

// Define the field of view
double fov = 60;

// Define the screen dimensions
int screenWidth = 800;
int screenHeight = 600;

// Define the projection matrix
double p_mx[4][4] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 1/camZ, 0}
};

// Define the transformation matrix
double t_mx[4][4] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
};

// Define a function to project a 3D point to a 2D point
//void project(double x, double y, double z, double *x2d, double *y2d) {
void	project(t_v3d *v3, t_v2d *v2)
{
	t_v3d	vT;
	t_v3d	vP;

	// Apply the transformation matrix
	vT.x = v3->x * t_mx[0][0] + v3->y * t_mx[1][0] + v3->z * t_mx[2][0] + t_mx[3][0];
	vT.y = v3->x * t_mx[0][1] + v3->y * t_mx[1][1] + v3->z * t_mx[2][1] + t_mx[3][1];
	vT.z = v3->x * t_mx[0][2] + v3->y * t_mx[1][2] + v3->z * t_mx[2][2] + t_mx[3][2];
	vT.w = v3->x * t_mx[0][3] + v3->y * t_mx[1][3] + v3->z * t_mx[2][3] + t_mx[3][3];

	// Apply the projection matrix
	vP.x = vT.x * p_mx[0][0] + vT.y * p_mx[1][0] + vT.z * p_mx[2][0] + vT.z * p_mx[3][0];
	vP.y = vT.x * p_mx[0][1] + vT.y * p_mx[1][1] + vT.z * p_mx[2][1] + vT.z* p_mx[3][1];
	vP.z = vT.x * p_mx[0][2] + vT.y * p_mx[1][2] + vT.z * p_mx[2][2] + vT.z * p_mx[3][2];
	vP.w = vT.x * p_mx[0][3] + vT.y * p_mx[1][3] + vT.z * p_mx[2][3] + vT.z * p_mx[3][3];

	// Normalize the projected coordinates
	v2->x = (vP.x / vP.w + 1) * screenWidth / 2;
	v2->y = (vP.y / vP.w + 1) * screenHeight / 2;
}
