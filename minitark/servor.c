#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include <stdio.h>
#include <stdlib.h>



int g_bit_count = 0;
int g_bits[8]; 


   char *s = NULL;


void action(int sig) {
    if (sig == SIGUSR1) {
        g_bits[g_bit_count] = 0;  
    } else if (sig == SIGUSR2) {
        g_bits[g_bit_count] = 1;  
    }
    g_bit_count++;


    int j=0;
    if (g_bit_count == 8) {
        char character = 0;
  
        int i=0;
        while( i < 8)
        {

            character |= (g_bits[i] << (7 - i)); 
            i++; 
        }
        s[j] = character;
        j++;
        if(character == '\0')
        {
            s[j] = '\0';
              printf("%s\n", s);
        }
        g_bit_count = 0;
    }
   
}
int main()
{
    pid_t pid = getpid();
    printf("pid de servor est :%d\n",pid);

    signal(SIGUSR1, action);
    signal(SIGUSR2, action);
    while (1)
    {
        pause();
    }
    return 0;
}