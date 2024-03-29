/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:25:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/04 17:58:19 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_ray(t_camera c, double near, int x, int y)
{
	t_vector	origin;
	t_vector	ray;

	origin.x = x - WIN_WIDTH * 0.5;
	origin.y = -(y - WIN_HEIGHT * 0.5);
	origin.z = near;
	ray.x = origin.x * c.right.x + origin.y * c.up.x + origin.z * c.dir.x;
	ray.y = origin.x * c.right.y + origin.y * c.up.y + origin.z * c.dir.y;
	ray.z = origin.x * c.right.z + origin.y * c.up.z + origin.z * c.dir.z;
	return (normalized(ray));
}

t_obj	*has_inter(t_vector ray, t_obj *tmp, t_vector origin)
{
	int		inter;
	t_obj	*min;
	double	t;

	min = NULL;
	t = FLT_MAX;
	while (tmp)
	{
		if (!strncmp("pl", tmp->identifier, 2))
			inter = render_planes(tmp, ray, origin);
		else if (!strncmp("sp", tmp->identifier, 2))
			inter = render_spheres(tmp, ray, origin);
		else
			inter = render_cylinders(tmp, ray, origin, 0.0);
		if (inter == 0 && tmp->t <= t)
		{
			min = tmp;
			t = min->t;
		}
		tmp = tmp->next;
	}
	return (min);
}

int	render(t_data *data)
{
	t_vector	ray;
	t_obj		*min;

	calculs_spheres(data);
	calculs_cylinders(data);
	data->y = 0;
	data->c.near = WIN_WIDTH / tan((data->c.fov * 0.5) * (M_PI / 180)) * 0.5;
	while (data->y < WIN_HEIGHT - 1)
	{
		data->x = 0;
		while (data->x < WIN_WIDTH - 1)
		{
			ray = vector_ray(data->c, data->c.near, data->x, data->y);
			min = has_inter(ray, data->obj, data->c.coord);
			if (min)
				colors(data, min, ray);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}
