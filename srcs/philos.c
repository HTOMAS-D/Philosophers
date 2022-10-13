#include "philo.h"

void	*only_one(void *p)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)p;
	data = philo->data;
	printf("%s%lli mx ->%s Philosopher %d %s\n", BLUE,  get_time(data->time0), 
		YELLOW, 1, L_FORK);
	printf("%s%lli mx ->%s Philosopher %d %s\n", BLUE,  get_time(data->time0), 
		RED, 1, DIED);
	return (NULL);
}

int	one_philo(t_data *data)
{
	data->philo = add_philo(1, data);
	if (!data->philo)
		return (1);
	data->time0 = get_time(0);
	if(pthread_create(&data->philo->thread, NULL, &only_one, data->philo))
			return (1);
	return (0);
}

t_philo	*add_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->next = NULL;
	philo->data = data;
	return (philo);
}

int	create_philos(t_data *data)
{
	int id;
	t_philo *philo;
	t_philo *first;

	id = 1;
	philo = add_philo(id, data);
	if (!philo)
		return (1);
	first = philo;
	while (++id < data->philo_num)
	{
		philo->next = add_philo(id, data);
		if (!philo->next)
			return (1);
		philo = philo->next;
	}
	philo->next = first;
	data->philo = first;
	return (0);
}