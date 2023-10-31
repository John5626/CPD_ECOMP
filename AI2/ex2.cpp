#include <bits/stdc++.h>

using namespace std;

int trocas = 0;

//Unir dois vetores ordenados, gerando um terceiro vetor ordenado
void merge(vector<int> v1, vector<int> v2, int &trocas);
void merge(vector<int> &v, int e, int m, int d, int &trocas);
void mergesort(vector<int> &vet, int e, int d);

int main(){
    vector<int> vet;
    vector<string> ganhou;

    int n;
    while((cin >> n) && n != 0){
        trocas = 0;
        vet.clear();

        for(int i = 0; i < n; i++){
            int val;
            cin >> val;
            vet.push_back(val);
        }

        mergesort(vet, 0, vet.size()-1);

        if(trocas % 2 != 0)
            ganhou.push_back("Marcelo");
        else ganhou.push_back("Carlos");
    }

    for(auto i : ganhou){
        cout << i << endl;
    }

}

void mergesort(vector<int> &vet, int e, int d){
    if(e < d) {
        int m = e + (d-e)/2;
        mergesort(vet, e, m);
        mergesort(vet, m+1, d);
        merge(vet, e, m, d, trocas);
    }
}

void merge(vector<int> &v, int e, int m, int d, int &trocas){
    vector<int> aux;

    int i = e, j = m+1;
    while(i <= m && j <= d) {
        if(v[i] < v[j]){
            aux.push_back(v[i++]);
        }
        else{
            aux.push_back(v[j++]);
            trocas += m - i + 1;  //Atualiza o número de trocas
        }
    }

    while(i <= m){
        aux.push_back(v[i++]);
    }
    while(j <= d){
        aux.push_back(v[j++]);
    }

    for(int i = 0; i < aux.size(); i++){
        v[e+i] = aux[i];
    }
}

void merge(vector<int> v1, vector<int> v2, int &trocas){
    vector<int> aux;

    int i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            aux.push_back(v1[i++]);
        }
        else{
            aux.push_back(v2[j++]);
            trocas += v1.size() - i;  //Atualiza o número de trocas
        }
    }

    while(i < v1.size()){
        aux.push_back(v1[i++]);
    }
    while(j < v2.size()){
        aux.push_back(v2[j++]);
    }
}
