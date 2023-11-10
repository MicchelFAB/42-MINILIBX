/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:08:01 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/05 11:46:48 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"myfdf.h"

int	get_trgb_i(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t_i(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r_i(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g_i(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b_i(int trgb)
{
	return (trgb & 0xFF);
}
