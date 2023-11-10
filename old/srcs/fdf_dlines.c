/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_dlines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/09 22:50:05 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"
#include	"../include/fdf_structs.h"

void	mlx_line_s_init(t_mlx_line *line)
{
	line->swap_xy = 0;
	line->xk = line->x0;
	line->yk = line->y0;
	line->k = 1;
	line->dx = abs_i(line->xn - line->x0);
	line->dy = abs_i(line->yn - line->y0);
	line->sdx = sign_d(line->xn - line->x0);
	line->sdy = sign_d(line->yn - line->y0);
	if (line->dy > line->dx)
		line->swap_xy = ft_swap(&line->dx, &line->dy);
	line->ek = 2 * line->dy - line->dx;
}

// commented 2023/10/05 13:01:35 by antoda-s
// void	mlx_line_m_init(t_m_line *line)
// {
// 	line->swap_xy = 0;
// 	line->pk.x = line->p0.x;
// 	line->pk.y = line->p0.y;
// 	line->k = 1;
// 	line->dx = abs_i(line->pn.x - line->p0.x);
// 	line->dy = abs_i(line->pn.y - line->p0.y);
// 	line->sdx = sign_d(line->pn.x - line->p0.x);
// 	line->sdy = sign_d(line->pn.y - line->p0.y);
// 	if (line->dy > line->dx)
// 		line->swap_xy = ft_swap(&line->dx, &line->dy);
// 	line->ek = 2 * line->dy - line->dx;
// }

void	mlx_line(t_win_data *img, t_mlx_line *line)
{
	mlx_line_s_init(line);
	mlx_pixel_s(img, &((t_mlx_pixel){line->x0, line->y0, line->color}));
	while (line->k <= line->dx)
	{
		line->k++;
		mlx_pixel_s(img, &((t_mlx_pixel){line->xk, line->yk, line->color}));
		line->yk += line->sdy * (line->swap_xy && line->ek < 0)
			+ line->sdy * !(line->ek < 0);
		line->xk += line->sdx * (!line->swap_xy && line->ek < 0)
			+ line->sdx * !(line->ek < 0);
		line->ek = (line->ek + 2 * line->dy) * (line->ek < 0)
			+ (line->ek + 2 * line->dy - 2 * line->dx) * !(line->ek < 0);
	}
}

// void	mlx_line_m(t_win_data *img, t_m_line *line)
// {
// 	mlx_line_m_init(line);
// 	mlx_pixel_s(img, &((t_mlx_pixel){line->p0.x, line->p0.y, line->p0.color}));
// 	while (line->k <= line->dx)
// 	{
// 		line->k++;
// 		mlx_pixel_s(img, &((t_mlx_pixel){
// 				line->pk.x, line->pk.y, line->p0.color}));
// 		line->yk += line->sdy * (line->swap_xy && line->ek < 0)
// 			+ line->sdy * !(line->ek < 0);
// 		line->xk += line->sdx * (!line->swap_xy && line->ek < 0)
// 			+ line->sdx * !(line->ek < 0);
// 		line->ek = (line->ek + 2 * line->dy) * (line->ek < 0)
// 			+ (line->ek + 2 * line->dy - 2 * line->dx) * !(line->ek < 0);
// 	}
// }

void	mlx_line_c(t_win_data *img, t_mlx_line *l)
{
	mlx_line(img, &(t_mlx_line){l->x0, l->y0, l->xn, l->yn, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0});
	return ;
}

void	mlx_line_tester_diagonals(t_win_data *img)
{
	mlx_line(img, &((t_mlx_line){0, F_SY, F_SX, 0, BLUE,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));

	// mlx_line_m(img, &((t_m_line){
	// 		&(t_pxy){0, F_SY, BLUE},
	// 		&(t_pxy){F_SX, 0, BLUE},
	// 		&(t_pxy){0, 0, BLUE},
	// 		0, 0, 0, 0, 0, 0, 0}));

	mlx_line(img, &((t_mlx_line){0, 0, F_SX, F_SY, BLUE,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){F_SX / 2, 0, F_SX, F_SY, RED,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){F_SX / 2, 0, 0, F_SY, RED,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){F_SX / 2, F_SY, F_SX, 0, GREEN,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){F_SX / 2, F_SY, 0, 0, GREEN,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	return ;
}

void	mlx_line_tester(t_win_data *img)
{
	mlx_line(img, &((t_mlx_line){L_X, L_Y, L_X, L_Y + 100, WHEAT,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){L_X, L_Y, L_X + 100, L_Y, WHEAT,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){L_X, L_Y, L_X + 100, L_Y + 100, WHEAT,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){L_X + 100, L_Y + 200, L_X + 100, L_Y + 100,
			BLUE, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){L_X + 100, L_Y + 200, L_X, L_Y + 200, BLUE,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_line(img, &((t_mlx_line){L_X + 100, L_Y + 200, L_X, L_Y + 100, BLUE,
			0, 0, 0, 0, 0, 0, 0, 0, 0}));
	mlx_put_image_to_window(img->mlx, img->win, img->img_ptr, 0, 0);
	mlx_line_tester_diagonals(img);
	return ;
}
