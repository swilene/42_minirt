/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:33 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 18:00:14 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_lst(char *line, t_data *data, char *file)
{
	t_list	*new;

	new = ft_lstnew(line);
	if (!new)
	{
		if (close(data->file) < 0)
			return (perror(file), 1);
		return (2);
	}
	ft_lstadd_back(&data->lst, new);
	return (0);
}

int	init_sphere(t_data *data, char **s)
{
	t_obj	*new;

	if (check_number_of_informations(s, 4))
		return (printf("Error\nWrong number of informations in sp\n"), 1);
	new = ft_objnew("sp");
	if (!new)
		return (2);
	if (check_coordinates(s[1], &new->coord))
		return (printf(" sp\n"), 2);
	if (check_double(s[2]))
		return (3);
	new->diameter = ft_atof(s[2]);
	if (new->diameter <= 0.0)
		return (printf("Error\nsp: diameter must be superior to 0\n"), 5);
	if (check_colors(s[3], &new->color, 0))
		return (printf(" sp\n"), 5);
	ft_objadd_back(&data->obj, new);
	return (0);
}

int	init_plane(t_data *data, char **s)
{
	t_obj	*new;

	if (check_number_of_informations(s, 4))
		return (printf("Error\nwrong number of informations in pl\n"), 1);
	new = ft_objnew("pl");
	if (!new)
		return (2);
	if (check_coordinates(s[1], &new->coord))
		return (printf(" pl\n"), 2);
	if (check_direction(s[2], &new->dir, 0))
		return (printf(" pl\n"), 3);
	if (check_colors(s[3], &new->color, 0))
		return (printf(" pl\n"), 4);
	ft_objadd_back(&data->obj, new);
	return (0);
}

int	init_cylinder(t_data *data, char **s)
{
	t_obj	*new;

	if (check_number_of_informations(s, 6))
		return (printf("Error\nwrong number of informations in cy\n"), 1);
	new = ft_objnew("cy");
	if (!new)
		return (2);
	if (check_coordinates(s[1], &new->coord))
		return (printf(" cy\n"), 3);
	if (check_direction(s[2], &new->dir, 0))
		return (printf(" cy\n"), 4);
	if (check_double(s[3]) || check_double(s[4]))
		return (5);
	new->diameter = ft_atof(s[3]);
	if (new->diameter < 0.0)
		return (printf("Error\ncy: diameter must be positive\n"), 6);
	new->height = ft_atof(s[4]);
	if (new->height < 0.0)
		return (printf("Error\ncy: height must be positive\n"), 7);
	if (check_colors(s[5], &new->color, 0))
		return (printf(" cy\n"), 8);
	ft_objadd_back(&data->obj, new);
	return (0);
}
