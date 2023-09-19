//JOAO VICTOR SOUZA - ECOMP
#include <bits/stdc++.h>
#include "headers/color.h"

using namespace std;

const int TAM = 50;

int main(){
    srand(time(NULL));

    int hist[TAM+1] = {0};
    int maximo = -1;

    for(int i = 1; i <= 400; i++) {
        int v = 1 + rand()%TAM;
        hist[v]++;
    }
    cout << endl;
    cout << endl;

    int max_linhas = 0; // Saber o maximo de linhas necessarias
    for(int i = 0; i < TAM; i++){
        if(hist[i] > max_linhas){
            max_linhas = hist[i];
        }
    }

    for(int i = max_linhas; i >= 1; i--){
        for(int j = 1; j <= TAM; j++){
            if(hist[j] >= i){ //verifica se será preenchido
                if(j % 10 == 1 && i ==1){
                    cout << RED << '\xDB' << RESET;
                } 
                else cout << '\xDB';
                
            }
            else cout << ' '; 
        }
        cout << endl; //pular linha para desenhar o proximo

    }
    cout << endl;


}