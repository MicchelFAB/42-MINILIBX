/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:56:02 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/24 00:19:08 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <stddef.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>

typedef struct p_params{
	int		with;
	char	fill;
	int		positive;
	int		leftjustify;
	int		gap;
	int		altformat;
	int		precision;
	char	type;
	char	sign;
	int		chrprinted;
}	t_params;

int		ft_printf(const char *params, ...);
int		ft_print_c(va_list arg, t_params *params);
int		ft_print_s(va_list arg, t_params *params);
int		ft_print_d(va_list arg, t_params *params);
int		ft_print_u(va_list arg, t_params *params);
char	*ft_uitoa(unsigned int n);
int		ft_print_x(va_list arg, t_params *params);
int		ft_print_xx(va_list arg, t_params *params);
char	*ft_itoa_hex(unsigned long n);
char	*ft_itoa_hex_4bytes(unsigned int n);
int		ft_print_p(va_list arg, t_params *params);
int		ft_print_fill(char c, int size);
int		ft_putstr(char *s);
int		ft_is_sign(t_params *params);
int		ft_sign_print(t_params *params);
int		ft_print_x_right(t_params *params, char *num, char *prefix);
int		ft_print_x_left(t_params *params, char *num, char *prefix);
int		ft_print_nbr_x(char *num, t_params *params);
int		ft_islimit(char c);
int		ft_isflags(char c);
void	ft_struct_ini(t_params *params);
void	ft_fill_flags(char c, t_params *params);
#endif
