#include "philo.h"

void	init_data(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	create_philos(data);
}

int main(int ac, char **av)
{
	t_data	data;
	
	if(check_args(ac, av))
		return 1;
	init_data(&data, ac, av);
}
