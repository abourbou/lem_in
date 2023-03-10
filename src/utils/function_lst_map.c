/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:02:03 by abourbou          #+#    #+#             */
/*   Updated: 2023/02/24 17:57:57 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_map	*lstnew_map(char *name)
{
	t_map	*lst;

	lst = malloc(sizeof(t_map));
	if (!lst)
		return (NULL);
	lst->line = ft_strdup(name);
	lst->next = NULL;
	lst->last = NULL;
	return (lst);
}

void	lstadd_back_map(t_map **alst, t_map *new)
{
	t_map	*p;
	t_map	*save;

	p = *alst;
	save = *alst;
	if (!alst)
		return ;
	if (!*alst)
	{
		new->last = new;
		*alst = new;
	}
	else if (p)
	{
		p = p->last;
		p->next = new;
		save->last = p->next;
	}
}

void	lstclear_map(t_data *data)
{
	t_map	*temp;
	t_map	*lst;

	if (data->list_map == NULL)
		return ;
	lst = data->list_map;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp->line);
		free(temp);
	}
	data->list_map = NULL;
}
