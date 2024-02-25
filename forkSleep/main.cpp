#include <iostream>
#include <libc.h>
using namespace std;

void showPid(int x, pid_t y, pid_t z){
    cout<<"Sono il processo figlio numero "<<x<<" con il pid "<<y<<" e mio padre ha pid "<<z<<endl;
    sleep(1);       //simula un carico di lavoro
}

int main(){
    int nProc = 5;
    pid_t parentPid = getpid();    //pid del processo padre

    for(int i = 1; i <= nProc; i++){      //Creazione dei processi
        pid_t sonPid = fork();
        if (sonPid == -1){
            cout<<"creazione fallita"<<endl;
        } else if (sonPid == 0){
            showPid(i, getpid(), parentPid);
            exit(0);
        } else{
            wait(NULL);     // Attesa del completamento del processo figlio prima di creare il successivo
        }
    }

    cout<<"Sono il processo padre con pid "<<parentPid;

    return 0;
}