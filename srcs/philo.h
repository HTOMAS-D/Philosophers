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
	t_philo *philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	struct s_philo 	*next;
}	t_philo;

//CHECK.C
int check_args(int ac, char **av);

//UTILS.C
int ft_atoi(char *str);

//PHILOS.C
void create_philos(t_data *data);

#endif
