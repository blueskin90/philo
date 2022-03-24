#include "philo.h"

void	dump_env(t_env *env)
{
	printf(env->params.must_eat == 0 ? "Until a philosopher dies\n" : "Until each philosopher has eaten %lld times\n", env->params.must_eat_number);
	printf("philo nbr : %lld\n", env->params.philo_number);
	printf("time to die : %lld\n", env->params.ttdie);
	printf("time to eat : %lld\n", env->params.tteat);
	printf("time to sleep : %lld\n", env->params.ttsleep);
	printf("must eat nbr : %lld\n", env->params.must_eat_number);
    printf("secs since epoch = %ld\n", env->params.start_time.tv_sec);
    printf("microsecs = %d\n", env->params.start_time.tv_usec);
}

void    dump_philos(t_env *env)
{
    for (unsigned long long int i = 0; i < env->params.philo_number; i++)
        printf("Philo number %d: left fork: %d right fork: %d\n", env->philo[i].id, env->philo[i].left->id, env->philo[i].right->id);
}
