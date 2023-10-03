#include <bits/stdc++.h>

using namespace std;

int max_elem(vector<int> vet);
int ord_cont(vector<int>& vet);


int main(){
    srand(time(NULL));
    vector<int> vet;
    
    for(int i = 0; i < 20; i++){
        int valor = rand() % 20;
        vet.push_back(valor);
    }

    for(int i = 0; i < vet.size(); i++){
        cout << vet[i] << " ";
    }
    cout << endl << endl;

    ord_cont(vet);
    
   

    for(int i = 0; i < vet.size(); i++){
        cout << vet[i] << " ";
    }
    cout << endl << endl;

    


}

int max_elem(vector<int> vet){
    int maior = 0;
    for(int i = 0; i < 20; i++){
        if(vet[i] > maior)
            maior = vet[i];
    }

    return maior;
}

int ord_cont(vector<int>& vet){
    int maior = max_elem(vet);

    int tam = maior;
    
    vector<int> b(tam+1, 0);

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 100; j++){
            if(vet[i] == j)
                b[j]++;
        }
    }
    
    for(int i = 0, id = 0; i <= maior; i++){
        if(b[i] != 0){
            int c = 0;
            while(c < b[i]){
                vet[id++] = i;
                c++;
            }
        }
    }

}