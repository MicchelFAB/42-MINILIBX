/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:33:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/10 19:48:30 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFDF_H
# define MYFDF_H

/*------LIBRARIES------*/

/*
** Basic libraries for the previous allowed functions: open, read, write, close,
** malloc, free, perror, strerror and exit.
*/
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** Allowed libraries: math and minilibx, witch is appended in the project's
** folder to guarantee usage by testers.
*/
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include "../minilibx/mlx.h"

/*
** My own libft library, completed with previously implemented functions such as
** get_next_line and ft_printf.
*/
# include "../libft/libft.h"
# include "../libft/gnl.h"
/*
** Other fdf libraries
*/
# include "keys.h"
# include "colors.h"
# include "fdf_constants.h"
# include "fdf_structs.h"
# include "fdf_debug.h"

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */
int				mlx_tester(void);
int				args_start(t_flags *f);

/* ************************************************************************** */
/// objects - pixel
/* ************************************************************************** */
void			mlx_pixel_s(t_win_data *img, t_mlx_pixel *pixel);
void			mlx_pixel_tester(t_win_data *img);
/* ************************************************************************** */
/// objects - square
/* ************************************************************************** */
void			mlx_square(t_win_data *img, t_mlx_square *sq);
void			mlx_square_tester(t_win_data *win_data);
/* ************************************************************************** */
/// objects - rectangle
/* ************************************************************************** */
void			mlx_rectangle_corners(t_win_data *img, t_mlx_rect *rt);
void			mlx_rectangle_sides(t_win_data *img, t_mlx_rect *rt);
void			mlx_rectangle_face(t_win_data *img, t_mlx_rect *rt);
void			mlx_rectangle_tester(t_win_data *win_data);
void			mlx_rectangle_menu(t_win_data *img);
/* ************************************************************************** */
/// objects - line
/* ************************************************************************** */
void			mlx_line_s_init(t_mlx_line *line);
void			mlx_line(t_win_data *img, t_mlx_line *line);
void			mlx_line_c(t_win_data *img, t_mlx_line *l);
void			mlx_line_tester_diagonals(t_win_data *img);
void			mlx_line_tester(t_win_data *img);
/* ************************************************************************** */
/// objects - circle
/* ************************************************************************** */
void			mlx_circle_(t_win_data *img, t_mlx_circle *circle);
void			mlx_circle_tester(t_win_data *win);
/* ************************************************************************** */
/// clock (test)
/* ************************************************************************** */
void			mlx_clock_secs_hand(t_win_data *img, t_mlx_circle *c);
void			clock_frame(t_win_data *img, int thick, t_mlx_circle *circle);
void			mlx_clock(t_win_data *img);
/* ************************************************************************** */
/// maths
/* ************************************************************************** */
int				abs_i(int n);
void			ft_abs(double *n);
double			abs_d(double n);
int				max_i(int a, int b);
int				min_i(int a, int b);
char			sign_d(double n);
int				my_round(double n);
int				ft_roundf(float n);
int				ft_swap(int *a, int *b);
/* ************************************************************************** */
/// colors
/* ************************************************************************** */
int				get_trgb_c(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b);
unsigned char	get_t_c(int trgb);
unsigned char	get_r_c(int trgb);
unsigned char	get_g_c(int trgb);
unsigned char	get_b_c(int trgb);
int				get_trgb_i(int t, int r, int g, int b);
int				get_t_i(int trgb);
int				get_r_i(int trgb);
int				get_g_i(int trgb);
int				get_b_i(int trgb);
/* ************************************************************************** */
/// args
/* ************************************************************************** */
t_flags			*flags_init(int ac, char **av);

int				args_build(t_flags *f);
void			args_print(t_flags *f);
int				args_check(t_flags *f);
int				args_data_err(void *line);

void			matrix_print(t_flags *f, char type);

/* ************************************************************************** */
/// error handling
/* ************************************************************************** */
int				ft_error(const int error_code);
/* ************************************************************************** */
/// memory handling
/* ************************************************************************** */
int				free_mem(t_flags *f);
int				free_arrays(t_flags *f);
int				free_pointers(t_flags *f);
void			file_open(t_flags *f);
#endif
