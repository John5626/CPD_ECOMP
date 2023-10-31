#include <bits/stdc++.h>

using namespace std;

void counting_sort(string& v);
int ordenado(string s);

int main(){
    string s;
    cin >> s;

    counting_sort(s);

    cout << endl;
    cout << "Ordenado: "; 
    if(ordenado(s))
        cout << "sim." << endl;
    else cout << "nao." << endl;
    cout << s << endl;
}

void counting_sort(string& s){
    auto max = max_element(s.begin(), s.end());
    
    int maior = *max;

    vector<int> aux(maior+1, 0);

  
    for(int i = 0; i < s.size(); i++)
       aux[s[i]]++;

   
    for(int i = 1; i < aux.size(); i++)
        aux[i] += aux[i-1];

    string temp(s.size(), 0);

    for(int i = s.size()-1; i >= 0; i--) {
        temp[aux[s[i]] - 1] = s[i];
        aux[s[i]]--;
    }

    for(int i = 0; i < s.size(); i++)
        s[i] = temp[i];
    
}

int ordenado(string s){
    for(int i = 1; i < s.size(); i++){
        if(s[i] < s[i-1])
            return false;
    }
    return true;
}
