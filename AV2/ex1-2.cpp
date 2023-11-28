#include <bits/stdc++.h>

using namespace std;

#define CAP 10

typedef struct{
    vector<int> tab;

    void exibir();
    void inicializar(int cap);
    int key(string s);
    void inserir(string s);
    void remover(string s);
    bool buscar(string s);
}Hash;

int main(){
    Hash t; t.inicializar(CAP);
    t.exibir();

    int teste = t.key("ABC");
    cout << teste;
}

void Hash::exibir(){
    for(int i : tab){
        cout << i << " ";
    }
    cout << endl;
}

void Hash::inicializar(int cap){
    tab.resize(cap);
    for(int i = 0; i < cap; i++){
        tab[i] = -1;
    }
}

int Hash::key(string s){
    int t = s.size();
    int c = s[0];
    int cont = 1;

    while(cont < t){
        c += s[cont];
        cont++;
    }

    return c % tab.size();
}

void Hash::inserir(string s){

}

void Hash::remover(string s){

}

bool Hash::buscar(string s){
    return true;
}


