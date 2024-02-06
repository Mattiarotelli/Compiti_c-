#include <iostream>
#include <string>
#include <libc.h>

int main( ){
    int pid, x=12, y=23;
    pid = fork();
    if(pid == getppid()){
        std::cout<<"sono la processo figlia, il mio numero è "<<getpid()<<"";

    }else{
        std::cout<<"sono il processo padre, il mio pid è "<<getppid()<<" ";
    }
}