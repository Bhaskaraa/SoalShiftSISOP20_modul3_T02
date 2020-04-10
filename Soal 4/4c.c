#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int fd1[2]; //membuat dua ujung pipe
    pid_t p;

    //Kondisi jika pipe gagal
    if (pipe(fd1)==-1){
        exit(1);
    }

    p = fork();
    //Kondisi jika proses anak gagal
    if (p < 0){
        exit(EXIT_FAILURE);
    }

    else if (p > 0){
        //selesai menulis
        close(1);
        //menulis
        dup(fd1[1]);
        //selesai membaca
        close(fd1[0]);
        execlp("ls","ls",NULL);
    }
    else{
        //close reading
        close(0);
        //membaca
        dup(fd1[0]);
        //selesai menulis
        close(fd1[1]);
        execlp("wc","wc", "-l", NULL);
    }
}
