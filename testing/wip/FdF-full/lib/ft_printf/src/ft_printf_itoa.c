/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:20:02 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/25 19:34:54 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_num_digits(unsigned long valor, int base)
{
	int	len;

	len = 0;
	while (valor > 0)
	{
		valor = valor / base;
		len++;
	}
	len++;
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*chrnum;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_num_digits(n, 10);
	chrnum = malloc(len * sizeof(char));
	if (chrnum == NULL)
		return (NULL);
	chrnum[len - 1] = '\0';
	while (n)
	{
		chrnum[len - 2] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (chrnum);
}

char	*ft_itoa_hex(unsigned long n)
{
	int				len;
	char			*chrnum;
	const char		hex[] = "0123456789abcdef";

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_num_digits(n, 16);
	chrnum = malloc(len * sizeof(char));
	if (chrnum == NULL)
		return (NULL);
	chrnum[len - 1] = '\0';
	while (n)
	{
		chrnum[len - 2] = hex[(n % 16)];
		n = n / 16;
		len--;
	}
	return (chrnum);
}

char	*ft_itoa_hex_4bytes(unsigned int n)
{
	int				len;
	char			*chrnum;
	const char		hex[] = "0123456789abcdef";

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_num_digits(n, 16);
	chrnum = malloc(len * sizeof(char));
	if (chrnum == NULL)
		return (NULL);
	chrnum[len - 1] = '\0';
	while (n)
	{
		chrnum[len - 2] = hex[(n % 16)];
		n = n / 16;
		len--;
	}
	return (chrnum);
}
