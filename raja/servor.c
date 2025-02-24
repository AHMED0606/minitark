#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int g_bit_count = 0;
int g_bits[8]; 

void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        g_bits[g_bit_count] = 0;  
    } else if (sig == SIGUSR2) {
        g_bits[g_bit_count] = 1;  
    }
    g_bit_count++;
   
    
    if (g_bit_count == 8) {
        char character = 0;
        
        for (int i = 0; i < 8; i++) {
            printf("%d|\n",g_bits[i]);
            character |= (g_bits[i] << (7 - i));  
            
        }

     
        printf("Serveur a reçu le caractère : %c\n", character);

       
        g_bit_count = 0;
    }
}

int main() {
    pid_t server_pid = getpid();

    printf("Serveur en cours d'exécution (PID: %d)\n", server_pid);

   
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    
    while (1) {
        pause(); 
    }

    return 0;
}
