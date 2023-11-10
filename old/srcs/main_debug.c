/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:04:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"
#include "../include/fdf_debug.h"

int	main(int argc, char **argv)
{
	t_flags	*f;
	int		error;

	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	_MOUSE_TEST_ ? ft_printf("%s(>) MOUSE TEST%s\n",SYLW, SWHT):0;
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		return(ft_error(ARGS_ERROR));
	}
	else
	{

		f = flags_init(argc - 1, ++argv);
		if (!f)
			return (ft_error(MALLOC_ERROR));
		_SHOW_VARS_ ? args_print(f):0;
		error = args_start(f);
		if (error != SUCCESS)
		{
			_SHOW_VARS_ ? args_print(f):0;
			free_mem(f);
			return(ft_error(error));
		}
		_SHOW_VARS_ ? args_print(f):0;
		if (_MLX_TEST_)
			mlx_tester();
	}
	free_mem(f);
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (0);
}

int	args_start(t_flags *f)
{
	int		error;

	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	error = args_build(f);
	if (error != SUCCESS)
	{
		MY_DEBUG ? ft_printf("%s(X1)%s %s ERROR%s\n",SYLW, SRED, __func__, SWHT):0;
		return (error);
	}
	if (_SHOW_MATRIX_ && f->cmx)
		matrix_print(f, 'c');
	if (_SHOW_MATRIX_ && f->imx)
		matrix_print(f, 'i');
	if (_SHOW_MATRIX_ && f->fmx)
		matrix_print(f, 'f');
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (SUCCESS);
}
