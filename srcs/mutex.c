#include "philo.h"

int	create_forks(t_data *data)
{
	int i;
	
	i = 0;
	while (i != data->philo_num)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (1);
		data->philo = data->philo->next;
		i++;
	}
	return (0);
}

int	create_mutexes(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
		return (1);
	if (create_forks(data))
		return (2);
	if (pthread_mutex_init(&(data->print), NULL))
		return (3);
	if (pthread_mutex_init(&(data->check_end), NULL))
		return (4);
	if (pthread_mutex_init(&(data->last_meal), NULL))
		return (5);
	if (pthread_mutex_init(&(data->check_all_ate), NULL))
		return (6);
	return (0);
}