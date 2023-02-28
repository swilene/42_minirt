/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:31 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/28 16:19:54 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "../libft/libft.h"

typedef struct s_img
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ambient
{
	char	*identifier;
	float	ratio;
	int		r;
	int		g;
	int		b;
}	t_ambient;

typedef struct s_camera
{
	char	*identifier;
	float	x;
	float	y;
	float	z;
	float	v_x;
	float	v_y;
	float	v_z;
	int		fov;
}	t_camera;

typedef struct s_light
{
	char	*identifier;
	float	x;
	float	y;
	float	z;
	float	light;
}	t_light;

typedef struct s_data
{
	int			file;
	t_list		*lst;
	t_img		img;
	t_ambient	a;
	t_camera	c;
	t_light		l;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_data;

#endif
