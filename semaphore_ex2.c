#include <stdio.h>
#include<semaphore.h>
#include <unistd.h>
#include<sys/wait.h>

int main(){
    int x=2;
    sem_t s;
    sem_init(&s,0,1);
    pid_t pid=fork();
    if (pid==0){
        sem_wait(&s);
        printf("je suis le fils\n");
        int p=2*x;
        printf("%d\t",p);
        sem_post(&s);
    }
    else{
        sem_wait(&s);
        printf("je suis le père\n");
        int p=3*x;
        printf("%d",p);
        sem_post(&s);
        sem_post(&s);
    }
    wait(NULL);
    return 0;
}
