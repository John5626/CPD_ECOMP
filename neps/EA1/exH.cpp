#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, C, S;

    cin >> N >> C >> S;

    int X[C];
    int pos = 1; 
    int vezes_S = 0;

    int cont = 1;
    
    while(cont <= C){
        cin >> X[cont];
        cont++;
                
    }

    for(int i = 0; i <= C; i++){
        //cout << pos <<" ";

        if(X[i] == 1){
            if(pos == N)
                pos = 1;

            else pos++;
        }
        else if(X[i] == -1){
            if(pos <= 1)
                pos = N;
            else pos--;
        }

        if(pos == S)
            vezes_S++;

        
    }

    cout << vezes_S << endl;

    return 0;
}
