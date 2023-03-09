/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:08:40 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 14:19:32 by saguesse         ###   ########.fr       */
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
	ft_delobj(data->obj);
}

int	close_win(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->img.mlx_ptr, data->img.mlx_img);
	if (data->img.win_ptr)
		mlx_destroy_window(data->img.mlx_ptr, data->img.win_ptr);
	if (data->img.mlx_ptr)
		mlx_destroy_display(data->img.mlx_ptr);
	free(data->img.mlx_ptr);
	clear(data);
	exit(EXIT_SUCCESS);
}
