#include <iostream>

using namespace std;

int quota_N(int X, int N);

int main(){
    int X;      // quota mensal
    cin >> X; 

    int N;      // N meses
    cin >> N;

    cout << quota_N(X, N);

    
}

int quota_N(int X, int N){
    int M; // quota que usou no mes
    int quota_gasta = N*X;

    for(int i = 1; i <= N; i++){
        cin >> M;
        quota_gasta -= M;
    }
    

    return X + quota_gasta;
}


/*
quota -> 100
meses -> 2
    1 mes -> 50
    2 mes -> 120

*/
