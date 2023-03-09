/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:51:29 by saguesse          #+#    #+#             */
/*   Updated: 2023/03/09 16:42:05 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *line)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (perror("new"), NULL);
	head->line = ft_strtrim(line, "\n");
	free(line);
	if (!head->line)
		return (perror("ft_strtrim"), NULL);
	head->next = NULL;
	return (head);
}

t_obj	*ft_objnew(char *identifier)
{
	t_obj	*head;

	head = malloc(sizeof(t_obj));
	if (!head)
		return (perror("new"), NULL);
	head->identifier = ft_strdup(identifier);
	if (!head->identifier)
		return (NULL);
	head->next = NULL;
	return (head);
}
