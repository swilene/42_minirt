/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:08:28 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/03 14:46:22 by saguesse         ###   ########.fr       */
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
	if (check_double(s[1]))
		return (printf(" A\n"), 3);
	data->a.ratio = ft_atof(s[1]);
	if (data->a.ratio < 0.0 || data->a.ratio > 1.0)
		return (printf("Error\nA: ratio must be between 0.0 and 1.0\n"), 4);
	if (check_colors(s[2], &data->a.color, 0))
		return (printf(" A\n"), 5);
	return (0);
}

int	init_camera(t_data *data, char **s)
{
	if (data->c.identifier)
		return (printf("Error\nyou can't have more than one C\n"), 1);
	data->c.identifier = s[0];
	if (check_number_of_informations(s, 4))
		return (printf("Error\nwrong number of informations in C\n"), 2);
	if (check_coordinates(s[1], &data->c.coord))
		return (printf(" C\n"), 3);
	if (check_direction(s[2], &data->c.dir, 0))
		return (printf(" C\n"), 4);
	if (data->c.dir.x == 0.0 && data->c.dir.y == 0.0 && data->c.dir.z == 0.0)
	{
		printf("Error\nIn C, ");
		return (printf("at least one direction must be different from 0\n"), 5);
	}
	data->c.dir = normalized(data->c.dir);
	if (check_int(s[3]))
		return (printf(" C\n"), 6);
	data->c.fov = ft_atoi(s[3]);
	if (data->c.fov < 0 || data->c.fov > 180)
		return (printf("Error\nC: FOV must be between 0 and 180\n"), 7);
	return (0);
}

int	init_light(t_data *data, char **s)
{
	if (data->l.identifier)
		return (printf("Error\nyou can't have more than one L\n"), 1);
	data->l.identifier = s[0];
	if (check_number_of_informations(s, 3))
		return (printf("Error\nwrong number of informations in L\n"), 2);
	if (check_coordinates(s[1], &data->l.coord))
		return (printf(" L\n"), 3);
	if (check_double(s[2]))
		return (4);
	data->l.light = ft_atof(s[2]);
	if (data->l.light < 0.0 || data->l.light > 1.0)
		return (printf("Error\nL: light must be between 0.0 and 1.0\n"), 5);
	return (0);
}
