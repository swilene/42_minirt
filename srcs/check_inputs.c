/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:11:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/24 16:40:38 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_number_of_informations(char **s, int n)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i != n)
		return (1);
	return (0);
}

int	check_inputs(t_data *data)
{
	t_list	*tmp;
	char	**s;
	int		err;

	tmp = data->lst;
	while (tmp)
	{
		s = ft_split(tmp->line, ' ');
		free(tmp->line);
		if (!s)
			return (1);
		if (!ft_strncmp(s[0], "A", ft_strlen(s[0])))
			err = init_ambient(data, s);
		else if (!ft_strncmp(s[0], "C", ft_strlen(s[0])))
			err = init_camera(data, s);
		else if (!ft_strncmp(s[0], "L", ft_strlen(s[0])))
			err = init_light(data, s);
		/*else if (!ft_strncmp(s[0], "sp"))
		else if (!ft_strncmp(s[0], "pl"))
		else if (!ft_strncmp(s[0], "cy"))*/
		else
			return (printf("Error\n%s doesn't exist\n", s[0]), 2);
		if (err)
			return (3);
		tmp = tmp->next;
	}
	return (0);
}
