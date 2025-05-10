#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Handler pour SIGTERM
void handle_sigterm(int sig) {
    printf("\n🧹 Signal SIGTERM reçu. Nettoyage en cours...\n");

    // Simuler un nettoyage (fermer fichiers, libérer mémoire, etc.)
    // Par exemple :
    printf("🔒 Fermeture des fichiers...\n");
    printf("🗑 Libération de la mémoire...\n");
    printf("✅ Nettoyage terminé. Fin du programme.\n");

    exit(0); // Quitter proprement
}

int main() {
    // Associer SIGTERM au handler personnalisé
    signal(SIGTERM, handle_sigterm);

    printf("PID du programme : %d\n", getpid());
    printf("Envoie SIGTERM avec : kill -TERM %d\n", getpid());

    // Boucle infinie pour laisser le programme tourner
    while (1) {
        printf("Le programme tourne... (Ctrl+C ne fait rien ici)\n");
        sleep(2);
    }

    return 0;
}
