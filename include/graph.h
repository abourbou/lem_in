/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:38:52 by abourbou          #+#    #+#             */
/*   Updated: 2023/02/24 12:24:04 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "lib.h"

/*
******************** Struct ********************
*/
/**
 * Node structure containing:
 *  - name
 *  - l_links : list links connected to the node
 *  - is_used : is the room already use for dfs or other algorithm
 *  - ant_nb : number of the ant in the room, 0 means the room is empty
*/
typedef struct s_node
{
	char			*name;
	t_dlist			*l_links;
	short			is_used;
	unsigned int	dist_source;
	int				ant_nb;
}	t_node;

/**
 * Link structure containing:
 * - terminal : node where it goes
 * - flow : status of the link
 *   (0 = blocked, 1 = available, 2 = used)
*/
typedef struct s_link
{
	t_node	*terminal;
	int		flow;
}	t_link;

/**
 * Graph structure containing:
 *  - list of nodes in the graph
 *  - start node
 *  - end node
*/
typedef struct s_graph
{
	t_dlist	*lnode;
	t_dlist	*source;
	t_dlist	*sink;
}	t_graph;

typedef struct s_path
{
	t_node			*arr_node;
	unsigned int	length;
}	t_path;

// flow of a graph from source to sink
// containing a list of path sorted by size
typedef struct s_flow
{
	t_dlist	*t_path;
}	t_flow;

// Prototypes
short	convert_data_graph(t_data *data, t_graph *graph);

// Utils for graph construction
void	create_link(t_node *node1, t_node *node2);
short	find_nodes(t_edge *edge, t_graph *graph, t_node **first_node,
			t_node **second_node);
t_node	*convert_vertex_to_node(t_vertex *vertex);

#endif