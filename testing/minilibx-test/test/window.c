/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:39:16 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/25 19:54:19 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"mlx.h"
#include	"mlx_int.h"
#include	"mlx_test.h"

void	window_show(t_wd *wd)
{
	t_uwin	*swin;
	int		unique;

	printf("\nwindow show all\n");
	unique = 1;
	swin = wd->swin;
	while (swin != wd->swin || unique)
	{
		unique = 0;
		printf("=== Window ID : %d \n", swin->win_id);
		printf("\t=> swin     : %p\n", swin);
		printf("\t=> win      : %p\n", swin->win);
		printf("\t=> w x h    : %d x %d\n", swin->w, swin->h);
		printf("\t=> swin.n   : %p\n", swin->next);
		swin = swin->next;
	}
	printf("\n");
}

void	window_show_one(t_wd *wd)
{
	printf("\nwindow show one\n");
	printf("=== Window ID : %d \n", wd->swin->win_id);
	printf("\t=> swin     : %p\n", wd->swin);
	printf("\t=> win      : %p\n", wd->swin->win);
	printf("\t=> w x h    : %d x %d\n", wd->swin->w, wd->swin->h);
	printf("\t=> swin.n   : %p\n", wd->swin->next);
	printf("\n");
}

t_wd	*wd_init(void)
{
	t_wd	*wd;
	int		a;

	wd = (t_wd *)malloc(sizeof(t_wd));
	if (!wd)
		return (0);
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		wd->l_endian = 1;
	else
		wd->l_endian = 0;
	wd->swin = 0;
	wd->simg = 0;
	return (wd);
}

t_uwin	*window_add_first(t_wd *wd, int sx, int sy, char *title)
{
	t_uwin	*swin;

	printf("\n ===> window_add_first() %d %d %s\n", sx, sy, title);
	swin = (t_uwin *)malloc(sizeof(t_uwin));
	if (!swin)
		return (0);
	swin->win = mlx_new_window(wd->smlx, sx, sy, title);
	if (!swin->win)
		return (0);
	swin->win_id = 1;
	swin->w = sx;
	swin->h = sy;
	swin->next = swin;
	wd->swin = swin;
	return (swin);
}

t_uwin	*window_add(t_wd *wd, int sx, int sy, char *title)
{
	t_uwin	*twin;

	twin = (t_uwin *)malloc(sizeof(t_uwin));
	if (!twin)
		return (0);
	twin->win = mlx_new_window(wd->smlx, sx, sy, title);
	if (!twin->win)
		return (0);
	twin->w = sx;
	twin->h = sy;
	twin->win_id = window_find_id(wd) + 1;
	if (!wd->swin)
		twin->next = twin;
	else
	{
		twin->next = wd->swin->next;
		wd->swin->next = twin;
	}
	wd->swin = twin;
	//window_show(wd);
	return (twin);
}

t_uwin	*window_find(t_wd *wd, int win_id)
{
	t_uwin	*swin;

	if (wd->swin)
	{
		if (wd->swin->win_id == win_id)
			return (wd->swin);
		swin = wd->swin->next;
		while (swin != wd->swin)
		{
			if (swin->win_id == win_id)
				return (wd->swin = swin);
			swin = swin->next;
		}
	}
	return (0);
}
int	window_find_id(t_wd *wd)
{
	t_uwin	*swin;
	int		last;

	if (!wd->swin)
		return (0);
	swin = wd->swin;
	last = wd->swin->win_id;
	while (swin->next != wd->swin)
	{
		if (swin->win_id > last)
			last = swin->win_id;
		swin = swin->next;
	}
	return (last);
}