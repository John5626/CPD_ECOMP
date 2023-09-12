#include <bits/stdc++.h>

using namespace std;

void troca(int *id1, int *id2);
void inserir(vector<int>& vet, int pais);
int busca(vector<int>& vet1, int val);


int main(){
    int n, m; // paises, modalidades
    cin >> n; cin >> m;

    vector<int> ouro, prata, bronze;

    
    int cont[n][3];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 3; j++)
            cont[i][j] = 0;

    for(int i = 0; i < m; i++){
        int pais;
        cin >> pais; inserir(ouro, pais);
        cont[pais-1][0] += 1;

        cin >> pais; inserir(prata, pais);
        cont[pais-1][1] += 1;

        cin >> pais; inserir(bronze, pais);
        cont[pais-1][2] += 1;
        

    }


    int m_ouro = cont[0][0], o = -1;
    int m_prata = cont[0][1], p = -1;
    int m_bronze = cont[0][2], b = -1;

    for(int i = 0; i < n; i++){
        if(cont[i][0] > m_ouro){
            m_ouro = cont[i][0];
            o = i + 1;
        }
        
        if(cont[i][1] > m_prata){
            m_prata = cont[i][1];
            p = i + 1;
        }
        
        if(cont[i][2] > m_bronze){
            m_bronze = cont[i][2];
            b = i + 1;
        }
        
        
    }

    //cout << m_ouro << " " << m_prata << " " << m_bronze << endl;
    //cout << o << " " << p << " " << b << endl;

    vector<int> ja_ganhou;
    if(o == -1 && p == -1 && b == -1){
        ja_ganhou.push_back(n);
    }

    
    if(o != -1){
        for(int i = 0; i < ouro.size(); i++){
            if(busca(ja_ganhou, ouro[i]) == -1)
                ja_ganhou.push_back(ouro[i]);
        }
    }
    else if(p != -1){
        for(int i = 0; i < prata.size(); i++){
            if(busca(ja_ganhou, prata[i]) == -1)
                ja_ganhou.push_back(prata[i]);
        }
    }

    else if(b != -1){
        for(int i = 0; i < bronze.size(); i++){
            if(busca(ja_ganhou, bronze[i]) == -1)
                ja_ganhou.push_back(bronze[i]);
        }
    }

    for(int i = 0; i <= n; i++){
        if(busca(ja_ganhou, n) == -1){
            ja_ganhou.push_back(n);
        }
    }

    






    cout << endl << endl;
    for(int i = 0; i < ja_ganhou.size(); i++)
        cout << ja_ganhou[i] << " ";

    
    

    
    




    
    
        

    
    




/*
    for(int i = 0; i < ouro.size(); i++){
        cout << ouro[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < prata.size(); i++){
        cout << prata[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < bronze.size(); i++){
        cout << bronze[i] << " ";
    }
    cout << endl;
*/



    
    
}

void troca(int *id1, int *id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

void inserir(vector<int>& vet, int pais){
    vet.push_back(pais);
    
    for(int i = 1; i < vet.size(); i++){
        int id_menor = i - 1;

        for(int j = i; j < vet.size(); j++){
            if(vet[id_menor] < vet[j])
                id_menor = j;
        }

        troca(&vet[i-1], &vet[id_menor]);
        

        
    }
}

int busca(vector<int>& vet, int val){
    for(int i = 0; i < vet.size(); i++){
        if(val == vet[i])
            return 1;
    }
    return -1;
}

