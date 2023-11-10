/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/09/19 14:07:06 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

int	abs_i(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_abs(double *n)
{
	if (*n < 0)
		*n = *n * (-1);
	return ;
}

double	abs_d(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max_i(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_i(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

