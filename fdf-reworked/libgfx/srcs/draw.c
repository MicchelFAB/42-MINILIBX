/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:18:18 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/26 11:21:18 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"

void	draw_point_to_img(t_view *view, int x, int y, float z)
{
	unsigned int	color;
	float			selection;
	int				i;

	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
	{
		i = (x * (view->bits_per_pixel / 8)) + (y * view->size_line);
		if (view->pixels[i] || view->pixels[i + 1] || view->pixels[i + 2])
			return ;
		if (!view->z_max && !view->z_min)
			view->z_max = 1;
		selection = ((z - view->z_min) / (view->z_max - view->z_min))
			* (view->num_colors);
		color = view->colors[abs((int)selection - 1)];
		view->pixels[i] = color;
		view->pixels[++i] = color >> 8;
		view->pixels[++i] = color >> 16;
	}
}

void	draw_point(t_view *view, int x, int y, float z)
{
	unsigned int	color;
	float			selection;

	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
	{
		if (!view->z_max && !view->z_min)
			view->z_max = 1;
		selection = ((z - view->z_min) / (view->z_max - view->z_min))
			* (view->num_colors);
		color = view->colors[abs((int)selection - 1)];
		mlx_pixel_put(view->id, view->win, x, y, color);
	}
}

static int	swap_slope(t_3dp *p0, t_3dp *p1)
{
	float	temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

void	draw_line(t_view *view, t_3dp p0, t_3dp p1)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_slope(&p0, &p1);
	delta[0] = p1.x - p0.x;
	delta[1] = p1.y - p0.y;
	delta[2] = p1.z - p0.z;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)p0.x != (int)p1.x)
	{
		draw_point(view, dir * p0.y + !dir * p0.x,
			dir * p0.x + !dir * p0.y, p0.z);
		error += slope;
		if (error >= 0.0)
		{
			p0.y += (p0.y > p1.y) * -1.0 + !(p0.y > p1.y) * 1.0;
			error -= 1.0;
		}
		p0.z += delta[2] / fabs(delta[0]);
		p0.x += (p0.x > p1.x) * -1.0 + !(p0.x > p1.x) * 1.0;
	}
}
