#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N; // Número de navios

    vector<vector<int>> tabuleiro(11, vector<int>(11, 0)); // Tabuleiro 10x10, índices de 1 a 10

    int navio = 1;
    bool val = true;

    while(navio <= N){
        int D, L, R, C; // Direção, largura, R e C são as posições
        cin >> D >> L >> R >> C;
        
        if(D == 0){
            if(C + L - 1 > 10){
                val = false;
                break;
            }
            for(int i = C; i < C + L; i++){
                if(tabuleiro[R][i] != 0){
                    val = false;
                    break;
                }
                tabuleiro[R][i] = navio;
            }
        } 
        else{
            if(R + L - 1 > 10){
                val = false;
                break;
            }
            for(int i = R; i < R + L; i++){
                if(tabuleiro[i][C] != 0){
                    val = false;
                    break;
                }
                tabuleiro[i][C] = navio;
            }
        }
            
        navio++;
         
    }

    if(val)
        cout << "Y" << endl;
    else cout << "N" << endl;

    return 0;
}

