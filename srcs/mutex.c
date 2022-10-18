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
}

int	create_mutexes(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks)
			return (1);
	if (create_forks(data))
			return (2);
	if (pthread_mutex_init(&(data->print), NULL) || pthread_mutex_init(&(data->end), NULL))
		return (3);
	if (pthread_mutex_init(&(data->last_meal), NULL) || pthread_mutex_init(&(data->all_ate), NULL))
		return (4);
}