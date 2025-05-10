#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    // Ignorer le signal SIGINT (Ctrl+C)
    signal(SIGINT, SIG_IGN);

    printf("SIGINT (Ctrl+C) est ignoré. Appuyez sur Ctrl+C : rien ne se passe.\n");

    // Boucle infinie pour tester le comportement
    while (1) {
        printf("Le programme tourne toujours...\n");
        sleep(1);
    }

    return 0;
}
