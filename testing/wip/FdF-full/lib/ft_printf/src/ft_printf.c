/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:54:28 by ailopez-          #+#    #+#             */
/*   Updated: 2022/06/03 18:28:44 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_fill_params(const char *str, t_params *params)
{
	int		i;
	char	*with;
	int		wd;

	ft_struct_ini(params);
	i = 0;
	while (ft_isflags(*(str + i)))
	{
		ft_fill_flags(*(str + i), params);
		i++;
	}
	wd = i;
	while (ft_isdigit(*(str + i)))
		i++;
	with = malloc((i - wd + 1) * sizeof(char));
	ft_strlcpy(with, str + wd, i - wd + 1);
	params->with = ft_atoi(with);
	free (with);
	return (i);
}

char	*ft_load_params(const char *str, t_params *params)
{
	int		i;
	char	*with;
	int		wd;

	i = ft_fill_params(str, params);
	if (*(str + i) == '.')
	{
		i++;
		wd = i;
		while (ft_isdigit(*(str + i)))
			i++;
		with = malloc((i - wd + 1) * sizeof(char));
		ft_strlcpy(with, str + wd, i - wd + 1);
		params->precision = ft_atoi(with);
		free (with);
	}
	if (params->precision > 0)
		params->fill = ' ';
	while (!ft_islimit(*(str)))
		str++;
	params->type = *(str);
	if (*str == '%' && *(str - 1) != '%' && params->with > 0)
		params->type = 'r';
	return ((char *)str);
}

void	ft_print_exceptions(t_params *params)
{
	if (params->type == '%')
	{
		write(1, "%", 1);
		params->chrprinted = 1;
	}
	if (params->type == 'r')
	{
		if (params->leftjustify)
		{
			write(1, "%", 1);
			params->chrprinted = ft_print_fill(' ', params->with - 1);
		}
		else
		{
			params->chrprinted = ft_print_fill(' ', params->with - 1);
			write(1, "%", 1);
		}
		params->chrprinted = 1;
	}
}

char	*ft_print_arg(const char *str, va_list	arg, t_params *params)
{
	char		*returnvalue;

	str++;
	returnvalue = ft_load_params(str, params);
	if (params->type == 'c')
		params->chrprinted = ft_print_c(arg, params);
	if (params->type == 's')
		params->chrprinted = ft_print_s(arg, params);
	if (params->type == 'p')
		params->chrprinted = ft_print_p(arg, params);
	if (params->type == 'd')
		params->chrprinted = ft_print_d(arg, params);
	if (params->type == 'i')
		params->chrprinted = ft_print_d(arg, params);
	if (params->type == 'u')
		params->chrprinted = ft_print_u(arg, params);
	if (params->type == 'x')
		params->chrprinted = ft_print_x(arg, params);
	if (params->type == 'X')
		params->chrprinted = ft_print_xx(arg, params);
	ft_print_exceptions(params);
	return (returnvalue);
}

int	ft_printf(const char *toprint, ...)
{
	int			n;
	va_list		argc;
	char		*str;
	t_params	params;

	str = (char *)toprint;
	va_start (argc, toprint);
	n = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_print_arg(str, argc, &params);
			n = n + params.chrprinted;
		}
		else
		{
			write (1, str, 1);
			n++;
		}
		str++;
	}
	va_end(argc);
	return (n);
}
