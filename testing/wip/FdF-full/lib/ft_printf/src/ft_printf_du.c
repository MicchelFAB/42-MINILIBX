/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:20 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/25 19:30:49 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

void	ft_print_nbr(char *num, t_params *params)
{
	if (params->precision == 0 && ft_atoi(num) == 0)
	{
		if (params->with > 0)
		{
			if (params->with > 1 && ft_is_sign(params) && \
				params->leftjustify == 0)
				params->chrprinted += ft_print_fill(' ', 1);
			if (ft_is_sign(params))
				params->chrprinted += ft_sign_print(params);
			else
				params->chrprinted += ft_print_fill(' ', 1);
		}
		else
			params->chrprinted += ft_sign_print(params);
		return ;
	}
	if (!(params->fill == '0' && params->with > (int)ft_strlen(num) && \
		params->precision < (int)ft_strlen(num)))
		params->chrprinted += ft_sign_print(params);
	ft_print_fill('0', params->precision - ft_strlen(num));
	ft_putstr_fd(num, 1);
	if (params->precision > (int)ft_strlen(num))
		params->chrprinted += params->precision;
	else
		params->chrprinted += (int)ft_strlen(num);
}

void	ft_print_gap_pre(char *num, t_params *params)
{
	int	gap;

	if (!params->leftjustify)
	{
		if (params->with > (int)ft_strlen(num))
		{
			gap = params->with - (int)ft_strlen(num) - ft_is_sign(params);
			if (params->precision > (int)ft_strlen(num))
				gap = params->with - params->precision - ft_is_sign(params);
			if ((params->fill == '0' && params->precision < 0))
				params->chrprinted += ft_sign_print(params);
			if (params->precision >= 0)
				params->fill = ' ';
			params->chrprinted += ft_print_fill(params->fill, gap);
		}
	}
	else
	{
		if (params->fill == '0' && params->with > (int)ft_strlen(num) && \
			params->precision < (int)ft_strlen(num))
			params->chrprinted += ft_sign_print(params);
	}
}

void	ft_print_gap_post(t_params *params)
{
	if (params->leftjustify && params->with > params->chrprinted)
		params->chrprinted += \
		ft_print_fill(' ', params->with - params->chrprinted);
}

int	ft_print_d(va_list	arg, t_params *params)
{
	char	*num;
	int		value;
	long	valueabs;

	value = va_arg(arg, int);
	valueabs = value;
	if (valueabs < 0)
		valueabs = -valueabs;
	if (value >= 0)
		params->sign = '+';
	else
		params->sign = '-';
	num = ft_uitoa((unsigned int)valueabs);
	ft_print_gap_pre(num, params);
	ft_print_nbr(num, params);
	ft_print_gap_post(params);
	free(num);
	return (params->chrprinted);
}

int	ft_print_u(va_list	arg, t_params *params)
{
	char	*num;

	num = ft_uitoa(va_arg(arg, unsigned int));
	params->sign = '+';
	ft_print_gap_pre(num, params);
	ft_print_nbr(num, params);
	ft_print_gap_post(params);
	free(num);
	return (params->chrprinted);
}
