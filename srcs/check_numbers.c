/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:19:16 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/27 17:57:53 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_ints(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) > 11)
		return (printf("Error\n%s is not an int in", s), 1);
	if (s[i] == '-')
		i++;
	if (!s[i])
		return (printf("Error\n%s is not an int in", s), 2);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (printf("Error\n%s is not an int in", s), 3);
		i++;
	}
	return (0);
}

int	check_floats(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (s[0] == '-')
		i++;
	if (!s[i])
		return (printf("Error\n%s is not a float in", s), 1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			if (s[i] == '.' && !dot)
			{
				dot++;
				i++;
			}
			else
				return (printf("Error\n%s is not a float in", s), 2);
		}
		else
			i++;
	}
	return (0);
}

int	check_colors(char *s, int *r, int *g, int *b)
{
	char	**colors;
	int		i;

	colors = ft_split(s, ',');
	if (!colors)
		return (1);
	if (check_number_of_informations(colors, 3))
	{
		free_str(colors);
		return (printf("Error\ncolors: wrong number of informations in"), 2);
	}
	i = 0;
	while (colors[i])
	{
		if (check_ints(colors[i]))
			return (free_str(colors), 1);
		i++;
	}
	*r = ft_atoi(colors[0]);
	*g = ft_atoi(colors[1]);
	*b = ft_atoi(colors[2]);
	free_str(colors);
	if (*r > 255 || *r < 0 || *g > 255 || *g < 0 || *b > 255 || *b < 0)
		return (printf("Error\ncolors must be between 0 and 255 in"), 4);
	return (0);
}

int	check_coordinates(char *s, float *x, float *y, float *z)
{
	int		i;
	char	**coord;

	coord = ft_split(s, ',');
	if (!coord)
		return (1);
	if (check_number_of_informations(coord, 3))
	{
		free_str(coord);
		return (printf("Error\nwrong number of informations for coord in"), 2);
	}
	i = 0;
	while (coord[i])
	{
		if (check_floats(coord[i]))
			return (free_str(coord), 1);
		i++;
	}
	if (ft_atof(coord[0], x, 0, 1) || ft_atof(coord[1], y, 0, 1)
		|| ft_atof(coord[2], z, 0, 1))
		return (free_str(coord), 2);
	free_str(coord);
	//if ((x > 255 && x < 0) || (y > 255 && y < 0) || (z > 255 && z < 0))
	//	return (printf("Error\ncolors must be between 0 and 255\n"), 4);
	return (0);
}

int	check_vectors(char *s, float *v_x, float *v_y, float *v_z)
{
	int		i;
	char	**vector;

	vector = ft_split(s, ',');
	if (!vector)
		return (1);
	if (check_number_of_informations(vector, 3))
	{
		free_str(vector);
		return (printf("Error\nwrong number of informations for vector in"), 2);
	}
	i = 0;
	while (vector[i])
	{
		if (check_floats(vector[i]))
			return (free_str(vector), 2);
		i++;
	}
	if (ft_atof(vector[0], v_x, 0, 1) || ft_atof(vector[1], v_y, 0, 1)
		|| ft_atof(vector[2], v_z, 0, 1))
		return (free_str(vector), 4);
	free_str(vector);
	if (*v_x < -1.0 || *v_x > 1.0 || *v_y < -1.0 || *v_y > 1.0 || *v_z < -1.0
		|| *v_z > 1.0)
		return (printf("Error\nvectors must be between -1.0 and 1.0 in"), 4);
	return (0);
}
