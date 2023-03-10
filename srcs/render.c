/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:25:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/10 15:42:48 by saguesse         ###   ########.fr       */
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

int	convert_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	img_pix_put(t_img *img, int *x, int *y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (*y * img->line_len + *x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

t_obj	*render_bis(t_vector ray, t_obj *tmp)
{
	int		inter;
	t_obj	*min;
	double	t;

	min = NULL;
	t = FLT_MAX;
	while (tmp)
	{
		if (!strncmp("pl", tmp->identifier, 2))
			inter = render_planes(tmp, ray);
		else if (!strncmp("sp", tmp->identifier, 2))
			inter = render_spheres(tmp, ray);
		/*else
			inter = render_cylinder(data, tmp, ray);*/
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
	int			x;
	int			y;
	t_vector	ray;
	t_obj		*min;

	y = 0;
	data->c.near = WIN_WIDTH / tan((data->c.fov * 0.5) * (M_PI / 180)) * 0.5;
	while (y < WIN_HEIGHT - 1)
	{
		x = 0;
		while (x < WIN_WIDTH - 1)
		{
			ray = vector_ray(data->c.near, x, y);
			min = render_bis(ray, data->obj);
			if (min)
			{
				intensity(data, min, ray);
				img_pix_put(&data->img, &x, &y, convert_rgb(min->intensity.r,
						min->intensity.g, min->intensity.b));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}
