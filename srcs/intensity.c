/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:37:19 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/10 15:52:30 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	intensity(t_data *data, t_obj *obj, t_vector ray)
{
	t_vector	om;
	t_vector	ml;
	t_vector	l;
	t_vector	n;

	om = mult(ray, obj->t);
	ml = sub(data->l.coord, om);
	l = normalized(ml);
	n = (normalized(sub(om, obj->coord)));
	obj->intensity.r = obj->color.r * dot_product(n, l) * data->l.light;
	if (obj->intensity.r > 255)
		obj->intensity.r = 255;
	else if (obj->intensity.r < 0)
		obj->intensity.r = 0;
	obj->intensity.g = obj->color.g * dot_product(n, l) * data->l.light;
	if (obj->intensity.g > 255)
		obj->intensity.g = 255;
	else if (obj->intensity.g < 0)
		obj->intensity.g = 0;
	obj->intensity.b = obj->color.b * dot_product(n, l) * data->l.light;
	if (obj->intensity.b > 255)
		obj->intensity.b = 255;
	else if (obj->intensity.b < 0)
		obj->intensity.b = 0;
}
