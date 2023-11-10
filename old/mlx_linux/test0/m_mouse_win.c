/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_mouse_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:21:01 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/24 22:37:33 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

//int	mouse_win1(int button, int x, int y, void *p)
int	mouse_win1(int button, int x, int y)
{
	printf("Mouse in Win1, button %d at %dx%d.\n", button, x, y);
	return (SUCCESS);
}

//int	mouse_win2(int button, int x, int y, void *p)
int	mouse_win2(int button, int x, int y)
{
	printf("Mouse in Win2, button %d at %dx%d.\n", button, x, y);
	return (SUCCESS);
}

//int	mouse_win3(int x, int y, void *p)
int	mouse_win3(int x, int y)
{
	printf("Mouse moving in Win3, at %dx%d.\n", x, y);
	return (SUCCESS);
}
