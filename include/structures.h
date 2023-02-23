/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:31 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/23 18:05:01 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "../libft/libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_ambient
{
	char	*identifier;
	double	ratio;
	int		r;
	int		g;
	int		b;
}	t_ambient;

typedef struct s_camera
{
	char	*identifier;
	double	x;
	double	y;
	double	z;
	double	v_x;
	double	v_y;
	double	v_z;
	int		fov;
}	t_camera;

typedef struct s_light
{
	char	*identifier;
	double	x;
	double	y;
	double	z;
	double	light;
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
