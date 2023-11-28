#include "avl.hpp"
#include <iostream>
#include <array>

using namespace std;

int main() {
    //array<int, 14> arr = {30, 40, 24, 58, 48, 26, 11, 13, 14, 28, 16, 15, 20, 17};
    //array<int, 9> arr = {10, 15, 20, 9, 5, 16, 17, 8, 6};
    array<int, 15> arr = {11, 20, 32, 43, 50, 61, 70, 99, 98, 97, 95, 93, 92, 91, 80};

    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    no* no_raiz = NULL;

    for(int i = 0; i < arr.size(); i++){
        no_raiz = inserir(no_raiz, arr[i]);
        //cout << "Em largura: "; largura(no_raiz); cout << endl;
    }
    cout << endl;

    cout << "Em largura: "; largura(no_raiz); cout << endl;

    cout << qtde_nos(no_raiz, 43, 61) << endl;

    cout << "Em ordem: "; em_ordem(no_raiz); cout << endl << endl;

    //cout << "Mais proximo de 33: " << no_proximo(no_raiz, 33) << endl;

    //remover_dir(no_raiz);

    //cout << "Em largura: "; largura(no_raiz); cout << endl;

    liberar(no_raiz);

    
}


