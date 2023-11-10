/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:54:02 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/10 18:10:44 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

/// @brief 			Displays errors when args or process not successful
/// @param		-	void
/// @return	-		ERROR
int	ft_error(const int error_code)
{
	if (error_code == MALLOC_ERROR)
		write(2, "Malloc Error\n", sizeof("Malloc Error\n"));
	else if (error_code == FILE_ERROR)
		write(2, "File Error\n", sizeof("File Error\n"));
	else if (error_code == FILE_NOT_VALID)
		write(2, "File not valid\n", sizeof("File not valid\n"));
	else if (error_code == FILE_NOT_FOUND)
		write(2, "File not found\n", sizeof("File not found\n"));
	else if (error_code == FILE_EMPTY)
		write(2, "Map File Empty\n", sizeof("Map File Empty\n"));
	else if (error_code == MAP_ERROR)
		write(2, "Map Error\n", sizeof("Map Error\n"));
	else if (error_code == MLX_ERROR)
		write(2, "Mlx Error\n", sizeof("Mlx Error\n"));
	else if (error_code == ARGS_ERROR)
		write(2, "Usage: ./fdf <filename>\n",
			sizeof("Usage: ./fdf <filename>\n"));
	else if (error_code == PROCESS_ERROR)
		write(2, "Process Error\n", sizeof("Process Error\n"));
	else if (error_code == MATRIX_ERROR)
		write(2, "Matrix Error\n", sizeof("Matrix Error\n"));
	else if (error_code == COLOR_ERROR)
		write(2, "Color Error\n", sizeof("Color Error\n"));
	else if (error_code == BONUS_ERROR)
		write(2, "Bonus Error\n", sizeof("Bonus Error\n"));
	else
		write(2, "Error\n", sizeof("Error\n"));
	return (ERROR);
}