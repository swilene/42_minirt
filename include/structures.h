/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:59:31 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/14 16:34:50 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_math
{
	double	near;
	double	far;
}	t_math;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct s_obj
{
	char			*identifier;
	t_vector		coord;
	t_vector		dir;
	t_color			color;
	t_color			intensity;
	double			diameter;
	double			height;
	double			t;
	t_vector		s0;
	t_vector		r;
	t_vector		ra1;
	t_vector		ra2;
	t_vector		s;
	t_vector		ra0;
	double			radius;
	double			c;
	struct s_obj	*next;
}	t_obj;

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
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	char		*identifier;
	t_vector	coord;
	t_vector	dir;
	int			fov;
	double		near;
}	t_camera;

typedef struct s_light
{
	char		*identifier;
	t_vector	coord;
	double		light;
}	t_light;

typedef struct s_data
{
	int			file;
	t_list		*lst;
	t_img		img;
	t_ambient	a;
	t_camera	c;
	t_light		l;
	t_obj		*obj;
	t_math		math;
}	t_data;

#endif
