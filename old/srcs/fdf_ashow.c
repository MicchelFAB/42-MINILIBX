/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ashow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 23:04:12 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/24 10:14:13 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

void	matrix_print(t_flags *f, char type)
{
	int	row;
	// int	j;

	MY_DEBUG ? ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT):0;
	row = 0;
	MY_DEBUG ? ft_printf("  %s%s (01) %c matrix: %s\n", __func__, SCYN, type, SWHT):0;
	while (f->cmx[row] && type == 'c')
	{
		_SHOW_MATRIX_ ? ft_printf("  %s%s (12) MALLOC f->cmx[%d] = %s %s\n", __func__, SCYN, row, f->cmx[row], SWHT) : 0;
		row++;
	}
		//ft_printf("%s", f->cmx[i++]);
	// while (i < f->r && type == 'i')
	// {
	// 	j = 0;
	// 	while (j < f->c)
	// 		ft_printf("%d", f->imx[i][j++]);
	// 	i++;
	// }
	// while (i < f->c && type == 'f')
	// {
	// 	j = 0;
	// 	while (j < f->c)
	// 		ft_printf("%0.3f", f->fmx[i][j++]);
	// 	i++;
	// }
	MY_DEBUG ? ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT):0;

}

void	args_print(t_flags *f)
{
	ft_printf("%s(>)%s %s%s\n",SYLW, SYLW, __func__, SWHT);
	ft_printf("  %s%s (01) f->columns\t= %d%s\n", __func__, SCYN, f->c, SWHT);
	ft_printf("  %s%s (02) f->rows\t= %d%s\n", __func__, SCYN, f->r, SWHT);
	ft_printf("  %s%s (03) f->file\t= %s%s\n", __func__, SCYN, f->file, SWHT);
	ft_printf("  %s%s (04) f->fd\t\t= %d%s\n", __func__, SCYN, f->fd, SWHT);
	ft_printf("  %s%s (05) f->aux01\t= %d%s\n", __func__, SCYN, f->aux01, SWHT);
	ft_printf("  %s%s (06) f->len\t= %d%s\n", __func__, SCYN, f->len, SWHT);
	if (f->line)
		ft_printf("  %s%s (0) f->line \t=[ %p ]%s\n", __func__, SCYN, f->line, SWHT);
	ft_printf("  %s%s (07) f->cmx\t= %p%s\n", __func__, SCYN, f->cmx, SWHT);
	ft_printf("  %s%s (09) f->imx\t= %p%s\n", __func__, SCYN, f->imx, SWHT);
	ft_printf("  %s%s (10) f->fmx\t= %p%s\n", __func__, SCYN, f->fmx, SWHT);
	ft_printf("%s(X)%s %s%s\n",SYLW, SGRN, __func__, SWHT);
	return ;
}
