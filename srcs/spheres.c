/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:00:52 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/07 15:32:10 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calculs_spheres(t_data *data)
{
	t_sphere	*tmp;

	tmp = data->sp;
	while (tmp)
	{
		tmp->s0.x = 0 - tmp->coord.x;
		tmp->s0.y = 0 - tmp->coord.y;
		tmp->s0.z = 0 - tmp->coord.z;
		tmp->r.x = tmp->coord.x - tmp->diameter / 2;
		tmp->r.y = tmp->coord.y;
		tmp->r.z = tmp->coord.z;
		tmp->radius = dot_product(tmp->r, tmp->r) - 2
			* dot_product(tmp->r, tmp->coord)
			+ dot_product(tmp->coord, tmp->coord);
		tmp->c = dot_product(tmp->s0, tmp->s0) - tmp->radius;
		tmp = tmp->next;
	}
}

void	render_spheres(t_data *data, t_vector ray, int *x, int *y)
{
	t_sphere	*tmp;
	double		a;
	double		b;

	tmp = data->sp;
	while (tmp)
	{
		a = dot_product(ray, ray);
		b = 2 * dot_product(ray, tmp->s0);
		if (pow(b, 2) - 4 * a * tmp->c >= 0)
			img_pix_put(&data->img, x, y, convert_rgb(tmp->color.r,
			tmp->color.g, tmp->color.b));
		tmp = tmp->next;
	}
}
