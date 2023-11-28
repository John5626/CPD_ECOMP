//JOAO VICTOR SOUZA   -   ECOMP
#include <iostream>
#include <array>
#include <ctime>
#include "header_files/abb.hpp"
#include "header_files/avl.hpp"
#include "header_files/calcular_h.hpp"

#define BREAK 500

using namespace std;

int main(){
    srand(time(NULL));
    int cont = 0;
    int m1, m2;
    m1 = m2 = 0;
    do{
        no_abb* abb = NULL;
        no_avl* avl = NULL;

        array<int, 2> h = calcular_h(abb, avl, 1000);
        //cout << "Iteracao " << cont + 1 << ":\n"; 
        //cout << "\tAltura ABB: " << h[0] << endl;
        //cout << "\tAltura AVL: " << h[1] << endl;

        m1 += h[0];
        m2 += h[1];

        liberar_abb(abb);
        liberar_avl(avl);
        cont++;

    }while(cont < BREAK);

    m1 = m1 / 500;
    m2 = m2 / 500;

    cout << "Medias:\n";
    cout << "H(abb): " << m1;
    cout << "\nH(avl): " << m2;
}