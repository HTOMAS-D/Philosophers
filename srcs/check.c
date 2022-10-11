#include "philo.h"

int check_args(int ac, char **av)
{
	int i;

	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	i = 1;
	while(i++ < ac)
	{
		if (ft_atoi(av[i]) < 1)
		{
			printf("Error: Invalid argument\n");
			return (1);
		}
	}
	return (0);
}