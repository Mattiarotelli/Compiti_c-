#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(){
    pid_t pidX, pidY;
    int x, y, z, status;
    if((pidX=fork())==-1){
        cout<<"fork non riuscita"<<endl;
    }else{
        if(pidX == 0){
            cout<<"aperta fork x"<<endl;
            x = 5* ((2 + 4 ) * (7 + 3 )) - 10;
            cout<<"chiusa fork x"<<endl;
            exit(0);
        }else{
            if((pidY=fork())==-1){
                cout<<"fork non riuscita"<<endl;
            }else{
                waitpid(pidX, &status, 0 );
                if(pidY == 0){
                    cout<<"aperta fork y"<<endl;
                    y = (3+2)*(5-2)+(8-3);
                    cout<<"chiusa fork y"<<endl;
                    exit(0);
                } else{
                    waitpid(pidY, &status, 0 );
                    cout<<"aperta fork z"<<endl;
                    z = (2+x)*(3+y)*(7*z+4)-10;
                    cout<<"il ris finale è "<<z<<endl;
                    cout<<"chiusa fork z"<<endl;
                    exit(0);


                }
            }
        }
    }
}
