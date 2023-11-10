/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:51:09 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/23 01:07:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TEST_H
# define MLX_TEST_H

# ifndef TIMER1
#  define TIMER1 1
# endif
# ifndef TIMER2
#  define TIMER2 2
# endif

# define WIN1_SX 242
# define WIN1_SY 242
# define IM1_SX 42
# define IM1_SY 42
# define IM3_SX 242
# define IM3_SY 242

typedef struct s_uwin
{
	void			*win;
	int				win_id;
	int				w;
	int				h;
	struct s_uwin	*next;
}	t_uwin;

typedef struct s_wd
{
	void			*smlx;
	int				l_endian;
	struct s_uwin	*swin;
	struct s_uimg	*simg;
}	t_wd;

typedef struct s_uimg
{
	void			*img;
	int				img_id;
	int				w;
	int				h;
	char			*addr;
	int				bpp;
	int				ll;
	int				bypp;
	int				endian;
	int				color;
	struct s_uimg	*next;
}	t_uimg;

/// window.c
t_wd	*wd_init(void);
t_uwin	*window_add_first(t_wd *wd, int sx, int sy, char *title);
t_uwin	*window_add(t_wd *wd, int sx, int sy, char *title);
void	window_show(t_wd *wd);
void	window_show_all(t_wd *wd);
t_uwin	*window_find(t_wd *wd, int win_id);
int		window_find_id(t_wd *wd);
void	window_show_one(t_wd *wd);

void	image_show(t_wd *wd);
t_uimg	*image_add_first(t_wd *wd, int sx, int sy);
t_uimg	*image_add(t_wd *wd, int sx, int sy);
t_uimg	*image_find(t_wd *wd, int img_id);
int		image_find_id(t_wd *wd);
t_uimg	*image_xpm_add(t_wd *wd, char *file);
void	image_show_one(t_wd *wd);

int		expose_win1(t_wd *wd);
int		expose_win2(t_wd *wd);
int		key_win1(int key, void *p);
int		key_win2(int key, void *p);
int		key_win3(int key, t_wd *wd);
int		mouse_win1(int button, int x, int y, void *p);
int		mouse_win2(int button, int x, int y, void *p);
int		mouse_win3(int x, int y, void *p);


#endif
