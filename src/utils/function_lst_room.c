/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 21:07:57 by sbaranes          #+#    #+#             */
/*   Updated: 2021/07/20 10:28:49 by sbaranes         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/lib.h"

t_room	*lstnew_room(char *name, int cord_x, int cord_y)
{
	t_room	*lst;

	puts("0");
	lst = wrmalloc(sizeof(t_room));
	puts("1");
	if (!lst)
		return (NULL);
	lst->name = name;
	lst->cord_x = cord_x;
	lst->cord_y = cord_y;
	lst->next = NULL;
	lst->prev = NULL;
	puts("2");
	return (lst);
}

void	lstadd_front_room(t_room **alst, t_room *new)
{
	new->next = *alst;
	*alst = new;
}

void	lstadd_back_room(t_room **alst, t_room *new)
{
	t_room	*p;

	p = *alst;
	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (p)
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

t_room	*lstlast_room(t_room *lstt)
{
	t_room	*lst;

	if (!lstt)
		return (lstt);
	lst = lstt;
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
