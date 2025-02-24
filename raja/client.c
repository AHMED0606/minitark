#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void send_bit(pid_t server_pid, char c) {
    for (int i = 7; i >= 0; i--) {
        
        int bit = (c >> i) & 1;

        printf("||%d||\n",bit);
        if (bit == 0) {

            kill(server_pid, SIGUSR1);  // Bit '0' -> SIGUSR1
        } else {
            kill(server_pid, SIGUSR2);  // Bit '1' -> SIGUSR2
        }

        usleep(100);  
    }
}

int main() {
    pid_t server_pid;
    char message[100];

   
    printf("Entrez le PID du serveur : ");
    scanf("%d", &server_pid);

    
    printf("Entrez le message à envoyer au serveur : ");
    scanf("%s", message);

  
    for (int i = 0; message[i] != '\0'; i++) {
        send_bit(server_pid, message[i]);
    }

    return 0;
}

