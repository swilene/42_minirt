/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:37:19 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/30 16:02:05 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

t_vector	get_ray_origin(t_vector point, t_obj *obj)
{
	t_vector	origin;
	t_vector	p_prime;
	double		d;

	if (!ft_strncmp(obj->identifier, "sp", 2))
		obj->normale = normalized(sub(point, obj->coord));
	else if (!ft_strncmp(obj->identifier, "pl", 2))
		obj->normale = obj->dir;
	else if (!ft_strncmp(obj->identifier, "cy", 2))
	{
		d = sqrt(pow(distance(obj->cy.ra2, point), 2) - pow(obj->cy.radius, 2));
		p_prime = add(obj->cy.ra2, mult(obj->dir, d));
		obj->normale = normalized(sub(point, p_prime));
		if (obj->cy.in_out)
			obj->normale = mult(obj->normale, -1.0);
	}
	origin = add(point, mult(obj->normale, 0.01));
	return (origin);
}

void	intensity(t_data *data, t_obj *obj, t_vector ray)
{
	t_vector	light;
	t_vector	point;
	t_vector	origin;

	point = mult(ray, obj->t);
	origin = get_ray_origin(point, obj);
	light = sub(data->l.coord, point);
	obj->ambient.r = obj->color.r * data->a.color.r * (data->a.ratio / 255);
	obj->ambient.g = obj->color.g * data->a.color.g * (data->a.ratio / 255);
	obj->ambient.b = obj->color.b * data->a.color.b * (data->a.ratio / 255);
	if (!has_shadow(light, data->obj, origin, data))
		shadows(light, obj, data);
	img_pix_put(&data->img, &data->x, &data->y, convert_rgb(obj->ambient.r,
			obj->ambient.g, obj->ambient.b));
}
