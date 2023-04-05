/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:44:15 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/05 17:06:03 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_file_name(char *file, t_data *data)
{
	char	buf[1];

	if (!ft_strnstr(file, ".rt", ft_strlen(file)))
		return (printf("Error\nexpected: ./miniRT file.rt\n"), 1);
	data->file = open(file, O_RDONLY);
	if (data->file < 0)
		return (perror(file), 2);
	if (read(data->file, buf, 1) < 0)
		return (printf("%s: Is a directory\n", file));
	if (close(data->file) < 0)
		return (perror(file), 4);
	data->file = open(file, O_RDONLY);
	if (data->file < 0)
		return (perror(file), 2);
	return (0);
}

int	check_file(char *file, t_data *data)
{
	char	*line;
	char	*s;

	data->lst = NULL;
	if (check_file_name(file, data))
		return (1);
	while (1)
	{
		line = get_next_line(data->file);
		if (!line)
			break ;
		s = ft_strtrim(line, " ");
		free(line);
		if (!s)
			return (perror("ft_strtrim"), 2);
		if (!ft_strncmp(s, "\n", ft_strlen(s)))
			free(s);
		else if (init_lst(s, data, file))
			return (3);
	}
	if (close(data->file) < 0)
		return (perror(file), 4);
	return (0);
}
