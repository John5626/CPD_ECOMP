//EXERCICIO 1  -  JOAO VICTOR SOUZA - ECOMP
#ifndef FUNCOES_AUX_H
#define FUNCOES_AUX_H

#include "alg_ordenacao.h"

/*preencher um vetor de n posições com números aleatórios em 
  uma dada faixa de valores [min, max]*/
void preencher(vector<int>& v, int n, int min, int max);

/*exibir o conteúdo de um vetor desde um índice
inicial até um índice final, passados como parâmetro*/
void exibir(vector<int> v, int ini, int fim);

/*Verificar se vetor está ordenado*/
bool ordenado(vector<int> v, int n);

/*Reverte o vetor para o preenchimento inicial*/
void reverter(vector<int>& vet, vector<int> copy);

void preencher(vector<int>& v, int n, int min, int max){
    for(int i = 0; i < n; i++){
        int aleatorio = rand() % (max - min) + min;
        v[i] = aleatorio;
    }
}

void exibir(vector<int> v, int ini, int fim){
    for(int i = ini; i < fim; i++)
        cout << v[i] << " ";
    cout << endl;
}

bool ordenado(vector<int> v, int n){
    for(int i = 1; i < n; i++){
        if(v[i-1] > v[i])
            return false;
    }
    return true;
}

void reverter(vector<int>& vet, vector<int> copy){
    for(int i = 0; i < vet.size(); i++){
        vet[i] = copy[i];
    }
}


#endif // FUNCOES_AUX_H
