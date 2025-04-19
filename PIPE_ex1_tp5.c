/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd[2];
    if (pipe(fd)==-1){
        perror("pipe");
        return 1;
        
    }
    if (fork()==0){
        close (fd[1]);
        char buffer [100];
        read(fd[0],buffer,sizeof(buffer));
        printf("fis a lu : %s\n",buffer);
        close(fd[0]);
    }else{
        close(fd[0]);
        char *msg="bonjour du parent";
        write(fd[1],msg,strlen(msg)+1);
        close(fd[1]);
    }
    return 0;
}
    

