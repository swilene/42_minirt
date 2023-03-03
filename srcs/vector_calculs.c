/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:43:55 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/03 10:53:13 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	norm_vector(double x, double y, double z)
{
	return (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
}

double	normalize_vector(double i, double x, double y, double z)
{
	return (i / norm_vector(x, y, z));
}
