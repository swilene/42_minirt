/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:19:16 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/05 14:48:32 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_int(char *s)
{
	int	i;

	i = 0;
	if (ft_strlen(s) > 11)
	{
		printf("ici\n");
		return (printf("Error\n%s is not an int in", s), 1);
	}
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

int	check_double(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (s[0] == '-')
		i++;
	if (!s[i])
		return (printf("Error\n%s is not a double in", s), 1);
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
				return (printf("Error\n%s is not a double in", s), 2);
		}
		else
			i++;
	}
	return (0);
}

int	check_colors(char *s, t_color *color, int i)
{
	char	**colors;

	colors = ft_split(s, ',');
	if (!colors)
		return (1);
	if (check_number_of_informations(colors, 3))
	{
		free_str(colors);
		return (printf("Error\ncolors: wrong number of informations in"), 2);
	}
	while (colors[i])
	{
		if (check_int(colors[i]))
			return (free_str(colors), 3);
		i++;
	}
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	free_str(colors);
	if (color->r > 255 || color->r < 0 || color->g > 255 || color->g < 0
		|| color->b > 255 || color->b < 0)
		return (printf("Error\ncolors must be between 0 and 255 in"), 4);
	return (0);
}

int	check_coordinates(char *s, t_vector *coord)
{
	int		i;
	char	**str;

	str = ft_split(s, ',');
	if (!str)
		return (1);
	if (check_number_of_informations(str, 3))
	{
		free_str(str);
		return (printf("Error\nwrong number of informations for coord in"), 2);
	}
	i = 0;
	while (str[i])
	{
		if (check_double(str[i]))
			return (free_str(str), 3);
		i++;
	}
	if (!ft_atof(str[0], &coord->x) || !ft_atof(str[1], &coord->y)
		|| !ft_atof(str[2], &coord->z))
		return (free_str(str), 4);
	free_str(str);
	return (0);
}

int	check_direction(char *s, t_vector *dir, int i)
{
	char	**str;

	str = ft_split(s, ',');
	if (!str)
		return (1);
	if (check_number_of_informations(str, 3))
	{
		free_str(str);
		return (printf("Error\nwrong number of informations for vector in"), 2);
	}
	while (str[i])
	{
		if (check_double(str[i]))
			return (free_str(str), 3);
		i++;
	}
	if (!ft_atof(str[0], &dir->x) || !ft_atof(str[1], &dir->y)
		|| !ft_atof(str[2], &dir->z))
		return (free_str(str), 4);
	free_str(str);
	if (dir->x < -1.0 || dir->x > 1.0 || dir->y < -1.0 || dir->y > 1.0
		|| dir->z < -1.0 || dir->z > 1.0)
		return (printf("Error\nvectors must be between -1.0 and 1.0 in"), 4);
	return (0);
}
