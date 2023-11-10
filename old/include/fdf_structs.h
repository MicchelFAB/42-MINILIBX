/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:33:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:36:53 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

/*------LIBRARIES------*/

/* ************************************************************************** */
///	GENERIC LIBRARIES
/* ************************************************************************** */

# include "colors.h"
# include "keys.h"

/* ************************************************************************** */
///	SPECIFIC LIBRARIES
/* ************************************************************************** */

# include "fdf_constants.h"

/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */

/* ************************************************************************** */
// Data Source file management:
// handle and validate file structure which contains teach point in map.
/* ************************************************************************** */
typedef struct s_flags
{
	int		c;
	int		r;
	char	*file;
	int		fd;
	int		aux01;
	int		len;
	char	*line;
	char	**cmx;
	int		**imx;
	float	**fmx;
}					t_flags;

/* ************************************************************************** */
// Single point :
//   x, y, z, color values for each point in map.
/* ************************************************************************** */
typedef struct s_pxyz
{
	float	x;
	float	y;
	float	z;
	int		trgb;
}	t_pxyz;

typedef struct s_pxy
{
	float	x;
	float	y;
	int		trgb;
}	t_pxy;

/* ************************************************************************** */
// Vector 3d :
//   x, y, z, vectors.
//   used to handle scale, rotation and translation.
/* ************************************************************************** */
typedef struct s_v3d
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_v3d;

/* ************************************************************************** */
// Vector 2d :
//   x, y, vectors.
//   used to handle screen projection.
/* ************************************************************************** */
typedef struct s_v2d
{
	float	x;
	float	y;
}	t_v2d;

/* ************************************************************************** */
// Triangle 3d :
//   x, y, z, triangle, the basic primitive shape to handle solid objects.
//   any solid object might be represented by a set of triangles.
/* ************************************************************************** */
typedef struct s_tri
{
	t_v3d	p[3];
}	t_tri;

/* ************************************************************************** */
// Object 3d :
//   x, y, z, object, built with the basic primitive shape triangle.
//   any solid object might be represented by a set of triangles.
///   mesh is a set of triangles.
///   *tris is a pointer to the first triangle in the mesh.
///   n_tris is the number of triangles in the mesh.
/* ************************************************************************** */

typedef struct s_mesh
{
	t_tri	*tris;
	int		ntris;
}	t_mesh;

/* ************************************************************************** */
/// Map parsed information ;
//   matrix size max X by max Y, maximum and minimum Z value;
//   The map is created with all of its points in **coordinates,
//   total width, depth and height values passed.
/* ************************************************************************** */
typedef struct s_map
{
	t_pxyz	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}	t_map;

/* ************************************************************************** */
// line to be plotted on fdf area.
/* ************************************************************************** */
typedef struct s_line
{
	t_pxyz	p0;
	t_pxyz	pn;
	float	trsfrm_z;
}	t_line;

/* ************************************************************************** */
/// Color: for the fdf line plot. (t_line)
/* ************************************************************************** */
typedef struct s_color
{
	int	start_color;
	int	start_r;
	int	start_g;
	int	start_b;
	int	end_color;
	int	end_r;
	int	end_g;
	int	end_b;
	int	delta_r;
	int	delta_g;
	int	delta_b;
}	t_color;

/* ************************************************************************** */
// Image data structure:
//  holds information given by MiniLibX:
//  img pointer
//  pixel area buffer pointer
//  bits per pixel, line size and endianess
//  current line to be transfered into the buffer.
/* ************************************************************************** */
typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_line	*line;
}	t_image;

/* ************************************************************************** */
// View information:
//  projection type, scale,
//  translation delta and
//  three axes angle (alpha, beta, gamma) values for rotation.
/* ************************************************************************** */
typedef struct s_view
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}	t_view;

/* ************************************************************************** */
// mlx data structure:
///  mlx pointer, window pointer, image pointer, image buffer pointer,
///  bits per pixel, line length and endianess.
///  background color
/* ************************************************************************** */
typedef struct s_win_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		color;
}				t_win_data;

// commented out because it is not used.
// 2021/10/05 13:25:21 by antoda-s
// typedef struct s_wdata
// {
// 	void	*mlx;
// 	void	*win;
// 	t_image	*img;
// }				t_wdata;

typedef struct s_mlx_pixel
{
	int		x;
	int		y;
	int		color;
}				t_mlx_pixel;

typedef struct s_mlx_line
{
	int		x0;
	int		y0;
	int		xn;
	int		yn;
	int		color;
	int		dx;
	int		dy;
	int		sdx;
	int		sdy;
	int		ek;
	int		swap_xy;
	int		xk;
	int		yk;
	int		k;
}				t_mlx_line;

typedef struct s_m_line
{
	t_mlx_pixel	p0;
	t_mlx_pixel	pn;
	t_mlx_pixel	pk;
	int			dx;
	int			dy;
	int			sdx;
	int			sdy;
	int			ek;
	int			swap_xy;
	int			k;
}				t_m_line;

typedef struct s_mlx_circle
{
	int		x;
	int		y;
	int		radius;
	int		color;
}				t_mlx_circle;

typedef struct s_mlx_square
{
	int		x;
	int		y;
	int		size;
	int		color;
}				t_mlx_square;

typedef struct s_mlx_rect
{
	int		x;
	int		y;
	int		w;
	int		h;
	int		color;
}				t_mlx_rect;

#endif
