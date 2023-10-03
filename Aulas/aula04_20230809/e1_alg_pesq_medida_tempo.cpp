#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int busca_binaria(short *v, int n, int k);
int busca_sequencial(short *v, int n, int k);
void exibir(short *v, int n);
void ord_selecao(short *v, int n);
void preencher(short *v, int n);
void troca(short *a, short* b);

int main(int argc, char* args[]) {
    int N;
    if(argc < 2) {
        cout << "Informe o tamanho do vetor como argumento de programa\n";
        return 0;
    }
    N = atoi(args[1]);

    short v[N];

    auto ini = high_resolution_clock::now();
    preencher(v, N);
    auto fim = high_resolution_clock::now();
    duration<double> intervalo = fim - ini;

    cout << intervalo.count() << "s\n";
    cout << duration_cast<milliseconds>(intervalo).count() << "ms\n";
    cout << duration_cast<microseconds>(intervalo).count() << "us\n";
    cout << duration_cast<nanoseconds>(intervalo).count() << "ns\n";

    exibir(v, N);

    ord_selecao(v, N);
    exibir(v, N);

    return 0;
}

int busca_binaria(short *v, int n, int k) {
    int ini = 0, fim = n-1, m;
    while(ini <= fim) {
        m = (ini + fim) / 2;
        if(k == v[m])
            return m;
        else if(k > v[m])
            ini = m + 1;
        else
            fim = m - 1;
    }

    return -1;  // valor não encontrado
}

int busca_sequencial(short *v, int n, int k) {
    for(int i = 0; i < n; i++)
        if(v[i] == k)
            return i;
    
    return -1;  // valor não encontrado
}

void exibir(short *v, int n) {
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void ord_selecao(short *v, int n) {
    for(int s = 1; s <= n-1; s++) {
        short idx_menor = s-1;
        for(int i = s; i < n; i++)
            if(v[i] < v[idx_menor])
                idx_menor = i;
        //cout << v[idx_menor] << endl;

        troca(&v[s-1], &v[idx_menor]);
    }
}

void preencher(short *v, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        v[i] = rand()%1000 + 1; // [0, 1000[ + 1 = [1, 1001[ // MAX: RAND_MAX
}

void troca(short * a, short * b) {
    short aux = *a;
    *a = *b;
    *b = aux;
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