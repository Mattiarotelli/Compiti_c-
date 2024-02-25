#include <iostream>
#include <libc.h>

int main(){
    int pid;
    pid = fork();
    if(pid == getppid()){
        std::cout<<"sono il processo padre, il mio numero è "<<getppid()<<"";

    }else{
        std::cout<<"sono il processo figlio, il mio pid è "<<getpid()<<" ";
    }
}
