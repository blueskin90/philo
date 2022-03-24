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

int		alloc_philo(t_env *env)
{
	if (!(env->philo = (t_philo*)malloc(sizeof(t_philo) * env->params.philo_number)))
		return (0);
	ft_bzero(env->philo, sizeof(t_philo) * env->params.philo_number);
	return (1);
}

int		alloc_forks(t_env *env)
{
	if (!(env->fork = (t_fork*)malloc(sizeof(t_fork) * env->params.philo_number)))
		return (0);
	ft_bzero(env->fork, sizeof(t_fork) * env->params.philo_number);
	return (1);
}

int		alloc_mutexes(t_env *env)
{
	for (unsigned long long int i=0; i < env->params.philo_number; i++)
	{
		if (pthread_mutex_init(&env->fork[i].mutex, NULL) != 0)
		{
			printf("Couldn't init mutex\n");
			for (unsigned long long int j=0; j < i; j++)
			{
				if (pthread_mutex_destroy(&env->fork[j].mutex) != 0)
					printf("Couldn't destroy mutex %llu\n", j);
			}
			return (0);
		}
	}
	return (1);
}

int     alloc_env(t_env *env)
{
	if (!alloc_philo(env))
		return (0); // goto clean
	if (!alloc_forks(env))
		return (0);
	if (!alloc_mutexes(env))
		return (0);
	for (unsigned long long int i = 0; i < env->params.philo_number; i++)
	{
		//        printf("%llu\n", (i + 1) % (env->philo_number));
		env->philo[i].left = &env->fork[i];
		env->philo[i].id = i;
		env->fork[i].id = i;
		env->philo[i].right = &env->fork[(i + 1) % (env->params.philo_number)];
		env->philo[i].params = &env->params;
	}
	return (1);
}
