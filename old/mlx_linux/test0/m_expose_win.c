/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_expose_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:15:48 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/24 22:34:48 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

//int	expose_win1(void *p)
int	expose_win1(void)
{
	mlx_put_image_to_window(mlx, win1, im3, 0, 0);
	return (SUCCESS);
}

//int	expose_win2(void *p)
int	expose_win2(void)
{
	mlx_put_image_to_window(mlx, win2, im4, 0, 0);
	mlx_put_image_to_window(mlx, win2, im2, 0, 0);
	return (SUCCESS);
}
