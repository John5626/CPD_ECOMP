#include "calcular_h.hpp"

std::array<int, 2> calcular_h(no_abb*& r_abb, no_avl*& r_avl, int tam){
    std::array<int, 2> h;  

    for(int i = 0; i < tam; i++){
        int v = rand() % 100;
        if(!buscar_avl(r_avl, v)){
            r_abb = inserir_abb(r_abb, v);
            r_avl = inserir_avl(r_avl, v);
        }
    }
    
    h[0] = altura_abb(r_abb);
    h[1] = altura_avl(r_avl);

    return h;
}