#include <chrono>
#include "headers/ordenacao.h"

using namespace std :: chrono;

#define N 10100
#define MIN 0
#define MAX 50
#define BREAK 10010

/*(a)preencher um vetor de n posições com números aleatórios em uma dada faixa de valores [min, max]*/
void preencher(vector<int>& v, int n, int min, int max);

/*(b) exibir o conteúdo de um vetor desde um índice
inicial até um índice final, passados como parâmetro*/
void exibir(vector<int> v, int ini, int fim); 

/*(d) verificar se um vetor encontra-se ordenado*/
bool ordenado(vector<int> v, int n);

void reverte(vector<int>& v, vector<int> copy);

int main(){
    srand(time(NULL));
    
    int n = 10100; //cout << n;

    vector<int> v;
    preencher(v, n, MIN, MAX);

    vector<int> copy;
    for(int i = 0; i < n; i++){
        copy.push_back(v[i]);
    }

    //exibir(v, MIN, n);

    ofstream sel;
    sel.open("dados/selecao.dat");
    if(!sel.is_open()){
        exit(0);
    }
    for(int i = 10; i <= n; i += 100){
        auto ini = high_resolution_clock :: now();
        ord_selec(v, i);
        auto fim = high_resolution_clock :: now();
        
        duration<double> t = fim - ini;
        sel << i << " " << duration_cast<microseconds>(t).count() << "\n"; //<< "us\n";
        
        if(ordenado(v, i) && i == BREAK){
            cout << "Ordenacao por SELECAO conluida com sucesso.\n";
        }
        
    }
    sel.close();

    
    ofstream ins;
    ins.open("dados/insercao.dat");
    if(!ins.is_open()){
        exit(0);
    }
    for(int i = 10; i <= n; i += 100){
        reverte(v, copy);
        auto ini = high_resolution_clock :: now();
        ord_ins(v, i);
        auto fim = high_resolution_clock :: now();
        
        duration<double> t = fim - ini;
        ins << i << " " << duration_cast<microseconds>(t).count() << "\n"; //<< "us\n";
        
        if(ordenado(v, i) && i == BREAK){
            cout << "Ordenacao por INSERCAO conluida com sucesso.\n";
        }
    }
    ins.close();

    ofstream flut;
    flut.open("dados/flutuacao.dat");
    if(!flut.is_open()){
        exit(0);
    }
    for(int i = 10; i <= n; i += 100){
        reverte(v, copy);
        auto ini = high_resolution_clock :: now();
        ord_flut(v, i);
        auto fim = high_resolution_clock :: now();
        
        duration<double> t = fim - ini;
        flut << i << " " << duration_cast<microseconds>(t).count() << "\n"; //<< "us\n";
        
        if(ordenado(v, i) && i == BREAK){
            cout << "Ordenacao por FLUTUACAO conluida com sucesso.\n";
        }
    }
    flut.close();

    ofstream heap;
    heap.open("dados/heapsort.dat");
    if(!heap.is_open()){
        exit(0);
    }
    for(int i = 10; i <= n; i += 100){
        auto ini = high_resolution_clock :: now();
        heapsort(v, i);
        auto fim = high_resolution_clock :: now();
        
        duration<double> t = fim - ini;
        heap << i << " " << duration_cast<microseconds>(t).count() << "\n"; //<< "us\n";
        
        if(ordenado(v, i) && i == BREAK){
            cout << "Ordenacao por HEAPSORT conluida com sucesso.\n";
        }
        
    }
    heap.close();

    exibir(v, MIN, 1000);
}

void preencher(vector<int>& v, int n, int min, int max){
    for(int i = 0; i < n; i++){
        int valor = rand() % (max - min) + min;
        v.push_back(valor);
    }
}

void exibir(vector<int> v, int ini, int fim){
    for(int i = ini; i < fim; i++){
       cout << v[i] << " ";
    }
    cout << endl;
}

bool ordenado(vector<int> v, int n){
    for(int i = 1; i < n; i++){
        if(v[i-1] > v[i]){
            return false;
        }
    }
    return true;
}

void reverte(vector<int>& v, vector<int> copy){
    for(int i = 0; i < copy.size(); i++){
        v[i] = copy[i];
    }
}