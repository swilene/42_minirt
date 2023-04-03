/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:11:24 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/03 15:45:17 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	rotation_x(t_obj *tmp, double angle)
{
	t_vector	rotation;

	rotation.x = tmp->coord.x;
	rotation.y = tmp->coord.y * cos(angle) - tmp->coord.z * sin(angle);
	rotation.z = tmp->coord.y * sin(angle) + tmp->coord.z * cos(angle);
	return (rotation);
}

t_vector	rotation_y(t_obj *tmp, double angle)
{
	t_vector	rotation;
	
	rotation.x = tmp->coord.x * cos(angle) + tmp->coord.z * sin(angle);
	rotation.y = tmp->coord.y;
	rotation.z = - tmp->coord.x * sin(angle) + tmp->coord.z * cos(angle);
	return (rotation);
}

t_vector	rotation_z(t_obj *tmp, double angle)
{
	t_vector	rotation;

	rotation.x = tmp->coord.x * cos(angle) - tmp->coord.y * sin(angle);
	rotation.y = tmp->coord.x * sin(angle) + tmp->coord.y * cos(angle);
	rotation.z = tmp->coord.z;
	return (rotation);
}

void	rotation(t_data *data)
{
	t_obj	*tmp;

	tmp = data->obj;
	while (tmp)
	{
		tmp->coord = rotation_x(tmp, (data->c.dir.x * 90) * M_PI / 180);
		printf("roration x\ncam.x = %f\ncam.y = %f\ncam.z = %f\n\n", tmp->coord.x, tmp->coord.y, tmp->coord.z);
		tmp->coord = rotation_y(tmp, (data->c.dir.y * 90) * M_PI / 180);
		printf("rotation y\ncam.x = %f\ncam.y = %f\ncam.z = %f\n\n", tmp->coord.x, tmp->coord.y, tmp->coord.z);
		tmp->coord = rotation_z(tmp, (180 - data->c.dir.z * 180) * M_PI / 180);
		printf("rotation z\ncam.x = %f\ncam.y = %f\ncam.z = %f\n\n", tmp->coord.x, tmp->coord.y, tmp->coord.z);
		tmp = tmp->next;
	}
}
