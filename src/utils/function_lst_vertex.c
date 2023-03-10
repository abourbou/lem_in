/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst_vertex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:02:38 by abourbou          #+#    #+#             */
/*   Updated: 2023/02/24 11:02:45 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_vertex	*lstnew_vertex(char *name, int cord_x, int cord_y)
{
	t_vertex	*lst;

	lst = malloc(sizeof(t_vertex));
	if (!lst)
		return (NULL);
	lst->name = ft_strdup(name);
	lst->cord_x = cord_x;
	lst->cord_y = cord_y;
	lst->next = NULL;
	lst->last = NULL;
	return (lst);
}

void	lstadd_back_vertex(t_vertex **alst, t_vertex *new)
{
	t_vertex	*p;
	t_vertex	*save;

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

void	lstclear_vertex(t_data *data)
{
	t_vertex	*temp;
	t_vertex	*lst;

	if (data->list_vertex == NULL)
		return ;
	lst = data->list_vertex;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp->name);
		free(temp);
	}
}

bool	set_start_or_end(t_data *data, t_vertex *new_vertex, int code)
{
	if (code == 0)
	{
		if (data->start_vertex != NULL)
		{
			free(new_vertex->name);
			free(new_vertex);
			return (write(2, "Error : start cant be 2 time.\n", 31));
		}
		data->start_vertex = new_vertex;
	}
	else
	{
		if (data->end_vertex != NULL)
		{
			free(new_vertex->name);
			free(new_vertex);
			return (write(2, "Error : end cant be 2 time.\n", 29));
		}
		data->end_vertex = new_vertex;
	}
	lstadd_back_vertex(&data->list_vertex, new_vertex);
	data->dico_vertex = add_node(data->dico_vertex, new_vertex->name);
	return (EXIT_SUCCESS);
}
