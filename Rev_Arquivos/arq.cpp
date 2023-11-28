#include <bits/stdc++.h>

#define FLAG_ERROR "Erro ao abrir os arquivos"

using namespace std;

int main(){
    ifstream f1; f1.open("av2/inteiros.txt");
    ifstream f2; f2.open("av2/inteiros.bin", ios::binary);

    if(!f1.is_open() || !f2.is_open()){
        cout << FLAG_ERROR;
        exit(1);
    }

    vector<int> vet;
    int i;
    while(f1 >> i){
        vet.push_back(i);
    }

    int c;
    while(f2.read((char*) &c, sizeof(c))){
        vet.push_back(c);
    }
    for(int v : vet)
        cout << v << " ";
    cout << endl;
    
    f1.close();
    f2.close();

    sort(vet.begin(), vet.end());

    ofstream f3; f3.open("vetor.txt");

    if(!f3.is_open()){
        cout << FLAG_ERROR;
        exit(1);
    }

    for(auto v : vet)
        f3 << v << " ";

    f3.close();
    


    

}