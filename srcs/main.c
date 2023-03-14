/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:18:49 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/14 16:46:50 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_data(t_data *data)
{
	data->a.identifier = NULL;
	data->c.identifier = NULL;
	data->l.identifier = NULL;
	data->obj = NULL;
	data->img.mlx_ptr = NULL;
	data->img.win_ptr = NULL;
	data->img.mlx_img = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		return (printf("Error\nexpected: ./miniRT file.rt\n"), 1);
	init_data(&data);
	if (check_file(argv[1], &data))
		return (clear(&data), 3);
	if (check_inputs(&data))
		return (clear(&data), 4);
	recalculate(&data);
	new_camera(&data.c);
	calculs_spheres(&data);
	calculs_cylinders(&data);
	if (window(data))
		return (clear(&data), 5);
	return (0);
}
