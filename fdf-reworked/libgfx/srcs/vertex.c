/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:19:28 by antoda-s          #+#    #+#             */
/*   Updated: 2023/10/25 23:04:38 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx.h"
//#include "../include/libgfx.h"

t_2dp	*get_2dp(float x, float y)
{
	t_2dp	*out;

	out = (t_2dp *)malloc(sizeof(t_2dp));
	out->x = x;
	out->y = y;
	return (out);
}

t_3dp	*get_3dp(float x, float y, float z)
{
	t_3dp	*out;

	out = (t_3dp *)malloc(sizeof(t_3dp));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}

t_vertex	*get_vertex(float x, float y, float z)
{
	t_vertex	*out;

	out = (t_vertex *)malloc(sizeof(t_vertex));
	out->local = get_3dp(x, y, z);
	out->world = get_3dp(0, 0, 0);
	out->aligned = get_3dp(0, 0, 0);
	out->projected = get_3dp(0, 0, 0);
	out->color = z;
	return (out);
}
