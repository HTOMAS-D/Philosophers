#include "philo.h"

void	*only_one(void *p)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)p;
	data = philo->data;
	printf("%s%lli ms ->%s Philosopher %d %s\n", BLUE,  get_time(data->time0), 
		YELLOW, 1, L_FORK);
	printf("%s%lli ms ->%s Philosopher %d %s\n", BLUE,  get_time(data->time0), 
		RED, 1, DIED);
	return (NULL);
}

int	one_philo(t_data *data)
{
	data->philo = add_philo(1, data);
	if (!data->philo)
		return (1);
	data->time0 = get_time(0);
	if (pthread_create(&(data->philo->thread), NULL, only_one, data->philo))
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
	philo->last_meal = 0;
	philo->ate = 0;
	philo->ate_all = 0;
	return (philo);
}

int	create_philos(t_data *data)
{
	int id;
	t_philo *philo;
	t_philo *first;

	philo = add_philo(1, data);
	first = philo;
	id = 1;
	while (++id <= data->philo_num)
	{
		philo->next = add_philo(id, data);
		philo = philo->next;
	}
	philo->next = first;
	data->philo = first;
	if(create_mutexes(data) || create_threads(data))
		return (1);
	return (0);
}