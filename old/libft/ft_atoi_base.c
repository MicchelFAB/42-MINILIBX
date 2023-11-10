/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:56:37 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/05 23:23:11 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Converts the initial portion of the string pointed to by nptr
///				to int
/// @param 		nptr	The string to convert
/// @return		The converted int
int	ft_atoi_base(const char *nptr, int base)
{
	static char		*def = "0123456789ABCDEF";
	int				ret;
	int				sign;
	int				i;

	ret = 0;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	while (ft_ishex(*nptr))
	{
		i = -1;
		while (++i < base)
			if (def[i] == ft_toupper(*nptr))
			{
				ret = (ret * base) + i;
				break ;
			}
		nptr++;
	}
	return (sign * ret);
}
