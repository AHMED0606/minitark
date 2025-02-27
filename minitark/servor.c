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
	pid_t pid = getpid();
    // write(1,"Pidde servor est :",18);
    // write(1,&pid,1);
    // write(1,"\n",1);
	printf("pid de servor est :%d\n", pid);

	signal(SIGUSR1, action);
	signal(SIGUSR2, action);

	while (1)
	{
		pause();
	}

	return (0);
}