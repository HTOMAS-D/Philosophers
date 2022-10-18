#include "philo.h"

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
}