#include "philo.h"

int	init_data(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->to_die = ft_atoi(av[2]);
	data->to_eat = ft_atoi(av[3]);
	data->to_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	if(data->philo_num == 1)
		{
			if(one_philo(data))
				printf("%sError: malloc or pthread failed\n%s", RED, DEFAULT);
				return (1);
			return (0);
		}
	if(create_philos(data))
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_data	data;
	
	if(check_args(ac, av))
		return (1);
	printf("ola 2\n");
	if(init_data(&data, ac, av))
		return (2);
	
}
