#include "philo.h"
int		arg_parsing(t_env *env, int ac, char **av)
{
	unsigned long long int *ptr;

	ptr = &(env->params.philo_number);
	if (ac < 4 || ac > 5)
	{
		ft_putendl(USAGE);
		return (0);
	}
	for (int i = 0; i < ac; i++)
	{
		if (strtoulli(av[i], &(ptr[i])) == 0)
			return (0);
		if (i == 4)
			env->params.must_eat = 1;
	}
	return (1);
}

int    start_time(t_env *env)
{
	if (gettimeofday(&(env->params.start_time), NULL) == -1)
	{
		printf("Couldn't get time of day\n");
		return (0);
	}
	return (1);
}

int		destroy_mutexes(t_env *env)
{
	for (unsigned long long int i=0; i < env->params.philo_number; i++)
	{
		if (pthread_mutex_destroy(&env->fork[i].mutex) != 0)
		{
			printf("Couldn't destroy mutex %llu\n", i);
		}	
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_env	env;

	env_init(&env);
	if (arg_parsing(&env, ac - 1, av + 1) == 0)
		return (0);
	if (!start_time(&env))
		return (0);
	if (!alloc_env(&env))
	{
		free_env(&env);
		printf("Something went wrong when allocating memory\n");
		return (0);
	}
	dump_env(&env);
	dump_philos(&env);
	destroy_mutexes(&env);
	free_env(&env);
	return (1);
}
