#include "philo.h"

int		ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

void    ft_bzero(void *ptr, size_t size)
{
    char    *tmp;

    tmp = ptr;
    for (size_t i = 0; i < size; i++)
        tmp[i] = 0;
}

int		strtoulli(char *str, unsigned long long int *ptr)
{
	int		i;
	unsigned long long int tmp;

	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			printf("%s contains illegal character \'%c\'\n", str, str[i]);
			return (0);
		}
		tmp = *ptr;
		*ptr *= 10;
		*ptr += str[i] - '0';
		if (tmp > *ptr)
		{
			printf("%s makes unsigned long long int overflow\n", str);
			return (0);
		}
		i++;
	}
	if (*ptr == 0)
	{
		printf("Can't have 0 as a value\n");
		return (0);
	}
	return (1);
}

void	env_init(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
}

int		arg_parsing(t_env *env, int ac, char **av)
{
	unsigned long long int *ptr;

	ptr = &(env->philo_number);
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
			env->must_eat = 1;
	}
	return (1);
}

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

int    start_time(t_env *env)
{
    if (gettimeofday(&(env->start_time), NULL) == -1)
    {
        printf("Couldn't get time of day\n");
        return (0);
    }
    return (1);
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

void    dump_philos(t_env *env)
{
    for (unsigned long long int i = 0; i < env->philo_number; i++)
        printf("Philo number %d: left fork: %d right fork: %d\n", env->philo[i].id, env->philo[i].left->id, env->philo[i].right->id);
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
    free_env(&env);
	return (1);
}
