/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:32:03 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/15 17:00:41 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_light(t_data *data)
{
	t_obj	*tmp;
	t_color	color;

	color.r = data->a.color.r * data->a.ratio;
	color.g = data->a.color.g * data->a.ratio;
	color.b = data->a.color.b * data->a.ratio;
	tmp = data->obj;
	while (tmp)
	{
		tmp->color.r = fmin(tmp->color.r + color.r, 255);
		tmp->color.g = fmin(tmp->color.g + color.g, 255);
		tmp->color.b = fmin(tmp->color.b + color.b, 255);
		printf("rouge =%d\n", tmp->color.r);
		printf("vert =%d\n", tmp->color.g);
		printf("bleu =%d\n\n", tmp->color.b);
		tmp = tmp->next;
	}
}
