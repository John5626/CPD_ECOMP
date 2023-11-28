#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    
    ifstream f1; f1.open("av2/inteiros.txt");
    if(!f1.is_open()){
        cout << "Falha ao abrir txt";
        exit(1);
    }

    int n;
    while(f1 >> n)
        v.push_back(n);

    f1.close();

    
    ifstream f2; f2.open("av2/inteiros.bin", ios::binary);
    if(!f2.is_open()){
        cout << "Falha ao abrir bin";
        exit(1);
    }
    int c;
    while(f2.read((char*) &c, sizeof(int)))
        v.push_back(c);


    for(int i : v)
        cout << i << " ";
    cout << endl;

    sort(v.begin(), v.end());

    ofstream ord; ord.open("ord.txt");
    if(!ord.is_open()){
        cout << "Falha ao abrir ord";
        exit(1);
    }
    for(int i = 0; i < v.size(); i++)
        ord << v[i] << " ";

    ord.close();

    
    


    
}