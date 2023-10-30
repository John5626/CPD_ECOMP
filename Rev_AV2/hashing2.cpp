// TRATAR CONFLITOS COM ENDEREÇAMENTO ABERTO (SONDAGEM LINEAR)
#include <bits/stdc++.h>

using namespace std;

vector<int> preencher(int tam, int min, int max);
void exibir(vector<int> v);

typedef struct Tab_hash{
    vector<int> tab;
    void inicializar(int cap);
    int key(int valor);
    bool buscar(int valor);
    bool inserir(int valor);
    bool remover(int valor);
}Tab_hash;


int main(){
    srand(time(NULL));

    Tab_hash h; h.inicializar(13);

    exibir(h.tab);

    cout << "Inserir na estrutura" << endl;
    for(int i = 1; i <= 13; i++){
        h.inserir(rand() % 100 + 1);
        exibir(h.tab);
    }

    cout << endl;
    for(int i = 3; i <= 5; i++){
        h.remover(i);
        exibir(h.tab);
    }


    


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
    return valor % tab.size(); 
}

bool Tab_hash::buscar(int valor){
    int chave = key(valor);
    int id = chave;
    while(tab[id] != -1){
        if(tab[id] == valor)
            return true;
        id = (id + 1) % tab.size();
        if(id == chave)
            break;
    }

    return false;
}

bool Tab_hash::inserir(int valor){
    if(tab[key(valor)] == -1){
        tab[key(valor)] = valor;
        return true;
    }
    else{
        int chave = key(valor);
        int id = chave;

        while(tab[chave] != -1 && tab[chave] != -2){
            chave = (chave + 1) % tab.size();
            if(chave == id)
                break;
        }

        if(tab[chave] == -1){
            tab[chave] = valor;
            return true;
        }
    }
    return false;
        
}

bool Tab_hash::remover(int valor){
    
    int chave = key(valor);
    int id = chave;
    while(tab[chave] != -1){
        if(tab[chave] == valor){
            if(tab[(chave + 1) % 13] == -1)
                tab[chave] = -1;
            else tab[chave] = -2;

            return true;
        }
        chave = (chave + 1) % 13;
        if(chave == id)
            break;
    }
    
    return false;
}