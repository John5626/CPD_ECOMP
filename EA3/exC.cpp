#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; //Amigos e Reunioes
    cin >> N >> M;

    int I, R; //Infectado e Reuniao infectada
    cin >> I >> R; 
    
    vector<set<int>> reuniao(M); //amigos na reuniao
    vector<bool> infectado(N+1, false);
    
    infectado[I] = true;

    //
    for(int i = 0; i < M; i++) {
        int A; cin >> A;

        for(int j = 0; j < A; j++){
            int participante; cin >> participante;

            reuniao[i].insert(participante); //insere participante
        }
        
    }
    
    //infectados
    for(int i = R-1; i < M; i++){
        bool esta_infec = false;

        for(int part_infectado : reuniao[i]){
            if(infectado[part_infectado]){
                esta_infec = true;
                break;
            }     

        }

        if(esta_infec)
            for(int part_infectado : reuniao[i])
                if(!infectado[part_infectado])
                    infectado[part_infectado] = true;
        
    }


    int soma = 0;
   // cout << endl << endl;
    for(int i = 1; i <= N; i++){
        //cout << infectado[i] << "  ";
        if(infectado[i])
            soma++;
    }
   // cout << endl << endl;

 
    cout << soma << endl;

    return 0;
}
