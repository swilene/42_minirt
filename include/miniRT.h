/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:11:21 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/24 17:46:24 by saguesse         ###   ########.fr       */
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

//			*** parsing ***
int		check_file(char *file, t_data *data);
int		check_inputs(t_data *data);
int		check_floats(char *s);
int		check_number_of_informations(char **s, int n);
int		check_ints(char *s);
int		check_floats(char *s);
int		check_colors(char *s, int r, int g, int b);
int		check_coordinates(char *s, float x, float y, float z);
int		check_vectors(char *s, float v_x, float v_y, float v_z);

//			*** init_structures.c ***
int		init_ambient(t_data *data, char **s);
int		init_camera(t_data *data, char **s);
int		init_light(t_data *data, char **s);

//			*** clear.c ***
void	free_str(char **s);
void	clear(t_data *data);

#endif
