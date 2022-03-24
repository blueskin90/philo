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
