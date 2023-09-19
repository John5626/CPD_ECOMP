#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;

    vector<vector<int>> quadrado(N, vector<int>(N, 0));

    int num=0, linha, coluna;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int X; cin >> X; 
            quadrado[i][j] = X;
            if(X == 0){
                linha = i;
                coluna = j;
            }
        }
    }
    int valor = 0;
    int valor_linha = 0;

    for(int i = 0; i < N; i++){
        if(i == linha){
            continue;;
        }
        for(int j = 0; j < N; j++){
            valor += quadrado[i][j];
        }
        break;
    }

    for(int i = 0; i < N; i++){
        valor_linha += quadrado[i][coluna];
    }
    
    num = valor - valor_linha;
/*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("%2d ", quadrado[i][j]);
        cout << "\n";
    }
*/

    //cout << valor << "\n" << valor_linha << endl << endl;
    cout << num << "\n"<< linha+1 << "\n" << coluna+1 << endl;
}