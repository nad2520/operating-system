#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Handler qui n'effectue aucune action (ignore tous les signaux)
void ignore_signal(int sig) {
    // Ne rien faire, juste ignorer le signal
}

int main() {
    // Ignorer tous les signaux possibles
    for (int i = 1; i < NSIG; i++) {
        signal(i, ignore_signal);
    }

    printf("Tous les signaux sont ignorés. PID : %d\n", getpid());
    printf("Le programme continue d'exécuter normalement, peu importe les signaux.\n");

    // Boucle infinie pour tester les signaux
    while (1) {
        printf("Le programme tourne sans interruption...\n");
        sleep(2);
    }

    return 0;
}
