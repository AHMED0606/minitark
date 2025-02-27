/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientbonis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:54:40 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/27 19:39:33 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
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

void	implementation(int j, pid_t pid, char c)
{
	int	bit;

	while (j >= 0)
	{
		bit = (c >> j) & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Error: Failed to send SIGUSR1\n", 28);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Error: Failed to send SIGUSR2\n", 28);
				exit(1);
			}
		}
		usleep(1000);
		j--;
	}
}

void	client(pid_t pid, char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 7;
	while (str && str[i])
	{
		c = str[i];
		j = 7;
		implementation(j, pid, c);
		i++;
	}
}

int	chek_pid(char *str)
{
	int	i;

	if (!str)
		return (0);
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
	int	pid;

	if (ac == 2 || ac > 3 || ac == 1)
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
	if (pid <= 0)
	{
		write(2, "Error: Invalid PID\n", 19);
		return (1);
	}
	client(pid, av[2]);
	return (0);
}
