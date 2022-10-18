#ifndef PHILO_H
#define PHILO_H
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>

//ACTIONS
#define R_FORK "has taken the right fork"
#define L_FORK "has taken the left fork"
#define EATING "is eating"
#define SLEEPING "is sleeping"
#define THINKING "is thinking"
#define DIED "died"

//COLORS
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define DEFAULT "\033[0m"

typedef struct s_data
{
	int	philo_num;
	long long	to_die;
	long long	to_eat;
	long long	to_sleep;
	int	must_eat;
	long long time0;
	pthread_t thread;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
	pthread_mutex_t end;
	pthread_mutex_t last_meal;
	pthread_mutex_t all_ate;
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
long long ft_atoi(char *str);
long long get_time(long long time0);

//PHILOS.C
int create_philos(t_data *data);
t_philo	*add_philo(int id, t_data *data);
int	one_philo(t_data *data);
void	*only_one(void *p);

//MUTEX.C
int create_mutexes(t_data *data);
int create_forks(t_data *data);

//THREADS.C
int create_threads(t_data *data);

//ROUTINE.C
void *philo_life(void *p);

//END.C
void *check_end(void *p);

#endif
