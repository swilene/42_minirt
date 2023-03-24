/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:22:50 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/24 14:36:29 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	mult(t_vector v, double i)
{
	t_vector	new;

	new.x = v.x * i;
	new.y = v.y * i;
	new.z = v.z * i;
	return (new);
}

t_vector	sub(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}

t_vector	add(t_vector v1, t_vector v2)
{
	t_vector	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vector	add_double(t_vector v1, double i)
{
	t_vector	new;

	new.x = v1.x + i;
	new.y = v1.y + i;
	new.z = v1.z + i;
	return (new);
}

t_vector	divide(t_vector v1, double i)
{
	t_vector	new;

	new.x = v1.x / i;
	new.y = v1.y / i;
	new.z = v1.z / i;
	return (new);
}
