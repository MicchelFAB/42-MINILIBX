/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:08:01 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/05 11:46:58 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"myfdf.h"

int	get_trgb_c(unsigned char t, unsigned char r,
	unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

unsigned char	get_t_c(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

unsigned char	get_r_c(int trgb)
{
	return (((unsigned char *)&trgb)[2]);
}

unsigned char	get_g_c(int trgb)
{
	return (((unsigned char *)&trgb)[1]);
}

unsigned char	get_b_c(int trgb)
{
	return (((unsigned char *)&trgb)[0]);
}
