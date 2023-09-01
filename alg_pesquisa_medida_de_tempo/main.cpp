#include <iostream>
#include <bits/stdc++.h>
#include <chrono> //medir tempo

using namespace std;
using namespace std::chrono;

void preencher_vet(short *vet, double N);
void exibir_vet(short *vet, double N);
bool busca_seq(short *vet, double N, int e);
void ordenar_vet(short *vet, double N);
int busca_binaria(short *vet, double N, int e);

int main(int argc, char* argv[]){
    srand(time(NULL));

    double N;
    if(argc < 2){
        cout << "Argumento invalido" << endl;
        exit(1);
    }

    N = atoi(argv[1]);

    //cout << N;

    short vet[int(N)];


    auto ini = high_resolution_clock::now();
    preencher_vet(vet, N);
    auto fim = high_resolution_clock::now();
    //exibir_vet(vet, N);
    
    cout << "Sequencial: " << busca_seq(vet, N, 502) << endl;

    duration<double> tempo = fim - ini;

   
    cout << tempo.count() << "s\n";

    cout.precision(10);
    cout << fixed;
    cout << duration_cast<milliseconds>(tempo).count() << "ms\n";

    cout.precision(10);
    cout << fixed;
    cout << duration_cast<microseconds>(tempo).count() << "us\n";

    cout.precision(10);
    cout << fixed;
    cout << duration_cast<nanoseconds>(tempo).count() << "ns\n";


    
    
    cout << endl;
    ordenar_vet(vet, N);
    //exibir_vet(vet, N);
    cout << endl;
    cout << "Binaria: " <<busca_binaria(vet, N, 502);
    



}

void preencher_vet(short *vet, double N){
    for(int i = 0; i < N; i++)
        vet[i] = rand() % (1000 + 1) - 1;
    
}

void exibir_vet(short *vet, double N){
    for(int i = 0; i < N; i++)
        cout << vet[i] << " ";

    cout << endl;
}

bool busca_seq(short *vet, double N, int e){
    for(int i = 0; i < N; i++)
        if(vet[i] == e)
            return true;

    return false;
}

void ordenar_vet(short *vet, double N){
    for(int i = 1; i < N; i++){
        short id_menor = i - 1;

        for(int j = i; j < N; j++)
            if(vet[j] < vet[id_menor])
                id_menor = j;
        
        short aux = vet[i-1];
        vet[i-1] = vet[id_menor];
        vet[id_menor] = aux;

    
    }
}

int busca_binaria(short *vet, double N, int e){
    
    int ini, fim, meio;
    ini = 0;
    fim = N - 1;
    while(ini <= fim){
        meio = (ini + fim) / 2;
        if(vet[meio] == e)
            return meio;
        else if(e < vet[meio])
                fim = meio - 1;
            
        else ini = meio + 1;  
        
    }
    return -1; // nao encontrou
}


/*
1) Criar uma função para preenchimento de um vetor de tamanho N
com valores aleatórios no intervalo [1, 1000]
2) Criar uma função para fazer uma busca sequencial, dados um vetor
e seu tamanho
3) Criar uma função para fazer uma busca binária, dados um vetor
e seu tamanho
4) Criar um programa para inicializar um vetor de tamanho N com 
valores aleatórios no intervalo [1, 1000] e fazer duas buscas do
valor 502, sendo uma sequencial e outra aleatória (N deve ser 
informado por argumento de programa)
*/