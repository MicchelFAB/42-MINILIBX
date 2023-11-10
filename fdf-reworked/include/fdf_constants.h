/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_constants.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:49:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/06 01:41:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_CONSTANTS_H
# define FDF_CONSTANTS_H

/* ************************************************************************** */
///	ERROR CODES
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
# ifndef MALLOC_ERROR
#  define MALLOC_ERROR 10
# endif
# ifndef MAP_ERROR
#  define MAP_ERROR 50
# endif
# ifndef MLX_ERROR
#  define MLX_ERROR 51
# endif
# ifndef ARGS_ERROR
#  define ARGS_ERROR 52
# endif
# ifndef PROCESS_ERROR
#  define PROCESS_ERROR 53
# endif
# ifndef MATRIX_ERROR
#  define MATRIX_ERROR 54
# endif
# ifndef COLOR_ERROR
#  define COLOR_ERROR 55
# endif
# ifndef BONUS_ERROR
#  define BONUS_ERROR 56
# endif

/* ************************************************************************** */
///	FILE ERROR CODES and STATUS
/* ************************************************************************** */
# ifndef FILE_EMPTY
#  define FILE_EMPTY 20
# endif
# ifndef FILE_ERROR
#  define FILE_ERROR 21
# endif
# ifndef FILE_NOT_FOUND
#  define FILE_NOT_FOUND 22
# endif
# ifndef FILE_NOT_READABLE
#  define FILE_NOT_READABLE 23
# endif
# ifndef FILE_NOT_VALID
#  define FILE_NOT_VALID 24
# endif
# ifndef FILE_NOT_OPEN
#  define FILE_NOT_OPEN 25
# endif
# ifndef FILE_NOT_CLOSED
#  define FILE_NOT_CLOSED 26
# endif
# ifndef FILE_NOT_WRITABLE
#  define FILE_NOT_WRITABLE 27
# endif
# ifndef FILE_NOT_CREATED
#  define FILE_NOT_CREATED 28
# endif
# ifndef FILE_NOT_DELETED
#  define FILE_NOT_DELETED 29
# endif
# ifndef FILE_NOT_RENAMED
#  define FILE_NOT_RENAMED 30
# endif
# ifndef FILE_NOT_COPIED
#  define FILE_NOT_COPIED 31
# endif
# ifndef FILE_NOT_MOVED
#  define FILE_NOT_MOVED 32
# endif
# ifndef FILE_NOT_EXECUTABLE
#  define FILE_NOT_EXECUTABLE 33
# endif
# ifndef FILE_NOT_EXECUTED
#  define FILE_NOT_EXECUTED 34
# endif

/* ************************************************************************** */
///	MATH
/* ************************************************************************** */
# ifndef PI
#  define PI 3.14159265358979323846
# endif

# ifndef PI2
#  define PI2 6.28318530717958647692
# endif

# ifndef DEG2RAD_1
#  define DEG2RAD_1 0.001745329252
# endif

# ifndef DEG2RAD_90
#  define DEG2RAD_90 1.57079632678
# endif

# ifndef SECS_CLK_HAND
#  define SECS_CLK_HAND 0.10471975512
# endif

/* ************************************************************************** */
///	WINDOW OBJECTS
/* ************************************************************************** */
# define F_SX	640
# define F_SY	360
# define D_SX	1280
# define D_SY	720
# define SHD_SX	640
# define SHD_SY	480
# define IM1_SX	50
# define IM1_SY	50
# define IM3_SX	242
# define IM3_SY	242
# define L_X	50
# define L_Y	150
# define L_S	100
# define SLEEP	1
# define MENU_W	100
# define BUTTON_W	40
# define BUTTON_H	16

#endif
