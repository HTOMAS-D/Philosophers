#include "philo.h"

int check_args(int ac, char **av)
{
	int i;
	
	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	i = 0;
	while(++i != ac)
	{
		if (ft_atoi(av[i]) < 1)
		{
			printf("Error: Invalid argument\n");
			return (2);
		}
		//printf("ola 1\n");
	}
	printf("ola 1\n");
	return (0);
}