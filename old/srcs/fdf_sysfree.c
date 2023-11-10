/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sysfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:04:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

int	free_mem(t_flags *f)
{
	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;

	if (free_arrays(f) == ERROR)
		return (ERROR);
	if (free_pointers(f) == ERROR)
		return (ERROR);
	free(f);
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (SUCCESS);
}

int	free_arrays(t_flags *f)
{
	int	i;

	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;

	i = 0;
	while (i < f->r)
	{
		if (f->cmx)
		{
			MY_DEBUG ? ft_printf("  %s%s (12) f->cmx[%i] = %p%s\n", __func__, SCYN, i, f->cmx[i], SWHT) : 0;
			free(f->cmx[i]);
		}
		if (f->imx)
		{
			MY_DEBUG ? ft_printf("  %s%s (21) f->imx[%i] = %p%s\n", __func__, SCYN, i, f->imx[i], SWHT) : 0;
			free(f->imx[i]);
		}
		if (f->fmx)
		{
			MY_DEBUG ? ft_printf("  %s%s (31) f->fmx[%i] = %p%s\n", __func__, SCYN, i, f->fmx[i], SWHT) : 0;
			free(f->fmx[i]);
		}
		i++;
	}
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (SUCCESS);
}

int	free_pointers(t_flags *f)
{
	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	if (f->cmx)
	{
		MY_DEBUG ? ft_printf("  %s%s (11) f->cmx = %p%s\n", __func__, SCYN, f->cmx, SWHT) : 0;
		free(f->cmx);
	}
	if (f->imx)
	{
		MY_DEBUG ? ft_printf("  %s%s (11) f->imx = %p%s\n", __func__, SCYN, f->imx, SWHT) : 0;
		free(f->imx);
	}
	if (f->fmx)
	{
		MY_DEBUG ? ft_printf("  %s%s (11) f->fmx = %p%s\n", __func__, SCYN, f->fmx, SWHT) : 0;
		free(f->fmx);
	}

	f->cmx = NULL;
	f->imx = NULL;
	f->fmx = NULL;
	_SHOW_VARS_ ? args_print(f):0;
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;
	return (SUCCESS);
}
