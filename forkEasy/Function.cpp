#include <iostream>
#include <unistd.h>



void static CreateSon(){
    pid_t pid = fork();
    if(pid < 0){
        std::cout<<"Fork fallita"<<std::endl;
        exit(0);
    } else if(pid != getppid()){
        std::cout<<"Sono il processo figlio! La mia pid è:"<<pid<<std::endl;
        exit(0);
    }else{
        std::cout<<"Sono il processo padre! Il mio pid è:"<<getppid();
    }
}
int main(){
    CreateSon();
    return 0;
}
