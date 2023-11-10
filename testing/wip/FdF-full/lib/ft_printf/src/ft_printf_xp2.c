/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:57:05 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/06/10 17:57:07 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_nbr_x(char *num, t_params *params)
{
	if (params->precision == 0 && ft_atoi(num) == 0)
	{
		ft_putstr_fd("", 1);
		return (0);
	}
	else
		return (ft_putstr(num));
}

int	ft_print_x_left(t_params *params, char *num, char *prefix)
{
	int	gap;
	int	len;

	len = 0;
	gap = params->precision - ft_strlen(num);
	if (params->precision < 0)
		gap++;
	if (params->altformat)
		len += ft_putstr(prefix);
	len += ft_print_fill('0', gap);
	len += ft_print_nbr_x(num, params);
	len += ft_print_fill(' ', params->with - len);
	return (len);
}

int	ft_print_x_right(t_params *params, char *num, char *prefix)
{
	int	len;

	len = 0;
	if (params->precision >= 0)
	{
		len += ft_print_fill(' ', params->with - params->precision - \
			2 * params->altformat);
		if (params->altformat)
			len += ft_putstr(prefix);
		len += ft_print_fill('0', params->precision - ft_strlen(num));
	}
	else
	{
		if (params->altformat && params->fill == '0')
			len += ft_putstr(prefix);
		len += ft_print_fill(params->fill, params->with - \
				(int)ft_strlen(num) - 2 * params->altformat);
		if (params->altformat && params->fill == ' ')
			len += ft_putstr(prefix);
	}
	len += ft_print_nbr_x(num, params);
	return (len);
}
