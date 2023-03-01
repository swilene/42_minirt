/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:02:51 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/01 15:40:11 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dot_index(const char *s, int i)
{
	int	dot;

	dot = -1;
	while (s[i])
	{
		if (s[i] == '.')
		{
			dot = i;
			break ;
		}
		i++;
	}
	return (dot);
}

double	integer_part(const char *s, int i, int dot)
{
	float	nb;

	nb = 0;
	while (i < dot)
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	return (nb);
}

double	float_part(const char *s, int dot)
{
	int		i;
	double	nb;

	i = dot + 1;
	while (s[i])
		i++;
	if (i > 6)
		return (-1);
	i = dot + 1;
	nb = 0;
	while (s[i])
	{
		nb += (s[i] - '0') * pow(10, dot - i);
		i++;
	}
	return (nb);
}

double	ft_atof(const char *s)
{
	double	nb_integer;
	double	nb_float;
	int		dot;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	dot = -1;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	dot = dot_index(s, i);
	if (dot == -1)
		return ((double)ft_atoi(s));
	nb_integer = integer_part(s, i, dot);
	nb_float = float_part(s, dot);
	return ((nb_integer + nb_float) * neg);
}
