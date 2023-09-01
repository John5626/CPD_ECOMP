#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; // quadrados na fita
    cin >> N;

    vector<int> fita;

    for(int i = 0; i < N; i++){
        int colorido;
        cin >> colorido;
        fita.push_back(colorido);
    }

    for(int i = 0; i < N; i++){
        if(fita[i] == -1){
            int esq = INT_MAX;
            int dir = INT_MAX;

            // distância para a esquerda
            for(int j = i; j >= 0; j--){
                if (fita[j] == 0) {
                    esq = i - j;
                    break;
                }
            }

            // Calcula a distância para a direita
            for(int j = i; j < N; j++){
                if(fita[j] == 0){
                    dir = j - i;
                    break;
                }
            }

            // Atribui a cor
            fita[i] = min(esq, dir);
            if(fita[i] >= 9){
                fita[i] = 9;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << fita[i] << " ";
    }

    cout << endl;

    return 0;
}
