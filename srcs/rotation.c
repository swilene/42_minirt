/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:11:24 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/31 16:35:09 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mniRT.h"

double	calcul_angle(t_data *data)
{
	
}

void	rotation(t_data *data)
{
	t_obj	*tmp;

	tmp = data->obj;
	while (tmp)
	{
		rotation_x(tmp, tmp->dir * 90);
		rotation_y(tmp, tmp->dir * 90);
		tmp->dir.z -= rot.z
		tmp = tmp->next;
	}
}

void	rotation_x(t_data *data, double angle)
{
		t_rot	test;

		rot.
}

void	rotation_y(t_data *data, double angle)
{

}

void	rotation_x(t_data *data, double angle)
{

}
