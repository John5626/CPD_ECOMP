//JOAO VICTOR SOUZA   -   ECOMP
#ifndef ARVORES_AVL_HPP
#define ARVORES_AVL_HPP

typedef struct no_avl no_avl;

/*Calcular altura
  Entrada: recebe o nó da AVL
  Saída: retorna a altura em relação ao no informado*/
int altura_avl(no_avl* n);

/*Buscar inteiro na AVL
  Entrada: recebe o nó da AVL e o valor a ser buscado
  Saída: retorna true caso encontre, falso caso contrário */
bool buscar_avl(no_avl* n, int valor);

/*Cria a AVL
  Entrada: recebe o valor para o no_raiz
  Saída: retorna uma variavel do tipo no_avl */
no_avl* criar_avl(int valor);


/*Calcular fator de balanceamento
  Entrada: recebe o nó da AVL
  Saída: retorna o fator de balanceamento do nó */
int fb_avl(no_avl* n);

/*Inserir na AVL
  Entrada: recebe o nó da AVL e o valor a ser inserido
  Saída: retorna uma variavel do tipo no_avl */
no_avl* inserir_avl(no_avl* n, int valor);

/*Remover da AVL
  Entrada: recebe o nó da AVL e o valor a ser removido
  Saída: retorna uma variavel do tipo no_avl */
no_avl* remover_avl(no_avl* n, int valor);

/*Exibe a AVL em ordem
  Entrada: recebe o nó da AVL
  Saída: nao tem */
void em_ordem_avl(no_avl* n);

/*Exibição em Largura
  Entrada: recebe o nó da AVL
  Saída : nao tem */
void largura_avl(no_avl* n);

/*Libera memória alocada
  Entrada: recebe o nó da AVL
  Saída : nao tem */
void liberar_avl(no_avl*& n);

//ATIVIDADE PRATICA


/*Encontra o nó cujo valor mais se aproxime do valor de k.
  Entrada: recebe o nó da AVL e um inteiro k
  Saída : inteiro mais proximo de k */
int no_proximo_avl(no_avl* n, int k);

/*Remove a SAD da AVL.
  Entrada: recebe o nó da AVL
  Saída : nao tem */
void remover_dir_avl(no_avl*& n);

/*Informaa quantidade de nós no intervalo [a,b].
  Entrada: recebe o nó da AVL e os inteiros a,b
  Saída : numero de nos */
int qtde_nos_avl(no_avl* n, int a, int b);


#endif // !ARVORES_AVL_HPP
