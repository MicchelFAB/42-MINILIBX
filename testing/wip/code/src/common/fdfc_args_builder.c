/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfc_args_builder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:22:03 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	args_build_c(t_flags *f)
{
	int		splits;
/* ************************************************************************** */
	if (MY_DEBUG)
		ft_printf("args_build_c STARTED!\n");
/* ************************************************************************** */
	splits = 0;

	if (args_check(f) == ERROR)
	{
		if (MY_DEBUG)
			ft_printf("args_build_c ERROR(arg_check)!\n");
		return (ERROR);
	}
	if (MY_DEBUG)
		ft_printf("args_build_c continue (arg_check == SUCCESS)!\n");
	f->fd = open(f->file, O_RDONLY);
/* ************************************************************************** */
	if (_SHOW_STACKS_)
		args_print(f);
/* ************************************************************************** */
	ft_printf("%s************ start building args step 1 **************%s\n", GRN, WTH);
	f->line = get_next_line(f->fd);
	//ft_printf("%srow = %s%s\n", CYN, f->cmx[splits], WTH);
	ft_printf("%s#### malloc ####%s\n", RED, WTH);
	ft_printf("malloced %d\n", splits);
	ft_printf("%s************ start building args step 2 **************%s\n", GRN, WTH);
	if (f->line)
	{
		f->c = ft_split_count(f->line, ' ');
		f->cmx = (char **)malloc(sizeof(char *) * (f->c + 1));
		ft_printf("%s#### malloc ####%s\n", RED, WTH);
		ft_printf("malloced cmx : %d x %d \n", f->c + 1, sizeof(char *));
		if (!f->cmx)
		{
			ft_printf("%s#### free   ####%s\n", GRN, WTH);
			free (f->cmx);
			ft_printf("%s#### free   ####%s\n", GRN, WTH);
			free (f->line);
			return (ERROR);
		}
		f->cmx[splits] = f->line;
		f->line = NULL;
	}
	while (f->cmx[splits]){
		f->cmx[++splits] = get_next_line(f->fd);
		ft_printf("%srow = %s%s\n", CYN, f->cmx[splits], WTH);
		ft_printf("%s#### malloc ####%s\n", RED, WTH);
		ft_printf("malloced %d\n", splits);
	}
	close(f->fd);
	if (splits != f->c)
		return (ERROR);
	if (_SHOW_STACKS_)
		args_print(f);
	return (SUCCESS);
}

/// @brief 			Generates a list of elements from an array of arguments
/// @param array	Arguments
/// @param ac		Number of arguments
/// @return			Pointer to the stack
t_flags	*flags_init(int ac, char **av)
{
	t_flags	*f;

	if (MY_DEBUG)
		ft_printf("flags_init STARTED!\n");
	f = malloc(sizeof(t_flags));
	if (!f)
		return (NULL);
	//*f = (t_flags){0, *av, 0, 0, ac, av, NULL, NULL, NULL};
	f->c = 0;
	f->r = 0;
	f->file = *av;
	f->fd = 0;
	f->aux01 = ac;
	f->aux02 = 0;
	f->line = NULL;
	f->cmx = NULL;
	f->imatrix = NULL;
	f->fmatrix = NULL;
	return (f);
}

void	args_print(t_flags *f)
{
	ft_printf("*******************************\n");
	ft_printf("f->c\t= %d\n", f->c);
	ft_printf("f->r\t= %d\n", f->r);
	ft_printf("f->file\t\t= %s\n", f->file);
	ft_printf("f->fd\t\t= %d\n", f->fd);
	ft_printf("f->aux01\t= %d\n", f->aux01);
	ft_printf("f->len\t\t= %d\n", f->aux02);
	if (f->line)
	{
		ft_printf("f->line \t=[ %p ]\n", f->line);
		//if(*f->line)
		//	ft_printf("*f->line \t=[ %p ]\n", *f->line);
	}
	ft_printf("f->cmx\t= %p\n", f->cmx);
	if (f->cmx)
		ft_printf("f->cmx\t= %s\n", *(f->cmx));
	ft_printf("f->imatrix\t= %p\n", f->imatrix);
	ft_printf("f->fmatrix\t= %p\n", f->fmatrix);

	ft_printf("*******************************\n");
}

int	args_check(t_flags *f)
{
	int		columns = 0;

	if (MY_DEBUG)
		ft_printf("args_check STARTED!\n");
	f->fd = open(f->file, O_RDONLY);
	ft_printf("\nf->fd = %d\n\n",f->fd);
	if (f->fd == -1)
	{
		ft_printf("ERROR: Invalid file!\n");
		return (ERROR);
	}
	f->line = get_next_line(f->fd);
	ft_printf("%s#### arg_check :: init :: malloc f->line ####%s\n", RED, WTH);
	if (f->line)
		f->c = ft_split_count(f->line, ' ');
	while (f->line)
	{
		f->r++;
		f->line[ft_strlen(f->line)] = '\0';
		columns = ft_split_count(f->line, ' ');
		ft_printf("columns = %d\n", columns);
		ft_printf("line = %s\n", f->line);
		ft_free(f->line);
		ft_printf("%s#### arg_check :: ft_free f->line ####%s\n", GRN, WTH);
		if (columns != f->c)
		{
			ft_printf("ERROR: Invalid map! Check columns on each row\n");
			ft_printf("columns = %i != f->c = %i\n",columns, f->c);
			return (ERROR);
		}
		f->line = get_next_line(f->fd);
		if(f->line)
		{
			ft_printf("inside line = %s\n", f->line);
			ft_printf("%s#### arg_check :: wcycle :: malloc f->line ####%s\n", RED, WTH);
		}
	}
	close(f->fd);
	if(f->line)
	{
		ft_free(f->line);
		ft_printf("%s#### arg_check :: exit :: ft_free f->line   ####%s\n", GRN, WTH);
	}
	ft_printf("Matrix size : Row(s) = %d, Column(s) = %d\n", f->r, f->c);
	if (MY_DEBUG)
		ft_printf("args_check SUCCESS!\n");
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
