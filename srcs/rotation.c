/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:33:19 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/04 17:40:47 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rotation(t_data *data)
{
	t_vector	dest;

	dest.x = 0.0;
	dest.y = 1.0;
	dest.z = 0.0;
	if (data->c.dir.x == 0 && data->c.dir.z == 0)
		data->c.dir.z = 0.00001;
	data->c.right = normalized(cross_product(dest, data->c.dir));
	data->c.up = normalized(cross_product(data->c.dir, data->c.right));
}
