#include <stdio.h>
#include<semaphore.h>
#include <unistd.h>
#include<sys/wait.h>

int main(){
    sem_t s;
    sem_init(&s,0,1);
    pid_t pid=fork();
    if (pid==0){
        sem_wait(&s);
        printf("je suis le fils\n");
        sem_post(&s);
    }
    else{
        sem_wait(&s);
        printf("je suis le père\n");
        sem_post(&s);
    }
    wait(NULL);
    return 0;
}
