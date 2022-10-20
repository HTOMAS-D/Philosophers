#include "philo.h"

static void (t_data *data, t_philo *philo, int *l_fork, int *r_fork)
{
	
}

static void eat(t_data *data, t_philo *philo)
{
	int l_fork;
	int r_fork;

	fork_lock(data, philo, &l_fork, &r_fork);
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