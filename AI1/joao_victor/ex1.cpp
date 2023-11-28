//JOAO VICTOR SOUZA - ECOMP

#include <chrono>
#include "headers/funcoes_aux.h" 

using namespace std;
using namespace std::chrono;

#define MIN 1

int main(){
    srand(time(NULL));
    
    int tam = 20000;
    vector<int> vet(tam);

    preencher(vet, tam, MIN, 1000);
    //cout << "Vetor nao ordenado: "; exibir(vet, 0, tam);

    vector<int> vet_copy(tam);
    for(int i = 0; i < tam; i++){
        vet_copy[i] = vet[i];
    }

    ofstream dados_ins; dados_ins.open("dados/ins.dat");
    ofstream dados_selec; dados_selec.open("dados/selec.dat");
    ofstream dados_flut; dados_flut.open("dados/flut.dat");
    ofstream dados_heap; dados_heap.open("dados/heap.dat");


    if(dados_ins.is_open() && dados_selec.is_open() && dados_flut.is_open(), dados_heap.is_open()){
        cout << "Aguarde. Calculando tempos...\n";
        for(int i = 10; i < tam; i += 500){

            auto ini = high_resolution_clock::now();
            ord_insercao(vet, i);
            auto fim = high_resolution_clock::now();

            duration<double> t = fim - ini;
            dados_ins << i << " " << duration_cast<microseconds>(t).count() << endl; //"us\n";

            reverter(vet, vet_copy); // Revertendo ordenação para o proximo algoritmo

            ini = high_resolution_clock::now();
            ord_selecao(vet, i);
            fim = high_resolution_clock::now();

            t = fim - ini;
            dados_selec << i << " " << duration_cast<microseconds>(t).count() << endl; //"us\n";

            reverter(vet, vet_copy);

            ini = high_resolution_clock::now();
            ord_flutuacao(vet, i);
            fim = high_resolution_clock::now();

            t = fim - ini;
            dados_flut << i << " " << duration_cast<microseconds>(t).count() << endl; //"us\n";

            reverter(vet, vet_copy);


            ini = high_resolution_clock::now();
            heapsort(vet, i);
            fim = high_resolution_clock::now();

            t = fim - ini;;
            dados_heap << i << " " << duration_cast<microseconds>(t).count() << endl; //"us\n";

            reverter(vet, vet_copy);

            
        
        }

    }
    else exit(1);


    dados_ins.close();    dados_selec.close();    
    dados_flut.close();   dados_heap.close();

    cout << "Dados gerados com sucesso!\n\n";

    heapsort(vet, tam); //Ordenando novamente para testar a função 'ordenado'
   // exibir(vet, 0, tam);
    if(ordenado(vet, tam))
        cout << "Vetor ordenado\n";
    else cout << "Vetor nao ordenado\n";
    

    //exibir(vet, 0, tam);

}



