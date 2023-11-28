//JOAO VICTOR SOUZA   -   ECOMP
#include <iostream>
#include <queue>
#include <algorithm>
#include "abb.hpp"

struct no_abb {
    int info;
    no_abb *sae;    // sub-árvore a esquerda
    no_abb *sad;    // sub_árvore a direita
};

bool buscar_abb(no_abb* a, int valor) {
    if(a == NULL)
        return false;
    
    if(valor == a->info)
        return true;
    else if(valor < a->info)
        return buscar_abb(a->sae, valor);
    else
        return buscar_abb(a->sad, valor);
}

no_abb* criar_abb(int valor_raiz) {
    no_abb *raiz = new no_abb;
    if(raiz != NULL){
        raiz->info = valor_raiz;
        raiz->sae = raiz->sad = NULL;
    }
    
    return raiz;
}

no_abb* inserir_abb(no_abb* n, int valor) {
    if(n == NULL)
        return criar_abb(valor);

    if(valor < n->info)
        n->sae = inserir_abb(n->sae, valor);
    else
        n->sad = inserir_abb(n->sad, valor);
    
    return n;
}

void largura_abb(no_abb* n) {
    std::queue<no_abb*> f;
    f.push(n);
    while(!f.empty()) {
        no_abb* atual = f.front();
        std::cout << atual->info << " ";
        f.pop();
        if(atual->sae)
            f.push(atual->sae);
        if(atual->sad)
            f.push(atual->sad);
    }
}

void liberar_abb(no_abb*& n) {
    if(n == NULL)
        return;
    
    liberar_abb(n->sae);
    liberar_abb(n->sad);

    delete n;
    n = NULL;
}

void percorrer_abb(no_abb *n) {
    if(n == NULL)
        return;

    percorrer_abb(n->sae);
    std::cout << " " << n->info;
    percorrer_abb(n->sad);
}

no_abb* minimo_abb(no_abb* n) {
    if(n->sae != NULL)
        return minimo_abb(n->sae);

    return n;
}

no_abb* remover_abb(no_abb* n, int valor) {
    if(n == NULL)
        return NULL;
    
    if(valor < n->info) {
        n->sae = remover_abb(n->sae, valor);
    } else if(valor > n->info) {
        n->sad = remover_abb(n->sad, valor);
    } else {
        no_abb* temp = NULL;
        if(n->sae == NULL && n->sad == NULL) {
            free(n);
            return NULL;
        } else if(n->sae == NULL) {
            temp = n->sad;
            free(n);
            return temp;
        } else if(n->sad == NULL) {
            temp = n->sae;
            free(n);
            return temp;
        } else {
            temp = minimo_abb(n->sad);
            n->info = temp->info;
            n->sad = remover_abb(n->sad, temp->info);
        }
    }

    return n;
}

int altura_abb(no_abb* n){
    if(n == NULL)
        return 0;
    else{
        int h_sae = altura_abb(n->sae);
        int h_sad = altura_abb(n->sad);

        return std::max(h_sae, h_sad) + 1;

    }
}
