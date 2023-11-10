/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_abuild.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:22:03 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/10 19:59:04 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

/// @brief 		Open file and validate it
/// @param f	Pointer to the struct with the arguments (fd, file, etc)
void	file_open(t_flags *f)
{
	f->fd = open(f->file, O_RDONLY);
	if (f->fd == -1)
		exit(EXIT_FAILURE);
	return ;
}

/// @brief 		Read plot data from file and validate it
/// @param f	Pointer to the struct with the arguments (fd, file, etc)
/// @return		0 if success,
///				1 if error reading file,
///				2 if error validating data
int	args_start(t_flags *f)
{
	file_open(f);
	args_check(f);
	close(f->fd);
	file_open(f);
	args_build(f);
	close(f->fd);
	if (_SHOW_MATRIX_ && f->cmx)
		matrix_print(f, 'c');
	if (_SHOW_MATRIX_ && f->imx)
		matrix_print(f, 'i');
	if (_SHOW_MATRIX_ && f->fmx)
		matrix_print(f, 'f');
	return (SUCCESS);
}

int	args_check(t_flags *f)
{
	int	col;

	f->line = get_next_line(f->fd);
	if (!f->line)
		return (FILE_EMPTY);
	col = 0;
	f->r = 0;
	f->c = 0;
	while (f->line)
	{
		col = ft_split_count(f->line, ' ');
		if (args_data_err(f->line) || (f->c != 0 && f->c != col))
			exit(EXIT_FAILURE);
		ft_free(f->line);
		f->c = col;
		f->r++;
		f->line = get_next_line(f->fd);
	}
	ft_free(f->line);
	return (SUCCESS);
}

int	args_build(t_flags *f)
{
	int		row;

	row = 0; // ???
	f->line = NULL;
	f->cmx = (char **)malloc(sizeof(char *) * (f->r + 1));
	if (!f->cmx)
		return (MALLOC_ERROR);
	f->cmx[f->r] = NULL;
	while (row < f->r)
	{
		f->line = get_next_line(f->fd);
		f->cmx[row] = ft_strtrim(f->line, " \n");
		ft_free(f->line);
		row++;
	}
	f->line = NULL;
	return (SUCCESS);
}

int	args_data_err(void *line)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)line;
	while (str[i])
	{
		if (!(ft_ishex(str[i])
				|| ft_isspace(str[i])
				|| ft_issign(str[i])
				|| str[i] == ','
				|| str[i] == 'x'))
			exit(EXIT_FAILURE);
		i++;
	}
	return (SUCCESS);
}

