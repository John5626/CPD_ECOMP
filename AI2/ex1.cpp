#include <bits/stdc++.h>

using namespace std;

void counting_sort(vector<int>& v);
int ordenado(string s);

int main(){
    string s;
    cin >> s;

    if(ordenado(s))
        cout << "String Ordenada." << endl;
    else cout << "String NAO Ordenada." << endl;
}

void counting_sort(string s){
    auto max = *max_element(s.begin(), s.end());
    int maior = max;
    /*
    vector<int> aux(maior+1, 0);
    
    // vetor de frequências: aux
    for(int i = 0; i < vet.size(); i++)
        aux[vet[i]]++;

    // vetor de frequências acumuladas: aux
    for(int i = 1; i < aux.size(); i++)
        aux[i] += aux[i-1];

    vector<int> temp(vet.size(), 0);
    for(int i = vet.size()-1; i >= 0; i--) {
        temp[aux[vet[i]] - 1] = vet[i];
        aux[vet[i]]--;
    }

    for(int i = 0; i < vet.size(); i++)
        vet[i] = temp[i];
}
    */

int ordenado(string s){
    for(int i = 1; i < s.size(); i++){
        if(s[i] < s[i-1])
            return false;
    }
    return true;
}
