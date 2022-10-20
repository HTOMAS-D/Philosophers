#include "philo.h"

static void eat(t_data *data, t_philo *philo)
{
	
}

void	*philo_life(void *p)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)p;
	data = philo->data;
	// if (philo->id % 2 == 0)
	// 	ft_usleep(10);
	eat(data, philo);

	return (NULL);
}