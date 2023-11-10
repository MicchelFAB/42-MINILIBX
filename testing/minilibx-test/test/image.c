/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:57:55 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/25 19:56:07 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"
#include	"mlx_int.h"
#include	"mlx_test.h"

void	image_show(t_wd *wd)
{
	t_uimg			*simg;
	unsigned char	unique;

	printf("\nImage show all\n");
	unique = 1;
	simg = wd->simg;
	while (simg != wd->simg || unique)
	{
		unique = 0;
		printf("=== Image ID     : %d \n", simg->img_id);
		printf("\t=> simg        : %p\n", simg);
		printf("\t=> img         : %p\n", simg->img);
		printf("\t=> w x d       : %d x %d\n", simg->w, simg->h);
		printf("\t=> simg.addr   : %p\n", simg->addr);
		printf("\t=> simg.bpp    : %d\n", simg->bpp);
		printf("\t=> simg.ll     : %d\n", simg->ll);
		printf("\t=> simg.endian : %d\n", simg->endian);
		printf("\t=> simg.n      : %p\n", simg->next);
		simg = simg->next;
	}
	printf("\n");
}

void	image_show_one(t_wd *wd)
{
	printf("\nImage show one\n");
	printf("=== Image ID     : %d \n", wd->simg->img_id);
	printf("\t=> simg        : %p\n", wd->simg);
	printf("\t=> img         : %p\n", wd->simg->img);
	printf("\t=> w x d       : %d x %d\n", wd->simg->w, wd->simg->h);
	printf("\t=> simg.addr   : %p\n", wd->simg->addr);
	printf("\t=> simg.bpp    : %d\n", wd->simg->bpp);
	printf("\t=> simg.ll     : %d\n", wd->simg->ll);
	printf("\t=> simg.endian : %d\n", wd->simg->endian);
	printf("\t=> simg.n      : %p\n", wd->simg->next);
	printf("\n");
}

t_uimg	*image_add(t_wd *wd, int sx, int sy)
{
	t_uimg	*timg;

	timg = (t_uimg *)malloc(sizeof(t_uimg));
	if (!timg)
		return (0);
	timg->img = mlx_new_image(wd->smlx, sx, sy);
	if (!timg->img)
		return (0);
	timg->w = sx;
	timg->h = sy;
	timg->addr = mlx_get_data_addr(timg->img,
			&timg->bpp, &timg->ll, &timg->endian);
	timg->img_id = image_find_id(wd) + 1;
	if (!wd->simg)
		timg->next = timg;
	else
	{
		timg->next = wd->simg->next;
		wd->simg->next = timg;
	}
	wd->simg = timg;
	//image_show(wd);
	return (timg);
}

t_uimg	*image_xpm_add(t_wd *wd, char *file)
{
	t_uimg	*timg;

	timg = (t_uimg *)malloc(sizeof(t_uimg));
	if (!timg)
		return (0);
	timg->img = mlx_xpm_file_to_image(wd->smlx, file, &timg->w, &timg->h);
	if (!timg->img)
		return (0);
	timg->addr = mlx_get_data_addr(timg->img,
			&timg->bpp, &timg->ll, &timg->endian);
	timg->img_id = image_find_id(wd) + 1;
	if (!wd->simg)
		timg->next = timg;
	else
	{
		timg->next = wd->simg->next;
		wd->simg->next = timg;
	}
	wd->simg = timg;
	//image_show(wd);
	return (timg);
}
t_uimg	*image_find(t_wd *wd, int img_id)
{
	t_uimg	*simg;

	if (wd->simg)
	{
		if (wd->simg->img_id == img_id)
			return (wd->simg);
		simg = wd->simg->next;
		while (simg != wd->simg)
		{
			if (simg->img_id == img_id)
				return (wd->simg = simg);
			simg = simg->next;
		}
	}
	return (0);
}

int	image_find_id(t_wd *wd)
{
	t_uimg	*simg;
	int		last;

	if (!wd->simg)
		return (0);
	simg = wd->simg;
	last = wd->simg->img_id;
	while (simg->next != wd->simg)
	{
		if (simg->img_id > last)
			last = simg->img_id;
		simg = simg->next;
	}
	return (last);
}

