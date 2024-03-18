#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Errore: numero di argomenti non valido." << endl;
        cout << "Uso: " << argv[0] << " <flag> <#_figli> <#_nipoti>" << endl;
        exit(1);
    }

    int flag = atoi(argv[1]);
    int n_figli = atoi(argv[2]);
    int n_nipoti = atoi(argv[3]);

    pid_t pid_figli[n_figli];
    for (int i = 0; i < n_figli; i++) {
        pid_figli[i] = fork();
        if (pid_figli[i] == -1) {
            perror("Errore nella creazione del figlio");
            exit(1);
        }

        if (pid_figli[i] == 0) {
            for (int j = 0; j < n_nipoti; j++) {
                pid_t pid_nipote = fork();
                if (pid_nipote == -1) {
                    perror("Errore nella creazione del nipote");
                    exit(1);
                }

                if (pid_nipote == 0) {
                    cout << "Sono un nipote (pid: " << getpid() << ") del figlio " << getppid() << endl;
                    exit(0);
                }

                wait(NULL);
            }

            exit(0);
        }
    }

    if (flag == 0) {
        for (int i = 0; i < n_figli; i++) {
            wait(NULL);
        }
    } else if (flag == 1) {
        for (int i = 0; i < n_figli; i++) {
            int status;
            wait(&status);
            if (WIFEXITED(status)) {
                cout << "Figlio " << pid_figli[i] << " terminato con successo (codice: " << WEXITSTATUS(status) << ")" << endl;
            } else {
                cout << "Figlio " << pid_figli[i] << " terminato in modo anomalo (segnale: " << WTERMSIG(status) << ")" << endl;
            }
        }
    }

    return 0;
}
