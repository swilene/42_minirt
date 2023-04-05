/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:59:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/05 11:59:58 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	has_shadow(t_vector ray, t_obj *tmp, t_vector origin, t_data *data)
{
	int		inter;

	while (tmp)
	{
		if (!strncmp("pl", tmp->identifier, 2))
			inter = render_planes(tmp, normalized(ray), origin);
		else if (!strncmp("sp", tmp->identifier, 2))
			inter = render_spheres(tmp, normalized(ray), origin);
		else
			inter = shadow_cylinders(tmp, ray, origin, 0.0);
		if (!inter && pow(tmp->t, 2) < pow(distance(origin, data->l.coord), 2))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	shadows(t_vector light, t_obj *obj, t_data *data)
{
	double		d;
	double		intensity;

	obj->diffuse.r = 0;
	obj->diffuse.g = 0;
	obj->diffuse.b = 0;
	d = dot_product(normalized(light), obj->normale);
	if (d > 0)
	{
		intensity = d * 20 * data->l.light * fmin(1.0, 1 / pow(norm(light), 2));
		obj->diffuse.r = intensity * obj->color.r * obj->ambient.r;
		obj->diffuse.g = intensity * obj->color.g * obj->ambient.g;
		obj->diffuse.b = intensity * obj->color.b * obj->ambient.b;
	}
	obj->ambient.r = fmin(255, fmax(0, obj->ambient.r + obj->diffuse.r));
	obj->ambient.g = fmin(255, fmax(0, obj->ambient.g + obj->diffuse.g));
	obj->ambient.b = fmin(255, fmax(0, obj->ambient.b + obj->diffuse.b));
}
