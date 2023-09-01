#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> D(61), E(61);
    int N, M, soma; //botas, tamnaho, soma dos pares
    char L; // D ou E

    cin >> N;

    int cont = 0;
    do{
        soma = 0;

        for(int i = 0; i < 61; i++){
            D[i] = 0;
            E[i] = 0;
        }

        while(N > 0){
            cin >> M; 
            cin >> L;

            if(L == 'E')
                E[M]++;
    
            else 
                D[M]++;
            
            if(E[M] && D[M]){
                E[M]--;
                D[M]--;
                soma++;
            }
            N--;
        }

        cont++;

    }while(cont < N);

    cout << soma << endl;
    
}
