/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:04:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/10 19:46:56 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"
#include "../include/fdf_debug.h"

int	main(int argc, char **argv)
{
	t_flags	*f;
	int		error;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		return (ft_error(ARGS_ERROR));
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
			return (ft_error(error));
		}
		_SHOW_VARS_ ? args_print(f):0;
		if (_MLX_TEST_)
			mlx_tester();
	}
	free_mem(f);
	return (0);
}



/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_flags	*flags_init(int ac, char **av)
{
	t_flags	*f;

	f = malloc(sizeof(t_flags));
	if (!f)
		exit (EXIT_FAILURE);
	*f = (t_flags){0, 0, *av, 0, ac, 0, NULL, NULL, NULL, NULL};
	return (f);
}
