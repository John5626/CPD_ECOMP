#include <bits/stdc++.h>

using namespace std;

void troca(int *id1, int *id2);
void ordenacao(vector<int>& total, vector<int>& carro);

int main(){
    srand(time(NULL));
    int n, m; //carros, voltas
    cin >> n; cin >> m;

    vector<int> total(n);
    vector<int> carro(n);

    for(int i = 0; i < n; i++){
        carro[i] = i+1;
    }
    
    int soma_voltas = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int tempo; cin >> tempo;
            soma_voltas += tempo; 
            total[i] = soma_voltas;
        }
        
        soma_voltas = 0;
    }
    
    ordenacao(total, carro);

    for(int i = 0; i < 3; i++)
        cout << carro[i] << "\n";
    
}

void troca(int *id1, int *id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

void ordenacao(vector<int>& total, vector<int>& carro){
    for(int i = 1; i < total.size(); i++){
        int id_menor = i - 1;

        for(int j = i; j < total.size(); j++){
            if(total[id_menor] > total[j])
                id_menor = j;
        }

        troca(&total[i-1], &total[id_menor]);
        troca(&carro[i-1], &carro[id_menor]);

        
    }
}

