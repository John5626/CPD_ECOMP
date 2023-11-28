//JOAO VICTOR SOUZA   -   ECOMP
#ifndef ABB_HPP
#define ABB_HPP

typedef struct no_abb no_abb;

/*Buscar ABB
  Entrada: recebe o nó da ABB e o inteiro a ser buscado
  Saída: retorna verdadeiro caso encontre, falso caso contrario*/
bool buscar_abb(no_abb* a, int valor);

/*Criar no
  Entrada: recebe o inteiro para ser a raiz
  Saída: retorna o no*/
no_abb* criar_abb(int valor_raiz);

/*Insere na ABB
  Entrada: recebe o nó da ABB e o valor a ser inserido
  Saída: retorna o no*/
no_abb* inserir_abb(no_abb* a, int valor);

/*Exibição em largura
  Entrada: recebe o nó da ABB
  Saída: nao tem*/
void largura_abb(no_abb* n);

/*Libera ABB
  Entrada: recebe o nó da ABB
  Saída: nao tem*/
void liberar_abb(no_abb*& n);

/*Percorre a ABB
  Entrada: recebe o nó da ABB
  Saída: nao tem*/
void percorrer_abb(no_abb *n);

/*Remover ABB
  Entrada: recebe o nó da ABB e o inteiro a ser removido
  Saída: retorna o no da ABB*/
no_abb* remover_abb(no_abb* a, int valor);

/*Calcular altura
  Entrada: recebe o nó da AVL
  Saída: retorna a altura em relação ao no informado*/
int altura_abb(no_abb* n);

#endif // ABB_HPP