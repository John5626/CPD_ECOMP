#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;  cin >> N;

    int seq_maior = 1;
    int cont = 1;
    int ant, atual;

    for(int i=0; i<N; i++){
        cin >> atual;

        if(atual == ant)
            cont++;
        else cont = 1;

        if(cont > seq_maior)
            seq_maior = cont;
        
        ant = atual;
    }

    cout << seq_maior << endl;

}

