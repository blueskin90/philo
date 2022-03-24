#include "philo.h"

void	env_init(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
}

void    free_env(t_env *env)
{
    free(env->philo);
    free(env->fork);
}

int     alloc_env(t_env *env)
{
    if (!(env->philo = (t_philo*)malloc(sizeof(t_philo) * env->philo_number)))
        return (0);
    if (!(env->fork = (t_fork*)malloc(sizeof(t_fork) * env->philo_number)))
        return (0);
    for (unsigned long long int i = 0; i < env->philo_number; i++)
    {
        printf("%llu\n", (i + 1) % (env->philo_number));
        env->philo[i].left = &env->fork[i];
        env->philo[i].id = i;
        env->fork[i].id = i;
        env->philo[i].right = &env->fork[(i + 1) % (env->philo_number)];
    }
    return (1);
}
