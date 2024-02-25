#include <iostream>
#include <libc.h>
using namespace std;

int main(){
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    pid2 = fork();
    pid3 = fork();
    if( pid1 == 0 || pid2 == 0 || pid3 == 0 ){
        cout<<"Sono il processo figlio e il mio pid "<<getpid()<<"";
        cout<<" mio padre ha il pid "<<getppid()<<endl;
        sleep(1);
        exit(0);
    }else{
        sleep(2);
        cout<<"Sono il processo padre con pid "<<getpid();
    }
    return 0;
}