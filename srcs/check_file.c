/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:44:15 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/23 18:09:32 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_file_name(char *file, t_data *data)
{
	if (!ft_strnstr(file, ".rt", ft_strlen(file)))
		return (printf("Error\nexpected: ./miniRT file.rt\n"), 1);
	data->file = open(file, O_RDONLY);
	if (data->file < 0)
	{
		printf("Error\n");
		return (perror(file), 2);
	}
	return (0);
}

int	check_file(char *file, t_data *data)
{
	t_list	*new;
	char	*line;

	data->lst = NULL;
	if (check_file_name(file, data))
		return (1);
	while (1)
	{
		line = get_next_line(data->file);
		if (!line)
			break ;
		new = ft_lstnew(line);
		if (!new)
		{
			perror("new");
			if (close(data->file) < 0)
				return (perror(file), 2);
			return (3);
		}
		printf("%s", new->line);
		ft_lstadd_back(&data->lst, new);
	}
	if (close(data->file) < 0)
		return (perror(file), 3);
	return (0);
}
