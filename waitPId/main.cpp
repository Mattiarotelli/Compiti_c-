#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid;
    int status;
    string frase;
    pid = fork();
    if (pid == -1) {
        perror("Errore nella creazione del processo figlio");
        exit(1);
    }
    if (pid == 0) {
        ofstream fileScrittura("file.txt");
        if (!fileScrittura.is_open()) {
            perror("Errore nell'apertura del file");
            exit(1);
        }

        cout << "Inserisci la frase"<<endl;
        getline(cin, frase);
        fileScrittura << frase << endl;
        fileScrittura.close();
        exit(0);
    }
    else {
        waitpid(pid, &status, 0);
        ifstream fileLettura("file.txt");
        if (!fileLettura.is_open()) {
            perror("Errore nell'apertura del file");
            exit(1);
        }
        getline(fileLettura, frase);
        fileLettura.close();
        cout << "La frase scritta nel file è: " << frase << endl;
    }

    return 0;
}
