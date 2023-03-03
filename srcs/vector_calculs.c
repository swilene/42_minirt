/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:43:55 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/03 17:16:34 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	norm_vector(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

t_vector	normalize_vector(double i, t_vector vector)
{
	t_vector	new;

	new.x = vector.x / norm_vector(vector);
	new.y = vector.y / norm_vector(vector);
	new.z = vector.z / norm_vector(vector);
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

t_vector	dot_product(t_vector v1, t_vector v2)
{
	t_vector	dot;

	dot.x = v1.x * v2.x;
	dot.y = v1.y * v2.y;
	dot.z = v1.z * v2.z;
	return (dot);
}
