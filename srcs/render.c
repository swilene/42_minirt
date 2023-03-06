/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:25:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/06 18:21:15 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	vector_ray(double near, int x, int y)
{
	t_vector	ray;

	ray.x = x - WIN_WIDTH * 0.5;
	ray.y = y - WIN_HEIGHT * 0.5;
	ray.z = near;
	return (normalized(ray));
}

int	render(t_data *data)
{
	int			x;
	int			y;
	double		near;
	double		a;
	double		b;
	double		c;
	double		r_2;
	t_vector	r;
	t_vector	s0;
	t_vector	ray;

	y = 0;
	near = - WIN_HEIGHT / tan((data->c.fov * 0.5) * (M_PI / 180)) * 0.5;
	//printf("near = %f\n", near);
	while (y < WIN_HEIGHT - 1)
	{
		x = 0;
		while (x < WIN_WIDTH - 1)
		{
			ray = vector_ray(near, x, y);
			a = dot_product(ray, ray);
			s0.x = 0 - data->sp->coord.x;
			s0.y = 0 - data->sp->coord.y;
			s0.z = 0 - data->sp->coord.z;
			b = 2 * dot_product(ray, s0);
			r.x = data->sp->coord.x - data->sp->diameter / 2;
			r.y = data->sp->coord.y;
			r.z = data->sp->coord.z;
			r_2 = dot_product(r, r) - 2 * dot_product(r, data->sp->coord) + dot_product(data->sp->coord, data->sp->coord);
			c = dot_product(s0, s0) - r_2;
			//printf("a: %f\nb2: %f\nc: %f\n", a, pow(b, 2), c);
			//printf("delta: %f\n", pow(b, 2) - 4 * a * c);
			if (pow(b, 2) - 4 * a * c >= 0)
				mlx_pixel_put(data->img.mlx_ptr, data->img.win_ptr, x, y, RED_PIXEL);
			x++;
		}
		y++;
	}
	return (0);
}
