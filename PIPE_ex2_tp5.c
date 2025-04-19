#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd1[2], fd2[2];
    pipe(fd1),pipe(fd2);
    
    if (fork()==0){
        close (fd1[1]);
        char buffer [100];
        read(fd1[0],buffer,sizeof(buffer));
        printf("fis 1 a lu : %s\n",buffer);
        close(fd1[0]);
    }else{
        close(fd1[0]);
        char *msg="bonjour 1 du parent";
        write(fd1[1],msg,strlen(msg)+1);
            close(fd1[1]);
            
    }
    pid_t p2=fork();
    if (p2==0){ close (fd2[1]);
        char buffer [100];
        read(fd2[0],buffer,sizeof(buffer));
        printf("fis 2 a lu : %s\n",buffer);
        close(fd2[0]);}
    else{
        close(fd2[0]);
        char *msg2="bonjour 2 du parent";
        write(fd2[1],msg2,strlen(msg2)+1);
        close(fd2[1]);

    }
    return 0;
}
    

