/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:54:54 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/01 18:16:56 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	new_vectors(t_camera c, double *v_x, double *v_y, double *v_z)
{
	*v_x += c.x;
	*v_y += c.y;
	*v_z += c.z;
}

void	new_coordinates(t_camera c, double *x, double *y, double *z)
{
	*x = WIN_WIDTH / 2 - (c.x - *x);
	*y = WIN_HEIGHT / 2 - (c.y - *y);
	*z = c.z - *z;
}

void	recalculate(t_data *data)
{
	t_sphere	*sp_tmp;
	t_plane		*pl_tmp;
	t_cylinder	*cy_tmp;

	new_coordinates(data->c, &data->l.x, &data->l.y, &data->l.z);
	sp_tmp = data->sp;
	while (sp_tmp)
	{
		printf("DEBUG old x: %f\ny: %f\nz:%f\n", sp_tmp->x, sp_tmp->y, sp_tmp->z);
		new_coordinates(data->c, &sp_tmp->x, &sp_tmp->y, &sp_tmp->z);
		printf("DEBUG new x: %f\ny: %f\nz:%f\n", sp_tmp->x, sp_tmp->y, sp_tmp->z);
		sp_tmp = sp_tmp->next;
	}
	pl_tmp = data->pl;
	while (pl_tmp)
	{
		new_coordinates(data->c, &pl_tmp->x, &pl_tmp->y, &pl_tmp->z);
		new_vectors(data->c, &pl_tmp->v_x, &pl_tmp->v_y, &pl_tmp->v_z);
		pl_tmp = pl_tmp->next;
	}
	cy_tmp = data->cy;
	while (cy_tmp)
	{
		new_coordinates(data->c, &cy_tmp->x, &cy_tmp->y, &cy_tmp->z);
		new_vectors(data->c, &cy_tmp->v_x, &cy_tmp->v_y, &cy_tmp->v_z);
		cy_tmp = cy_tmp->next;
	}
}

void	new_camera(t_camera *c)
{
	c->x = WIN_WIDTH / 2;
	c->y = WIN_HEIGHT / 2;
	c->z = 0;
	c->v_x = 0;
	c->v_y = 0;
	c->v_z = 0;
}
