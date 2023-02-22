#include "../../include/lib.h"

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
}

static void	print_free_map(t_data *data)
{
	t_map	*save;

	while (data->list_map)
	{
		save = data->list_map;
		ft_putstrln(data->list_map->line);
		free(data->list_map->line);
		data->list_map = data->list_map->next;
		free(save);
	}
}

bool	pars_args(t_data *data)
{
	read_stdin(data);
	parse_stdin(data);
	print_free_map(data);

	return EXIT_SUCCESS;
}
