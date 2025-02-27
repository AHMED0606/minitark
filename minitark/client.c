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
		//printf("jjj\n");
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			printf("%d",bit);
			if (bit == 0)
				kill(pid, SIGUSR1); // Bit '0' -> SIGUSR1
			else
				kill(pid, SIGUSR2); // Bit '1' -> SIGUSR2
			usleep(1000);
			j--;
		}
		i++;
	}

}
	
int	chek_pid(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int pid;

	if (ac == 1)
		return (0);
	if (ac == 2 || ac > 3)
	{
		write(2, "Eroor Arg\n", 10);
		return (0);
	}
	if (chek_pid(av[1]) == 0)
	{
		write(2, "Eroor Pid\n", 10);
		return (0);
	}
	pid = ft_atoi(av[1]);
	client(pid, av[2]);
}