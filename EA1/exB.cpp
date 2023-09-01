#include <iostream>

using namespace std;

int fatorial(int N);

int main(int argc, char* argv[]){
    int N = atoi(argv[3]);
    //cin >> N;

    cout << fatorial(N);
}

int fatorial(int N){
    if(N == 0 || N == 1)
        return 1;
    
    else return (N * fatorial(N-1));
}

