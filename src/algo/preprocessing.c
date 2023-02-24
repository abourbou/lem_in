/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:59:45 by abourbou          #+#    #+#             */
/*   Updated: 2023/02/24 17:51:45 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

// DFS algorithm saying if end can be reach from node
short	dfs_find_end(t_node *node, t_node *end)
{
	t_dlist	*current;
	t_link	*link;
	t_node	*opposite_node;

	if (node == end)
		return (EXIT_SUCCESS);
	if (node->is_used)
		return (EXIT_FAILURE);
	node->is_used = true;
	current = node->l_links;
	while (current)
	{
		link = current->content;
		opposite_node = find_opposite_node(link, node);
		if (!dfs_find_end(opposite_node, end))
			return (EXIT_SUCCESS);
		current = current->next;
	}
	return (EXIT_FAILURE);
}

short	check_path_exists(t_graph *graph)
{
	t_dlist	*lcurrent;
	t_node	*node;

	lcurrent = graph->lnode;
	while (lcurrent)
	{
		node = lcurrent->content;
		node->is_used = false;
		lcurrent = lcurrent->next;
	}
	return (dfs_find_end(graph->source, graph->sink));
}

/**
 * Erase nodes that have less than 2 connections
 * because they will never be usefull for the graph
*/
void	erase_dead_end_nodes(t_graph *graph)
{
	short	is_change;
	t_dlist	*lnode_next;
	t_dlist	*lnode;
	t_node	*node;

	is_change = true;
	while (is_change)
	{
		is_change = false;
		lnode = graph->lnode;
		while (lnode)
		{
			lnode_next = lnode->next;
			node = lnode->content;
			if (node != graph->source && node != graph->sink
				&& dlist_compt(node->l_links) < 2)
			{
				erase_node(node);
				dlist_erase(&graph->lnode, lnode);
				is_change = true;
			}
			lnode = lnode_next;
		}
	}
}
