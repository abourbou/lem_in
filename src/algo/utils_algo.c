/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:54:21 by abourbou          #+#    #+#             */
/*   Updated: 2023/03/02 15:54:51 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

size_t	find_theory_maxflow(t_graph *graph)
{
	size_t	max;
	size_t	nb_start;
	size_t	nb_end;

	max = graph->nb_ants;
	nb_start = dlist_compt(graph->start_node->l_links);
	nb_end = dlist_compt(graph->end_node->l_links);
	if (nb_start < max)
		max = nb_start;
	if (nb_end < max)
		max = nb_end;
	return (max);
}

short	is_node_accessible(t_link *link, t_node *tail, t_node *head)
{
	if (link->flow == 1 && tail == link->node1 && head == link->node2)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

// Can the node be accessed in the residual graph
// from the link
// Valid if the flow can pass or reverse
// return EXIT_SUCCESS if it is the case
// or EXIT_FAILURE if it is blocked
short	can_access_residual_node(t_link *link, t_node *head)
{
	if (head == link->node2 && link->flow == 0)
		return (EXIT_SUCCESS);
	else if (head == link->node1 && link->flow == 1)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
