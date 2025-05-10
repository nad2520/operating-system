#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Handler pour le signal SIGCHLD
void handle_sigchld(int sig) {
    printf("📢 Signal SIGCHLD reçu : le processus fils s'est terminé.\n");

    // Nettoyer le processus zombie
    int status;
    wait(&status);

    if (WIFEXITED(status)) {
        printf("✅ Le fils s'est terminé avec le code %d.\n", WEXITSTATUS(status));
    } else {
        printf("⚠️ Le fils ne s'est pas terminé normalement.\n");
    }
}

int main() {
    // Associer le signal SIGCHLD à notre handler
    signal(SIGCHLD, handle_sigchld);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Erreur lors du fork");
        return 1;
    } else if (pid == 0) {
        // Code du processus fils
        printf("👶 Fils (PID = %d) en cours...\n", getpid());
        sleep(2); // Simulation d'un travail
        printf("👶 Fils (PID = %d) terminé.\n", getpid());
        exit(42); // Quitter avec un code de retour arbitraire
    } else {
        // Code du parent
        printf("👨 Parent (PID = %d) attend le signal SIGCHLD...\n", getpid());

        // Boucle pour laisser le temps au fils de se terminer
        for (;;) {
            pause(); // Attend un signal
        }
    }

    return 0;
}
