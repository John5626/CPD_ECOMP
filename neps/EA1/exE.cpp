#include <iostream>

#define N_SECRETO 2018

using namespace std;

int main(){
    int tentativas = 0;
    int chute;

    bool acertou = false;

    while(!acertou){
        cin >> chute;

        if(chute == N_SECRETO)
            acertou = true;
        
        else tentativas++;
        
    }

    cout << tentativas << endl;
}