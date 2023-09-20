#include <bits/stdc++.h>
#include "ordenacao.h"

/*troca o conteúdo dos valores armazenados em duas
variáveis ou em duas posições de um vetor*/
static void troca(int *id1, int *id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

void ord_selec(vector<int>& v, int n){
    for(int i = 0; i < n-1; i++){
        int id_menor = i;
        for(int j = i+1; j < n; j++){
            if(v[id_menor] > v[j])
                id_menor = j;
        }

        troca(&v[id_menor], &v[i]);
        
    }
}

void ord_ins(vector<int>& v, int n){
    for(int i = 1; i < n; i++){
        int chave = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > chave){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;

    }
            
}

void ord_flut(vector<int>& v, int n){
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(v[j-1] > v[i]){
                troca(&v[j-1], &v[i]);
            }
        }   
    }
}

//Mantem as caracteristicas do heap
static void heapify(vector<int>& v, int n, int id_pai){
    int f_esq = 2 * id_pai + 1;
    int f_dir = 2 * id_pai + 2;
    int id = id_pai;

    if(f_esq < n && v[f_esq] > v[id]){
        id = f_esq;
    }
    if(f_dir < n && v[f_dir] > v[id]){
        id = f_dir;
    }

    if(id != id_pai){
        troca(&v[id_pai], &v[id]);
        heapify(v, n, id);
    }

}

void heapsort(vector<int>& v, int n){
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(v, n, i); //Leva n e compara com os filhos
    }
/*
    for(int i = 0; i < n; i++){
        cout << v[i] << " "; 
    }
    cout << endl;
*/

    for(int i = n - 1; i >= 0; i--){
        troca(&v[0], &v[i]); //inverter o vet
        heapify(v, i, 0); // compara novamente
    }
}



