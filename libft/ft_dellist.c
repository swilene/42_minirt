/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:00:25 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 17:57:23 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dellist(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->line)
			free(lst->line);
		free(lst);
		lst = tmp;
	}
}

void	ft_delobj(t_obj *lst)
{
	t_obj	*tmp;

	if (lst == NULL)
		return ;
	while (lst)
	{
		tmp = lst->next;
		if (lst->identifier)
			free(lst->identifier);
		free(lst);
		lst = tmp;
	}
}
