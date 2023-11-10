/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:11:14 by aitorlope         #+#    #+#             */
/*   Updated: 2022/06/01 10:11:15 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_x(va_list arg, t_params *params)
{
	char	*num;
	int		valor;	
	int		len;

	valor = va_arg(arg, int);
	num = ft_itoa_hex_4bytes(valor);
	if (valor == 0)
		params->altformat = 0;
	if (params->precision >= 0 && params->precision < (int)ft_strlen(num) && \
		valor != 0)
		params->precision = (int)ft_strlen(num);
	if (params->leftjustify)
		len = ft_print_x_left(params, num, "0x");
	else
		len = ft_print_x_right(params, num, "0x");
	free(num);
	return (len);
}

int	ft_print_xx(va_list arg, t_params *params)
{
	char	*num;
	int		valor;	
	int		len;		
	int		i;

	valor = va_arg(arg, int);
	num = ft_itoa_hex_4bytes(valor);
	i = 0;
	while (*(num + i))
	{
		*(num + i) = ft_toupper(*(num + i));
		i++;
	}	
	if (valor == 0)
		params->altformat = 0;
	if (params->precision >= 0 && params->precision < (int)ft_strlen(num) && \
		valor != 0)
		params->precision = (int)ft_strlen(num);
	len = 0;
	if (params->leftjustify)
		len = ft_print_x_left(params, num, "0X");
	else
		len = ft_print_x_right(params, num, "0X");
	free(num);
	return (len);
}

int	ft_print_p(va_list arg, t_params *params)
{
	char	*num;
	char	*ptr;
	int		len;

	ptr = va_arg(arg, char *);
	num = ft_itoa_hex((unsigned long)ptr);
	if (params->leftjustify)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(num, 1);
		ft_print_fill(' ', params->with - ft_strlen(num) - 2);
	}
	else
	{
		ft_print_fill(' ', params->with - ft_strlen(num) - 2);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(num, 1);
	}
	len = (int)ft_strlen(num) + 2;
	free(num);
	if (params->with > len)
		return (params->with);
	return (len);
}
