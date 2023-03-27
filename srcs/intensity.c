/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:37:19 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/27 17:06:12 by saguesse         ###   ########.fr       */
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
		if (obj->cy.in_out)
			obj->normale = normalized(sub(p_prime, point));
		else
			obj->normale = normalized(sub(point, p_prime));
	}
	origin = add(point, mult(obj->normale, 0.01));
	return (origin);
}

t_obj	*has_shadow(t_vector ray, t_obj *tmp, t_vector origin, t_data *data)
{
	int		inter;
	t_obj	*min;
	double	t;

	min = NULL;
	t = FLT_MAX;
	while (tmp)
	{
		if (!strncmp("pl", tmp->identifier, 2))
			inter = shadow_planes(tmp, ray, origin, data);
		else if (!strncmp("sp", tmp->identifier, 2))
			inter = shadow_spheres(tmp, ray, origin);
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

void	shadows(t_vector cam, t_obj *obj, t_data *data)
{
	t_vector	light;
	t_vector	point;
	t_vector	origin;
	t_obj 		*min;
	double		d;
	double		intensity;

	obj->diffuse.r = 0;
	obj->diffuse.g = 0;
	obj->diffuse.b = 0;
	point = mult(cam, obj->t);
	origin = get_ray_origin(point, obj);
	light = sub(data->l.coord, point);
	min = has_shadow(light, data->obj, origin, data);
	if (min && pow(min->t, 2) < pow(norm(sub(point, data->l.coord)), 2))
	{
		d = dot_product(normalized(light), obj->normale);
		if (d > 0)
		{
			intensity = d * data->l.light * fmin(1.0, 1 / pow(norm(light), 2));
			obj->diffuse.r = intensity * obj->color.r * obj->ambient.r;
			obj->diffuse.g = intensity * obj->color.g * obj->ambient.g;
			obj->diffuse.b = intensity * obj->color.b * obj->ambient.b;
		}
		obj->intensity.r = fmin(255, fmax(0, obj->ambient.r + obj->diffuse.r));
		obj->intensity.g = fmin(255, fmax(0, obj->ambient.g + obj->diffuse.g));
		obj->intensity.b = fmin(255, fmax(0, obj->ambient.b + obj->diffuse.b));
	}
	img_pix_put(&data->img, &data->x, &data->y, convert_rgb(obj->intensity.r,
			obj->intensity.g, obj->intensity.b));
}

void	intensity(t_data *data, t_obj *obj, t_vector ray)
{
	obj->ambient.r = obj->color.r * data->a.color.r * (data->a.ratio / 255);
	obj->ambient.g = obj->color.g * data->a.color.g * (data->a.ratio / 255);
	obj->ambient.b = obj->color.b * data->a.color.b * (data->a.ratio / 255);
	shadows(ray, obj, data);
}
