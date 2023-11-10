/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgfx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 03:27:52 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 11:22:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H

# include "math.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

# define WIN_W 800
# define WIN_H 800

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# ifndef M_PI
#  define M_PI 1.57079632678
# endif

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
	t_keys		*keys;
	int			project;
}				t_view;

//void			toggle_pressed(int keycode, t_view *view, int toggle);
void			use_view_image(t_view *view);
void			create_view_image(t_view *view);

void			init_color_table(t_view *view, int colors);

void			mx_zero(float mat[4][4]);
void			mx_id(float mat[4][4]);

void			v_mx_mul(t_3dp *src, float mat[4][4], t_3dp *dst);

void			mx_mul(float m1[4][4], float m2[4][4], float p[4][4]);
void			mx_t(float p[4][4], float x, float y, float z);
void			mx_s(float p[4][4], float x, float y, float z);
void			mx_r(float p[4][4], float theta, float phi, float psi);

void			draw_point(t_view *view, int x, int y, float z);
void			draw_line(t_view *view, t_3dp p0, t_3dp p1);

t_2dp			*get_2dp(float x, float y);
t_3dp			*get_3dp(float x, float y, float z);
t_vertex		*get_vertex(float x, float y, float z);
#endif
