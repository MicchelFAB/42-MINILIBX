/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:45:42 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/10 19:44:19 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Checks is an alphabetic upper case character.
/// @param c	Character to check
/// @return		1 if c is alphabetic, 0 otherwise
// static int	ft_isupperhex(int c)
// {
// 	if (c >= 'A' && c <= 'F')
// 		return (1);
// 	return (0);
// }

/// @brief 		Checks is an alphabetic lower case character.
/// @param c	Character to check
/// @return		1 if c is alphabetic, 0 otherwise
// static int	ft_islowerhex(int c)
// {
// 	if (c >= 'a' && c <= 'f')
// 		return (c >= 'a' && c <= 'f');
// 	return (0);
// }

/// @brief 		Checks for an alphabetic character.
/// @param c	Character to check
/// @return		1 if c is alphabetic, 0 otherwise
int	ft_ishex(int c)
{
	// if (ft_islowerhex(c) || ft_isupperhex(c) || ft_isdigit(c))
	// 	return (1);
	return ((c >= 'a' && c <= 'f')
		|| (c >= 'A' && c <= 'F')
		|| (c >= '0' && c <= '9'));
	//return (0);
}
