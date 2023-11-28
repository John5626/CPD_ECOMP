//ALGORITMOS DE ORDENAÇÃO - JOAO VICTOR SOUZA - ECOMP
#include <bits/stdc++.h>

using namespace std;

/*Função de troca
Entrada: indices do vetor para troca
Saída: não tem*/
void troca(int *id1, int *id2);

/*Ordenação por Inserção
Entrada: vector e seu tamanho
Saída: não tem*/
void ord_insercao(vector<int>& vet, int n);

/*Ordenação por Seleção
Entrada: vector e seu tamanho
Saída: não tem*/
void ord_selecao(vector<int>& vet, int n);

/*Ordenação por Flutuação
Entrada: vector e seu tamanho
Saída: não tem*/
void ord_flutuacao(vector<int>& vet, int n);

/*Max Heapify
Entrada: vector, tamanho, índice do pai
Saída: não tem*/
static void max_heapify(vector<int>& vet, int n, int id_pai);

/*Ordenação Heapsort
Entrada: vector, tamanho
Saída: não tem*/
void heapsort(vector<int>& vet, int n);


void troca(int *id1, int *id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

void ord_insercao(vector<int>& vet, int n){
    for(int i = 1; i < n; i++){
        int c = vet[i];
        
        int j = i - 1;
        while(j >= 0 && vet[j] > c){
            vet[j+1] = vet[j];

            j--;
        }
        vet[j+1] = c;
    }
}

void ord_selecao(vector<int>& vet, int n){
    for(int i = 0; i < n - 1; i++){
        int id_menor = i;

        for (int j = i + 1; j < n; j++){
            if(vet[j] < vet[id_menor]){
                id_menor = j;
            }
        }

        
        troca(&vet[i], &vet[id_menor]);
        
    }
}

void ord_flutuacao(vector<int>& vet, int n){
    bool trocou = true;
    while(trocou){
        trocou = false;
        for(int i = 1; i < n; i++){
            if(vet[i] < vet[i-1]){
                troca(&vet[i], &vet[i-1]);
                trocou = true;
            }
        }
    }

}

static void max_heapify(vector<int>& vet, int n, int id_pai){
    int id_fesq = 2 * id_pai + 1;
    int id_fdir = 2 * id_pai + 2;

    int maior = id_pai;

    if(id_fesq < n && vet[id_fesq] > vet[maior]){
        maior = id_fesq;
    }

    if(id_fdir < n && vet[id_fdir] > vet[maior]){
        maior = id_fdir;
    }

    if(maior != id_pai){
        troca(&vet[id_pai], &vet[maior]);
        max_heapify(vet, n, maior);
    }
}

void heapsort(vector<int>& vet, int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        max_heapify(vet, n, i);
    }

    //Extrair elementos
    for(int i = n - 1; i >= 0; i--){
        troca(&vet[0], &vet[i]);
        max_heapify(vet, i, 0);
    }
}