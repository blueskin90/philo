#include "philo.h"

void	dump_env(t_env *env)
{
	printf(env->must_eat == 0 ? "Until a philosopher dies\n" : "Until each philosopher has eaten %lld times\n", env->must_eat_number);
	printf("philo nbr : %lld\n", env->philo_number);
	printf("time to die : %lld\n", env->ttdie);
	printf("time to eat : %lld\n", env->tteat);
	printf("time to sleep : %lld\n", env->ttsleep);
	printf("must eat nbr : %lld\n", env->must_eat_number);
    printf("secs since epoch = %ld\n", env->start_time.tv_sec);
    printf("microsecs = %d\n", env->start_time.tv_usec);
}

void    dump_philos(t_env *env)
{
    for (unsigned long long int i = 0; i < env->philo_number; i++)
        printf("Philo number %d: left fork: %d right fork: %d\n", env->philo[i].id, env->philo[i].left->id, env->philo[i].right->id);
}
