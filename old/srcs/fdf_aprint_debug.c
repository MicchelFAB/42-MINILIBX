/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aprint_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:223 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/10 17:56:42 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/myfdf.h"

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
