#include "philo.h"

int		ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
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
			ft_printf("%s contains illegal character \'%c\'\n", str, str[i]);
			return (0);
		}
		tmp = *ptr;
		*ptr *= 10;
		*ptr += str[i] - '0';
		if (tmp > *ptr)
		{
			ft_printf("%s makes unsigned long long int overflow\n", str);
			return (0);
		}
		i++;
	}
	return (1);
}

void	env_init(t_env *env)
{
	ft_bzero(env, sizeof(t_env));
	env->must_eat = 0; // unnecessary but just to be safe;
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
	ft_printf(env->must_eat == 0 ? "Until a philosopher dies\n" : "Until each philosopher has eaten %lld times\n", env->must_eat_number);
	ft_printf("philo nbr : %lld\n", env->philo_number);
	ft_printf("time to die : %lld\n", env->ttdie);
	ft_printf("time to eat : %lld\n", env->tteat);
	ft_printf("time to sleep : %lld\n", env->ttsleep);
	ft_printf("must eat nbr : %lld\n", env->must_eat_number);
}

int		main(int ac, char **av)
{
	t_env	env;

	env_init(&env);
	if (arg_parsing(&env, ac - 1, av + 1) == 0)
		return (0);
	dump_env(&env);
	ft_printf("Ca marche\n");
	return (1);
}
