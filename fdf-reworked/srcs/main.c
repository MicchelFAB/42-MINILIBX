/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 00:39:05 by myoung            #+#    #+#             */
/*   Updated: 2023/10/26 00:19:41 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	view_set_hooks(t_view *view)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);

	mlx_expose_hook(view->win, expose_hook, view);


	mlx_do_key_autorepeatoff(view->id);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_do_key_autorepeatoff", SWHT);

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_hook", SWHT);
	mlx_hook(view->win, KeyPress, KeyPressMask, key_press_hook, view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_hook", SWHT);

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_hook", SWHT);
	mlx_hook(view->win, KeyRelease, KeyReleaseMask, key_release_hook, view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_hook", SWHT);

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_hook", SWHT);
	mlx_hook(view->win, DestroyNotify, 0, exit_hook, view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_hook", SWHT);

	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n",SYLW, SYLW, "mlx_loop_hook", SWHT);
	mlx_loop_hook(view->id, my_loop_hook, view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, "mlx_loop_hook", SWHT);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
}

// void	view_set_hooks(t_view *view)
// {
// 	if (MY_DEBUG)
// 		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	mlx_expose_hook(view->win, expose_hook, view);
// 	mlx_do_key_autorepeatoff(view->id);
// 	mlx_hook(view->win, 2, 0, key_press_hook, view);
// 	mlx_hook(view->win, 3, 0, key_release_hook, view);
// 	mlx_hook(view->win, 17, 0, exit_hook, view);
// 	mlx_loop_hook(view->id, my_loop_hook, view);
// 	if (MY_DEBUG)
// 		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
// }

int	main(int argc, char **argv)
{
	if (MY_DEBUG)
		printf("%s(>)%s %s%s\n", SYLW, SYLW, __func__, SWHT);
	t_view	*view;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (0);
	}
	view = init_v();
	parse(view, argv[1]);
	fdf(view);
	if (MY_DEBUG)
		printf("%s(X)%s %s%s\n", SYLW, SGRN, __func__, SWHT);
}
// 	if (MY_DEBUG)
// 		printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
// 	if (MY_DEBUG)
// 		printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);