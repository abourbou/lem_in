#include "../include/lib.h"

void	init_data(t_data *data)
{
	data->numb_ants = 0;
	data->start_room = NULL;
	data->end_room = NULL;
}

void free_and_exit()
{
	wrdestroy();
}

// int	check_arg(int ac, char **av)
// {
// 	printf("test ac = %d\n", ac);
// 	if (ac < 2 || ac > 3)
// 		return (print_error("Error : numbers of argument not valide\n"));
// 	if (ac == 3)
// 		print_error("fichier\n");
// 	if (ac == 2)
// 		print_error("entrer standart\n");
// 	return 0;
// }

int	main(int ac, char **av)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_data(&data);
	// if (check_arg(ac, av))
	// 	return (EXIT_FAILURE);
	if(pars_args(&data))
		return (EXIT_FAILURE);

	printf("start print list\n");
	for (t_room *cursor = data.start_room; cursor; cursor = cursor->next)
	{
		printf("name of room : %s | cord x : %d | cord y : %d\n", cursor->name, cursor->cord_x, cursor->cord_y);
	}
	printf("end print list\n");

	free_and_exit();
	return 0;
}
