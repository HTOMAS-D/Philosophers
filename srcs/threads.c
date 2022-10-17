#include "philo.h"

int	create_threads(t_data *data)
{
	int index;

	index = 0;
	while (index != data->philo_num)
	{
		if (pthread_create(&(data->philo->thread), NULL, philo_life, data->philo))
			return (1);
		data->philo = data->philo->next;
		index++;
	}
}