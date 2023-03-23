/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:52:31 by tchantro          #+#    #+#             */
/*   Updated: 2023/03/23 16:11:55 by saguesse         ###   ########.fr       */
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
	if (delta < 0)
		return (1);
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
