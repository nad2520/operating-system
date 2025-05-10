#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Fonction appelée lorsqu'on reçoit SIGUSR1
void handle_sigusr1(int sig) {
    printf("  Signal SIGUSR1 reçu ! Message spécial affiché.\n");
}

int main() {
    // Associer le signal SIGUSR1 au handler personnalisé
    signal(SIGUSR1, handle_sigusr1);

    printf("PID du programme : %d\n", getpid());
    printf("Envoie le signal SIGUSR1 avec : kill -USR1 %d\n", getpid());

    // Boucle infinie en attente de signal
    while (1) {
        pause(); // Attendre un signal
    }

    return 0;
}
