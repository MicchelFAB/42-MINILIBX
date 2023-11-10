/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myfdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:33:44 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/06 17:57:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYFDF_H
# define MYFDF_H

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<math.h>
#include	<fcntl.h>
#include	<errno.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<sys/uio.h>
#include	<time.h>

#include	"../mlx.h"
#include	"../mlx_int.h"
#include	"colors.h"
#include	"keys.h"
#include	"fdf_constants.h"

#define	FHD_SX		640
#define	FHD_SY		480
#define	SHD_SX		640
#define	SHD_SY		480
#define	IM1_SX		50
#define	IM1_SY		50
#define	IM3_SX		242
#define	IM3_SY		242


typedef struct	s_img_data
{
	void	*mlx;
	void	*win;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		x;
	int		y;
	int		size;
	int		radius;
	int		color;
}				t_img_data;

typedef struct s_mlx_line
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x0;
	int		y0;
	int		xn;
	int		yn;
	int		dx;
	int		dy;
	int		sdx;
	int		sdy;

}				t_mlx_line;

/* ************************************************************************** */
///	STRINGS COLORS
/* ************************************************************************** */
# define SRED "\033[0;31m"
# define SGRN "\033[0;32m"
# define SYLW "\033[0;33m"
# define SBLU "\033[0;34m"
# define SPPL "\033[0;35m"
# define SCYN "\033[1;36m"
# define SWHT "\033[0m"
# define SBOLD "\033[1;1m"

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */
void	mlx_pixel(t_img_data *img, int x, int y, int color);
void	mlx_square(t_img_data *img);
void	mlx_line(t_img_data *img, int x1, int y1, int x2, int y2, int color);
void	mlx_line_b(t_img_data *img, int x0, int y0, int xn, int yn, int color);
void	mlx_circle(t_img_data *img, int x, int y, int radius, int color);
//void	mlx_circle_g(t_img_data *img, int x, int y, int radius, int color);
void	mlx_circle_g(t_img_data *img);//, int x, int y, int radius, int color);
//void	mlx_circle_g(void *mlx, void *window, t_img_data *img, int x, int y, int radius, int color);

void	mlx_secs_hand(void *mlx, void *window, t_img_data *img);

//void	mlx_secs_hand_b(void *mlx, void *window, t_img_data *img);
void	mlx_secs_hand_b(t_img_data *img);
//void	mlx_clock(void *mlx, void *mlx_win, t_img_data *img);
void	mlx_clock(t_img_data *img);
void	mlx_line_tester(void *mlx, void *win, t_img_data *img);
int		abs_i(int n);
void	ft_abs(double *n);
double	abs_d(double n);
int		max_i(int a, int b);
int		min_i(int a, int b);
char	sign_d(double n);
int		my_round(double n);

#endif
