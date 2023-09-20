#include <bits/stdc++.h>
#include <chrono>
#include "ex2/color.h"

#define N 100000
#define MIN 0
#define MAX 100
#define BREAK 10010

using namespace std;
using namespace std :: chrono;

//VARIAVEL GLOBAL
vector<int> pivo_def; //armazena pivos definitivos


void troca(int *id1, int *id2);
int particiona(vector<int>& v, int ini, int fim);
void quicksort(vector<int>& v, int n, int en); //'en' apenas para exibir ou nao o passo-a-passo
void preencher(vector<int>& v, int n, int min, int max);
void exibir(vector<int> v, int n, int p);
bool ordenado(vector<int> v, int n);
void reverte(vector<int>& v, vector<int> copy);

int main(int argc, char* argv[]){
    cout << "Informe a execucao requerida:\n(1) Estimar a complexidade\t(2) Execucao do algoritmo  ";
    int op; cin >> op; 
    if(op == 1){
    
        vector<int> v;
        preencher(v, N, MIN, MAX);

        vector<int> copy;
        for(int i = 0; i < N; i++){
            copy.push_back(v[i]);
        }

        ofstream quick;
        quick.open("dados/quicksort.dat");
        if(!quick.is_open()){
            exit(0);
        }

        cout << "Calculando...\n";
        for(int i = 10; i <= N; i += 500){
            auto ini = high_resolution_clock :: now();
            quicksort(v, i, 0);
            auto fim = high_resolution_clock :: now();
                
            duration<double> t = fim - ini;
            quick << i << " " << duration_cast<microseconds>(t).count() << "\n"; //<< "us\n";
                
            if(ordenado(v, i) && i == BREAK){
                cout << "Ordenacao QUICKSORT concluida com sucesso.\n";
            }
            reverte(v, copy); 
                
        }
        quick.close();
    }
    if(op == 2){
        vector<int> v;
        int tam = 40;
        preencher(v, tam, MIN, MAX);

        exibir(v, tam, -1);
        quicksort(v, tam, 1);



    }
            
    
}

void troca(int *id1, int *id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

int particiona(vector<int>& v, int ini, int fim){
    int pivo = ini;
    
    int pos, atual;
    pos = atual = pivo + 1;

    while(atual <= fim){
        if(v[atual] < v[pivo]){
            troca(&v[atual], &v[pos]);
            pos++;
        }
        atual++;
    }

    
    troca(&v[pivo], &v[pos-1]);
    pivo = pos - 1;
    
    pivo_def.push_back(pivo);
    return pivo;
}

void quicksort(vector<int>& v, int n, int en){
    stack<int> pilha;
    int ini = 0;
    int fim = n - 1;

    pilha.push(ini);
    pilha.push(fim);

    while(!pilha.empty()){
        fim = pilha.top(); pilha.pop();
        ini = pilha.top(); pilha.pop();

        int p = particiona(v, ini, fim);
        
        //Exibir passo-a-passo
        if(en)
            exibir(v, v.size(), p);

        if(p-1 > ini){
            pilha.push(ini);
            pilha.push(p-1);
        }
        if(p+1 < fim){
            pilha.push(p+1);
            pilha.push(fim);
        }
    }
}

void preencher(vector<int>& v, int n, int min, int max){
    for(int i = 0; i < n; i++){
        int valor = rand() % (max - min) + min;
        v.push_back(valor);
    }
}


void exibir(vector<int> v, int n, int p){
    for(int i = 0; i < n; i++){
        bool eh_pivo = false;
        for(int j = 0; j < pivo_def.size(); j++){
            if(i == pivo_def[j]){
                eh_pivo = true; //Compara se i é já é definitivo
                break;
            }
        }
        if(eh_pivo || i == p)
            cout << RED << v[i] << RESET << " ";
        else cout << v[i] << " ";
    }
    cout << endl;
    
}

bool ordenado(vector<int> v, int n){
    for(int i = 1; i < n; i++){
        if(v[i-1] > v[i]){
            return false;
        }
    }
    return true;
}

void reverte(vector<int>& v, vector<int> copy){
    for(int i = 0; i < copy.size(); i++){
        v[i] = copy[i];
    }
}