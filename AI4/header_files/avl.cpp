//JOAO VICTOR SOUZA   -   ECOMP
#include <iostream>
#include <algorithm>
#include <queue>

struct no_avl{
	int info;
	no_avl* sae; 
	no_avl* sad;
	int h;
};

int altura_avl(no_avl* n) {
	if(n == NULL)
		return 0;
	
	return n->h;
}

bool buscar_avl(no_avl* n, int valor) {
	if(n == NULL)
		return false;
	
	if(valor == n->info)
		return true;

	else if(valor < n->info){
		return buscar_avl(n->sae, valor);
	}
	else return buscar_avl(n->sad, valor);
}

no_avl* criar_avl(int valor) {
	no_avl* n = new no_avl;

	if(n != NULL){
		n->info = valor;
		n->sae = n->sad = NULL;
		n->h = 1;
	}

	return n;
}


int fb_avl(no_avl* n) {
	if(n == NULL)
		return 0;
	
	return altura_avl(n->sae) - altura_avl(n->sad);
}

static no_avl* RR_rotation(no_avl* n){
	no_avl* dir = n->sad;

	n->sad = dir->sae;
	dir->sae = n;

	n->h = 1 + std::max(altura_avl(n->sad), altura_avl(n->sae));
	dir->h = 1 + std::max(altura_avl(dir->sad), altura_avl(dir->sae));

	return dir;
}

static no_avl* LL_rotation(no_avl* n){
	no_avl* esq = n->sae;

	n->sae = esq->sad;
	esq->sad = n;

	n->h = 1 + std::max(altura_avl(n->sad), altura_avl(n->sae));
	esq->h = 1 + std::max(altura_avl(esq->sad), altura_avl(esq->sae));

	return esq;
}

no_avl* inserir_avl(no_avl* n, int valor) {
	if(n == NULL)
		return criar_avl(valor);
	
	if(valor < n->info)
		n->sae = inserir_avl(n->sae, valor);
	
	else n->sad = inserir_avl(n->sad, valor);

	n->h = 1 + std::max(altura_avl(n->sae), altura_avl(n->sad));

	int fat = fb_avl(n);

	//LL-IMBALANCE
	if(fat > 1 && valor < n->sae->info){//Peso à esquerda
		return LL_rotation(n);
	} 
	
	//RR-IMBALANCE
	if(fat < -1 && valor > n->sad->info){ //Peso à direita
		return RR_rotation(n);

	} 
	//LR-ROTATION
	if(fat > 1 && valor > n->sae->info){ //Peso à esquerda e dupla rotação
		n->sae = RR_rotation(n->sae);
		return LL_rotation(n);
	}

	//RL-ROTATION
	if(fat < -1 && valor < n->sad->info){ //Peso à direita e dupla rotação
		n->sad = LL_rotation(n->sad);
		return RR_rotation(n);
	}

	return n;
}

no_avl* remover_avl(no_avl* n, int valor) {
	if(n == NULL)
		return NULL;
	
	no_avl* temp = NULL;

	if(valor > n->info){
		n->sad = remover_avl(n->sad, valor);
		if(fb_avl(n) == 2){
			if(fb_avl(n->sae) >= 0)
				n = LL_rotation(n);
			else{  //LR
				n->sae = RR_rotation(n->sae);
				n = LL_rotation(n);
			}
		}
	}
	else if(valor < n->info){
		n->sae = remover_avl(n->sae, valor);

		if(fb_avl(n) == -2){
			if(fb_avl(n->sad) <= 0)
				n = RR_rotation(n);
			else{ //RL
				n->sad = LL_rotation(n->sad);
				n = RR_rotation(n);
			}
		}
	}

	else{
		if(n->sad != NULL){
			temp = n->sad;
			while(temp->sae != NULL) //Pega o maior no da sae
				temp = temp->sae;

			n->info = temp->info;
			n->sad = remover_avl(n->sad, temp->info);

			if(fb_avl(n) == 2){
				if(fb_avl(n->sae) >= 0)
					n = LL_rotation(n);
				else{ //LR
					n->sae = RR_rotation(n->sae);
					n = LL_rotation(n);
				}
			}
		}
		else{
			return n->sae;
		}
	}

	n->h = altura_avl(n);

	return n;
}

void em_ordem_avl(no_avl* n) {
	if(n == NULL)
		return;
	
	em_ordem_avl(n->sae);
	std::cout << n->info << " ";
	em_ordem_avl(n->sad);
}

void largura_avl(no_avl* n) {
	std::queue<no_avl*> f;
	f.push(n);
	
	while(!f.empty()){
		no_avl* atual = f.front();
		std::cout << atual->info << " ";

		f.pop();
		if(atual->sae)
			f.push(atual->sae);
		if(atual->sad)
			f.push(atual->sad); 
	}
}

void liberar_avl(no_avl*& n) {
	if(n == NULL)
		return;
		
	liberar_avl(n->sae);
	liberar_avl(n->sad);
	delete n;
	n = NULL;
}

int no_proximo_avl(no_avl* n, int k){
    if(n == NULL)
        return -404;

  	int mais_prox = n->info;

	if(n->info == k)
		return k;
	
	else if(k < n->info){
		int prox_esq = no_proximo_avl(n->sae, k);

		if(prox_esq != -404 && abs(k - prox_esq) < abs(k - mais_prox))
			mais_prox = prox_esq;
		
		return mais_prox;
	}
	else{
		int prox_dir = no_proximo_avl(n->sad, k);

		if(prox_dir != -404 && abs(k - prox_dir) < abs(k - mais_prox))
			mais_prox = prox_dir;
		
		return mais_prox;
	}
	
}

void remover_dir_avl(no_avl*& n){
	if(n == NULL)
		return;
		
	remover_dir_avl(n->sad);
	delete n->sad;
	n->sad = NULL;

	int b = altura_avl(n);

	if(b > 1){
		if(altura_avl(n->sae->sae) >= altura_avl(n->sae->sad)){
			n = LL_rotation(n);
		}
		else{//LR
			n->sae = RR_rotation(n->sae);
			n = LL_rotation(n);
		}
	
	}
	else if(b < -1){
		if(altura_avl(n->sad->sad) >= altura_avl(n->sad->sae)){
			n = RR_rotation(n);
		}
		else{//RL
			n->sad = LL_rotation(n->sad);
			n = RR_rotation(n);
		}
	}


}

int qtde_nos_avl(no_avl* n, int a, int b){ 
	if(n == NULL)
		return 0;
	
	int cont = 0;
	
	cont += qtde_nos_avl(n->sae, a, b);

	if(n->info >= a && n->info <= b)
		cont++;

	cont += qtde_nos_avl(n->sad,a, b);

	return cont;

}

