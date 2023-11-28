#include <iostream>
#include <array>
#include "avl.hpp"

using namespace std;

int main(){
    array<int, 9> arr1 = {10, 15, 20, 9, 5, 16, 17, 8, 6};
    array<int, 14> arr2 = {30, 40, 24, 58, 48, 26, 11, 13, 14, 28, 16, 15, 20, 17};
    array<int, 15> arr3 = {11, 20, 32, 43, 50, 61, 70, 99, 98, 97, 95, 93, 92, 91, 80};

    no *root1, *root2, *root3;

    root1 = root2 = root3 = NULL;

    for(auto valor : arr1){
        root1 = inserir(root1, valor);
    }

    for(auto valor : arr2){
        root2 = inserir(root2, valor);
    }

    for(auto valor : arr3){
        root3 = inserir(root3, valor);
    }

    cout << "ROOT 1:" << " "; largura(root1); cout << endl;
    cout << "ROOT 2:" << " "; largura(root2); cout << endl;
    cout << "ROOT 3:" << " "; largura(root3); cout << endl;

    cout << "\nRemocao das SAD's: ";
    remover_dir(root1);
    remover_dir(root2);
    remover_dir(root3);

    cout << "\nROOT 1: "; largura(root1);
    cout << "\nROOT 2: "; largura(root2);
    cout << "\nROOT 3: "; largura(root3);


    liberar(root1); liberar(root2); liberar(root3);



}