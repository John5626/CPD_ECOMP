#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N; // Seções da piscina

    vector<int> altura;

    for(int i = 0; i < N; i++){
        int H;
        cin >> H; // Altura da seção i
        altura.push_back(H);
    }

    vector<int> secao_cheia(N, false);
    vector<int> secao_ant(N), secao_pos(N);

    secao_ant[0] = altura[0];
    for(int i = 1; i < N; i++)
        secao_ant[i] = max(secao_ant[i-1], altura[i]);


    secao_pos[N-1] = altura[N-1];
    for(int i = N - 2; i >= 0; i--)
        secao_pos[i] = max(secao_pos[i+1], altura[i]);


    for(int i = 0; i < N; i++)
        if((i > 0 && i < N-1 ) && altura[i] < min(secao_ant[i-1], secao_pos[i+1]))
            secao_cheia[i] = true;

    int cont = 0;

    for(int i = 0; i < N; i++){
        if(secao_cheia[i])
            cont++;
    }

    cout << cont << endl;

    return 0;
}
