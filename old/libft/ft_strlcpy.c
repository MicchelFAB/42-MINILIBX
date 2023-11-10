/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:59:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/07/11 15:45:52 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 			Copy strings
/// @param dst		Destination string
/// @param src		Source string
/// @param dst_size	Maximum size of the destination string
/// @return			The total length of the string they tried to create
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dst_size == 0)
		return (src_size);
	else if (src_size < dst_size)
	{
		while (*src)
			*dst++ = *src++;
	}
	else
	{
		while (--dst_size)
			*dst++ = *src++;
	}
	*dst = '\0';
	return (src_size);
}
