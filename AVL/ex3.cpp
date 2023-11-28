#include <iostream>
#include <array>
#include "avl.hpp"

#define A 20
#define B 65

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

    cout << "ROOT 1:" << " "; em_ordem(root1); cout << endl;
    cout << "ROOT 2:" << " "; em_ordem(root2); cout << endl;
    cout << "ROOT 3:" << " "; em_ordem(root3); cout << endl;


    cout << "\nQuantidade de nos presentes no intervalo [" << A << ", " << B << "]";
    cout << "\nROOT 1: "; cout << qtde_nos(root1, A, B);
    cout << "\nROOT 2: "; cout << qtde_nos(root2, A, B);
    cout << "\nROOT 3: "; cout << qtde_nos(root3, A, B);


    liberar(root1); liberar(root2); liberar(root3);



}