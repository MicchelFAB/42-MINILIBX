
#include	"mlx.h"
#include	"mlx_int.h"
#include	"mlx_test.h"

// #define WIN1_SX 242
// #define WIN1_SY 242
// #define IM1_SX 42
// #define IM1_SY 42
// #define IM3_SX 242
// #define IM3_SY 242

int	fill_win_grade(t_wd *wd)
{
	int	x;
	int	y;
	int	color;

	x = wd->swin->w;
	while (x--)
	{
		y = wd->swin->h;
		while (y--)
		{
			color = (x * 255) / wd->swin->w
				+ ((((wd->swin->w - x) * 255) / wd->swin->w) << 16)
				+ (((y * 255) / wd->swin->h) << 8);
			mlx_pixel_put(wd->smlx, wd->swin->win, x, y, color);
		}
	}
}

int	fill_win_color(t_wd *wd, int color)
{
	int	x;
	int	y;

	x = wd->swin->w;
	while (x--)
	{
		y = wd->swin->h;
		while (y--)
			mlx_pixel_put(wd->smlx, wd->swin->win, x, y, color);
	}
}

int	fill_img_grade(t_wd *wd, int type)
{
	int				x;
	int				y;
	int				dec;
	int				color;
	int				color2;
	unsigned char	*ptr;

	wd->simg->bypp = wd->simg->bpp / 8;
	y = wd->simg->h;
	while (y--)
	{
		ptr = wd->simg->addr + y * wd->simg->ll;
		x = wd->simg->w;
		while (x--)
		{
			if (type == 2)
				color = (y * 255) / wd->simg->w
					+ ((((wd->simg->w - x) * 255) / wd->simg->w) << 16)
					+ (((y * 255) / wd->simg->h) << 8);
			else
				color = (x * 255) / wd->simg->w
					+ ((((wd->simg->w - x) * 255) / wd->simg->w) << 16)
					+ (((y * 255) / wd->simg->h) << 8);
			color2 = mlx_get_color_value(wd->smlx, color);
			dec = wd->simg->bypp;
			while (dec--)
			{
				if (wd->simg->endian == wd->l_endian)
				{
					if (wd->simg->endian)
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[4 - wd->simg->bypp + dec];
					else
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[dec];
				}
				else
				{
					if (wd->simg->endian)
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[wd->simg->bypp - 1 - dec];
					else
						*(ptr + x * wd->simg->bypp + dec)
							= ((unsigned char *)(&color2))[3 - dec];
				}
			}
		}
	}

}

