#ifndef ARVORES_AVL_HPP
#define ARVORES_AVL_HPP


typedef struct no no;

/*Calcular altura
  Entrada: recebe o nó da AVL
  Saída: retorna a altura em relação ao no informado*/
int altura(no* n);

/*Buscar inteiro na AVL
  Entrada: recebe o nó da AVL e o valor a ser buscado
  Saída: retorna true caso encontre, falso caso contrário*/
bool buscar(no* n, int valor);

/*Cria a AVL
  Entrada: recebe o valor para o no_raiz
  Saída: retorna uma variavel do tipo no*/
no* criar(int valor);


/*Calcular fator de balanceamento
  Entrada: recebe o nó da AVL
  Saída: retorna o fator de balanceamento do nó*/
int fb(no* n);

/*Inserir na AVL
  Entrada: recebe o nó da AVL e o valor a ser inserido
  Saída: retorna uma variavel do tipo no*/
no* inserir(no* n, int valor);

/*Remover da AVL
  Entrada: recebe o nó da AVL e o valor a ser removido
  Saída: retorna uma variavel do tipo no*/
no* remover(no* n, int valor);

/*Exibe a AVL em ordem
  Entrada: recebe o nó da AVL
  Saída: nao tem*/
void em_ordem(no* n);

/*Exibição em Largura
  Entrada: recebe o nó da AVL
  Saída : nao tem*/
void largura(no* n);

/*Libera memória alocada
  Entrada: recebe o nó da AVL
  Saída : nao tem*/
void liberar(no*& n);

//ATIVIDADE PRATICA


/*Encontra o nó cujo valor mais se aproxime do valor de k.
  Entrada: recebe o nó da AVL e um inteiro k
  Saída : inteiro mais proximo de k*/
int no_proximo(no* n, int k);

/*Remove a SAD da AVL.
  Entrada: recebe o nó da AVL
  Saída : nao tem*/
void remover_dir(no*& n);

/*Informaa quantidade de nós no intervalo [a,b].
  Entrada: recebe o nó da AVL e os inteiros a,b
  Saída : numero de nos*/
int qtde_nos(no* n, int a, int b);


#endif // !ARVORES_AVL_HPP
