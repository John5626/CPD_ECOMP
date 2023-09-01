#include <iostream>

using namespace std;

int main(){
   int N; cin >> N;

   int seq_maior = 1;
   int cont_seq = 1;
   int val_ant, val_atual;

   
   for(int i = 0; i < N; i++){
        cin >> val_atual;
        
        if(val_atual == val_ant)
            cont_seq++;
        else cont_seq = 1;

        if(cont_seq > seq_maior)
            seq_maior = cont_seq;
        

        val_ant = val_atual;

   }
   


   cout << seq_maior << endl;

}