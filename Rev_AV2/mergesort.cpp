#include <bits/stdc++.h>

using namespace std;

vector<int> preencher(int tam, int min, int max);
void exibir(vector<int> v);
void merge(vector<int>& v, int esq, int meio, int dir);
void mergesort(vector<int>& v, int esq, int dir);

int main(){
    srand(time(NULL));

    vector<int> v = preencher(50, 0, 50);

    exibir(v);

    mergesort(v, 0, v.size() - 1);

    exibir(v);

}

vector<int> preencher(int tam, int min, int max){
    vector<int> v;
    for(int i = 0; i < tam; i++){
        v.push_back(rand() % (max - min) + 1);
    }

    return v;
}

void exibir(vector<int> v){
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

void merge(vector<int>& v, int esq, int meio, int dir){
    int tam1 = meio - esq + 1; // TAM Primeira metade
    int tam2 = dir - meio; // TAM Segunda metade

    vector<int> e(tam1), d(tam2);

    for(int i = 0; i < tam1; i++)
        e[i] = v[esq + i];

    for(int i = 0; i < tam2; i++)
        d[i] = v[meio + 1 + i];

    int i, j, k = esq;
    i = j = 0;

    // Unir de volta
    while(i < tam1 && j < tam2){
        if(e[i] <= d[j]){
            v[k] = e[i++];
        }
        else v[k] = d[j++];

        k++;
    }

    while(i < tam1)
        v[k++] = e[i++];
    
    while(j < tam2)
        v[k++] = d[j++];


}


void mergesort(vector<int>& v, int esq, int dir){
    if(esq < dir){
        int m = esq + (dir - esq) / 2;

        mergesort(v, esq, m);
        mergesort(v, m + 1, dir);
        merge(v, esq, m, dir);
    }
}