/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:54:54 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/06 14:41:11 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	new_direction(t_camera c, t_vector *dir)
{
	dir->x += c.dir.x;
	dir->y += c.dir.y;
	dir->z += c.dir.z;
}

void	new_coordinates(t_camera c, t_vector *coord)
{
	coord->x = c.coord.x - coord->x;
	coord->y = c.coord.y - coord->y;
	coord->z = c.coord.z - coord->z;
}

void	recalculate(t_data *data)
{
	t_sphere	*sp_tmp;
	t_plane		*pl_tmp;
	t_cylinder	*cy_tmp;

	new_coordinates(data->c, &data->l.coord);
	sp_tmp = data->sp;
	while (sp_tmp)
	{
		//printf("DEBUG old x: %f\ny: %f\nz:%f\n", sp_tmp->x, sp_tmp->y, sp_tmp->z);
		new_coordinates(data->c, &sp_tmp->coord);
		//printf("DEBUG new x: %f\ny: %f\nz:%f\n", sp_tmp->x, sp_tmp->y, sp_tmp->z);
		sp_tmp = sp_tmp->next;
	}
	pl_tmp = data->pl;
	while (pl_tmp)
	{
		new_coordinates(data->c, &pl_tmp->coord);
		//new_direction(data->c, &pl_tmp->dir);
		pl_tmp = pl_tmp->next;
	}
	cy_tmp = data->cy;
	while (cy_tmp)
	{
		new_coordinates(data->c, &cy_tmp->coord);
		//new_direction(data->c, &cy_tmp->dir);
		cy_tmp = cy_tmp->next;
	}
}

void	new_camera(t_camera *c)
{
	c->coord.x = 0;
	c->coord.y = 0;
	c->coord.z = 0;
	//c->dir.x = 0;
	//c->dir.y = 0;
	//c->dir.z = 0;
}
