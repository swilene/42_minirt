/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:31 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/29 19:11:52 by saguesse         ###   ########.fr       */
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
			tmp->cy.ra1 = add(tmp->coord, mult(tmp->dir, tmp->height / 2));
			tmp->cy.ra2 = add(tmp->coord, mult(tmp->dir, -tmp->height / 2));
			tmp->cy.s = normalized(sub(tmp->cy.ra2, tmp->cy.ra1));
			tmp->cy.radius = tmp->diameter / 2;
		}
		tmp = tmp->next;
	}
}

int	render_cylinders(t_obj *tmp, t_vector ray, t_vector origin, double delta)
{
	double		t1;
	double		t2;

	tmp->cy.ra0 = cross_product(cross_product(tmp->cy.s, sub(origin,
					tmp->cy.ra1)), tmp->cy.s);
	tmp->c = dot_product(tmp->cy.ra0, tmp->cy.ra0) - pow(tmp->cy.radius, 2);
	tmp->cy.va = cross_product(cross_product(tmp->cy.s, ray), tmp->cy.s);
	tmp->a = dot_product(tmp->cy.va, tmp->cy.va);
	tmp->b = 2 * dot_product(tmp->cy.ra0, tmp->cy.va);
	delta = pow(tmp->b, 2) - 4 * tmp->a * tmp->c;
	t1 = (-tmp->b - sqrt(delta)) / (2 * tmp->a);
	t2 = (-tmp->b + sqrt(delta)) / (2 * tmp->a);
	if (t1 > 0 && t1 < t2
		&& dot_product(sub(mult(ray, t1), tmp->cy.ra1), tmp->cy.s) >= 0
		&& dot_product(sub(mult(ray, t1), tmp->cy.ra2), tmp->cy.s) <= 0)
	{
		tmp->t = t1;
		tmp->cy.in_out = 0;
	}
	else if (t2 > 0 && t1 < t2
		&& dot_product(sub(mult(ray, t2), tmp->cy.ra1), tmp->cy.s) >= 0
		&& dot_product(sub(mult(ray, t2), tmp->cy.ra2), tmp->cy.s) <= 0)
	{
		tmp->t = t2;
		tmp->cy.in_out = 1;
	}
	else
		return (1);
	return (0);
}

int	test(t_obj *tmp, t_vector point)
{
	double	d;

	d = dot_product(sub(tmp->coord, point), tmp->dir);
	if (fabs(d) > tmp->height / 2.0)
		return (0);
	return (1);
}

int	shadow_cylinders(t_obj *tmp, t_vector ray, t_vector origin, double delta)
{
	double		t1;
	double		t2;
	t_vector	point;

	ray = normalized(ray);
	tmp->cy.ra0 = cross_product(cross_product(tmp->cy.s, sub(origin,
					tmp->cy.ra1)), tmp->cy.s);
	tmp->c = dot_product(tmp->cy.ra0, tmp->cy.ra0) - pow(tmp->cy.radius, 2);
	tmp->cy.va = cross_product(cross_product(tmp->cy.s, ray), tmp->cy.s);
	tmp->a = dot_product(tmp->cy.va, tmp->cy.va);
	tmp->b = 2 * dot_product(tmp->cy.ra0, tmp->cy.va);
	delta = pow(tmp->b, 2) - 4 * tmp->a * tmp->c;
	t1 = (-tmp->b - sqrt(delta)) / (2 * tmp->a);
	t2 = (-tmp->b + sqrt(delta)) / (2 * tmp->a);
	if (t1 > 0)
		tmp->t = t1;
	else
		tmp->t = t2;
	if (tmp->t < 0)
		return (1);
	ray = normalized(ray);
	point = add(origin, mult(ray, tmp->t));
	if (test(tmp, point))
		return (0);
	if (delta != 0)
	{
		tmp->t = t2;
		point = add(origin, mult(ray, tmp->t));
		if (test(tmp, point))
			return (0);
	}
	return (2);
}
