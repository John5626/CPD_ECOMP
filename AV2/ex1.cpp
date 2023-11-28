#include <bits/stdc++.h>

using namespace std;

typedef struct{
    vector<string> tab;
    void ininializar(int cap);
    void exibir();
    int key(string s);
    bool inserir(string s);
    bool remover(string s);
    bool buscar(string s);

}Hash;


int main(){
    Hash t; t.ininializar(23);
    t.exibir();

    for(int i = 0; i < 20; ++i){
        t.inserir("str" + to_string(i));
        t.exibir();
        
    }
    

    cout << "Buscando str5: ";
    if(t.buscar("str5"))
        cout << "encontrado\n";
    else cout << "nao encontrado\n";

    cout << "Buscando str20: ";
    if(t.buscar("str20"))
        cout << "encontrado\n";
    else cout << "nao encontrado\n";
    
    // Teste de remoção
    t.remover("str5");
    t.exibir();





}

void Hash::ininializar(int cap){
    tab.resize(cap);

    for(int i = 0; i < tab.size(); i++){
        tab[i] = "-1";
    }

}

void Hash::exibir(){
    for(auto i : tab){
        cout << i << "  ";
    }
    cout << endl;

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

bool Hash::inserir(string s){
    int chave = key(s);
    
    if(tab[chave] == "-1"){
        tab[chave] = s;

    }
    else{
        int id_ini = chave;
        cout << "\nColisoes: ";
        cout << chave << " ";
        while(tab[chave] != "-1"){
            chave = (chave + 1) % tab.size();
            cout << chave << " ";

            if(chave == id_ini)
                return false;
        }
        cout << ".\n";

        tab[chave] = s;

    }
    return true;
}

bool Hash::remover(string s){
    int chave = key(s);
    
    if(tab[chave] == s){
        tab[chave] = "-2";

    }
    else{
        int id_ini = chave;
        while(tab[chave] != "-1"){
            chave = (chave + 1) % tab.size();

            if(tab[chave] == s){
                tab[chave] = "-2";
                break;
            }

            if(chave == id_ini)
                return false;
        }

    }
    return true;


}

bool Hash::buscar(string s){
    int chave = key(s);
    int id_ini = chave;
    do {
        if (tab[chave] == s) {
            return true;
        }
        chave = (chave + 1) % tab.size();
    } while (chave != id_ini && tab[chave] != "-1");
    return false;
}

