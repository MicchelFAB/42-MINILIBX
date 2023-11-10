/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:17:14 by aitorlope         #+#    #+#             */
/*   Updated: 2022/05/25 19:39:26 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_fill(char c, int size)
{
	int	num;

	if (size < 0)
		return (0);
	num = size;
	while (size)
	{
		ft_putchar_fd(c, 1);
		size--;
	}
	return (num);
}

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_is_sign(t_params *params)
{
	return ((params->sign == '+' && params->positive) || \
		params->sign == '-' || params->gap);
}

int	ft_sign_print(t_params *params)
{
	if (ft_is_sign(params))
	{
		if (params->gap && params->sign == '+')
			params->sign = ' ';
		ft_putchar_fd(params->sign, 1);
		return (1);
	}
	return (0);
}

/*
void	ft_print_params(t_params *params)
{
	printf("\nparams->fill [%c]\n", params->fill);
	printf("\nparams->gap  [%d]\n", params->gap);
	printf("\nparams->positive [%d]\n", params->positive);
	printf("\nparams->leftjustify [%d]\n", params->leftjustify);
	printf("\nparams->altformat [%d]\n", params->altformat);
	printf("\nparams->with [%d]\n", params->with);
	printf("\nparams->precision [%d]\n", params->precision);
}
*/