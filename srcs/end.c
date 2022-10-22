#include "philo.h"

void	end_simulation(t_data *data)
{
	t_philo *philo;
	int i;

	if (data->philo_num == 1)
	{
		free(data->philo);
		return ;
	}
	i = 0;
	while (++i <= data->philo_num)
	{
		philo = data->philo->next;
		pthread_mutex_destroy(&(data->forks[i - 1]));
		free(data->philo);
		data->philo = philo;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->last_meal);
	pthread_mutex_destroy(&data->check_all_ate);
	pthread_mutex_destroy(&data->check_end);
}

static int	check_death(t_data *data, t_philo *philo)
{
	long long lastmeal;

	pthread_mutex_lock(&data->last_meal);
	lastmeal = philo->last_meal;
	pthread_mutex_unlock(&data->last_meal);
	if(lastmeal && get_time(data->time0) - lastmeal > data->to_die)
	{
		logs(philo->id, DIED, data);
		pthread_mutex_lock(&data->check_end);
		data->end = 1;
		pthread_mutex_unlock(&data->check_end);
		return (1);
	}
	return (0);
}

static int check_all_ate(t_data *data)
{
	int i;
	
	pthread_mutex_lock(&data->check_all_ate);
	i = data->all_ate;
	pthread_mutex_unlock(&data->check_all_ate);
	if (i == data->philo_num)
		return (1);
	return (0);
}

void	*check_end(void *p)
{
	t_data *data;
	t_philo *philo;
	
	data = (t_data *)p;
	philo = data->philo;
	while (!(check_all_ate(data) || check_death(data, philo)))
		philo = philo->next;
	return (NULL);
}