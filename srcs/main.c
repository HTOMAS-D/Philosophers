#include "philo.h"

int init_atoi(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->to_die = ft_atoi(av[2]);
	data->to_eat = ft_atoi(av[3]);
	data->to_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	data->time0 = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	return (0);
}

int	init_data(t_data *data, int ac, char **av)
{
	init(data, ac, av);
	if(data->philo_num == 1)
		{
			if(one_philo(data))
				printf("%sError: malloc or pthread failed\n%s", RED, DEFAULT);
				return (2);
			return (0);
		}
	if(create_philos(data))
	{	
		printf("Error creating philosophers\n");
		return (3);
	}
	return (0);
}	

int main(int ac, char **av)
{
	t_data	data;
	
	if(check_args(ac, av))
		return (1);
	if(init_data(&data, ac, av))
		return (2);
	if(join_threads(&data))
		{
			printf("Error joining threads\n");
			return (3);
		}
	ft_usleep(10);

	return (0);
}
