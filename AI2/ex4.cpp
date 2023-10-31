#include <bits/stdc++.h>

using namespace std;


void merge(vector<float> &v, int e, int m, int d);
void mergesort(vector<float> &vet, int e, int d);

int trocas = 0;

int main(){
    int n; cin >> n;

    vector<float> dist;
    vector<int> penalidades;
    int pen = 0;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        dist.push_back(sqrt(pow(x, 2) + pow(y, 2)));
    
        
    }
/*
    for(int i = 0; i < n; i++){
        cout << dist[i];
        cout << endl;
    }
*/

    mergesort(dist, 0, n-1);
  
    cout <<trocas << endl;
    
}


void mergesort(vector<float> &vet, int e, int d){
    if(e < d) {
        int m = e + (d-e)/2;
        mergesort(vet, e, m);
        mergesort(vet, m+1, d);
        merge(vet, e, m, d);
    }
}

void merge(vector<float> &v, int e, int m, int d){
    vector<int> aux;

    int i = e, j = m+1;
    while(i <= m && j <= d) {
        if(v[i] > v[j]){
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

