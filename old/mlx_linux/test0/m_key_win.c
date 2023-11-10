/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_key_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:19:34 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/24 22:36:43 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

//int	key_win1(int key, void *p)
int	key_win1(int key)
{
	printf("Key in Win1 : %d\n", key);
	if (key == 0xFF1B)
		exit(SUCCESS);
	return (ERROR);
}

//int	key_win2(int key, void *p)
int	key_win2(int key)
{
	printf("Key in Win2 : %d\n", key);
	if (key == 0xFF1B)
		exit(SUCCESS);
	return (ERROR);
}

//int	key_win3(int key, void *p)
int	key_win3(int key)
{
	printf("Key in Win3 : %d\n", key);
	if (key == 0xFF1B)
		mlx_destroy_window(mlx, win3);
	return (SUCCESS);
}
