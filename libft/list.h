/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:06:02 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/27 12:10:12 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct s_sphere
{
	float			x;
	float			y;
	float			z;
	float			diameter;
	int				r;
	int				g;
	int				b;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	float			x;
	float			y;
	float			z;
	float			v_x;
	float			v_y;
	float			v_z;
	int				r;
	int				g;
	int				b;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	float				x;
	float				y;
	float				z;
	float				v_x;
	float				v_y;
	float				v_z;
	float				diameter;
	float				height;
	int					r;
	int					g;
	int					b;
	struct s_cylinder	*next;
}	t_cylinder;

#endif
