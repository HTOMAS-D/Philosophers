#include "philo.h"

t_philo	*add_philo(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->next = NULL;
	philo->data = data;
}

int	create_philos(t_data *data)
{
	int id;
	t_philo *philo;
	t_philo *first;

	id = 1;
	philo = add_philo(id, data);
	
}