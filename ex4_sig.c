#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Handler de signaux personnalisés
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("🔔 Signal SIGUSR1 reçu : Action spéciale 1\n");
    } else if (sig == SIGUSR2) {
        printf("🔔 Signal SIGUSR2 reçu : Action spéciale 2\n");
    }
}

int main() {
    // Associer les signaux à la fonction handler
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    printf("PID du programme : %d\n", getpid());
    printf("Envoie un signal avec : kill -USR1 %d ou kill -USR2 %d\n", getpid(), getpid());

    // Boucle infinie en attente de signaux
    while (1) {
        pause(); // Attend un signal
    }

    return 0;
}
