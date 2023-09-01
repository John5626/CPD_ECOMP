#include <bits/stdc++.h>

using namespace std;

int main() {
    fstream fout;
    fout.open("dados.dat", ios::out);

    if(fout.is_open()) {
        for(int i = 1; i <= 10; i++)
            fout << i << endl;
        fout.close();
    } else {
        cout << "falha na abertura do arquivo\n";
    }

    fstream fin;
    fin.open("dados.dat", ios::in);
    
    string line;
    if(fin.is_open()) {
        while(getline(fin, line))
            cout << line << endl;
        
        fin.close();
    }

    return 0;
}