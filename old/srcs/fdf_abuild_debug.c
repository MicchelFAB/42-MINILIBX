/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_abuild_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:22:03 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

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

int	args_build(t_flags *f)
{
	int		row;
	int		error;
	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;

	row = 0;
	error = args_check(f);
	if (error)
	{
		MY_DEBUG ? ft_printf("%s(X1)%s %s ERROR%s\n",SYLW, SRED, __func__, SWHT):0;
		return (error);
	}
	f->line = NULL;
	f->cmx = (char **)malloc(sizeof(char *) * (f->r + 1));
	MY_DEBUG ? ft_printf("  %s%s (01) MALLOC f->cmx : %d x rows  %s\n",__func__, SCYN, f->r, SWHT) : 0;
	if (!f->cmx)
	{
		MY_DEBUG ? ft_printf("  %s%s (21) MALLOC ERROR!%s\n", __func__, SCYN, SWHT):0;
		MY_DEBUG ? ft_printf("  %s%s (22) free (f->cmx)!%s\n", __func__, SCYN, SWHT):0;
		free (f->cmx);
		MY_DEBUG ? ft_printf("  %s%s (23) free (f->line)!%s\n", __func__, SCYN, SWHT):0;
		free (f->line);
		MY_DEBUG ? ft_printf("%s%s (X2) MALLOC ERROR!%s\n", __func__, SRED, SWHT):0;
		return (MALLOC_ERROR);
	}
	f->cmx[f->r] = NULL;
	_SHOW_VARS_ ? args_print(f) : 0;

	f->fd = open(f->file, O_RDONLY);
	while (row < f->r)
	{
		f->line = get_next_line(f->fd);
		f->cmx[row] = ft_strtrim(f->line, " \n");
		MY_DEBUG ? ft_printf("  %s%s (12) MALLOC f->cmx[%d] = %s %s\n", __func__, SCYN, row, f->cmx[row], SWHT) : 0;
		ft_free_str(&f->line);
		row++;
	}
	f->line = NULL;
	close(f->fd);
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (SUCCESS);
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_flags	*flags_init(int ac, char **av)
{
	t_flags	*f;

	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	f = malloc(sizeof(t_flags));
	if (!f)
	{
		MY_DEBUG ? ft_printf("%s(X) %s MALLOC ERROR!%s\n",SYLW, SRED, __func__, SWHT):0;
		return (NULL);
	}
	MY_DEBUG ? ft_printf("  %s(1)%s %s MALLOC SUCCESS!%s\n",SYLW, SCYN, __func__, SWHT):0;
	*f = (t_flags){0, 0, *av, 0, ac, 0, NULL, NULL, NULL, NULL};
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (f);
}

void	args_print(t_flags *f)
{
	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (01) f->columns\t= %d%s\n", __func__, SCYN, f->c, SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (02) f->rows\t= %d%s\n", __func__, SCYN, f->r,SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (03) f->file\t= %s%s\n", __func__, SCYN, f->file,SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (04) f->fd\t\t= %d%s\n", __func__, SCYN, f->fd,SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (05) f->aux01\t= %d%s\n", __func__, SCYN, f->aux01,SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (06) f->len\t= %d%s\n", __func__, SCYN, f->len,SWHT):0;
	if (f->line)
		MY_DEBUG ? ft_printf("  %s%s (0) f->line \t=[ %p ]%s\n", __func__, SCYN, f->line,SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (07) f->cmx\t= %p%s\n", __func__, SCYN, f->cmx,SWHT):0;
	// if (f->cmx)
	// 	MY_DEBUG ? ft_printf("  %s%s (08) f->cmx\t= %s%s\n", __func__, SCYN, *(f->cmx),SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (09) f->imx\t= %p%s\n", __func__, SCYN, f->imx,SWHT):0;
	MY_DEBUG ? ft_printf("  %s%s (10) f->fmx\t= %p%s\n", __func__, SCYN, f->fmx,SWHT):0;
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return ;
}

int	args_check(t_flags *f)
{
	int		columns = 0;

	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	f->fd = open(f->file, O_RDONLY);
	MY_DEBUG ? ft_printf("  %s%s (01) f->fd = %d%s\n", __func__, SCYN, f->fd, SWHT):0;
	if (f->fd == -1)
	{
		MY_DEBUG ? ft_printf("%s(X1)%s %s FILE NOT FOUND!%s\n",SYLW, SRED, __func__, SWHT):0;
		return (FILE_NOT_FOUND);
	}
	f->line = get_next_line(f->fd);
	if (!f->line)
	{
		MY_DEBUG ? ft_printf("%s(X1)%s %s FILE IS EMPTY!%s\n",SYLW, SRED, __func__, SWHT):0;
		return (FILE_EMPTY);
	}
	MY_DEBUG ? ft_printf("  %s%s (02) malloc f->line!%s\n", __func__, SCYN, SWHT):0;
	f->c = ft_split_count(f->line, ' ');
	MY_DEBUG ? ft_printf("  %s%s (03) f->c = %d%s\n", __func__, SCYN, f->c, SWHT):0;
	while (f->line)
	{
		MY_DEBUG ? ft_printf("\n  %s%s (10) while(%p) %s\n", __func__, SCYN, f->line, SWHT):0;
		f->r++;
		if(f->line[ft_strlen(f->line) - 1] == '\n')
			f->line[ft_strlen(f->line) - 1] = '\0';
		MY_DEBUG ? ft_printf("\n  %s%s (101) strlen(f->line) = %d%s\n", __func__, SCYN, ft_strlen(f->line), SWHT):0;

		columns = ft_split_count(f->line, ' ');
		MY_DEBUG ? ft_printf("  %s%s (11) columns = %d, line = %s!%s\n", __func__, SCYN, columns, f->line, SWHT):0;
		ft_free_str(&f->line);
		MY_DEBUG ? ft_printf("  %s%s (12) free f->line!%s\n", __func__, SCYN, SWHT):0;
		if (columns != f->c)
		{
			MY_DEBUG ? ft_printf("  %s%s (21) columns = %i != f->c = %i%s\n", __func__, SCYN, columns, f->c, SWHT):0;
			MY_DEBUG ? ft_printf("%s%s (X3) INVALID MAP!%s\n", __func__, SRED, SWHT):0;
			return (MAP_ERROR);
		}
		f->line = get_next_line(f->fd);
		if (f->line)
		{
			MY_DEBUG ? ft_printf("  %s%s (31) malloc f->line!%s\n", __func__, SCYN,SWHT):0;
			//MY_DEBUG ? ft_printf("%s%s (32) inside line = %s!%s\n",  __func__, SCYN, f->line, SWHT):0;
		}
	}
	close(f->fd);
	if(f->line)
	{
		ft_free(f->line);
	MY_DEBUG ? ft_printf("  %s%s (41) free line!%s\n", __func__, SCYN, SWHT):0;
	}
		MY_DEBUG ? ft_printf("  %s%s (51) Matrix size : Row(s) = %d, Column(s) = %d%s\n", __func__, SCYN, f->r, f->c, SWHT):0;
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (SUCCESS);
}

void	ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
