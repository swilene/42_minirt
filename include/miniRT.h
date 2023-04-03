/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:11:21 by saguesse          #+#    #+#             */
/*   Updated: 2023/04/03 13:48:01 by saguesse         ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define WIN_WIDTH 1440  //x
# define WIN_HEIGHT 900 //y
# define RED_PIXEL 0xFF0000

//			*** check_file.c ***
int			check_file(char *file, t_data *data);

//			*** check_inputs.c ***
int			check_number_of_informations(char **s, int n);
int			check_inputs(t_data *data);

//			*** check_numbers.c ***
int			check_int(char *s);
int			check_double(char *s);
int			check_colors(char *s, t_color *color, int i);
int			check_coordinates(char *s, t_vector *coord);
int			check_direction(char *s, t_vector *dir, int i);

//			*** init_structures.c ***
int			init_ambient(t_data *data, char **s);
int			init_camera(t_data *data, char **s);
int			init_light(t_data *data, char **s);

//			*** init_lists.c ***
int			init_lst(char *line, t_data *data, char *file);
int			init_objs(t_data *data, char **s);

//			*** init_window.c ***
int			window(t_data data);

//			*** render.c ***
int			render(t_data *data);
t_obj		*has_inter(t_vector ray, t_obj *tmp, t_vector origin);

//			*** translation.c ***
void		translation(t_data *data);

//			*** rotation.c ***
void    rotation(t_data *data);

//			*** ambient_light.c ***
void		ambient_light(t_data *data);

//			*** vector_operations.c ***
t_vector	mult(t_vector v, double i);
t_vector	sub(t_vector v1, t_vector v2);
t_vector	add(t_vector v1, t_vector v2);
t_vector	add_double(t_vector v1, double i);
t_vector	divide(t_vector v1, double i);

//			*** vector_calculs.c ***
double		norm(t_vector v);
double		distance(t_vector v1, t_vector v2);
t_vector	normalized(t_vector vector);
t_vector	cross_product(t_vector v1, t_vector v2);
double		dot_product(t_vector v1, t_vector v2);

//			*** spheres.c ***
int			render_spheres(t_obj *tmp, t_vector ray, t_vector o);
void		calculs_spheres(t_data *data);

//			*** planes.c ***
int			render_planes(t_obj *tmp, t_vector ray, t_vector o);

//			*** cylinders.c ***
void		calculs_cylinders(t_data *data);
int			render_cylinders(t_obj *tmp, t_vector ray, t_vector o,
				double delta);
int			shadow_cylinders(t_obj *tmp, t_vector ray, t_vector o,
				double delta);

//			*** colors.c ***
void		colors(t_data *data, t_obj *obj, t_vector ray);
void		img_pix_put(t_img *img, int *x, int *y, int color);
int			convert_rgb(int r, int g, int b);

//			*** shadows.c ***
void		shadows(t_vector light, t_obj *obj, t_data *data);
int			has_shadow(t_vector ray, t_obj *tmp, t_vector origin, t_data *data);

//			*** clear.c ***
void		free_str(char **s);
void		clear(t_data *data);
int			close_win(t_data *data);

#endif
