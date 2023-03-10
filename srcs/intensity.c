/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:37:19 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/10 14:08:40 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	intensity(t_data *data, t_obj *obj, t_vector ray)
{
	t_vector	p;
	t_vector	n;
	double		pix_int;
	double		r;
	double		g;
	double		b;

	p = mult(ray, obj->t);
	n = normalized(sub(p, obj->coord));
	pix_int = data->l.light * dot_product(normalized(sub(data->l.coord, p)), n)
		/ norm(sub(data->l.coord, p));
	r = obj->color.r / 255.0;
	g = obj->color.r / 255.0;
	b = obj->color.b / 255.0;


	obj->intensity.r = r * pix_int;
	printf("r: %f\t", r);
	if (obj->intensity.r > 255)
		obj->intensity.r = 255;
	else if (obj->intensity.r < 0)
		obj->intensity.r = 0;
	obj->intensity.g = g  * pix_int;
	printf("g: %f\t", g);
	if (obj->intensity.g > 255)
		obj->intensity.g = 255;
	else if (obj->intensity.g < 0)
		obj->intensity.g = 0;
	obj->intensity.b = b * pix_int;
	printf("b: %f\n", b);
	if (obj->intensity.b > 255)
		obj->intensity.b = 255;
	else if (obj->intensity.b < 0)
		obj->intensity.b = 0;
}
