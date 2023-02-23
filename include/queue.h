/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourbou <abourbou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 07:57:13 by abourbou          #+#    #+#             */
/*   Updated: 2023/02/23 10:13:33 by abourbou         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

# include "graph.h"

typedef struct s_queue
{
	t_dlist	*start;
	t_dlist	*end;
}	t_queue;

void	queue_init(t_queue *queue);
void	free_queue(t_queue *queue, void deallocator(void*));
short	is_queue_empty(t_queue *queue);
short	queue_push(t_queue *queue, void *content);
void	*queue_pop(t_queue *queue);

#endif