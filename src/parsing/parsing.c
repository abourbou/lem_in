/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:23 by sbaranes          #+#    #+#             */
/*   Updated: 2023/03/03 12:55:41 by sbaranes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	print_map(t_map *list_map)
{
	while (list_map)
	{
		ft_putstrln(list_map->line);
		list_map = list_map->next;
	}
	ft_putstr("\n");
}

void	free_map(t_data *data)
{
	t_map	*next_map;
	t_map	*current_map;

	current_map = data->list_map;
	while (current_map)
	{
		next_map = current_map->next;
		free(current_map->line);
		free(current_map);
		current_map = next_map;
	}
	data->list_map = NULL;
}

static void	read_stdin(t_data *data)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			free_exit(data, "Error : empty line\n", NULL);
		}
		lstadd_back_map(&data->list_map, lstnew_map(line));
		free(line);
	}
	free(line);
}

bool	pars_args(t_data *data)
{
	read_stdin(data);
	parse_stdin(data);
	if (data->start_vertex == NULL)
		free_exit(data, "Error : command start not found.\n", NULL);
	if (data->end_vertex == NULL)
		free_exit(data, "Error : command end not found.\n", NULL);
	return (EXIT_SUCCESS);
}
