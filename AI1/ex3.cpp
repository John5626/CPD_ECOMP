//JOAO VICTOR SOUZA - ECOMP

#include <chrono>
#include "headers/funcoes_aux.h"
#include "headers/color.h"

using namespace std;
using namespace std::chrono;

vector<int> pivo_def; //Vector para armazenar as posições definitivas dos pivôs

void exibe(vector<int> v, int ini, int fim, int p); //PARTE B
int ordenacao(vector<int>& vet, int esq, int dir);
void quicksort(vector<int>& v, int n); //PARTE A

int main(){
    srand(time(NULL));

    int tam = 50;
    vector<int> vet(tam);


    vector<int> copy(tam);
    for(int i = 0; i < tam; i++){
        copy[i] = vet[i];
    }

    preencher(vet, tam, 4, 50);

    exibe(vet, 0, tam, -1);
    
    quicksort(vet, tam);

    if(ordenado(vet, tam))
        cout << "Vetor Ordenado" << endl;

//PARTE A
/*
    ofstream qsrt;
    qsrt.open("dados/quicksort.dat");
    if(!qsrt.is_open()){
        exit(1);
    }

    for(int i = 10; i < tam; i+=500){

        auto ini = high_resolution_clock::now();
        quicksort(vet, i);
        auto fim = high_resolution_clock::now();

        duration<double> t = fim - ini;

        qsrt << i << " " << duration_cast<microseconds>(t).count() << endl;
        reverter(vet, copy);

    }
    qsrt.close();
*/
    
}

void exibe(vector<int> v, int ini, int fim, int p){
    for(int i = ini; i < fim; i++){
        bool eh_pivo = false;
        for(int j = 0; j < pivo_def.size(); j++){
            if(i == pivo_def[j]){
                eh_pivo = true; //Compara se i é já é definitivo
                break;
            }
        }

        if(i == p || eh_pivo)
            cout << RED << v[i] << RESET << " ";
        else
            cout << v[i] << " ";
    }
    cout << endl;
}

int ordenacao(vector<int>& vet, int esq, int dir){
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

void quicksort(vector<int>& v, int n){
    stack<int> pilha;
    int esq = 0, dir = n-1;
    pilha.push(esq);
    pilha.push(dir);

    int p = 0;
    while(!pilha.empty()){
        dir = pilha.top(); pilha.pop();
        esq = pilha.top(); pilha.pop();

        p = ordenacao(v, esq, dir);
        exibe(v, 0, v.size(), p);

        if(p - 1 > esq){
            pilha.push(esq);
            pilha.push(p-1);
        }
        if(p+1 < dir){
            pilha.push(p+1);
            pilha.push(dir);
        }
    }
}
