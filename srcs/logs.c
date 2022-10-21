#include "philo.h"

static char	*check_color(char *log)
{
	char *color;
	
	if (!ft_strcmp(log, DIED))
		color = RED;
	else if (!ft_strcmp(log, EATING))
		color = GREEN;
	else if (!ft_strcmp(log, SLEEPING))
		color = BLUE;
	else
		color = YELLOW;
	return (color);
}

void	logs(int philo, char *log, t_data *data)
{
	int i;
	char *color;

	pthread_mutex_lock(&data->print);
	color = check_color(log);
	pthread_mutex_lock(&(data->check_end));
	i = data->end;
	pthread_mutex_unlock(&(data->check_end));
	if (i)
	{
		pthread_mutex_unlock(&data->print);
		return ;
	}
	printf("%s%lli ms ->%s Philosopher %d %s\n", BLUE, get_time(data->time0), 
		color, philo, log);
	printf(DEFAULT);
	pthread_mutex_unlock(&data->print);	
}