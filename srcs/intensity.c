/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:37:19 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/14 16:38:58 by saguesse         ###   ########.fr       */
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

void	intensity(t_data *data, t_obj *obj, t_vector ray, int *x, int *y)
{
	t_vector	point;
	t_vector	l;
	t_vector	n;

	point = mult(ray, obj->t);
	l = normalized(sub(data->l.coord, point));
	if (!ft_strncmp(obj->identifier, "sp", 2))
		n = normalized(sub(point, obj->coord));
	else if (!ft_strncmp(obj->identifier, "pl", 2))
		n = normalized(point);
	obj->intensity.r = obj->color.r * dot_product(n, l) * data->l.light;
	if (obj->intensity.r > 255)
		obj->intensity.r = 255;
	else if (obj->intensity.r < 0)
		obj->intensity.r = 0;
	obj->intensity.g = obj->color.g * dot_product(n, l) * data->l.light;
	if (obj->intensity.g > 255)
		obj->intensity.g = 255;
	else if (obj->intensity.g < 0)
		obj->intensity.g = 0;
	obj->intensity.b = obj->color.b * dot_product(n, l) * data->l.light;
	if (obj->intensity.b > 255)
		obj->intensity.b = 255;
	else if (obj->intensity.b < 0)
		obj->intensity.b = 0;
	if (!ft_strncmp(obj->identifier, "cy", 2))
		img_pix_put(&data->img, x, y, convert_rgb(obj->color.r,
						obj->color.g, obj->color.b));
	else
		img_pix_put(&data->img, x, y, convert_rgb(obj->intensity.r,
						obj->intensity.g, obj->intensity.b));
}
