/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:31:08 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/29 15:54:45 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	render_planes(t_obj *tmp, t_vector ray, t_vector origin)
{
	tmp->t = dot_product(tmp->dir, sub(tmp->coord, origin))
		/ dot_product(tmp->dir, ray);
	if (tmp->t < 0)
		return (1);
	return (0);
}

void	print_vector(t_vector v)
{
	printf("x: %f\ty: %f\tz: %f\n", v.x, v.y, v.z);
}

int	shadow_planes(t_obj *tmp, t_vector ray, t_vector origin, t_data *data)
{
	tmp->t = (dot_product(tmp->dir, sub(tmp->coord, data->c.coord))
		- dot_product(tmp->dir, origin))
		/ dot_product(tmp->dir, normalized(ray));
	//tmp->t = dot_product(tmp->dir, sub(data->l.coord, origin))
	//	/ dot_product(tmp->dir, normalized(ray));
	if (tmp->t < 0)
		return (1);
	return (0);
}
