/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:46:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:55:28 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include <math.h>

# define WIN_WIDTH 1600
# define WIN_HEIGHT 1200

typedef int		t_color;

typedef struct s_2dp
{
	float		x;
	float		y;
}				t_2dp;

typedef struct s_3dp
{
	float		x;
	float		y;
	float		z;
}				t_3dp;

typedef struct s_vertex
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*aligned;
	t_3dp		*projected;
	t_color		color;
}				t_vertex;

typedef struct s_view
{
	void		*id;
	void		*win;
	void		*img;
	char		*pixels;
	t_vertex	***points;
	t_color		*colors;
	int			num_colors;
	int			width;
	int			height;
	int			z_min;
	int			z_max;
	float		theta;
	float		phi;
	float		psi;
	float		x_scale;
	float		y_scale;
	float		z_scale;
	float		scale;
	float		x_shift;
	float		y_shift;
	float		z_shift;
	float		r;
	float		g;
	float		b;
	int			focal_dist;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_keys		*pressed;
	int			project:1;
}				t_view;

#endif
