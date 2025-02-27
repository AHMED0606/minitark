/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamiri <alamiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:54:20 by alamiri           #+#    #+#             */
/*   Updated: 2025/02/27 18:57:17 by alamiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int		g_bit_count = 0;

void	action(int sig)
{
	char	character;
	int		i;
	int		g_bits[8];

	if (sig == SIGUSR1)
	{
		g_bits[g_bit_count] = 0;
	}
	else if (sig == SIGUSR2)
	{
		g_bits[g_bit_count] = 1;
	}
	g_bit_count++;
	if (g_bit_count == 8)
	{
		character = 0;
		i = 0;
		while (i < 8)
		{
			character |= (g_bits[i] << (7 - i));
			i++;
		}
		write(1, &character, 1);
		g_bit_count = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	if (pid <= 0)
	{
		write(2, "Error print PID\n", 16);
		return (0);
	}
	ft_printf("pid de servor est :%d\n", pid);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
	{
		pause();
	}
	return (0);
}
