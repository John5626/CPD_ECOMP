//JOAO VICTOR SOUZA   -   ECOMP
#include <iostream>
#include <array>
#include "header_files/avl.hpp"

using namespace std;

int main(){
    array<int, 9> arr1 = {10, 15, 20, 9, 5, 16, 17, 8, 6};
    array<int, 14> arr2 = {30, 40, 24, 58, 48, 26, 11, 13, 14, 28, 16, 15, 20, 17};
    array<int, 15> arr3 = {11, 20, 32, 43, 50, 61, 70, 99, 98, 97, 95, 93, 92, 91, 80};

    no_avl *root1, *root2, *root3;

    root1 = root2 = root3 = NULL;

    for(auto valor : arr1){
        root1 = inserir_avl(root1, valor);
    }

    for(auto valor : arr2){
        root2 = inserir_avl(root2, valor);
    }

    for(auto valor : arr3){
        root3 = inserir_avl(root3, valor);
    }

    cout << "ROOT 1:" << " "; em_ordem_avl(root1); cout << endl;
    cout << "ROOT 2:" << " "; em_ordem_avl(root2); cout << endl;
    cout << "ROOT 3:" << " "; em_ordem_avl(root3); cout << endl;

    int k = 48;
    cout << "\nROOT 1: valor mais proximo de " << k << " eh " << no_proximo_avl(root1, k);
    cout << "\nROOT 2: valor mais proximo de " << k << " eh " << no_proximo_avl(root2, k);
    cout << "\nROOT 3: valor mais proximo de " << k << " eh " << no_proximo_avl(root3, k);

    liberar_avl(root1); liberar_avl(root2); liberar_avl(root3);
}