#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int id;
    int resto;
}pessoas;

bool compara(const pessoas&a, const pessoas& b);

int main(){
    int n, k; // Pessoas e k-esima pos
    cin >> n >> k;
    vector<pessoas> fila(n);

    for(int i = 0; i < n; i++){
        fila[i].id = i + 1;
        fila[i].resto = 0;
    }

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        fila[i].resto = x % y; 
    }

    sort(fila.begin(), fila.end(), compara);

    cout << fila[k-1].resto;
} 


bool compara(const pessoas&a, const pessoas& b){
    return a.resto < b.resto;
}
    
