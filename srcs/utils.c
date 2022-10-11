#include "philo.h"

int ft_atoi(char *str)
{
	int i;
	int res;
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