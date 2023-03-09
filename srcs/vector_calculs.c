/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:43:55 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 11:00:20 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	norm(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vector	normalized(t_vector vector)
{
	t_vector	new;

	new.x = vector.x / norm(vector);
	new.y = vector.y / norm(vector);
	new.z = vector.z / norm(vector);
	return (new);
}

t_vector	cross_product(t_vector v1, t_vector v2)
{
	t_vector	cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = -(v1.x * v2.z - v1.z * v2.x);
	cross.x = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}

double	dot_product(t_vector v1, t_vector v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vector	mult(t_vector v, int i)
{
	t_vector	new;

	new.x = v.x * i;
	new.y = v.y * i;
	new.z = v.z * i;
	return (new);
}
