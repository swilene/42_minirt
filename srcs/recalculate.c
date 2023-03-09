/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:54:54 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 17:06:57 by saguesse         ###   ########.fr       */
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
	coord->x = c.coord.x + coord->x;
	coord->y = c.coord.y + coord->y;
	coord->z = c.coord.z + coord->z;
}

void	recalculate(t_data *data)
{
	t_obj	*tmp;

	new_coordinates(data->c, &data->l.coord);
	tmp = data->obj;
	while (tmp)
	{
		new_coordinates(data->c, &tmp->coord);
		tmp = tmp->next;
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
