#include "philo.h"

void ft_usleep(long long time)
{
	long long t;

	t = get_time(0) + time;
	while (get_time(0) < t)
		usleep(10);
}

long long get_time(long long time0)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - time0);
}

long long ft_atoi(char *str)
{
	int i;
	long long res;
	int flag;

	i = 0;
	res = 0;
	flag = 1;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * flag);
}

int ft_strcmp(char *s1, char *s2)
{
	int i;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}