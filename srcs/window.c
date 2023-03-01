/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:57:46 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/01 12:59:42 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_win(data);
	return (0);
}

int	window(t_data data)
{
	data.img.mlx_ptr = mlx_init();
	if (!data.img.mlx_ptr)
		return (1);
	data.img.win_ptr = mlx_new_window(data.img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"miniRT");
	if (!data.img.win_ptr)
		return (free(data.img.win_ptr), 1);
	data.img.mlx_img = mlx_new_image(data.img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_hook(data.img.win_ptr, KeyPress, KeyPressMask, &key_pressed, &data);
	mlx_hook(data.img.win_ptr, DestroyNotify, Button1MotionMask, &close_win, &data);
	mlx_loop_hook(data.img.mlx_ptr, &render, &data);
	mlx_loop(data.img.mlx_ptr);
	return (0);	
}
