#include <bits/stdc++.h>

using namespace std;

bool criar_arquivo(int n, int min, int max){
    ofstream file;
    file.open("vetor.txt");
    if(!file.is_open())
        return false;
    for(int i = 0; i < n; i++){
        file << rand() % (max - min) + min << "\n";
    }
    return true;
}

int main(){
    srand(time(NULL));

    if(criar_arquivo(10000, 1, 1000))
        cout << "Arquivo gerado\n";
}