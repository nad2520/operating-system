#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID du programme : %d\n", getpid());
    printf("Boucle infinie en cours... Utilisez 'kill -KILL %d' pour l'arrêter.\n", getpid());

    while (1) {
        printf("Je tourne toujours...\n");
        sleep(1);
    }

    return 0;
}
