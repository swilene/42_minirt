/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:00:52 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 18:02:26 by saguesse         ###   ########.fr       */
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
			tmp->s0.x = 0 - tmp->coord.x;
			tmp->s0.y = 0 - tmp->coord.y;
			tmp->s0.z = 0 - tmp->coord.z;
			tmp->r.x = tmp->coord.x - tmp->diameter * 0.5;
			tmp->r.y = tmp->coord.y;
			tmp->r.z = tmp->coord.z;
			tmp->radius = dot_product(tmp->r, tmp->r) - 2
				* dot_product(tmp->r, tmp->coord)
				+ dot_product(tmp->coord, tmp->coord);
			tmp->c = dot_product(tmp->s0, tmp->s0) - tmp->radius;
		}
		tmp = tmp->next;
	}
}

int	render_spheres(t_obj *tmp, t_vector ray)
{
	double		a;
	double		b;
	double		delta;
	double		t1;
	double		t2;

	a = dot_product(ray, ray);
	b = 2 * dot_product(ray, tmp->s0);
	delta = pow(b, 2) - 4 * a * tmp->c;
	if (delta < 0)
		return (1);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t2 < 0)
		return (2);
	if (t1 > 0)
		tmp->t = t1;
	else
		tmp->t = t2;
	return (0);
}
