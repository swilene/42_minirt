/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:48:33 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/01 16:46:19 by saguesse         ###   ########.fr       */
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
	t_sphere	*new;

	if (check_number_of_informations(s, 4))
		return (printf("Error\nWrong number of informations in sp\n"), 1);
	new = malloc(sizeof(t_sphere));
	if (!new)
		return (2);
	new->next = NULL;
	if (check_coordinates(s[1], &new->x, &new->y, &new->z))
		return (printf(" sp\n"), 2);
	if (check_double(s[2]))
		return (3);
	new->diameter = ft_atof(s[2]);
	if (new->diameter < 0.0)
		return (printf("Error\nsp: diameter must be superior to 0\n"), 5);
	if (check_colors(s[3], &new->r, &new->g, &new->b))
		return (printf(" sp\n"), 5);
	ft_sphereadd_back(&data->sp, new);
	return (0);
}

int	init_plane(t_data *data, char **s)
{
	t_plane	*new;

	if (check_number_of_informations(s, 4))
		return (printf("Error\nwrong number of informations in pl\n"), 1);
	new = malloc(sizeof(t_plane));
	if (!new)
		return (2);
	new->next = NULL;
	if (check_coordinates(s[1], &new->x, &new->y, &new->z))
		return (printf(" pl\n"), 2);
	if (check_vectors(s[2], &new->v_x, &new->v_y, &new->v_z))
		return (printf(" pl\n"), 3);
	if (check_colors(s[3], &new->r, &new->g, &new->b))
		return (printf(" pl\n"), 4);
	ft_planeadd_back(&data->pl, new);
	return (0);
}

int	init_cylinder(t_data *data, char **s)
{
	t_cylinder	*new;

	if (check_number_of_informations(s, 6))
		return (printf("Error\nwrong number of informations in cy\n"), 1);
	new = malloc(sizeof(t_cylinder));
	if (!new)
		return (2);
	new->next = NULL;
	if (check_coordinates(s[1], &new->x, &new->y, &new->z))
		return (printf(" cy\n"), 3);
	if (check_vectors(s[2], &new->v_x, &new->v_y, &new->v_z))
		return (printf(" cy\n"), 4);
	if (check_double(s[3]) || check_double(s[4]))
		return (5);
	new->diameter = ft_atof(s[3]);
	if (new->diameter < 0.0)
		return (printf("Error\ncy: diameter must be positive\n"), 6);
	new->height = ft_atof(s[4]);
	if (new->height < 0.0)
		return (printf("Error\ncy: height must be positive\n"), 7);
	if (check_colors(s[5], &new->r, &new->g, &new->b))
		return (printf(" cy\n"), 8);
	ft_cylinderadd_back(&data->cy, new);
	return (0);
}
