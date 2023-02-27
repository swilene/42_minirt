/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:08:40 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/27 17:34:23 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_str(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	clear(t_data *data)
{
	ft_dellist(data->lst);
	ft_delsphere(data->sp);
	ft_delplane(data->pl);
	ft_delcylinder(data->cy);
	free(data);
}
