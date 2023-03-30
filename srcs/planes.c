/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:31:08 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/30 15:48:47 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	render_planes(t_obj *tmp, t_vector ray, t_vector origin)
{
	tmp->t = dot_product(tmp->dir, sub(tmp->coord, origin))
		/ dot_product(tmp->dir, ray);
	if (tmp->t < 0)
		return (1);
	return (0);
}
