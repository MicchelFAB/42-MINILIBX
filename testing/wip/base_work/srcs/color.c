/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:14:35 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:25:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_color_table(t_view *view, int colors)
{
	int				i;
	float			f;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	view->colors = (t_color *)malloc(sizeof(t_color) * colors);
	f = 0;
	i = -1;
	while (++i < colors)
	{
		r = (cos(f) + view->r) * 127;
		g = (sin(f) + view->g) * 127;
		b = (-cos(f) + view->b) * 127;
		view->colors[i] = ((int)b) << 16 | ((int)g) << 8 | r;
		f += M_PI / colors;
	}
	view->num_colors = colors;
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}
