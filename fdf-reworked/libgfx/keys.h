/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:37:57 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 02:31:27 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/*
** char *string = ""
**	"asdfhgzxcv"		This string has the matching symbol or letter
**	"bqweryt123"		for the index of the keycode for the key.
**	"465=97-80]"		if you press KEY_BRACE_R or ]
**	"ou[ip lj\"k"		You could use string[30] or string[KEY_BRACE_R]
**	";\\,/nm.  ` "		to access the matching symbol or letter.
**	"	. * +   "
**	"/ -  =012345"		If you find anything missing please let me know.
**	"67 89";
*/

# define KEY_A 0x61
# define KEY_B 0x62
# define KEY_C 0x63
# define KEY_D 0x64
# define KEY_E 0x65
# define KEY_F 0x66
# define KEY_G 0x67
# define KEY_H 0x68
# define KEY_I 0x69
# define KEY_J 0x6a
# define KEY_K 0x6b
# define KEY_L 0x6c
# define KEY_M 0x6d
# define KEY_N 0x6e
# define KEY_O 0x6f
# define KEY_P 0x70
# define KEY_Q 0x71
# define KEY_R 0x72
# define KEY_S 0x73
# define KEY_T 0x74
# define KEY_U 0x75
# define KEY_V 0x76
# define KEY_W 0x77
# define KEY_X 0x78
# define KEY_Y 0x79
# define KEY_Z 0x7a

# define KEY_0 0x30
# define KEY_1 0x31
# define KEY_2 0x32
# define KEY_3 0x33
# define KEY_4 0x34
# define KEY_5 0x35
# define KEY_6 0x36
# define KEY_7 0x37
# define KEY_8 0x38
# define KEY_9 0x39

# define KEY_BRACE_R 0x5d
# define KEY_BRACE_L 0x5b

# define KEY_TAB 0xff09
# define KEY_SEMI 0x3b

# define KEY_PLUS 0x3d
# define KEY_MINUS 0x2d

# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53

typedef struct s_keys
{
	int			status;
	int			a;
	int			b;
	int			c;
	int			d;
	int			e;
	int			f;
	int			g;
	int			h;
	int			i;
	int			j;
	int			k;
	int			l;
	int			m;
	int			n;
	int			o;
	int			p;
	int			q;
	int			r;
	int			s;
	int			t;
	int			u;
	int			v;
	int			w;
	int			x;
	int			y;
	int			z;
	int			tab;
	int			semi;
	int			brace_l;
	int			brace_r;
	int			plus;
	int			minus;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_keys;

#endif
