/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaranes <sbaranes@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:04 by sbaranes          #+#    #+#             */
/*   Updated: 2023/03/03 12:50:10 by sbaranes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	process_ants(t_data *data, char *line)
{
	int	i;

	i = 0;
	data->pars.step++;
	skip_space_i(line, &i);
	data->numb_ants = atoi_sp(line, &i);
	if (check_space_end(line, &i))
		free_exit(data, "Error : numbers of ants incorrect format.\n", NULL);
	if (data->numb_ants <= 0)
		free_exit(data, "Error : invalid numbers of ants.\n", NULL);
}

void	process_vertex(t_data *data, char *line)
{
	char	**arg;

	arg = NULL;
	if (data->pars.step != 2)
		free_exit(data, "Error : bad order of arguments\n", NULL);
	arg = ft_split(line, ' ');
	if (arg[0][0] == 'L' || arg[0][0] == '#')
		free_exit(data, "Error : room name cant start by # or 'L'.\n", arg);
	if (is_interger(arg[1]) || is_interger(arg[2]))
		free_exit(data, "Error : bad format coordinates.\n", arg);
	if (is_exist(data->dico_vertex, arg[0]) == 0)
	{
		lstadd_back_vertex(&data->list_vertex, lstnew_vertex(arg[0],
				atoi(arg[1]), atoi(arg[2])));
		data->dico_vertex = add_node(data->dico_vertex, arg[0]);
	}
	else
		free_exit(data, "Error : 2 rooms cant have same name.\n", arg);
	free_tab(arg);
}

static void	process_command(t_data *data, t_map	*cursor)
{
	int			code;
	char		**arg;

	if (data->pars.step != 2)
		free_exit(data, "Error : bad order of arguments\n", NULL);
	code = ft_strcmp(cursor->line, "##start");
	cursor = cursor->next;
	arg = ft_split(cursor->line, ' ');
	if (ft_substrlen(arg) != 3)
		free_exit(data, "Error : bad numbers of argument in line\n", arg);
	if (arg[0][0] == 'L' || arg[0][0] == '#')
		free_exit(data, "Error : room name cant start by # or 'L'\n", arg);
	if (is_interger(arg[1]) || is_interger(arg[2]))
		free_exit(data, "Error : bad format for coordinates\n", arg);
	if (is_exist(data->dico_vertex, arg[0]) == 0)
	{
		if (set_start_or_end(data, lstnew_vertex(arg[0], atoi(arg[1]),
					atoi(arg[2])), code))
			free_exit(data, NULL, arg);
	}
	else
		free_exit(data, "Error : 2 rooms cant have same name.\n", arg);
	free_tab(arg);
}

static void	process_edgr(t_data *data, char *line)
{
	char	**arg;

	arg = ft_split(line, '-');
	if (data->pars.step == 2)
		data->pars.step++;
	if (data->pars.step != 3)
		free_exit(data, "Error : bad order of arguments\n", NULL);
	if (ft_substrlen(arg) != 2)
		free_exit(data, "Error : line link bad format.\n", arg);
	if ((arg[0][0] == 'L' || arg[0][0] == '#') ||
		(arg[1][0] == 'L' || arg[1][0] == '#'))
		free_exit(data, "Error : room name cant start by # or 'L'.\n", arg);
	if (ft_strcmp(arg[0], arg[1]) == 0)
		free_exit(data, "Error : link cannot connect a room to itself.\n", arg);
	lstadd_back_edge(&data->list_edge, lstnew_edge(arg[0], arg[1], 0));
	free_tab(arg);
}

void	parse_stdin(t_data *data)
{
	t_map	*cursor;
	int		code;

	cursor = data->list_map;
	while (cursor != NULL)
	{
		code = define_line(cursor->line);
		if (code == COM)
			;
		else if (data->pars.step == 1 && code != COM)
			process_ants(data, cursor->line);
		else if (code == CMD)
		{
			process_command(data, cursor);
			cursor = cursor->next;
		}
		else if (code == VERTEX)
			process_vertex(data, cursor->line);
		else if (code == EDGE)
			process_edgr(data, cursor->line);
		else if (code == UNKNOWN)
			free_exit(data, "Error : unknown line format.\n", NULL);
		cursor = cursor->next;
	}
	return ;
}
