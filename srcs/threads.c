#include "philo.h"

int	join_threads(t_data *data)
{
	int i;

	i = 0;
	if(data->philo_num == 1)
	{
		if(pthread_join(data->philo->thread, NULL))
				return (1);
		return (0);
	}
	while (i != data->philo_num)
	{
		if(pthread_join(data->philo->thread, NULL))
			return (2);
		data->philo = data->philo->next;
		i++;
	}
	if (pthread_join(data->thread, NULL))
		return (3);
	return (0);
}

int	create_threads(t_data *data)
{
	int index;

	index = 0;
	data->time0 = get_time(0);
	while (index != data->philo_num)
	{
		if (pthread_create(&(data->philo->thread), NULL, philo_life, data->philo))
			{
				printf("Error creating philo thread\n");
				return (1);
			}
		data->philo = data->philo->next;
		index++;
	}
	if (pthread_create(&(data->thread), NULL, check_end, data))
		{
			printf("Error creating data thread\n");
			return (1);
		}
	return (0);
}