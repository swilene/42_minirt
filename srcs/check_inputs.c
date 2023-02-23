/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:11:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/23 17:56:37 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_inputs(t_data *data)
{
	t_list	*tmp;
	char	**s;

	tmp = data->lst;
	while (tmp)
	{
		s = ft_split(line, " ");
		if (!s)
			return (1);
		if (s[0])
	}
	return (0);
}
