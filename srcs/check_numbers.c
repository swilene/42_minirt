/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:19:16 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/24 18:18:34 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_ints(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (printf("Error\n%s is not an int", s), 1);
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
		return (1);	
	while (s[i])
	{
		if (s[i] == '.')
		{
			dot++;
			i++;
		}
		if (!ft_isdigit(s[i]) && dot > 1)
			return (2);
		i++;
	}
	return (0);
}

int	check_colors(char *s, int r, int g, int b)
{
	char	**colors;
	int		i;

	// trim \n
	colors = ft_split(s, ',');
	if (!colors)
		return (1);
	if (check_number_of_informations(colors, 3))
		return (printf("Error\nWrong number of informations for colors\n"), 2);
	i = 0;
	while (colors[i])
	{
		if (check_ints(colors[i]))
			return (1);
		i++;
	}
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_str(colors);
	if ((r > 255 && r < 0) || (g > 255 && g < 0) || (b > 255 && b < 0))
		return (printf("Error\ncolors must be between 0 and 255\n"), 4);
	return (0);
}

int	check_coordinates(char *s, float x, float y, float z)
{
	int		i;
	char	**coord;

	coord = ft_split(s, ',');
	if (!coord)
		return (1);
	if (check_number_of_informations(coord, 3))
		return (printf("Error\nWrong number of informations for coord\n"), 2);
	i = 0;
	while (coord[i])
	{
		if (check_floats(coord[i]))
			return (printf("Error\n%s is not a float\n", coord[i]), 1);
		i++;
	}
	if (ft_atof(coord[0], &x) || ft_atof(coord[1], &y) || ft_atof(coord[2], &z))
		return (2);
	free_str(coord);
	//if ((x > 255 && x < 0) || (y > 255 && y < 0) || (z > 255 && z < 0))
	//	return (printf("Error\ncolors must be between 0 and 255\n"), 4);
	return (0);
}

int	check_vectors(char *s, float v_x, float v_y, float v_z)
{
	int		i;
	char	**vector;

	vector = ft_split(s, ',');
	if (!vector)
		return (1);
	if (check_number_of_informations(vector, 3))
		return (printf("Error\nWrong number of informations for vector\n"), 2);
	i = 0;
	while (vector[i])
	{
		if (check_floats(vector[i]))
			return (printf("Error\n%s is not a float\n", vector[i]), 2);
		i++;
	}
	if (ft_atof(vector[0], &v_x) || ft_atof(vector[1], &v_y)
		|| ft_atof(vector[2], &v_z))
		return (4);
	free_str(vector);
	if (v_x < -1.0 || v_x > 1.0 || v_y < -1.0 || v_y > 1.0 || v_z < -1.0
		|| v_z > 1.0)
		return (printf("Error\nvectors must be between -1.0 and 1.0\n"), 4);
	return (0);
}
