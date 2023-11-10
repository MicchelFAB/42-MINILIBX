/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:22:20 by myoung            #+#    #+#             */
/*   Updated: 2023/10/24 22:01:31 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	show_controls(void)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	ft_putstr("w/s : rotate by x axis\n"
		"a/d : rotate by y axis\n"
		"q/e : rotate by z axis\n"
		"\n"
		"c   : trippy colors\n"
		"ijkl: translate (move around)\n"
		"+/- : zoom / scale\n"
		"with z x or y, scale that axis\n"
		"Esc to quit.\n");
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}

void	fdf(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	show_controls();
	init_color_table(view, 100);
	full_redraw(view);
	view_set_hooks(view);
	mlx_loop(view->id);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}
// 	if (MY_DEBUG)
// 		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	if (MY_DEBUG)
// 		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);