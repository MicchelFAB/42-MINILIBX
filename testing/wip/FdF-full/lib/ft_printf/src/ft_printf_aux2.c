/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:03:27 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/06/10 18:03:29 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_islimit(char c)
{
	const char	limit[] = "cspdiuxX%";
	char		*ptr;

	ptr = (char *) &limit[0];
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

int	ft_isflags(char c)
{
	char		*ptr;
	const char	flags[] = "0+-# ";

	ptr = (char *) &flags[0];
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

void	ft_struct_ini(t_params *params)
{
	params->fill = ' ';
	params->positive = 0;
	params->leftjustify = 0;
	params->gap = 0;
	params->altformat = 0;
	params->precision = -1;
	params->with = 0;
	params->chrprinted = 0;
}

void	ft_fill_flags(char c, t_params *params)
{
	if (c == '0')
		params->fill = '0';
	if (c == ' ')
		params->gap = 1;
	if (c == '+')
		params->positive = 1;
	if (c == '-')
		params->leftjustify = 1;
	if (c == '#')
		params->altformat = 1;
}