int	main()
{
	t_wd	*wd;
	t_uwin	*swin;
	t_uimg	*simg;
	int		a;

	printf("### main() : MinilibX Test Program ###\n");
	printf(" => Init Struct t_wd* ...");
	wd = wd_init();
	printf(" OK\n");
	printf(" => main() Local Endian : %d\n", wd->l_endian);

	printf(" => main() Connection mlx_init()...");
	wd->smlx = mlx_init();
	if (!wd->smlx)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK (use_xshm %d pshm_format %d)\n",
		((t_xvar *)wd->smlx)->use_xshm, ((t_xvar *)wd->smlx)->pshm_format);

	printf(" => main() Window[1] : size %dx%d \"Title 1\" ...", WIN1_SX, WIN1_SY);
	swin = window_add(wd, WIN1_SX, WIN1_SY, "Title1");
	if (!swin)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK\n");
	//window_show(wd);
	//sleep(1);

	printf(" => Color Window[1] sans event ...");
	fill_win_grade(wd);
	printf("OK\n");
	//sleep(1);

	printf(" => Clear Window[1] ...");
	mlx_clear_window(wd->smlx, wd->swin->win);
	printf("OK\n");
	//sleep(1);

	printf(" => Image[1] ZPixmap %dx%d ...", IM1_SX, IM1_SY);
	simg = image_add(wd, IM1_SX, IM1_SY);
	if (!simg)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	//sleep(1);

	printf(" => Fill Image[1] ...");
	fill_img_grade(wd, 1);
	printf("OK (pixmap : %d)\n", (int)((t_img *)simg->img)->pix);
	//sleep(1);

	printf(" => Put Image[1] ...");
	mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 20, 20);
	printf("OK\n");
	//sleep(1);

	// printf(" => Destroy Image[1] ... ");
	// mlx_destroy_image(wd->smlx, wd->simg->img);
	// printf("OK\n");
	//sleep(1);

	printf(" => Image[2] ZPixmap %dx%d ...", IM3_SX, IM3_SY);
	simg = image_add(wd, IM3_SX, IM3_SY);
	if (!simg)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	//sleep(1);

	printf(" => Fill Image[2] ...");
	fill_img_grade(wd, 1);
	printf("OK (pixmap : %d)\n", (int)((t_img *)simg->img)->pix);

	printf(" => Put Image[2] @ 20 X 20 ...");
	mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 20, 20);
	printf("OK\n");
	//sleep(1);

	printf(" => Put Image[2] @ 4 0X 40 ...");
	mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 40, 40);
	printf("OK\n");
	//sleep(1);

	printf(" => String ...");
	mlx_string_put(wd->smlx, wd->swin->win, 5, WIN1_SY / 2, 0xFF99FF, "String output");
	mlx_string_put(wd->smlx, wd->swin->win, 15, WIN1_SY / 2 + 20, 0x00FFFF, "MinilibX test");
	printf("OK\n");
	//sleep(1);

	printf(" => Xpm from file ...");
	simg = image_xpm_add(wd, "open.xpm");
	if (!simg)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK (xpm type: %d)\n", ((t_img *)simg->img)->type);
	//sleep(1);

	printf(" => Put xpm ...");
	mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 0, 0);
	mlx_put_image_to_window(wd->smlx, wd->swin->win, wd->simg->img, 100, 100);
	printf("OK\n");
	//sleep(1);

	printf(" => 2nd window, ");
	printf(" => main() Window[2] : size %dx%d \"Title 2\" ...", WIN1_SX, WIN1_SY);
	swin = window_add(wd, WIN1_SX, WIN1_SY, "Title2");
	if (!swin)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK\n");
	//sleep(1);

	printf(" => Image[4] ZPixmap %dx%d ...", IM3_SX, IM3_SY);
	simg = image_add(wd, IM3_SX, IM3_SY);
	if (!simg)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK\n");
	//sleep(1);

	fill_img_grade(wd, 2);

	printf(" => 3rd window, ");
	printf(" => main() Window[3] : size %dx%d \"Title 3\" ...", WIN1_SX, WIN1_SY);
	swin = window_add(wd, WIN1_SX, WIN1_SY, "Title 3");
	if (!swin)
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("OK\n");
	//sleep(1);

	printf(" => Installing hooks ...\n");

	window_find(wd, 1);
	//window_show_one(wd);
	printf("\t => window 1 hooks ********************************************\n");
	//sleep(1);

	mlx_expose_hook(wd->swin->win, expose_win1, wd);
	mlx_mouse_hook(wd->swin->win, mouse_win1, 0);
	mlx_key_hook(wd->swin->win, key_win1, 0);

	window_find(wd, 2);
	//window_show_one(wd);
	printf("\t => window 2 hooks ********************************************\n");
	//sleep(1);

	mlx_expose_hook(wd->swin->win, expose_win2, wd);
	mlx_mouse_hook(wd->swin->win, mouse_win2, 0);
	mlx_key_hook(wd->swin->win, key_win2, 0);

	window_find(wd, 3);
	//window_show_one(wd);
	printf("\t => window 3 hooks ********************************************\n");
	//sleep(1);

	mlx_key_hook(wd->swin->win, key_win3, wd);
	mlx_hook(wd->swin->win, MotionNotify, PointerMotionMask, mouse_win3, 0);

	printf("OK\nNow in Loop. Just play. Esc in 3 to destroy,  1&2 to quit.\n");

	mlx_loop(wd->smlx);

}
