/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fdf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:38:40 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/27 19:07:25 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"
#include	"fdf_globals.h"

int	show_image(t_window *win)
{
	printf(" => show_image(...)");

	win->img = mlx_new_image(win->mlx, win->img_w, win->img_h);
	if (!win->img)
		exit(ERROR);
	win->data = (unsigned char *)mlx_get_data_addr(win->img,
			&win->bpp, &win->sl, &win->endian);

	printf("OK (bpp %d, sizeline %d ", win->bpp, win->sl);
	printf("endian %d type %d)\n", win->endian, ((t_img *)win->img)->type);
	printf(" => Fill Image [color_map_2(...)]\n");
	color_map_2(win);
	printf("(pixmap : %d)\n", (int)((t_img *)win->img)->pix);
	printf(" => Fill Image [color_map_2] DONE!\n");

	printf(" => [mlx_put_image_to_window(...)]\n");
	mlx_put_image_to_window(win->mlx, win->win, win->img, 20, 20);
	printf(" => [mlx_put_image_to_window] DONE!\n");
	sleep(FDF_WAIT);
	printf(" => show_image(...) DONE\n");
	return (SUCCESS);
}

int 	show_string(t_window *win, char *str)
{
	printf(" => show_string(...)");
	mlx_string_put(win->mlx, win->win, win->img_w, win->img_h, win->color, str);
	printf(" <= show_string(...) OK\n");
	sleep(5);
}


int	show_xpm(t_window *win, char *filename)
{
	//int		xpm1_x;
	//int		xpm1_y;

	printf(" => show_xpm(...)");
	printf(" => Xpm from file ...");
	win->img = mlx_xpm_file_to_image(win->mlx, filename, &win->w, &win->h, );
	if (!win->img)
		exit(ERROR);
	win->data = (unsigned char *)mlx_get_data_addr(win->img, &win->bpp,
			&win->sl, &win->endian);
	printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
		xpm1_x, xpm1_y, win->bpp, win->sl,
		win->endian, ((t_img *)win->img)->type);
	sleep(5);

	printf(" => Put xpm ...");
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 00, 100);
	printf("OK\n");
	sleep(5);
	printf(" => show_xpm(...) OK");
	return (SUCCESS);
}

t_window	*get_window(void *mlx, int w, int h, char *title)
{
	t_window	*win;

	win = (t_window *)malloc(sizeof(t_window));

	win->mlx = mlx;
	win->w = w;
	win->h = h;
	win->title = title;

	printf(" => Window1 %dx%d %s ...", win->w, win->h, win->title);

	win->win = mlx_new_window(win->mlx, win->w, win->h, win->title);
	if (!win->win)
	{
		printf(" !! KO !! => NO WINDOW CREATED\n");
		exit(ERROR);
	}
	printf("OK\n");

	return (win);
}


int	main(void)
{
	int			a;
	void		*mlx;
	t_window	*wd1;
	t_window	*wd2;
	t_window	*wd3;


	printf("MinilibX Test Program\n");
	a = 0x11223344;

/*#0001*/
	printf(" => Connection ...");
	mlx = mlx_init();
	if (!mlx)
	{
		printf(" !! KO !! NO MLX CONNECTION\n");
		exit(ERROR);
	}

	printf("OK (use_xshm %d pshm_format %d)\n",
		((t_xvar *)mlx)->use_xshm, ((t_xvar *)mlx)->pshm_format);

/*#0002*/
	wd1 = get_window(mlx, WIN1_SX, WIN1_SY, "Title1");
	if (!wd1)
	{
		printf(" !! KO !! NO WINDOW\n");
		exit(ERROR);
	}

/*#0000*/
	if (((unsigned char *)&a)[0] == 0x11)
		wd1->l_endian = 1;
	else
		wd1->l_endian = 0;
	printf(" => Local Endian : %d\n", wd1->l_endian);

/*#0003*/
	printf(" => Colormap without event ...");
	color_map_1(wd1);
	printf("OK\n");
	sleep(FDF_WAIT);

	printf(" => Clear Window ...");
	mlx_clear_window(wd1->mlx, wd1->win);
	printf("OK\n");
	sleep(FDF_WAIT);

/*#0004*/
/*************** => Image1 ZPixmap *******************************/
	wd1->img_w = IM1_SX;
	wd1->img_h = IM1_SY;
	printf(" => Image1 ZPixmap %dx%d ...", wd1->img_w, wd1->img_h);
	wd1->type = 1;
	if (show_image(wd1) == ERROR)
	{
		printf(" !! KO !! NO SHOW IMAGE\n");
		exit(ERROR);
	}

	printf(" => [mlx_destroy_image(...)]\n");
	mlx_destroy_image(wd1->mlx, wd1->img);
	printf(" => [mlx_destroy_image(...)] ");
	sleep(FDF_WAIT);

/*#0005*/
/************* show image3 ***************************************/
	wd1->img_w = IM3_SX;
	wd1->img_h = IM3_SY;
	printf(" => Image3 ZPixmap %dx%d ...", wd1->img_w, wd1->img_h);
	wd1->type = 1;
	if (show_image(wd1) == ERROR)
	{
		printf(" !! KO !! NO SHOW IMAGE\n");
		exit(ERROR);
	}
/*#0006*/
/************* show string ***************************************/
	wd1->color = 0xFF99FF;
	wd1->img_w = 5;
	wd1->img_h = WIN1_SY / 2;
	if (show_string(wd1, "String output") == ERROR)
	{
		printf(" !! KO !! NO SHOW STRING\n");
		exit(ERROR);
	}
	wd1->color = 0x00FFFF;
	wd1->img_w = 15;
	wd1->img_h = WIN1_SY / 2 + 20;
	if (show_string(wd1, "MinilibX test") == ERROR)
	{
		printf(" !! KO !! NO SHOW STRING\n");
		exit(ERROR);
	}

/*#0007*/
/************* put xpm *******************************************/
	if (show_xpm(wd1, "open.xpm") == ERROR)
	{
		printf(" !! KO !!\n");
		exit(ERROR);
	}
/*#0008*/
/************* 2nd window ****************************************/
	printf(" => 2nd window,");
	wd2 = get_window(mlx, WIN1_SX, WIN1_SY, "Title2");
	if (!wd2)
	{
		printf(" !! KO !! NO WINDOW\n");
		exit(ERROR);
	}
	wd2->img_w = IM3_SX;
	wd2->img_h = IM3_SY;
	wd1->type = 2;
	if (show_image(wd2) == ERROR)
	{
		printf(" !! KO !! NO SHOW IMAGE\n");
		exit(ERROR);
	}
	color_map_2(data4, bpp4, sl4, IM3_SX, IM3_SY, endian4, 2);

	printf(" 3rd window, Installing hooks ...");
	win3 = mlx_new_window(mlx, WIN1_SX, WIN1_SY, "Title3");
	mlx_expose_hook(win1, expose_win1, 0);
	mlx_mouse_hook(win1, mouse_win1, 0);
	mlx_key_hook(win1, key_win1, 0);
	mlx_expose_hook(win2, expose_win2, 0);
	mlx_mouse_hook(win2, mouse_win2, 0);
	mlx_key_hook(win2, key_win2, 0);
	mlx_key_hook(win3, key_win3, 0);

	mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);

	printf("OK\nNow in Loop. Just play. Esc in 3 to destroy, 1&2 to quit.\n");

	mlx_loop(mlx);
}

