#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    //creazione del processo figlio
    pid_t pidFiglio = fork();

    //gestione in caso di errore
    if(pidFiglio == -1){
        cout<<"Errore nella creazione della fork"<<endl;
        return 1;
    }else if(pidFiglio == 0){
        //inizio del codice per il processo figlio

        //apertura del file scrittura
        ofstream fileScrittura("file.txt");
        if(!fileScrittura.is_open()){
            cout<<"il file non è stato aperto correttamente"<<endl;
            return 1;
        }

        //scrittura nel processo figlio
        fileScrittura << "Buon lavoro, dal processo figlio"<< endl;

        //chiusura file.txt
        fileScrittura.close();

        //uscita dal process figlio
        exit(0);
    } else {
        //codice processo padre

        //attesa terminazione processo
        int status;
        waitpid(pidFiglio, &status, 0);

        //apertura file lettura
        ifstream fileLettura("output.txt");
        if (!fileLettura.is_open()) {
            cerr << "Errore nell'apertura del file." << endl;
            return 1;
        }

        //lettura del contenuto di file.txt
        string line;
        while (getline(fileLettura, line)){
            cout << line << endl;
        }

        //chiusura file.txt
        fileLettura.close();
    }
    return 0;
}
