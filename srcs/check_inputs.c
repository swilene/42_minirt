/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:11:41 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/20 14:37:48 by saguesse         ###   ########.fr       */
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

int	check_element(char **s, t_data *data)
{
	int		err;

	if (!ft_strncmp(s[0], "A", ft_strlen(s[0])))
		err = init_ambient(data, s);
	else if (!ft_strncmp(s[0], "C", ft_strlen(s[0])))
		err = init_camera(data, s);
	else if (!ft_strncmp(s[0], "L", ft_strlen(s[0])))
		err = init_light(data, s);
	else
		err = init_objs(data, s);
	return (err);
}

int	check_inputs(t_data *data)
{
	t_list	*tmp;
	char	**s;

	tmp = data->lst;
	while (tmp)
	{
		s = ft_split(tmp->line, ' ');
		free(tmp->line);
		tmp->line = NULL;
		if (!s)
			return (1);
		if (check_element(s, data))
			return (free_str(s), 2);
		free_str(s);
		tmp = tmp->next;
	}
	if (!data->a.identifier || !data->c.identifier || !data->l.identifier)
	{
		printf("Error\nyou must have exactly ");
		return (printf("one camera, one light and one ambient light\n"), 3);
	}
	return (0);
}
