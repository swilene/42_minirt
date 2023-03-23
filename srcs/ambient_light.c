/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:03 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/23 15:05:47 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_light(t_data *data)
{
	t_obj	*tmp;
	t_color	color;

	color.r = data->a.color.r * data->a.ratio * 0.5;
	color.g = data->a.color.g * data->a.ratio * 0.5;
	color.b = data->a.color.b * data->a.ratio * 0.5;
	tmp = data->obj;
	while (tmp)
	{
		tmp->ambient.r = tmp->color.r * 0.5 + color.r;
		tmp->ambient.g = tmp->color.g * 0.5 + color.g;
		tmp->ambient.b = tmp->color.b * 0.5 + color.b;
		tmp = tmp->next;
	}
}
