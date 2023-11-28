#include <iostream>
#include <algorithm>
#include <queue>


struct no{
	int info;
	struct no* sae; 
	struct no* sad;
	int h;
};

int altura(no* n) {
	if(n == NULL)
		return 0;
	
	return n->h;
}

bool buscar(no* n, int valor) {
	if(n == NULL)
		return false;
	
	if(valor == n->info)
		return true;

	else if(valor < n->info){
		return buscar(n->sae, valor);
	}
	else return buscar(n->sad, valor);
}

no* criar(int valor) {
	//no* n = (no*) calloc(1, sizeof(no));
	no* n = new no;

	if(n != NULL){
		n->info = valor;
		n->sae = n->sad = NULL;
		n->h = 1;
	}

	return n;
}


int fb(no* n) {
	if(n == NULL)
		return 0;
	
	return altura(n->sae) - altura(n->sad);
}

static no* RR_rotation(no* n){
	no* dir = n->sad;

	n->sad = dir->sae;
	dir->sae = n;

	n->h = 1 + std::max(altura(n->sad), altura(n->sae));
	dir->h = 1 + std::max(altura(dir->sad), altura(dir->sae));

	return dir;
}

static no* LL_rotation(no* n){
	no* esq = n->sae;

	n->sae = esq->sad;
	esq->sad = n;

	n->h = 1 + std::max(altura(n->sad), altura(n->sae));
	esq->h = 1 + std::max(altura(esq->sad), altura(esq->sae));

	return esq;
}

no* inserir(no* n, int valor) {
	if(n == NULL)
		return criar(valor);
	
	if(valor < n->info)
		n->sae = inserir(n->sae, valor);
	
	else n->sad = inserir(n->sad, valor);

	n->h = 1 + std::max(altura(n->sae), altura(n->sad));

	int fat = fb(n);

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

no* remover(no* n, int valor) {
	if(n == NULL)
		return NULL;
	
	no* temp = NULL;

	if(valor > n->info){
		n->sad = remover(n->sad, valor);
		if(fb(n) == 2){
			if(fb(n->sae) >= 0)
				n = LL_rotation(n);
			else{  //LR
				n->sae = RR_rotation(n->sae);
				n = LL_rotation(n);
			}
		}
	}
	else if(valor < n->info){
		n->sae = remover(n->sae, valor);

		if(fb(n) == -2){
			if(fb(n->sad) <= 0)
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
			n->sad = remover(n->sad, temp->info);

			if(fb(n) == 2){
				if(fb(n->sae) >= 0)
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

	n->h = altura(n);

	return n;
}

void em_ordem(no* n) {
	if(n == NULL)
		return;
	
	em_ordem(n->sae);
	std::cout << n->info << " ";
	em_ordem(n->sad);
}

void largura(no* n) {
	std::queue<no*> f;
	f.push(n);
	
	while(!f.empty()){
		no* atual = f.front();
		std::cout << atual->info << " ";

		f.pop();
		if(atual->sae)
			f.push(atual->sae);
		if(atual->sad)
			f.push(atual->sad); 
	}
}

void liberar(no*& n) {
	if(n == NULL)
		return;
		
	liberar(n->sae);
	liberar(n->sad);
	delete n;
	n = NULL;
}

int no_proximo(no* n, int k){
    if(n == NULL)
        return -404;

  	int mais_prox = n->info;

	if(n->info == k)
		return k;
	
	else if(k < n->info){
		int prox_esq = no_proximo(n->sae, k);

		if(prox_esq != -404 && abs(k - prox_esq) < abs(k - mais_prox))
			mais_prox = prox_esq;
		
		return mais_prox;
	}
	else{
		int prox_dir = no_proximo(n->sad, k);

		if(prox_dir != -404 && abs(k - prox_dir) < abs(k - mais_prox))
			mais_prox = prox_dir;
		
		return mais_prox;
	}
	
}

void remover_dir(no*& n){
	if(n == NULL)
		return;
		
	remover_dir(n->sad);
	delete n->sad;
	n->sad = NULL;

	int b = altura(n);

	if(b > 1){
		if(altura(n->sae->sae) >= altura(n->sae->sad)){
			n = LL_rotation(n);
		}
		else{//LR
			n->sae = RR_rotation(n->sae);
			n = LL_rotation(n);
		}
	
	}
	else if(b < -1){
		if(altura(n->sad->sad) >= altura(n->sad->sae)){
			n = RR_rotation(n);
		}
		else{//RL
			n->sad = LL_rotation(n->sad);
			n = RR_rotation(n);
		}
	}


}

int qtde_nos(no* n, int a, int b){ 
	if(n == NULL)
		return 0;
	
	int cont = 0;
	
	cont += qtde_nos(n->sae, a, b);

	if(n->info >= a && n->info <= b)
		cont++;

	cont += qtde_nos(n->sad,a, b);

	return cont;

}

