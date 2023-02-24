/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:08:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/24 17:35:41 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_ambient(t_data *data, char **s)
{
	if (check_number_of_informations(s, 3))
		return (printf("Error\nWrong number of informations for A\n"), 1);
	if (data->a.identifier)
		return (printf("Error\nA already exists\n"), 1);
	data->a.identifier = s[0];
	if (check_floats(s[1]))
		return (printf("Error\n%s is not a float\n", s[1]), 2);
	if (ft_atof(s[1], &data->a.ratio))
		return (3);
	if (data->a.ratio < 0.0 || data->a.ratio > 1.0)
		return (printf("Error\nRatio must be between 0.0 and 1.0\n"), 4);
	if (check_colors(s[2], data->a.r, data->a.g, data->a.b))
		return (5);
	return (0);
}

int	init_camera(t_data *data, char **s)
{
	if (check_number_of_informations(s, 4))
		return (printf("Error\nWrong number of informations for C\n"), 1);
	if (data->c.identifier)
		return (printf("Error\nC already exists\n"), 2);
	data->c.identifier = s[0];
	if (check_coordinates(s[1], data->c.x, data->c.y, data->c.z))
		return (3);
	if (check_vectors(s[2], data->c.v_x, data->c.v_y, data->c.v_z))
		return (4);
	if (check_ints(s[3]))
		return (5);
	data->c.fov = ft_atoi(s[3]);
	if (data->c.fov < 0 || data->c.fov > 180)
		return (printf("Error\nFOV must be between 0 and 180\n"), 6);
	return (0);
}

int	init_light(t_data *data, char **s)
{
	if (check_number_of_informations(s, 3))
		return (printf("Error\nWrong number of informations for L\n"), 1);
	if (data->l.identifier)
		return (printf("Error\nL already exists\n"), 2);
	data->l.identifier = s[0];
	if (check_coordinates(s[1], data->l.x, data->l.y, data->l.z))
		return (3);
	if (check_floats(s[2]))
		return (4);
	if (ft_atof(s[2], &data->l.light))
		return (5);
	if (data->l.light < 0.0 || data->c.fov > 1.0)
		return (printf("Error\nlight must be between 0.0 and 1.0\n"), 6);
	return (0);
}
