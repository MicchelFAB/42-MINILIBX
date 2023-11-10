/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:27:11 by antoda-s	       #+#    #+#             */
/*   Updated: 2023/08/09 22:28:41 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fdf_learn.h>

int	main(void)
{
	int	i;
	int	j;
	int	a[10][10];
	int	size;

	printf("Enter square matrix size N:\n");
	scanf("%d", &size);
	printf("Enter matrix elements:\n");
	for (i = 0; i <	size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("Matrix	read	is:\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
	return (0);
}
