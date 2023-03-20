/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:00:52 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/20 15:26:14 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calculs_spheres(t_data *data)
{
	t_obj	*tmp;

	tmp = data->obj;
	while (tmp)
	{
		if (!ft_strncmp("sp", tmp->identifier, 2))
		{
			tmp->sp.r.x = tmp->coord.x - tmp->diameter * 0.5;
			tmp->sp.r.y = tmp->coord.y;
			tmp->sp.r.z = tmp->coord.z;
			tmp->sp.radius = dot_product(tmp->sp.r, tmp->sp.r) - 2
				* dot_product(tmp->sp.r, tmp->coord)
				+ dot_product(tmp->coord, tmp->coord);
		}
		tmp = tmp->next;
	}
}

int	render_spheres(t_obj *tmp, t_vector ray, t_vector origin)
{
	double		delta;
	double		t1;
	double		t2;

	tmp->sp.s0 = sub(origin, tmp->coord);
	tmp->c = dot_product(tmp->sp.s0, tmp->sp.s0) - tmp->sp.radius;
	tmp->a = dot_product(ray, ray);
	tmp->b = 2 * dot_product(ray, tmp->sp.s0);
	delta = pow(tmp->b, 2) - 4 * tmp->a * tmp->c;
	if (delta < 0)
		return (1);
	t1 = (-tmp->b - sqrt(delta)) / (2 * tmp->a);
	t2 = (-tmp->b + sqrt(delta)) / (2 * tmp->a);
	if (t2 < 0)
		return (2);
	if (t1 > 0)
		tmp->t = t1;
	else
		tmp->t = t2;
	return (0);
}
