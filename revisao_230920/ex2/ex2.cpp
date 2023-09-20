#include <bits/stdc++.h>
#include "color.h"

using namespace std;

const int TAM = 50;

int main() {
    srand(time(NULL));
    int hist[TAM+1] = {0};
    int maximo = -1;

    for(int i = 1; i <= 400; i++) {
        int v = 1 + rand()%TAM;
        hist[v]++;
    }
    cout << endl;

    //encontrar quantidade de linhas
    int quant_linhas = 0;
    for(int i = 1; i < TAM+1; i++){
        if(hist[i] > quant_linhas)
            quant_linhas = hist[i];
    }

   //cout << quant_linhas;
    
    //Imprimir vertical
    cout << endl;
    for(int i = quant_linhas; i >= 1; i--){
        for(int j = 1; j <= TAM; j++){
            if(hist[j] >= i){ //imprimir pintados
                if(j%10 == 1 && i == 1)
                cout << RED << '\xDB' << RESET;
                else
                    cout << '\xDB';
            }
            else cout << ' '; //deixar em branco
        }
        cout << endl;
    }

/*
    for(int i = 1; i <= TAM; i++) {
        for(int j = 1; j <= hist[i]; j++) {
            if(i%10 == 1 && j == 1)
                cout << RED << '\xDB' << RESET;
            else
                cout << '\xDB';
        }
        cout << endl;
    }
*/
    return 0;
}