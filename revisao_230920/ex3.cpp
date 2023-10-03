#include <bits/stdc++.h>
#include <chrono>
#include "headers/color.h"

#define N 10050
#define MIN 1
#define MAX 1000
#define BREAK 10010

using namespace std;
using namespace std::chrono;

//VARIAVEL GLOBAL
vector<int> pivo_def; //armazena pivos definitivos

void troca(int *id1, int *id2);
int particiona(vector<int>& vet, int esq, int dir);
void quicksort(vector<int>& v, int n, int en); //'en' apenas para exibir ou nao o passo-a-passo
void preencher(vector<int>& v, int n, int min, int max);
void exibir(vector<int> v, int n, int p);
bool ordenado(vector<int> v, int n);
void reverter(vector<int>& vet, vector<int> copy);

int main(){
    cout << "Informe a execucao requerida:\n(1) Estimar a complexidade\t(2) Execucao do algoritmo  ";
    int op; cin >> op; 
    if(op == 1){
        srand(time(NULL));

        int tam = 10050;
        vector<int> vet(tam);


        vector<int> copy(tam);
        for(int i = 0; i < tam; i++){
            copy[i] = vet[i];
        }
        preencher(vet, tam, 1, 1000);

        ofstream qsrt;
        qsrt.open("dados/quicksort.dat");
        if(!qsrt.is_open()){
            exit(1);
        }

        for(int i = 10; i < N; i+=500){

            auto ini = high_resolution_clock::now();
            quicksort(vet, i, 0);
            auto fim = high_resolution_clock::now();

            duration<double> t = fim - ini;

            qsrt << i << " " << duration_cast<microseconds>(t).count() << endl;
            reverter(vet, copy);

        }
        qsrt.close();

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

int particiona(vector<int>& vet, int esq, int dir){
    int p, pos, atual;
    p = esq;
    pos = atual = p + 1;
    while(atual <= dir){
        if(vet[atual] < vet[p]){
            troca(&vet[atual], &vet[pos]);
            pos++;
        }
        atual++;
    }

    troca(&vet[p], &vet[pos-1]);
    p = pos-1;

    pivo_def.push_back(p); //Adicionar posição definitiva

    return p;
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

void reverter(vector<int>& vet, vector<int> copy){
    for(int i = 0; i < vet.size(); i++){
        vet[i] = copy[i];
    }
}