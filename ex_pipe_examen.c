#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2];
    
    pid_t pid1, pid2;
    pid1 = fork();
    
    if (pid1 == 0) {
        // ========== FILS 1 ==========
        close(pipe_fd[1]); // il va lire le PID du fils 2

        pid_t parent_pid = getppid();
        pid_t my_pid = getpid();
        pid_t brother_pid;

        // lire le PID du frère depuis la pipe
        read(pipe_fd[0], &brother_pid, sizeof(brother_pid));

        printf("FILS 1 : mon PID = %d, PID père = %d, PID frère = %d\n",
               my_pid, parent_pid, brother_pid);

        close(pipe_fd[0]);
        return 0;
    }
    pid2 = fork();
    
    if (pid2 == 0) {
        // ========== FILS 2 ==========
        close(pipe_fd[0]); // il va écrire son PID

        pid_t parent_pid = getppid();
        pid_t my_pid = getpid();
        pid_t brother_pid = pid1; // hérite du PID du frère (transmis par le parent)

        // écrire son propre PID dans la pipe pour le frère
        write(pipe_fd[1], &my_pid, sizeof(my_pid));

        printf("FILS 2 : mon PID = %d, PID père = %d, PID frère = %d\n",
               my_pid, parent_pid, brother_pid);

        close(pipe_fd[1]);
        return 0;
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    pid_t parent_pid = getpid();
    printf("PARENT : mon PID = %d, PID fils1 = %d, PID fils2 = %d\n",
           parent_pid, pid1, pid2);

    // attendre les deux fils pour une terminaison propre
    wait(NULL);
    wait(NULL);

    return 0;
}

