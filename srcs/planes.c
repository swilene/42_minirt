/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:31:08 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/05 17:03:21 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	render_planes(t_obj *tmp, t_vector ray, t_vector origin)
{
	t_vector	inv;

	inv = mult(tmp->dir, -1.0);
	if (dot_product(ray, tmp->dir) >= dot_product(inv, ray))
		tmp->dir = inv;
	tmp->t = dot_product(tmp->dir, sub(tmp->coord, origin))
		/ dot_product(tmp->dir, ray);
	if (tmp->t < 0)
		return (1);
	return (0);
}
