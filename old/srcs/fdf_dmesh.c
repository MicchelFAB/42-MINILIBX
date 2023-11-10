/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dmesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/09 22:50:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

void	fdf_mesh_draw(t_win_data *img, t_mesh *mesh)
{
	int			i;
	int			j;
	t_mlx_line	line;

	i = 0;
	while (i < mesh->ntris)
	{
		j = 0;
		while (j < 3)
		{
			line.x0 = ft_roundf(mesh->tris[i].p[j].x);
			line.y0 = ft_roundf(mesh->tris[i].p[j].y);
			++j;
			j %= 3;
			line.xn = ft_roundf(mesh->tris[i].p[j].x);
			line.yn = ft_roundf(mesh->tris[i].p[j].y);
			mlx_line(img, &line);
			if (!j)
				break ;
		}
		i++;
	}
	return ;
}
