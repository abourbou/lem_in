#include "../../include/lib.h"

static char	**read_stdin()
{
	char	*line;
	char	*ret = NULL;
	char	**map = NULL;

	while (get_next_line(0, &line))
	{
		if (ft_strlen(line) == 0)
			return NULL;
		ret = ft_strjoin_sp(ret, line);
	}
	map = ft_split(ret, '\n');
	free(ret);
	free(line);
	return map;
}

static bool	ants_line(t_data *data, char *line)
{
	int	i;

	i = 0;
	skip_space_i(line, &i);
	data->numb_ants = atoi_sp(line, &i);
	if (check_space_end(line, &i))
		return (print_error("Error : number of ants is in incorrect format.\n"));
	if (data->numb_ants == 0)
		return (print_error("Error : [numbers of ants] cant be 0.\n"));
	return (EXIT_SUCCESS);
}

static int	parse_stdin(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (map[i] && is_comment(map[i]))
		i++;
	if (ants_line(data, map[i]))
		return (EXIT_FAILURE);
	printf("number of ant = %d\n", data->numb_ants);
	i++;
	while (map[i])
	{
		if (process_line(data, map, &i))
			return (EXIT_FAILURE);
		if (map[i])
			i++;
	}
	return 0;
}

bool	pars_args(t_data *data)
{
	char	**map = NULL;

	map = read_stdin();
	if (map == NULL)
		return (print_error("Error : empty line\n"));
	if (parse_stdin(data, map))
	{
		wrdestroy_parsing();
		return (EXIT_FAILURE);
	}
	wrdestroy_parsing();
	return EXIT_SUCCESS;
}
