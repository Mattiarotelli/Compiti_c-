#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid_f1, pid_f2;
    pid_t pid_g1, pid_h1, pid_g2, pid_h2;
    int status;

    // Creazione del processo figlio F1

    cout<<"sono il processo figlio F1 e proverò a creare G1 e H1"<<endl;

    pid_f1 = fork();
    if (pid_f1 == -1) {
        cerr << "Errore nella creazione del processo figlio F1" << endl;
        exit(1);
    } else if (pid_f1 == 0) {
        // Codice del processo figlio F1
        // Creazione del processo figlio G1
        pid_g1 = fork();
        if (pid_g1 == -1) {
            cerr << "Errore nella creazione del processo figlio G1" << endl;
            exit(1);
        } else if (pid_g1 == 0) {
            // Codice del processo figlio G1
            cout << "Sono il processo G1" << endl;
            exit(0);
        } else {
            // Codice del processo padre F1
            // Attende la terminazione di G1
            waitpid(pid_g1, &status, 0);
            // Creazione del processo figlio H1
            pid_h1 = fork();
            if (pid_h1 == -1) {
                cerr << "Errore nella creazione del processo figlio H1" << endl;
                exit(1);
            } else if (pid_h1 == 0) {
                // Codice del processo figlio H1
                cout << "Sono il processo H1" << endl;
                exit(0);
            } else {
                // Codice del processo padre F1
                // Attende la terminazione di H1
                waitpid(pid_h1, &status, 0);
                exit(0);
            }
        }
    } else {
        // Codice del processo padre P
        // Creazione del processo figlio F2
        pid_f2 = fork();

        cout<<"sono il processo figlio F2 e proverò a creare G2 e H2"<<endl;

        if (pid_f2 == -1) {
            cerr << "Errore nella creazione del processo figlio F2" << endl;
            exit(1);
        } else if (pid_f2 == 0) {
            // Codice del processo figlio F2
            // Creazione del processo figlio G2
            pid_g2 = fork();
            if (pid_g2 == -1) {
                cerr << "Errore nella creazione del processo figlio G2" << endl;
                exit(1);
            } else if (pid_g2 == 0) {
                // Codice del processo figlio G2
                cout << "Sono il processo G2" << endl;
                exit(0);
            } else {
                // Codice del processo padre F2
                // Attende la terminazione di G2
                waitpid(pid_g2, &status, 0);
                // Creazione del processo figlio H2
                pid_h2 = fork();
                if (pid_h2 == -1) {
                    cerr << "Errore nella creazione del processo figlio H2" << endl;
                    exit(1);
                } else if (pid_h2 == 0) {
                    // Codice del processo figlio H2
                    cout << "Sono il processo H2" << endl;
                    exit(0);
                } else {
                    // Codice del processo padre F2
                    // Attende la terminazione di H2
                    waitpid(pid_h2, &status, 0);
                    exit(0);
                }
            }
        } else {
            // Codice del processo padre P
            // Attende la terminazione di F2
            waitpid(pid_f2, &status, 0);
            // Attende la terminazione di F1
            waitpid(pid_f1, &status, 0);
        }
    }

    return 0;
}
