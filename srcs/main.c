#include "philo.h"

static void init_atoi(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->to_die = ft_atoi(av[2]);
	data->to_eat = ft_atoi(av[3]);
	data->to_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	data->time0 = 0;
	data->all_ate = 0;
	data->end = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
}

int	init_data(t_data *data, int ac, char **av)
{
	init_atoi(data, ac, av);
	if(data->philo_num == 1)
		{
			if(one_philo(data))
			{
				printf("%sError: malloc or pthread failed\n%s", RED, DEFAULT);
				return (2);
			}
			return (0);
		}
	else 
	{	
		if (create_philos(data))
		{
			printf("Error creating philosophers\n");
			return (3);
		}
	}
	return (0);
}	

int main(int ac, char **av)
{
	t_data	data;
	
	if(check_args(ac, av))
	{
		printf("%sError: wrong arguments\n%s", RED, DEFAULT);
		return (1);
	}
	if(init_data(&data, ac, av))
	{
		printf("Error initializing data\n");
		return (2);
	}
	if(join_threads(&data))
	{
		printf("Error joining threads\n");
		return (3);
	}
//	ft_usleep(50);
	end_simulation(&data);
	return (0);
}
