#include <bits/stdc++.h>

using namespace std;

int particionar(vector<int>& vet, int esq, int dir);
void quicksort(vector<int>& v, int esq, int dir);
void troca(int* id1, int* id2);

int main(){
    int n;
    cin >> n;

    vector<int> bonecas(n);
    for(int i = 0; i < n; i++)
        cin >> bonecas[i];
/*
    for(int i : bonecas)
        cout << i << " ";
    cout << endl;
*/
    vector<int> bonecas_ord(n);
    for(int i = 0; i < n; i++){
        bonecas_ord[i] = bonecas[i];
    }

    quicksort(bonecas_ord, 0, n-1);
   
    vector<int> recolhidas;
    for(int i = 0; i < n; i++){
        if(bonecas_ord[i] != bonecas[i]){
            recolhidas.push_back(bonecas_ord[i]);
        }

    }

    cout << recolhidas.size() << endl;
    if(recolhidas.size() != 0){
        for(int i : recolhidas)
            cout << i << " ";
        cout << endl;
    }





}

void troca(int* id1, int* id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

int particionar(vector<int>& vet, int esq, int dir){
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

    return p;
}

void quicksort(vector<int>& v, int esq, int dir){
    if(esq <= dir){
        int p = particionar(v, esq, dir);
        quicksort(v, esq, p - 1);
        quicksort(v, p + 1, dir);

    }
}
