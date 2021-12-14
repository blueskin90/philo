#ifndef PHILO_H
#define PHILO_H

#include "libftprintf.h"
#include "libft.h"

#include <sys/time.h>
#include <pthread.h>


#define USAGE "Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"

typedef struct      s_fork
{
    int             id;
}                   t_fork;

typedef struct      s_philo
{
    int             id;
    t_fork          *left;
    t_fork          *right;
}                   t_philo;

typedef struct		s_env
{
	char					must_eat;
	unsigned long long int	philo_number;
	unsigned long long int	ttdie;
	unsigned long long int	tteat;
	unsigned long long int	ttsleep;
	unsigned long long int	must_eat_number;
    struct timeval          start_time;

    t_philo                 *philo;
    t_fork                  *fork;
}					t_env;

/*memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock
*/

#endif
