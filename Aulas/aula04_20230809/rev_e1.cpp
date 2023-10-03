#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*1) Criar uma função para preenchimento de um vetor de tamanho N
com valores aleatórios no intervalo [1, 1000]*/
void preencher(vector<short>& vet);

void exibir(vector<short> vet);

/*2) Criar uma função para fazer uma busca sequencial, dados um vetor
e seu tamanho*/
bool busca_s(vector<short>& vet, int e);

void troca(short *id1, short *id2);

void ord_selecao(vector<short>& vet);

/*3) Criar uma função para fazer uma busca binária, dados um vetor
e seu tamanho*/
bool busca_b(vector<short>& vet, int e);

int main(int argc, char* argv[]){
    int n;
    if(argc < 2){
        cout << "Informe o tamanho do vetor";
        exit(1);
    }
    n = atoi(argv[1]);

    int e = atoi(argv[2]);

    vector<short> vet(n);
    
    auto ini = high_resolution_clock::now();
    preencher(vet);
    auto fim = high_resolution_clock::now();

    duration<double> intervalo = fim - ini;

    ofstream file;
    file.open("dados.dat");
    for(int i = 10; i < n; i *= 5){
        auto ini = high_resolution_clock::now();
        preencher(vet);
        auto fim = high_resolution_clock::now();
        //cout << intervalo.count() << "s\n";
        //cout << duration_cast<milliseconds>(intervalo).count() << "ms\n";
        file << i << " " << duration_cast<microseconds>(intervalo).count() << "ms\n";
        //cout << duration_cast<nanoseconds>(intervalo).count() << "ms\n";
    }
    file.close();

    //exibir(vet);

    if(busca_s(vet, e))
        cout << "Valor " << e << " encontrado na busca sequencial." << endl;
    else cout << "Valor " << e << " nao encontrado na busca sequencial." << endl;

    if(busca_b(vet, e))
        cout << "Valor " << e << " encontrado na busca binaria." << endl;
    else cout << "Valor " << e << " nao encontrado na busca binaria." << endl;

    

}



void preencher(vector<short>& vet){
    srand(time(NULL));

    for(int i = 0; i < vet.size(); i++){
        vet[i] = rand() % (1000 - 1 + 1) + 1;  // (max - min + 1) + min
    }
}

void exibir(vector<short> vet){
    for(int i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << endl;
}

bool busca_s(vector<short>& vet, int e){
    for(int i = 0; i < vet.size(); i++){
        if(vet[i] == e)
            return true;
    }

    return false;
}

void troca(short *id1, short *id2){
    int aux = *id1;
    *id1 = *id2;
    *id2 = aux;
}

void ord_selecao(vector<short>& vet){
    for(int i = 1; i <= vet.size() - 1; i++){
        int id_menor = i - 1; //vet[0]

        for(int j = i; j < vet.size(); j++)
            if(vet[j] < vet[id_menor])
                id_menor = j;
            
            

        troca(&vet[i-1], &vet[id_menor]);

    }
}

bool busca_b(vector<short>& vet, int e){
    ord_selecao(vet);

    int i, m, f;
    i = 0;
    f = vet.size() - 1;

    while(i <= f){
        m = (i + f) / 2;
        if(vet[m] == e)
            return true;

        else if(vet[m] < e){
            i = m + 1;
        }
        else 
            f = m - 1;
    }

    return false;
}



