#include <bits/stdc++.h>

using namespace std;

vector<int> preencher(int tam, int min, int max);
void exibir(vector<int> v);
void couting_sort(vector<int>& v);

int main(){
    vector<int> v = preencher(100, 0, 50);

    exibir(v);

    couting_sort(v);

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

void couting_sort(vector<int>& v){
    int max = *max_element(v.begin(), v.end()) + 1;

    vector<int> aux(max, 0);

    for(int i = 0; i < v.size(); i++)
        aux[v[i]]++;

    for(int i = 1; i < aux.size(); i++)
        aux[i] += aux[i-1];

    vector<int> temp(v.size(), 0);

    for(int i = v.size() - 1; i >= 0; i--){
        temp[--aux[v[i]]] = v[i];
        
    } 

    for(int i = 0; i < v.size(); i++)
        v[i] = temp[i];

    
}