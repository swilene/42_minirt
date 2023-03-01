/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:06:02 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/01 15:34:55 by saguesse         ###   ########.fr       */
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
	double			x;
	double			y;
	double			z;
	double			diameter;
	int				r;
	int				g;
	int				b;
	struct s_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	double			x;
	double			y;
	double			z;
	double			v_x;
	double			v_y;
	double			v_z;
	int				r;
	int				g;
	int				b;
	struct s_plane	*next;
}	t_plane;

typedef struct s_cylinder
{
	double				x;
	double				y;
	double				z;
	double				v_x;
	double				v_y;
	double				v_z;
	double				diameter;
	double				height;
	int					r;
	int					g;
	int					b;
	struct s_cylinder	*next;
}	t_cylinder;

#endif
