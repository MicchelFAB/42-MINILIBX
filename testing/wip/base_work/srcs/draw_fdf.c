/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:27:25 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:25:40 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	full_redraw(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	local_to_world(view);
	redraw(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

void	redraw(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	world_to_aligned(view);
	aligned_to_projected(view);
	mlx_clear_window(view->id, view->win);
	if (view->project)
		draw_projected(view);
	else
		draw_wireframe(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

void	draw_projected(t_view *view)
{
	int		y;
	int		x;

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				drawline(view, *(view->points[y][x]->projected),
					*(view->points[y][x + 1]->projected));
			if (y < view->height - 1)
				drawline(view, *(view->points[y][x]->projected),
					*(view->points[y + 1][x]->projected));
		}
	}
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

void	draw_wireframe(t_view *view)
{
	int		y;
	int		x;

	//MY_DEBUG ? printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	y = -1;
	while (++y < view->height)
	{
		x = -1;
		while (++x < view->width)
		{
			if (x < view->width - 1)
				drawline(view, *(view->points[y][x]->aligned),
					*(view->points[y][x + 1]->aligned));
			if (y < view->height - 1)
				drawline(view, *(view->points[y][x]->aligned),
					*(view->points[y + 1][x]->aligned));
		}
	}
	//MY_DEBUG ? printf("%s(>)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}
