#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

long	ft_atoi(const char *nptr)
{
	int		i;
	int		a;
	long	n;

	i = 0;
	a = 1;
	n = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			a = a * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * a);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
void	client(pid_t pid, char *str)
{
	int		i;
	int		j;
	char	c;
	int		bit;

	i = 0;
	j = 7;
	while (str && str[i])
	{
		c = str[i];
	//	printf("%c\n",c);
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			//printf("%d\n",bit);
			if (bit == 0)
			{
				kill(pid, SIGUSR1); // Bit '0' -> SIGUSR1
			}
			else
			{
				kill(pid, SIGUSR2); // Bit '1' -> SIGUSR2
			}
			usleep(100);
           j--; 
		}
        i++;
	}
}
int	main(int ac, char **av)
{
	int pid;
	int lent;
	int i;
	i = 0;
	pid = ft_atoi(av[1]);
	lent = ft_strlen(av[2]);
	printf("%d\n", lent);

	// while (i < ac)
	// {
		printf("%s\n", av[2]);
		client(pid, av[2]);
	// 	i++;
	// }
}