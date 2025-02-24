#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler_SIGUSR1(int sig) {
    printf("Reçu SIGUSR1 (bit 0)\n");
}

void handler_SIGUSR2(int sig) {
    printf("Reçu SIGUSR2 (bit 1)\n");
}

int main() {
    signal(SIGUSR1, handler_SIGUSR1);
    signal(SIGUSR2, handler_SIGUSR2);

    printf("Processus prêt à recevoir des signaux...\n");

    while(1) {
        pause(); // Attendre un signal
    }

    return 0;
}
