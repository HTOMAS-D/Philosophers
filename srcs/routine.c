#include "philo.h"

static void fork_lock(t_data *data, t_philo *philo, int *l_fork, int *r_fork)
{
	*l_fork = philo->id - 1;
	*r_fork = philo->id;
	if (philo->id == data->philo_num)
		{
			*r_fork = *l_fork;
			*l_fork = 0;
		}
	pthread_mutex_lock(&(data->forks[*r_fork]));
	logs(philo->id, R_FORK, data);
	pthread_mutex_lock(&(data->forks[*l_fork]));
	logs(philo->id, L_FORK, data);
}

static void eat(t_data *data, t_philo *philo)
{
	int l_fork;
	int r_fork;

	fork_lock(data, philo, &l_fork, &r_fork);
	pthread_mutex_lock(&(data->last_meal));
	philo->last_meal = get_time(data->time0);
	pthread_mutex_unlock(&(data->last_meal));
	logs(philo->id, EATING, data);
	ft_usleep(data->to_eat);
	pthread_mutex_unlock(&(data->forks[l_fork]));
	pthread_mutex_unlock(&(data->forks[r_fork]));
	philo->ate++;
	if (data->must_eat && philo->ate == data->must_eat)
	{
		philo->ate_all = 1;
		pthread_mutex_lock(&(data->check_all_ate));
		data->all_ate++;
		pthread_mutex_unlock(&(data->check_all_ate));
	}
}

static int	check_end1(t_data *data)
{
	int i;

	pthread_mutex_lock(&(data->check_end));
	i = data->end;
	pthread_mutex_unlock(&(data->check_end));
	if (i)
		return (0);
	return (1);
}

void	*philo_life(void *p)
{
	t_philo *philo;
	t_data *data;

	philo = (t_philo *)p;
	data = philo->data;
	if (philo->id % 2 == 0)
	ft_usleep(10);
	while (check_end1(data))
	{
		eat(data, philo);
		if (philo->ate_all)
			break ;
		logs(philo->id, SLEEPING, data);
		ft_usleep(data->to_sleep);
		logs(philo->id, THINKING, data);
	}
	return (NULL);
}