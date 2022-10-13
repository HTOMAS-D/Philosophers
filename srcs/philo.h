#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	struct s_philo *philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t	thread;
	struct s_philo 	*next;
	struct s_data	*data;
}	t_philo;

//CHECK.C
int check_args(int ac, char **av);

//UTILS.C
int ft_atoi(char *str);

//PHILOS.C
int create_philos(t_data *data);
t_philo	*add_philo(int id, t_data *data);

#endif
