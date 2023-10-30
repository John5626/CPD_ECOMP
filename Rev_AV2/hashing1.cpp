// SEM TRATAR CONFLITOS
#include <bits/stdc++.h>

using namespace std;

vector<int> preencher(int tam, int min, int max);
void exibir(vector<int> v);

typedef struct{
    vector<int> tab;
    void inicializar(int cap);
    int key(int valor);
    bool buscar(int valor);
    bool inserir(int valor);
    bool remover(int valor);
}Tab_hash;


int main(){
    srand(time(NULL));

    Tab_hash h; h.inicializar(14);

    exibir(h.tab);

    for(int i = 0; i <= 13; i++){
        h.inserir(rand() % 100 + 1);
    }

    exibir(h.tab);


}

vector<int> preencher(int tam, int min, int max){
    vector<int> v;
    for(int i = 0; i < tam; i++){
        v.push_back(rand() % (max - min) + 1);
    }

    return v;
}

void exibir(vector<int> v){
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}

void Tab_hash::inicializar(int cap){
    tab.resize(cap);

    for(int i = 0; i < tab.size(); i++){
        tab[i] = -1;
    }
}

int Tab_hash::key(int valor){
    return valor % 13; 
}

bool Tab_hash::buscar(int valor){
    return (tab[key(valor)] != -1) ? true : false;
}

bool Tab_hash::inserir(int valor){
    if(tab[key(valor)] != -1)
        return false;

    tab[key(valor)] = valor;
    return true;
}

bool Tab_hash::remover(int valor){
    if(tab[key(valor)] == -1)
        return false;
    
    tab[key(valor)] = -1;
    return true;
}