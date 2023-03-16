/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:31 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/16 16:30:04 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	calculs_cylinders(t_data *data)
{
	t_obj	*tmp;

	tmp = data->obj;
	while (tmp)
	{
		if (!strncmp("cy", tmp->identifier, 2))
		{
			tmp->ra1 = add(tmp->coord, mult(tmp->dir, tmp->height / 2));
			tmp->ra2 = add(tmp->coord, mult(tmp->dir, -tmp->height / 2));
			tmp->s = normalized(sub(tmp->ra2, tmp->ra1));
			tmp->ra0 = cross_product(cross_product(tmp->s,
					sub(data->c.coord, tmp->ra1)), tmp->s);
			tmp->radius = tmp->diameter / 2;
			tmp->c = dot_product(tmp->ra0, tmp->ra0) - pow(tmp->radius, 2);
		}
		tmp = tmp->next;
	}
}

int	render_cylinders(t_obj *tmp, t_vector ray)
{
	t_vector	va;
	double	a;
	double	b;
	double	delta;
	double	t1;
	double	t2;

	va = cross_product(cross_product(tmp->s, ray), tmp->s);
	a = dot_product(va, va);
	b = 2 * dot_product(tmp->ra0, va);
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
	if (dot_product(sub(mult(ray, tmp->t), tmp->ra1), tmp->s) > 0
			&& dot_product(sub(mult(ray, tmp->t), tmp->ra2), tmp->s) < 0)
	{
		//int ou ext cylindre ?
		return (0);
	}
	return (1);
}
