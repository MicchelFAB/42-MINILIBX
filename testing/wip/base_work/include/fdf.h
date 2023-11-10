/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 20:13:58 by myoung            #+#    #+#             */
/*   Updated: 2023/10/24 19:45:28 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
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
# include "keys.h"
# include "gfx.h"
# include "fdf_constants.h"
# include "fdf_debug.h"
# include "colors.h"

# ifndef PI
#  define PI 3.14159265358979323846
# endif

# ifndef M_PI
#  define M_PI 1.57079632678
# endif

void		fdf(t_view *view);

// static void	parse_points(t_view *view, int fd);
// static void	pre_parse(t_view *view, int fd);
void		parse(t_view *view, char *filename);


//int			mouse_hook(int button, int x, int y, t_view *view);
int			hook_exit(t_view *view);
void		hook_view_set(t_view *view);
void		hook_color(t_view *view);
void		hook_scale(t_view *view);
void		translate_hook(t_view *view);
void		toggle_pressed(int keycode, t_view *view, int toggle);
int			hook_key_press(int keycode, t_view *view);
int			hook_key_release(int keycode, t_view *view);
int			expose_hook(t_view *view);
int			my_loop_hook(t_view *view);
void		hook_zoom(t_view *view);

void		redraw(t_view *view);
void		full_redraw(t_view *view);
void		draw_wireframe(t_view *view);
void		draw_projected(t_view *view);

void		local_to_world(t_view *view);
void		world_to_aligned(t_view *view);
void		aligned_to_projected(t_view *view);

t_view		*new_map(void);
void		keys_init(t_view *view);
void		keys_show(t_view *v);
void		use_view_image(t_view *view);
void		create_view_image(t_view *view);

void		init_color_table(t_view *view, int colors);

void		mat_bzero(float mat[4][4]);
void		get_id_matrix(float mat[4][4]);

void		vec_mat_mult(t_3dp *src, float mat[4][4], t_3dp *dst);

void		mat_mult(float m1[4][4], float m2[4][4], float p[4][4]);
void		mat_translate(float p[4][4], float x, float y, float z);
void		mat_scale(float p[4][4], float x, float y, float z);
void		mat_rotate(float p[4][4], float theta, float phi, float psi);

void		draw_point(t_view *view, int x, int y, float z);
void		drawline(t_view *view, t_3dp p0, t_3dp p1);

t_2dp		*get_2dp(float x, float y);
t_3dp		*get_3dp(float x, float y, float z);

t_vertex	*get_vertex(float x, float y, float z);

#endif
