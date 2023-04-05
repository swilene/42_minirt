/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:33 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/05 17:24:42 by tchantro         ###   ########.fr       */
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

int	init_sphere(char **s, t_obj *new)
{
	new->identifier = "sp";
	if (check_number_of_informations(s, 4))
		return (printf("Error\nWrong number of informations in sp\n"), 1);
	if (check_coordinates(s[1], &new->coord))
		return (printf(" sp\n"), 2);
	if (check_double(s[2]))
		return (3);
	new->diameter = ft_atof(s[2]);
	if (new->diameter <= 0.0)
		return (printf("Error\nsp: diameter must be superior to 0\n"), 4);
	if (check_colors(s[3], &new->color, 0))
		return (printf(" sp\n"), 5);
	return (0);
}

int	init_plane(char **s, t_obj *new)
{
	new->identifier = "pl";
	if (check_number_of_informations(s, 4))
		return (printf("Error\nwrong number of informations in pl\n"), 1);
	if (check_coordinates(s[1], &new->coord))
		return (printf(" pl\n"), 2);
	if (check_direction(s[2], &new->dir, 0))
		return (printf(" pl\n"), 3);
	if (new->dir.x == 0.0 && new->dir.y == 0.0 && new->dir.z == 0.0)
	{
		printf("Error\nIn pl, ");
		return (printf("at least one direction must be different from 0\n"), 4);
	}
	new->dir = normalized(new->dir);
	if (check_colors(s[3], &new->color, 0))
		return (printf(" pl\n"), 5);
	return (0);
}

int	init_cylinder(char **s, t_obj *new)
{
	new->identifier = "cy";
	if (check_number_of_informations(s, 6))
		return (printf("Error\nwrong number of informations in cy\n"), 1);
	if (check_coordinates(s[1], &new->coord))
		return (printf(" cy\n"), 2);
	if (check_direction(s[2], &new->dir, 0))
		return (printf(" cy\n"), 3);
	if (new->dir.x == 0.0 && new->dir.y == 0.0 && new->dir.z == 0.0)
	{
		printf("Error\nIn cy, ");
		return (printf("at least one direction must be different from 0\n"), 4);
	}
	new->dir = normalized(new->dir);
	if (check_double(s[3]) || check_double(s[4]))
		return (5);
	new->diameter = ft_atof(s[3]);
	if (new->diameter < 0.0 || new->diameter > INT_MAX)
		return (printf("Error\ncy: diameter must be between 0 and INT_MAX\n"), 6);
	new->height = ft_atof(s[4]);
	if (new->height < 0.0 || new->height > INT_MAX)
		return (printf("Error\ncy: height must be between 0 and INT_MAX\n"), 7);
	if (check_colors(s[5], &new->color, 0))
		return (printf(" cy\n"), 8);
	return (0);
}

int	init_objs(t_data *data, char **s)
{
	int		err;
	t_obj	*new;

	new = ft_objnew();
	if (!new)
		return (1);
	else if (!ft_strncmp(s[0], "sp", ft_strlen(s[0])))
		err = init_sphere(s, new);
	else if (!ft_strncmp(s[0], "pl", ft_strlen(s[0])))
		err = init_plane(s, new);
	else if (!ft_strncmp(s[0], "cy", ft_strlen(s[0])))
		err = init_cylinder(s, new);
	else
	{
		free(new);
		return (printf("Error\n%s doesn't exist\n", s[0]), 2);
	}
	if (err)
		return (free(new), 3);
	ft_objadd_back(&data->obj, new);
	return (0);
}
