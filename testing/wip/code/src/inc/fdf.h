/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:44:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
///	LIBS
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
//#include <mlx.h>
# include <math.h>
# include "../../libft/libft.h"
# include "../../libft/gnl.h"

/* ************************************************************************** */
///	CONSTANTS DEBUG
/* ************************************************************************** */
# ifndef _PRINT
#  define _PRINT 1
#  define _NOPRINT 0
# endif
# ifndef _SHOW_STACKS_
#  define _SHOW_STACKS_ 1
# endif
# ifndef _SHOW_MATRIX_
#  define _SHOW_MATRIX_ 1
# endif
# ifndef MY_DEBUG
#  define MY_DEBUG 1
# endif
# ifndef MY_DEBUGMALLOC_
#  define MY_DEBUGMALLOC_ 0
# endif
# ifndef _CHUNK_
#  define _CHUNK_ 100
# endif
/* ************************************************************************** */
///	CONSTANTS RESULTS
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

/* ************************************************************************** */
///	COLORS STRINGS
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
///	STRUCTS
/* ************************************************************************** */

typedef struct s_flags
{
	int		c;
	int		r;
	char	*file;
	int		fd;
	int		aux01;
	int		aux02;
	char	*line;
	char	**cmatrix;
	int		**imatrix;
	float	**fmatrix;
}					t_flags;

/* ************************************************************************** */
///	FUNCTIONS
/* ************************************************************************** */

int		args_build_c(t_flags *f);
t_flags	*flags_init(int ac, char **av);
void	args_print(t_flags *f);
void	matrix_print(t_flags *f, char type);
int		ft_error(void);
int		free_mem(t_flags *f);
int		args_check(t_flags *f);
void	ft_free(void *ptr);

#endif
