/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:25:51 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/29 17:44:47 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
///	LIBS
/* ************************************************************************** */
# include <signal.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
//# include "../../libft/libft.h"
//# include "../../libft/gnl.h"
# include	"debug.h"
# include	"mlx.h"
# include	"mlx_int.h"

/* ************************************************************************** */
///	CONSTANTS
/* ************************************************************************** */
# ifndef ERROR
#  define ERROR 1
# endif
# ifndef SUCCESS
#  define SUCCESS 0
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# ifndef BM
#  define BM 255
# endif
# ifndef FDF_WAIT
#  define FDF_WAIT 5
# endif
/* ************************************************************************** */
///	COLORS
/* ************************************************************************** */
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;34m"
# define PPL "\033[0;35m"
# define CYN "\033[1;36m"
# define WTH "\033[0m"
# define BOLD "\033[1;1m"
/* ************************************************************************** */
///	MLX PIXEL COLORS
/* ************************************************************************** */
# define GOLD				0xffd700
# define YELLOW				0xffff00
# define YELLOW_L			0xffffe0
# define LEMONCHIFFON		0xfffacd
# define GOLDENRODYELLOW_L	0xfafad2
# define PAPAYAWHIP			0xffefd5
# define MOCCASIN			0xffe4b5
# define PEACHPUFF			0xffdab9
# define PALEGOLDENROD		0xeee8aa
# define KHAKI				0xf0e68c
# define DARKKHAKI			0xbdb76b

/* ************************************************************************** */
///	STRUCTS
/* ************************************************************************** */

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct s_polar
{
	int				rho;
	int				theta;
	int				phi;
}					t_polar;

typedef struct s_complex
{
	double			real;
	double			imaginary;
}					t_complex;

typedef struct s_vector
{
	t_point			*start;
	t_point			*end;
}					t_vector;

typedef struct s_map
{
	int				width;
	int				height;
	int				depth_min;
	int				depth_max;
	int				**matrix;
}					t_map;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_vector		*vector;
}					t_fdf;

typedef struct s_window
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	char			*title;
	unsigned char	*data;
	int				bpp;
	int				opp;
	int				sl;
	int				endian;
	int				l_endian;
	int				w;
	int				h;
	int				img_w;
	int				img_h;
	int				type;
	int				color;
}					t_window;

typedef struct s_elem
{
	int				data;
	int				i;
	int				cost_a;
	int				cost_b;
	char			move_a;
	char			move_b;
	struct s_elem	*n;
	struct s_elem	*p;
}					t_elem;

typedef struct s_stack
{
	struct s_elem	*ta;
	int				size_a;
	int				min_a;
	int				max_a;
	struct s_elem	*tb;
	int				size_b;
	int				min_b;
	int				max_b;
	int				chunk;
}					t_stack;

typedef struct s_flags
{
	int				show_stacks;
	int				show_moves;
	int				show_colors;
	int				save_moves;
	int				fd;
	int				any_flag;
	int				len;
	char			**arg;
}					t_flags;

/* ************************************************************************** */
///	FUNCTIONS PROTOTYPES
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*	COMMON FUNCTIONS PROTOTYPES                                               */
/*                                                                            */
/* ************************************************************************** */
///	FILE ; fc_action_px.c
/* ************************************************************************** */
int			color_map_1(t_window *window);
//int			color_map_1(void *win, int w, int h);
//int			color_map_2(unsigned char *data, int bpp, int sl, int w, int h,
				//int endian, int type);
//int			color_map_2(t_window *win, int local_endian);
int			color_map_2(t_window *window);
int			expose_win1(void);
int			expose_win2(void);
int			key_win1(int key);
int			key_win2(int key);
int			key_win3(int key);
int			mouse_win1(int button, int x, int y);
int			mouse_win2(int button, int x, int y);
int			mouse_win3(int x, int y);
t_window	*get_window(void *mlx, int w, int h, char *wd_title);

#endif