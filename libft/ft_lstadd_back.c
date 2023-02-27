/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:16:52 by saguesse          #+#    #+#             */
/*   Updated: 2023/02/27 12:08:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_sphereadd_back(t_sphere **lst, t_sphere *new)
{
	t_sphere	*last;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		last = ft_spherelast(*lst);
		last->next = new;
	}
}

void	ft_planeadd_back(t_plane **lst, t_plane *new)
{
	t_plane	*last;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		last = ft_planelast(*lst);
		last->next = new;
	}
}

void	ft_cylinderadd_back(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*last;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		last = ft_cylinderlast(*lst);
		last->next = new;
	}
}
