/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:18:49 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/27 17:35:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_data(t_data *data)
{
	data->a.identifier = NULL;
	data->c.identifier = NULL;
	data->l.identifier = NULL;
	data->sp = NULL;
	data->pl = NULL;
	data->cy = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (argc != 2)
		return (printf("Error\nexpected: ./miniRT file.rt\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (perror("data"), 2);
	init_data(data);
	if (check_file(argv[1], data))
		return (clear(data), 3);
	if (check_inputs(data))
		return (clear(data), 4);
	clear(data);
	return (0);
}
