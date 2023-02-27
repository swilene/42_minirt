/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:08:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/27 17:41:04 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_ambient(t_data *data, char **s)
{
	if (data->a.identifier)
		return (printf("Error\nyou can't have more than one A\n"), 1);
	data->a.identifier = s[0];
	if (check_number_of_informations(s, 3))
		return (printf("Error\nwrong number of informations in A\n"), 2);
	if (check_floats(s[1]))
		return (printf("Error\nA: %s is not a float\n", s[1]), 3);
	if (ft_atof(s[1], &data->a.ratio, 0, 1))
		return (printf(" A\n"), 4);
	if (data->a.ratio < 0.0 || data->a.ratio > 1.0)
		return (printf("Error\nA: ratio must be between 0.0 and 1.0\n"), 5);
	if (check_colors(s[2], &data->a.r, &data->a.g, &data->a.b))
		return (printf(" A\n"), 6);
	return (0);
}

int	init_camera(t_data *data, char **s)
{
	if (data->c.identifier)
		return (printf("Error\nyou can't have more than one C\n"), 1);
	data->c.identifier = s[0];
	if (check_number_of_informations(s, 4))
		return (printf("Error\nwrong number of informations in C\n"), 2);
	if (check_coordinates(s[1], &data->c.x, &data->c.y, &data->c.z))
		return (printf(" C\n"), 3);
	if (check_vectors(s[2], &data->c.v_x, &data->c.v_y, &data->c.v_z))
		return (printf(" C\n"), 4);
	if (check_ints(s[3]))
		return (printf(" C\n"), 5);
	data->c.fov = ft_atoi(s[3]);
	if (data->c.fov < 0 || data->c.fov > 180)
		return (printf("Error\nC: FOV must be between 0 and 180\n"), 6);
	return (0);
}

int	init_light(t_data *data, char **s)
{
	if (data->l.identifier)
		return (printf("Error\nyou can't have more than one L\n"), 1);
	data->l.identifier = s[0];
	if (check_number_of_informations(s, 3))
		return (printf("Error\nwrong number of informations in L\n"), 2);
	if (check_coordinates(s[1], &data->l.x, &data->l.y, &data->l.z))
		return (printf(" L\n"), 3);
	if (check_floats(s[2]))
		return (4);
	if (ft_atof(s[2], &data->l.light, 0, 1))
		return (printf(" L\n"), 5);
	if (data->l.light < 0.0 || data->l.light > 1.0)
		return (printf("Error\nL: light must be between 0.0 and 1.0\n"), 6);
	return (0);
}
