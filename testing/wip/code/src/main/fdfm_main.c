/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfm_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:04:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_flags	*f;

	ft_printf("main STARTED!\n");
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf <filename>\n");
		return (0);
	}
	else
	{
		f = flags_init(argc - 1, ++argv);
		if (_SHOW_STACKS_)
			args_print(f);
		if (args_build_c(f) == ERROR)
		{
			ft_printf("ERROR DETECTED!\n");
			args_print(f);
			free_mem(f);
			return(ft_error());
		}
		if (_SHOW_MATRIX_ && f->cmatrix)
			matrix_print(f, 'c');
		if (_SHOW_MATRIX_ && f->imatrix)
			matrix_print(f, 'i');
		if (_SHOW_MATRIX_ && f->fmatrix)
			matrix_print(f, 'f');
	}
	free_mem(f);
	return (0);
}

void	matrix_print(t_flags *f, char type)
{
	int	i;
	int	j;

	if (MY_DEBUG)
		ft_printf("matrix_print STARTED!\n");
	i = 0;
	ft_printf("%c matrix:\n", type);
	while (f->cmatrix[i] && type == 'c')
		ft_printf("%s", f->cmatrix[i++]);
	while (i < f->c && type == 'i')
	{
		j = 0;
		while (j < f->c)
			ft_printf("%d", f->imatrix[i][j++]);
		i++;
	}
	while (i < f->c && type == 'f')
	{
		j = 0;
		while (j < f->c)
			ft_printf("%0.3f", f->fmatrix[i][j++]);
		i++;
	}
	ft_printf("\n");
}

int	free_mem(t_flags *f)
{
	int	i;

	if (MY_DEBUG)
		ft_printf("free_mem STARTED!\n");
	i = 0;
	while (i < f->c)
	{
		if (f->cmatrix)
		{
			ft_printf("free_mem f->cmatrix! %p\n", f->cmatrix);
			ft_printf("free_mem f->cmatrix[%d]! %p\n", i, f->cmatrix[i]);
			ft_printf("%s#### free char cmatrix[%i]  ####%s\n", GRN, i, WTH);
			free(f->cmatrix[i]);
		}
		if (f->imatrix)
		{
			ft_printf("free_mem f->imatrix!\n");
			ft_printf("%s#### free int imatrix[%i]  ####%s\n", GRN, i, WTH);
			free(f->imatrix[i]);
		}
		if (f->fmatrix)
		{
			ft_printf("free_mem f->fmatrix!\n");
			ft_printf("%s#### free float fmatrix[%i]  ####%s\n", GRN, i, WTH);
			free(f->fmatrix[i]);
		}
		i++;
	}
//	args_print(f);
	if (f->cmatrix)
	{
		ft_printf("%s#### free  cmatrix ####%s\n", GRN, WTH);
		free(f->cmatrix);
	}
	if (f->imatrix)
	{
		ft_printf("%s#### free  imatrix ####%s\n", GRN, WTH);
		free(f->imatrix);
	}
	if (f->fmatrix)
	{
		ft_printf("%s#### free  fmatrix ####%s\n", GRN, WTH);
		free(f->fmatrix);
	}
	if (f->line)
	{
		ft_printf("%s#### free  line x ####%s\n", GRN, WTH);
		ft_printf("%s#### line = %p x ####%s\n", GRN, *f->line, WTH);
		//free(f->line);
	}
	f->cmatrix = NULL;
	f->imatrix = NULL;
	f->fmatrix = NULL;
	args_print(f);

	free(f);
	return (SUCCESS);
}
