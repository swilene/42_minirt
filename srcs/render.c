/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:25:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/07 15:30:41 by saguesse         ###   ########.fr       */
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

int convert_rgb(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
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

int	render(t_data *data)
{
	int			x;
	int			y;
	t_vector	ray;

	y = 0;
	data->c.near = - WIN_HEIGHT / tan((data->c.fov * 0.5) * (M_PI / 180)) * 0.5;
	while (y < WIN_HEIGHT - 1)
	{
		x = 0;
		while (x < WIN_WIDTH - 1)
		{
			ray = vector_ray(data->c.near, x, y);
			render_spheres(data, ray, &x, &y);
			//render_planes(data, ray);
			//render_cylinders(data, ray);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->img.mlx_ptr, data->img.win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
