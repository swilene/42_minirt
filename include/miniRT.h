/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:11:21 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/01 18:14:51 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "structures.h"
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 1920  //x
# define WIN_HEIGHT 1080 //y
# define RED_PIXEL 0xFF0000

//			*** check_file.c ***
int		check_file(char *file, t_data *data);

//			*** check_inputs.c ***
int		check_number_of_informations(char **s, int n);
int		check_inputs(t_data *data);

//			*** check_numbers.c ***
int		check_int(char *s);
int		check_double(char *s);
int		check_colors(char *s, int *r, int *g, int *b);
int		check_coordinates(char *s, double *x, double *y, double *z);
int		check_vectors(char *s, double *v_x, double *v_y, double *v_z);

//			*** init_structures.c ***
int		init_ambient(t_data *data, char **s);
int		init_camera(t_data *data, char **s);
int		init_light(t_data *data, char **s);

//			*** init_lists.c ***
int		init_lst(char *line, t_data *data, char *file);
int		init_sphere(t_data *data, char **s);
int		init_plane(t_data *data, char **s);
int		init_cylinder(t_data *data, char **s);

//			*** init_window.c ***
int		window(t_data data);

//			*** render.c ***
int		render(t_data *data);

//			*** new_coordinates.c ***
void	recalculate(t_data *data);
void	new_camera(t_camera *c);

//			*** clear.c ***
void	free_str(char **s);
void	clear(t_data *data);
int		close_win(t_data *data);

#endif
