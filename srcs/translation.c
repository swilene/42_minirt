/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalculate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:54:54 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/30 15:50:01 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	new_coordinates(t_camera c, t_vector *coord)
{
	coord->x = c.coord.x + coord->x;
	coord->y = c.coord.y + coord->y;
	coord->z = c.coord.z + coord->z;
}

void	translation(t_data *data)
{
	t_obj	*tmp;

	new_coordinates(data->c, &data->l.coord);
	tmp = data->obj;
	while (tmp)
	{
		new_coordinates(data->c, &tmp->coord);
		tmp = tmp->next;
	}
	data->c.coord.x = 0;
	data->c.coord.y = 0;
	data->c.coord.z = 0;
}
