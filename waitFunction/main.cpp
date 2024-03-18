#include <iostream>
#include <libc.h>
#include <sys/wait.h>
using namespace std;

int main(){
    pid_t pid, pid1, pid2;
    int status, x;
    pid1 = fork();
    if(pid1 == 0){
        x = 6;
        cout<<"Sono il primo processo figlio con pid: "<<getpid()<<", e dorme per "<<x<<" sec"<<endl;
        sleep(x);
        exit(1);
    }else{
        pid2= fork();
        if(pid2 == 0){
            x = 4;
            cout<<"Sono il secondo processo figlio con pid: "<<getpid()<<", e dorme per "<<x<<" sec"<<endl;
            sleep(x);
            exit(2);
        }else{
            cout<<"Il padre è in attesa della terminazione del figlio..."<<endl;
            pid = wait(&status);
            cout<<"Il primo processo terminato ha pid: "<<pid;

        }
    }
}
