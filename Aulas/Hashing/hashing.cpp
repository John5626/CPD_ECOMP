#include <bits/stdc++.h>

using namespace std;

vector<int> tab(13, -1);

void exibir(vector<int> v);
int h(int valor);
bool inserir(int val);
bool buscar(int val);
bool remover(int val);


int main(){
    /*
    map<char, vector<string>> t;

    t['J'].push_back("John");
    t['A'].push_back("Arthur");
    t['A'].push_back("Andre");


    cout << t['J'][0] << endl;
    cout << t['A'][0] << endl;
    cout << t['A'][1] << endl;
    */

    srand(time(NULL));

    exibir(tab);

    for(auto i : tab){
        inserir(rand() % (100 - 0) + 1);
    }

    exibir(tab);
    cout << buscar(31) << endl;
    remover(31);
    exibir(tab);
    


    
}

void exibir(vector<int> v){
    for(int i : tab){
        cout << i << " ";
    }
    cout << endl;
}

int h(int valor){
    return valor % 13;
}

bool inserir(int val){
    int chave = h(val);

    if(tab[chave] != -1)
        return false;
    
    tab[chave] = val;
    return true;
}

bool buscar(int val){
    return (tab[h(val)] != -1) ? true : false;
}

bool remover(int val){
    int chave = h(val);
    
    if(tab[chave] == -1)
        return false;
    
    tab[chave] = -1;
    return true;
}
