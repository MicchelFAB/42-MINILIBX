/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lesson1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:22:06 by antoda-s          #+#    #+#             */
/*   Updated: 2023/08/09 18:06:02 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float	**alloc_float_array(int size)
{
	float	**m;
	m = (float **)malloc(sizeof(float *) * 4);
	m[0] = (float *)malloc(sizeof(float) * 4);
	m[1] = (float *)malloc(sizeof(float) * 4);
	m[2] = (float *)malloc(sizeof(float) * 4);
	m[3] = (float *)malloc(sizeof(float) * 4);
	return (m);
}

void	print_m44(float **m)
{
	int i = 0;
	int j = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%#6.1f ", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	swap(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	invert_it44(float **m, unsigned int size)
{
	unsigned int	r; // row
	unsigned int	c; //column;
	unsigned int	b; //bigger row ;
	unsigned int	j; //surf inside row
	unsigned int	i; //surf inside column
	int swap_count = 1;

	printf("INVERTED ARG MATRIX:\n");
	print_m44(m);
	while (swap_count != 0)
	{
		printf("CYCLE\n");
		swap_count = 0;
		c = 0;
		while (c < size)
		{
			j = 0;
			r = c;
			if (m[r][c] == 0) // pivot point is 0
			{
				b = c;
				printf("************* r = %d\n", r);
				printf("************* c = %d\n", c);
				if (r == (size -1))
				{
					i = 0;
					while (i < size)
					{
						if (m[r][i] != 0)
						{
							j = 0;
							while (j < size)
							{
									swap(&m[i][j], &m[r][j]);
								j++;
							}
						}
						i++;
					}
					swap_count = 1;
					break ;
				}
				while (r < size)
				{

					if (fabs(m[r][c]) > fabs(m[b][c]))
					{
						b = r;
						swap_count = 1;
					}
					r++;
				}
				if (b == c)
					printf("Singular matrix\n");
				else
					while (j < size)
					{
						swap(&m[c][j], &m[b][j]);
						j++;
					}
			}
			c++;
		}
		print_m44(m);

	}
	return ;
}

int	main(void)
{
	float	**m;
	int		i;
	int		j;

	i = 0;
	m= alloc_float_array(4);

	// m[0] = {1.0, 2.0, 3.0, 4.0};

	m[0][0] = 1;
	m[0][1] = 2;
	m[0][2] = 3;
	m[0][3] = 4;

	m[1][0] = 5;
	m[1][1] = 0;
	m[1][2] = 7;
	m[1][3] = 8;

	m[2][0] = 9;
	m[2][1] = 10;
	m[2][2] = 11;
	m[2][3] = 12;

	m[3][0] = 13;
	m[3][1] = 14;
	m[3][2] = 15;
	m[3][3] = 16;

	invert_it44(m, 4);
	return (0);

}