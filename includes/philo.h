#ifndef PHILO_H
#define PHILO_H

#include "libftprintf.h"
#include "libft.h"

#define USAGE "Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"

typedef struct		s_env
{
	char					must_eat;
	unsigned long long int	philo_number;
	unsigned long long int	ttdie;
	unsigned long long int	tteat;
	unsigned long long int	ttsleep;
	unsigned long long int	must_eat_number;
}					t_env;

#endif
