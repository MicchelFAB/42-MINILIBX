/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:18:26 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 11:20:34 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	full_redraw(t_view *v)
{
	//if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	local_to_world(v);
	redraw(v);
	//if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	redraw(t_view *v)
{
	printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	world_to_aligned(v);
	aligned_to_projected(v);
	mlx_clear_window(v->id, v->win);
	if (v->project)
		draw_projected(v);
	else
		draw_wireframe(v);

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	draw_projected(t_view *v)
{

	int		y;
	int		x;
	printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (x < v->width - 1)
				draw_line(v, *(v->points[y][x]->projected),
					*(v->points[y][x + 1]->projected));
			if (y < v->height - 1)
				draw_line(v, *(v->points[y][x]->projected),
					*(v->points[y + 1][x]->projected));
		}
	}

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}

void	draw_wireframe(t_view *v)
{
	int		y;
	int		x;
	printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	sleep(MYTIME);

	y = -1;
	while (++y < v->height)
	{
		x = -1;
		while (++x < v->width)
		{
			if (x < v->width - 1)
				draw_line(v, *(v->points[y][x]->aligned),
					*(v->points[y][x + 1]->aligned));
			if (y < v->height - 1)
				draw_line(v, *(v->points[y][x]->aligned),
					*(v->points[y + 1][x]->aligned));
		}
	}

	printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
	sleep(MYTIME);
}
