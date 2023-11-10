/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:15:14 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/05 13:31:02 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/myfdf.h"

char	sign_d(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}

int	my_round(double n)
{
	if ((sign_d(n) * (n - (int)n)) >= 0.5)
		return ((int)n + sign_d(n));
	return ((int)n);
}

int	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

int	ft_roundf(float n)
{
	if ((sign_d(n) * (n - (int)n)) >= 0.5)
		return ((int)n + sign_d(n));
	return ((int)n);
}
