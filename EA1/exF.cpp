#include <iostream>

using namespace std;

int main(){
    bool grafo[5][5];
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++)
            grafo[i][j] = false;
    }
    grafo[0][1] = grafo[0][2] = true;
    grafo[1][2] = grafo[1][3] = true;
    grafo[2][3] = grafo[2][4] = true;
    grafo[3][0] = grafo[3][4] = true;
    grafo[4][0] = grafo[4][1] = true;

    int N;
    cin >> N;
    int pts[2] = {0}; //[0] dario [1] Xerxes

    for(int i = 0; i < N; i++){
        int D,X;
        cin >> D >> X;
        if(grafo[X][D] == true)
            pts[1]++; 
        else pts[0]++;
    }

    if(pts[0] > pts[1])
        cout << "dario";
    
    else cout << "xerxes";

}

/*

-  0  1  2  3  4
0  0  1  1  0  0
1  0  0  0  0  0
2  0  0  0  0  0
3  0  0  0  0  0
4  0  0  0  0  0



*/  