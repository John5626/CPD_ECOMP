#include <iostream>

using namespace std;

int N_collatz(int N);

int main(){
    int N;
    cin >> N;

    cout << N_collatz(N);
}

int N_collatz(int N){
    static int cont = 0;
    static int y = 0;

    if(N == 1)
        return 0;

    if(N % 2 == 0)
        y = N/2;

    else y = 3*N + 1;

    cont++;

    if(y != 1)
        return N_collatz(y);
    
    else return cont;

}

