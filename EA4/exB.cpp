#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int id, ouro, prata, bronze;
}Pais;

void troca(Pais* id1, Pais* id2);

void ordenacao(vector<Pais>& vet);

bool compara_paises(const Pais& a, const Pais& b);

int main() {
    int n, m;
    cin >> n >> m;

    vector<Pais> paises(n);

    for(int i = 0; i < n; i++){
        paises[i].id = i+1;
        paises[i].ouro = paises[i].prata = paises[i].bronze = 0;
        
    }

    for(int i = 0; i < m; i++){
        int pais;
        cin >> pais;
        paises[pais - 1].ouro++;

        cin >> pais;
        paises[pais - 1].prata++;

        cin >> pais;
        paises[pais - 1].bronze++;
    }

    ordenacao(paises);

    for(int i = 0; i < n; i++){
        cout << paises[i].id << " ";
    }

    cout << endl;

}

void troca(Pais* id1, Pais* id2){
    Pais aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

void ordenacao(vector<Pais>& vet) {
    for(int i = 0; i < vet.size() - 1; i++){
        int id_maior = i;

        for(int j = i + 1; j < vet.size(); j++){
            if(compara_paises(vet[j], vet[id_maior]))
                id_maior = j;
            
        }

        troca(&vet[i], &vet[id_maior]);
        
    }
}

bool compara_paises(const Pais& a, const Pais& b){
    if(a.ouro != b.ouro)
        return a.ouro > b.ouro;

    if(a.prata != b.prata)
        return a.prata > b.prata;

    if (a.bronze != b.bronze)
        return a.bronze > b.bronze;

    return a.id < b.id;
}


